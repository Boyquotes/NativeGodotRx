#include "basic.h"

#include <chrono>
#include <string>
#include <exception>
#include <iostream>

void basic::noop() {}
template <typename T>
void basic::noop(T args...) {}

template <typename T>
T basic::identity(T x) {
    return x;
}
template <typename T0, typename T1>
T0 basic::identity(T0 x, T1 args...) {
    return x;
}

template <typename T>
T basic::now() {
    return std::chrono::system_clock::now();
}

template <typename T>
bool basic::default_comparer(T x, T y) {
    return x == y;
}

template <typename T>
T basic::default_sub_comparer(T x, T y) {
    return x - y;
}

template <typename T>
T basic::default_key_serializer(T x) {
    return std::string(reinterpret_cast<uint64_t>(x));
}

template <typename T>
void basic::default_error(T err) {
    throw err;
}

template <typename T>
void basic::default_crash(T err) {
    std::cout << "Unhandled exception: " << err.what << std::endl;
    exit(1);
}

template <typename T>
bool basic::default_condition(T args...) {
    return true;
}
bool basic::default_condition() {
    return true;
}