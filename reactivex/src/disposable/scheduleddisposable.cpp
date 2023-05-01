#include "scheduleddisposable.h"

ScheduledDisposable::ScheduledDisposable() : scheduler(), disposable(memnew(SingleAssignmentDisposable)), lock(memnew(RLock)) {}
ScheduledDisposable::~ScheduledDisposable() {}

ScheduledDisposable* ScheduledDisposable::Get(Ref<SchedulerBase> scheduler, Ref<DisposableBase> disposable) {
    auto disp = memnew(ScheduledDisposable);
    disp->scheduler = scheduler;
    disp->disposable->set_disposable(disposable);
    return disp;
}

void ScheduledDisposable::_bind_methods() {
    ClassDB::bind_static_method("ScheduledDisposable", D_METHOD("Get", "scheduler", "disposable"), &ScheduledDisposable::Get);
    ClassDB::bind_method(D_METHOD("dispose"), &ScheduledDisposable::dispose);
    ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &ScheduledDisposable::dispose_with);
    ClassDB::bind_method(D_METHOD("is_disposed"), &ScheduledDisposable::is_disposed);

    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_disposed"), "", "is_disposed");

    ClassDB::bind_method(D_METHOD("__get__lock__"), &ScheduledDisposable::__get__lock__);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "lock"), "", "__get__lock__");

    ClassDB::bind_method(D_METHOD("__get__scheduler__"), &ScheduledDisposable::__get__scheduler__);
    ClassDB::bind_method(D_METHOD("__set__scheduler__", "v"), &ScheduledDisposable::__set__scheduler__);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "scheduler"), "__set__scheduler__", "__get__scheduler__");
}

bool ScheduledDisposable::is_disposed() {
    return this->disposable->is_disposed;
}

void ScheduledDisposable::dispose() {
    auto action = Callable(this->disposable.ptr(), "dispose");
    this->scheduler->schedule(action);
}

void ScheduledDisposable::dispose_with(Object* obj) {
    // TODO Implement AutoDisposer!!!
    throw NotImplementedException();
}

// Setters and Getters
Ref<RLock> ScheduledDisposable::__get__lock__() {
    return this->lock;
}
Ref<SchedulerBase> ScheduledDisposable::__get__scheduler__() {
    return this->scheduler;
}
void ScheduledDisposable::__set__scheduler__(Ref<SchedulerBase> scheduler) {
    this->scheduler = scheduler;
}