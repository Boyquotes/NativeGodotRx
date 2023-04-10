#include "tuple.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Tuple::_bind_methods() {
	ClassDB::bind_method(D_METHOD("size"), &Tuple::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &Tuple::is_empty);
    ClassDB::bind_method(D_METHOD("to_array"), &Tuple::to_array);
    ClassDB::bind_method(D_METHOD("at"), &Tuple::at);
    ClassDB::bind_method(D_METHOD("eq"), &Tuple::equals);
    ClassDB::bind_method(D_METHOD("neq"), &Tuple::nequals);
    ClassDB::bind_method(D_METHOD("gt"), &Tuple::greaterThan);
    ClassDB::bind_method(D_METHOD("gte"), &Tuple::greaterEquals);
    ClassDB::bind_method(D_METHOD("lt"), &Tuple::lessThan);
    ClassDB::bind_method(D_METHOD("lte"), &Tuple::lessEquals);
    ClassDB::bind_static_method("Tuple", D_METHOD("empty"), &Tuple::empty);
    ClassDB::bind_static_method("Tuple", D_METHOD("with", "xs"), &Tuple::with);
}

Tuple::Tuple() {

}

Tuple::~Tuple() {

}

Tuple* Tuple::empty() {
    return memnew(Tuple());
}

Tuple* Tuple::with(Array xs) {
    auto tuple = memnew(Tuple());
    tuple->data = xs.duplicate();
    return tuple;
}

Variant Tuple::at(int idx) {
    return (*this)[idx];
}

Array Tuple::to_array() {
    return data.duplicate();
}

size_t Tuple::size() {
    return data.size();
}

bool Tuple::is_empty() {
    return data.is_empty();
}

bool Tuple::equals(Tuple* other) {
    return *this == *other;
}

bool Tuple::lessThan(Tuple* other) {
    return data[0] < other->data[0];
}

Variant& Tuple::operator[](int index) {
    return data[index];
}

bool Tuple::operator==(Tuple other) {
    if (is_empty() || other.is_empty()) {
        return is_empty() && other.is_empty();
    }
    return data[0] == other.data[0];
}