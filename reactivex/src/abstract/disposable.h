#ifndef RX_ABSTRACT_DISPOSABLE_H
#define RX_ABSTRACT_DISPOSABLE_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "exception/exception.h"

using namespace godot;

class DisposableBase : public RefCounted {
    GDCLASS(DisposableBase, RefCounted);

protected:
	static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("dispose"), &DisposableBase::dispose);
        ClassDB::bind_method(D_METHOD("dispose_with", "obj"), &DisposableBase::dispose_with);
    }

public:
    DisposableBase(){}
    ~DisposableBase(){}

    virtual void dispose(){
        throw NotImplementedException();
    }
    virtual void dispose_with(Object* obj) {
        throw NotImplementedException();
    }
};

#endif // RX_ABSTRACT_DISPOSABLE_H