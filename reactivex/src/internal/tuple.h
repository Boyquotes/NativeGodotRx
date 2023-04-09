#ifndef RX_TUPLE_H
#define RX_TUPLE_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/array.hpp>

using namespace godot;

class Tuple : public RefCounted {
    GDCLASS(Tuple, RefCounted);

private:
    Array data;

protected:
	static void _bind_methods();

public:
    Tuple();
	~Tuple();

    static Tuple* empty();
    //static Tuple with(Variant xs...);

    /*Variant& operator[](uint64_t idx);
    Array to_array();*/
    bool is_empty();
    size_t size();
};

#endif // RX_TUPLE_H