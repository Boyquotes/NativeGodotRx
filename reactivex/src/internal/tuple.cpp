#include "tuple.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Tuple::_bind_methods() {
	ClassDB::bind_method(D_METHOD("size"), &Tuple::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &Tuple::is_empty);
    ClassDB::bind_static_method("Tuple", D_METHOD("empty"), &Tuple::empty);
    //ClassDB::bind_static_method("Tuple", D_METHOD("with"), &Tuple::with);
}

Tuple::Tuple() {

}

Tuple::~Tuple() {

}

Tuple* Tuple::empty() {
    return memnew(Tuple());
}

/*Tuple Tuple::with(Variant xs...) {
    Tuple tuple;
    //tuple.data = xs;
    return tuple;
}*/

size_t Tuple::size() {
    return data.size();
}

bool Tuple::is_empty() {
    return data.is_empty();
}

