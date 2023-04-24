#include "disposable.h"

#include <godot_cpp/variant/callable.hpp>

Disposable::Disposable() : is_disposed(false), action(), lock() {}
Disposable::~Disposable(){}

Disposable* Disposable::Get(Callable action) {
    auto disp = memnew(Disposable);
    disp->action = action;
    return disp;
}

void Disposable::_bind_methods() {
    ClassDB::bind_static_method("Disposable", D_METHOD("Get", "action"), &Disposable::Get);
    ClassDB::bind_method(D_METHOD("dispose"), &Disposable::dispose);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &Disposable::dispose_with);
}

void Disposable::dispose() {
    bool disposed = false;
    this->lock.lock();
    if (!this->is_disposed) {
        disposed = true;
        this->is_disposed = true;
    }
    this->lock.unlock();

    if (disposed) {
        this->action.callv(Array());
    }
}

void Disposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}