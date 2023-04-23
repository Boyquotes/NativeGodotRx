#ifndef RX_ABSTRACT_OBSERVABLE_H
#define RX_ABSTRACT_OBSERVABLE_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/disposable.h"
#include "abstract/scheduler.h"

using namespace godot;

class ObservableBase : public RefCounted {
    GDCLASS(ObservableBase, RefCounted);

public:
    ObservableBase(){}
    ~ObservableBase(){}

protected:
    static void _bind_methods() {
        BIND_VIRTUAL_METHOD(ObservableBase, subscribe);
    }

public:
    virtual DisposableBase* subscribe(Callable on_next, Callable on_error, Callable on_completed, SchedulerBase* scheduler) {
        throw NotImplementedException();
    }

};

#endif // RX_ABSTRACT_OBSERVABLE_H