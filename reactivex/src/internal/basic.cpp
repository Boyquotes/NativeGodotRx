#include "basic.h"

#include <chrono>
#include <string>
#include <exception>
#include <iostream>

template <class T>
void noop(T args...) {

}

template <class T0, class T1>
T0 identity(T0 x, T1 args...) {
    return x;
}

template <class T>
T now() {
    return std::chrono::system_clock::now();
}

template <class T>
bool default_comparer(T x, T y) {
    return x == y;
}

template <class T>
T default_sub_comparer(T x, T y) {
    return x - y;
}

template <class T>
T default_key_serializer(T x) {
    return std::string(reinterpret_cast<uint64_t>(x));
}

template <class T>
void default_error(T err) {
    throw err;
}

template <class T>
void default_crash(T err) {
    std::cout << "Unhandled exception: " << err.what << std::endl;
    exit(1);
}

template <class T>
bool default_condition(T args...) {
    return true;
}