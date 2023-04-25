#include "refcountdisposable.h"

InnerDisposable::InnerDisposable() : parent(), is_disposed(false), lock() {}
InnerDisposable::~InnerDisposable() {}

InnerDisposable* InnerDisposable::Get(RefCountDisposable* parent) {
    auto disp = memnew(InnerDisposable);
    disp->parent = Ref<RefCountDisposable>(parent);
    return disp;
}

void InnerDisposable::dispose() {
    /*this->lock.lock();
    auto parent = this->parent;
    this->parent = Ref<RefCountDisposable>();
    this->lock.unlock();

    if (!parent.is_null()) {
        parent->release();
    }*/
}

