#include "disposable.h"

#include <godot_cpp/variant/callable.hpp>

Disposable::Disposable(){}
Disposable::Disposable(Callable action) : is_disposed(false), action(action), lock() {}
Disposable::~Disposable(){}

void Disposable::_bind_methods() {
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
        this->action.call();
    }
}

void Disposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}