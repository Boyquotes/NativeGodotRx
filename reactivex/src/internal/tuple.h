#ifndef RX_TUPLE_H
#define RX_TUPLE_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "../interfaces.h"

using namespace godot;

class Tuple : public RefCounted, Comparable {
    GDCLASS(Tuple, RefCounted);

private:
    Array data;

protected:
	static void _bind_methods();

public:
    Tuple();
	~Tuple();

    static Tuple* empty();
    static Tuple* with(Array xs);

    Variant at(int idx);
    Array to_array();
    bool is_empty();
    size_t size();

    bool equals(Tuple* other);
    bool lessThan(Tuple* other);

    Variant& operator[](int index);
    bool operator==(Tuple other);
};

#endif // RX_TUPLE_H