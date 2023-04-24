#include "booleandisposable.h"

BooleanDisposable::BooleanDisposable() : is_disposed(false), lock() {}
BooleanDisposable::~BooleanDisposable(){}

BooleanDisposable* BooleanDisposable::Get() {
    return memnew(BooleanDisposable);
}

void BooleanDisposable::_bind_methods() {
    ClassDB::bind_method(D_METHOD("dispose"), &BooleanDisposable::dispose);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &BooleanDisposable::dispose_with);
}

void BooleanDisposable::dispose() {
    this->is_disposed = true;
}

void BooleanDisposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}