#include "compositedisposable.h"

CompositeDisposable::CompositeDisposable() : disposable(), is_disposed(false), lock() {}
CompositeDisposable::~CompositeDisposable() {}

CompositeDisposable* CompositeDisposable::Get(Array items) {
    auto disp = memnew(CompositeDisposable);
    disp->disposable = items;
    return disp;
}

void CompositeDisposable::_bind_methods() {
    ClassDB::bind_static_method("CompositeDisposable", D_METHOD("Get", "items"), &CompositeDisposable::Get);
}