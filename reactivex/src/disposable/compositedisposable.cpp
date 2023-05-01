#include "compositedisposable.h"

CompositeDisposable::CompositeDisposable() : disposable(), is_disposed(false), lock(memnew(RLock)) {}
CompositeDisposable::~CompositeDisposable() {}

CompositeDisposable* CompositeDisposable::Get(const Array& items) {
    auto disp = memnew(CompositeDisposable);
    disp->disposable = items;
    return disp;
}

void CompositeDisposable::_bind_methods() {
    ClassDB::bind_static_method("CompositeDisposable", D_METHOD("Get", "items"), &CompositeDisposable::Get);
    ClassDB::bind_method(D_METHOD("add", "item"), &CompositeDisposable::add);
    ClassDB::bind_method(D_METHOD("remove", "item"), &CompositeDisposable::remove);
    ClassDB::bind_method(D_METHOD("dispose"), &CompositeDisposable::dispose);
    ClassDB::bind_method(D_METHOD("clear"), &CompositeDisposable::clear);
    ClassDB::bind_method(D_METHOD("contains", "item"), &CompositeDisposable::contains);
    ClassDB::bind_method(D_METHOD("to_list"), &CompositeDisposable::to_list);
    ClassDB::bind_method(D_METHOD("size"), &CompositeDisposable::size);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &CompositeDisposable::dispose_with);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "length"), "", "size");

    ClassDB::bind_method(D_METHOD("__get__is_disposed__"), &CompositeDisposable::__get__is_disposed__);
    ClassDB::bind_method(D_METHOD("__set__is_disposed__", "v"), &CompositeDisposable::__set__is_disposed__);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_disposed"), "__set__is_disposed__", "__get__is_disposed__");

    ClassDB::bind_method(D_METHOD("__get__lock__"), &CompositeDisposable::__get__lock__);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "lock"), "", "__get__lock__");
}

void CompositeDisposable::add(Ref<DisposableBase> item) {
    bool should_dispose = false;
    this->lock->lock();
    if (this->is_disposed) {
        should_dispose = true;
    }
    else {
        this->disposable.append(item);
    }
    this->lock->unlock();

    if (should_dispose) {
        item->dispose();
    }
}

bool CompositeDisposable::remove(Ref<DisposableBase> item) {
    if (this->is_disposed) {
        return false;
    }

    bool should_dispose = false;
    this->lock->lock();
    if (this->disposable.find(item) >= 0) {
        this->disposable.erase(item);
        should_dispose = true;
    }
    this->lock->unlock();

    if (should_dispose) {
        item->dispose();
    }

    return should_dispose;
}

void CompositeDisposable::dispose() {
    if (this->is_disposed) {
        return;
    }

    this->lock->lock();
    this->is_disposed = true;
    auto current_disposable = this->disposable;
    this->disposable = Array();
    this->lock->unlock();

    for (auto i = 0ul; i < current_disposable.size(); i++) {
        Ref<DisposableBase> disp = current_disposable[i];
        disp->dispose();
    }
}

void CompositeDisposable::clear() {
    this->lock->lock();
    auto current_disposable = this->disposable;
    this->disposable = Array();
    this->lock->unlock();

    for (auto i = 0ul; i < current_disposable.size(); i++) {
        Ref<DisposableBase> disp = current_disposable[i];
        disp->dispose();
    }
}

bool CompositeDisposable::contains(Ref<DisposableBase> item) {
    return this->disposable.find(item) >= 0;
}

Array CompositeDisposable::to_list() {
    return this->disposable.duplicate();
}

int CompositeDisposable::size() {
    return this->disposable.size();
}

void CompositeDisposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}

// Setters and Getters
bool CompositeDisposable::__get__is_disposed__() {
    return this->is_disposed;
}
void CompositeDisposable::__set__is_disposed__(bool is_disposed) {
    this->is_disposed = is_disposed;
}
Ref<RLock> CompositeDisposable::__get__lock__() {
    return this->lock;
}