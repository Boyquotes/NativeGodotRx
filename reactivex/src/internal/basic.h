#ifndef RX_BASIC_H
#define RX_BASIC_H

#include <chrono>
#include <string>
#include <exception>
#include <iostream>

template <class T>
static void noop(T args...) {

}

template <class T0, class T1>
static T0 identity(T0 x, T1 args...) {
    return x;
}

template <class T>
static T now() {
    return std::chrono::system_clock::now();
}

template <class T>
static bool default_comparer(T x, T y) {
    return x == y;
}

template <class T>
static T default_sub_comparer(T x, T y) {
    return x - y;
}

template <class T>
static T default_key_serializer(T x) {
    return std::string(reinterpret_cast<uint64_t>(x));
}

template <class T>
static void default_error(T err) {
    throw err;
}

template <class T>
static void default_crash(T err) {
    std::cout << "Unhandled exception: " << err.what << std::endl;
    exit(1);
}

template <class T>
static bool default_condition(T args...) {
    return true;
}

#endif // RX_BASIC_H