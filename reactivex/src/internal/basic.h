#ifndef RX_BASIC_H
#define RX_BASIC_H

#include <chrono>
#include <string>

template <class T>
static void noop(T args...) {}

template <class T0, class T1>
static T0 identity(T0 x, T1 args...) {
    return x;
}

static std::chrono::time_point<std::chrono::system_clock> now() {
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
static std::string default_key_serializer(T x) {
    return std::string(reinterpret_cast<uint64_t>(x));
}

#endif // RX_BASIC_H