#ifndef RX_BASIC_H
#define RX_BASIC_H

namespace basic {

void noop();
template <typename T>
void noop(T args...);

template <typename T0, typename T1>
T0 identity(T0 x, T1 args...);
template <typename T>
T identity(T x);

template <typename T>
T now();

template <typename T>
bool default_comparer(T x, T y);

template <typename T>
T default_sub_comparer(T x, T y);

template <typename T>
T default_key_serializer(T x);

template <typename T>
void default_error(T err);

template <typename T>
void default_crash(T err);

bool default_condition();
template <typename T>
bool default_condition(T args...);

} // END namespace basic

#endif // RX_BASIC_H