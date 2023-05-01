#ifndef RX_ABSTRACT_SCHEDULER_H
#define RX_ABSTRACT_SCHEDULER_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/disposable.h"
#include "internal/time.h"

using namespace godot;

class SchedulerBase : public RefCounted {
    GDCLASS(SchedulerBase, RefCounted);

public:
    SchedulerBase(){}
    ~SchedulerBase(){}

protected:
    static void _bind_methods() {
        BIND_VIRTUAL_METHOD(SchedulerBase, now);
        BIND_VIRTUAL_METHOD(SchedulerBase, schedule);
        BIND_VIRTUAL_METHOD(SchedulerBase, schedule_absolute);
        BIND_VIRTUAL_METHOD(SchedulerBase, schedule_relative);
    }

public:
    virtual Ref<AbsoluteTime> now() {
        throw NotImplementedException();
    }

    virtual Ref<DisposableBase> schedule(Callable action, Variant state = Variant()) {
        throw NotImplementedException();
    }

    virtual Ref<DisposableBase> schedule_absolute(float duetime, Callable action, Variant state = Variant()) {
        throw NotImplementedException();
    }

    virtual Ref<DisposableBase> schedule_relative(float duetime, Callable action, Variant state = Variant()) {
        throw NotImplementedException();
    }

    static float to_seconds(const Variant& value) {
        throw NotImplementedException();
    }

    static Ref<RelativeTime> to_timedelta(const Variant& value) {
        throw NotImplementedException();
    }

    static Ref<AbsoluteTime> to_datetime(const Variant& value) {
        throw NotImplementedException();
    }

};

#endif // RX_ABSTRACT_SCHEDULER_H