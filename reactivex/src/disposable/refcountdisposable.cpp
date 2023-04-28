#include "refcountdisposable.h"

#include "disposable.h"

InnerDisposable::InnerDisposable() : parent(), is_disposed(false), lock() {}
InnerDisposable::~InnerDisposable() {}

void InnerDisposable::_bind_methods() {
    ClassDB::bind_static_method("InnerDisposable", D_METHOD("Get", "parent"), &InnerDisposable::Get);
    ClassDB::bind_method(D_METHOD("dispose"), &InnerDisposable::dispose);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &InnerDisposable::dispose_with);
}

InnerDisposable* InnerDisposable::Get(RefCountDisposable* parent) {
    auto disp = memnew(InnerDisposable);
    disp->parent = Ref<RefCountDisposable>(parent);
    return disp;
}

void InnerDisposable::dispose() {
    this->lock.lock();
    auto parent = this->parent;
    this->parent = Ref<RefCountDisposable>();
    this->lock.unlock();

    if (!parent.is_null()) {
        parent->release();
    }
}

void InnerDisposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}

RefCountDisposable::RefCountDisposable() : underlying_disposable(), is_primary_disposed(false), is_disposed(false), lock(), count(0) {}
RefCountDisposable::~RefCountDisposable() {}

void RefCountDisposable::_bind_methods() {
    ClassDB::bind_static_method("RefCountDisposable", D_METHOD("Get", "disposable"), &RefCountDisposable::Get);
    ClassDB::bind_method(D_METHOD("dispose"), &RefCountDisposable::dispose);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &RefCountDisposable::dispose_with);
    ClassDB::bind_method(D_METHOD("release"), &RefCountDisposable::release);
    ClassDB::bind_method(D_METHOD("get_disposable"), &RefCountDisposable::get_disposable);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "disposable"), "", "get_disposable");
}

RefCountDisposable* RefCountDisposable::Get(DisposableBase* disposable) {
    auto disp = memnew(RefCountDisposable);
    disp->underlying_disposable = Ref<DisposableBase>(disposable);
    return disp;
}

void RefCountDisposable::dispose() {
    if (this->is_disposed) {
        return;
    }

    Ref<DisposableBase> _underlying_disposable;
    this->lock.lock();
    if (!this->is_primary_disposed) {
        this->is_primary_disposed = true;
        if (!this->count) {
            this->is_disposed = true;
            _underlying_disposable = this->underlying_disposable;
        }
    }
    this->lock.unlock();

    if (!_underlying_disposable.is_null()) {
        _underlying_disposable->dispose();
    }
}

void RefCountDisposable::release() {
    if (this->is_disposed) {
        return;
    }

    bool should_dispose = false;
    this->lock.lock();
    this->count--;
    if (!this->count && this->is_primary_disposed) {
        this->is_disposed = true;
        should_dispose = true;
    }
    this->lock.unlock();

    if (should_dispose) {
        this->underlying_disposable->dispose();
    }
}

DisposableBase* RefCountDisposable::get_disposable() {
    this->lock.lock();
    if (this->is_disposed) {
        this->lock.unlock();
        return memnew(Disposable);
    }
    this->count++;
    auto disp = InnerDisposable::Get(this);
    this->lock.unlock();
    return disp;
}

void RefCountDisposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}