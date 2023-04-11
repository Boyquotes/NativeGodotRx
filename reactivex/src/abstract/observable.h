#ifndef RX_ABSTRACT_OBSERVABLE_H
#define RX_ABSTRACT_OBSERVABLE_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class ObservableBase : public RefCounted {
    GDCLASS(ObservableBase, RefCounted);

public:
    ObservableBase(){}
    ~ObservableBase(){}

protected:
    static void _bind_methods() {
        {
		    MethodInfo mi;
		    mi.arguments.push_back(PropertyInfo(Variant::VARIANT_MAX, "args"));
		    mi.name = "subscribe";
		    ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "subscribe", &ObservableBase::subscribe, mi);
	    }
    }

public:
    virtual void subscribe(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
        throw NotImplementedException();
    }

};

#endif // RX_ABSTRACT_OBSERVABLE_H