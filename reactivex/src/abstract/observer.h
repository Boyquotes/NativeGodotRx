#ifndef RX_ABSTRACT_OBSERVER_H
#define RX_ABSTRACT_OBSERVER_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "exception/exception.h"
#include "exception/exceptionwrapper.h"

using namespace godot;

class ObserverBase : public RefCounted {
    GDCLASS(ObserverBase, RefCounted);

public:
    ObserverBase(){}
    ~ObserverBase(){}

protected:
	static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("on_next", "item"), &ObserverBase::on_next);
        ClassDB::bind_method(D_METHOD("on_error", "error"), &ObserverBase::on_error);
        ClassDB::bind_method(D_METHOD("on_completed"), &ObserverBase::on_completed);
    }

public:
    virtual void on_next(Variant i) {
        throw NotImplementedException();
    }

    virtual void on_error(RxError* e) {
        throw NotImplementedException();
    }

    virtual void on_completed() {
        throw NotImplementedException();
    }
};

#endif // RX_ABSTRACT_OBSERVER_H