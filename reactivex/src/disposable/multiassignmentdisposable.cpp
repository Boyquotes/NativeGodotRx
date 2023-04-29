#include "multiassignmentdisposable.h"

MultiAssignmentDisposable::MultiAssignmentDisposable() : current(), is_disposed(false), lock(memnew(RLock)) {}
MultiAssignmentDisposable::~MultiAssignmentDisposable() {}

MultiAssignmentDisposable* MultiAssignmentDisposable::Get() {
    return memnew(MultiAssignmentDisposable);
}

void MultiAssignmentDisposable::_bind_methods() {
    ClassDB::bind_static_method("MultiAssignmentDisposable", D_METHOD("Get"), &MultiAssignmentDisposable::Get);
    ClassDB::bind_method(D_METHOD("get_disposable"), &MultiAssignmentDisposable::get_disposable);
    ClassDB::bind_method(D_METHOD("set_disposable", "value"), &MultiAssignmentDisposable::set_disposable);
    ClassDB::bind_method(D_METHOD("dispose"), &MultiAssignmentDisposable::dispose);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &MultiAssignmentDisposable::dispose_with);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "disposable"), "set_disposable", "get_disposable");

    ClassDB::bind_method(D_METHOD("__get__is_disposed__"), &MultiAssignmentDisposable::__get__is_disposed__);
    ClassDB::bind_method(D_METHOD("__set__is_disposed__", "v"), &MultiAssignmentDisposable::__set__is_disposed__);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_disposed"), "__set__is_disposed__", "__get__is_disposed__");

    ClassDB::bind_method(D_METHOD("__get__lock__"), &MultiAssignmentDisposable::__get__lock__);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "lock"), "", "__get__lock__");
}

Ref<DisposableBase> MultiAssignmentDisposable::get_disposable() {
    return this->current;
}

void MultiAssignmentDisposable::set_disposable(DisposableBase* value) {
    this->lock->lock();
    bool should_dispose = this->is_disposed;
    if (!should_dispose) {
        this->current = Ref<DisposableBase>(value);
    }
    this->lock->unlock();

    if (should_dispose && value) {
        value->dispose();
    }
}

void MultiAssignmentDisposable::dispose() {
    Ref<DisposableBase> old;

    this->lock->lock();
    if (!this->is_disposed) {
        this->is_disposed = true;
        old = this->current;
    }
    this->lock->unlock();

    if (!old.is_null()) {
        old->dispose();
    }
}

void MultiAssignmentDisposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}

// Setters and Getters
bool MultiAssignmentDisposable::__get__is_disposed__() {
    return this->is_disposed;
}
void MultiAssignmentDisposable::__set__is_disposed__(bool is_disposed) {
    this->is_disposed = is_disposed;
}
Ref<RLock> MultiAssignmentDisposable::__get__lock__() {
    return this->lock;
}