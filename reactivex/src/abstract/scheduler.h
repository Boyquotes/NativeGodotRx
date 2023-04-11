#ifndef RX_ABSTRACT_SCHEDULER_H
#define RX_ABSTRACT_SCHEDULER_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "disposable.h"

#include <chrono>

using namespace godot;

class SchedulerBase : public RefCounted {
    GDCLASS(SchedulerBase, RefCounted);

public:
    SchedulerBase(){}
    ~SchedulerBase(){}

protected:
    static void _bind_methods() {

    }

public:
    float now() {
        throw NotImplementedException();
    }

    DisposableBase* schedule(Callable action, Variant state) {
        throw NotImplementedException();
    }

    DisposableBase* schedule_absolute(float duetime, Callable action, Variant state) {
        throw NotImplementedException();
    }

    DisposableBase* schedule_relative(float duetime, Callable action, Variant state) {
        throw NotImplementedException();
    }

    static float to_seconds(std::chrono::time_point<std::chrono::system_clock> t) {
        return 0.0f;
    }

    static float to_timedelta(std::chrono::time_point<std::chrono::system_clock> t) {
        return 0.0f;
    }

    static float to_datetime(std::chrono::time_point<std::chrono::system_clock>::duration dt) {
        return 0.0f;
    }

};

#endif // RX_ABSTRACT_SCHEDULER_H