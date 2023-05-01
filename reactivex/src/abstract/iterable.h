#ifndef RX_ABSTRACT_ITERABLE_H
#define RX_ABSTRACT_ITERABLE_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/iterator.h"
#include "exception/exception.h"

using namespace godot;

class IterableBase : public RefCounted {
    GDCLASS(IterableBase, RefCounted);

public:
    IterableBase(){}
    ~IterableBase(){}

protected:
	static void _bind_methods() {
        BIND_VIRTUAL_METHOD(IterableBase, iter);
    }

public:
    virtual Ref<IteratorBase> iter() {
        throw NotImplementedException();
    }
};

#endif // RX_ABSTRACT_ITERABLE_H