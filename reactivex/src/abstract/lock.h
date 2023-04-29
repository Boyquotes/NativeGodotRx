#ifndef RX_ABSTRACT_LOCK_H
#define RX_ABSTRACT_LOCK_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "exception/exception.h"

using namespace godot;

class LockBase : public RefCounted {
    GDCLASS(LockBase, RefCounted);

public:
    LockBase(){}
    ~LockBase(){}

protected:
	static void _bind_methods() {
        BIND_VIRTUAL_METHOD(LockBase, lock);
        BIND_VIRTUAL_METHOD(LockBase, unlock);
        BIND_VIRTUAL_METHOD(LockBase, try_lock);
    }

public:
    virtual void lock() {
        throw NotImplementedException();
    }
    virtual void unlock() {
        throw NotImplementedException();
    }
    virtual bool try_lock() {
        throw NotImplementedException();
    }
};

#endif // RX_ABSTRACT_LOCK_H