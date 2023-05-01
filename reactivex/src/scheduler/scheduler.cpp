#include "scheduler.h"

#include <godot_cpp/variant/callable.hpp>

#include "internal/basic.h"
#include "disposable/disposable.h"
#include "exception/exception.h"

Scheduler::Scheduler(){}
Scheduler::~Scheduler(){}

Scheduler* Scheduler::Get() {
    return memnew(Scheduler);
}

void Scheduler::_bind_methods() {
    ClassDB::bind_static_method("Scheduler", D_METHOD("Get"), &Scheduler::Get);
    ClassDB::bind_static_method("Scheduler", D_METHOD("to_seconds", "value"), &Scheduler::to_seconds);
    ClassDB::bind_static_method("Scheduler", D_METHOD("to_datetime", "value"), &Scheduler::to_datetime);
    ClassDB::bind_static_method("Scheduler", D_METHOD("to_timedelta", "value"), &Scheduler::to_timedelta);
    ClassDB::bind_method(D_METHOD("now"), &Scheduler::now);
    ClassDB::bind_method(D_METHOD("invoke_action", "action", "state"), &Scheduler::invoke_action);
}

float Scheduler::to_seconds(const Variant& value) {
    if (auto t = Object::cast_to<AbsoluteTime>(value)) {
        return t->to_sec();
    }
    if (auto dt = Object::cast_to<RelativeTime>(value)) {
        return dt->to_sec();
    }
    throw BadArgumentException();
}

Ref<RelativeTime> Scheduler::to_timedelta(const Variant& value) {
    if (auto dt = Object::cast_to<RelativeTime>(value)) {
        return dt;
    }
    if (auto t = Object::cast_to<AbsoluteTime>(value)) {
        return t->time_since_epoch();
    }
    throw BadArgumentException();
}

Ref<AbsoluteTime> Scheduler::to_datetime(const Variant& value) {
    if (auto t = Object::cast_to<AbsoluteTime>(value)) {
        return t;
    }
    if (auto dt = Object::cast_to<RelativeTime>(value)) {
        throw NotImplementedException();
    }
    throw BadArgumentException();
}

Ref<AbsoluteTime> Scheduler::now() {
    return memnew(AbsoluteTime(basic::now<time_point_>()));
}

Ref<DisposableBase> Scheduler::invoke_action(Callable action, Variant state) {
    auto res = action.callv(Array::make(Ref<SchedulerBase>(this), state));
    if (auto ret = Object::cast_to<DisposableBase>(res)) {
        return ret;
    }
    return Disposable::Empty();
 }