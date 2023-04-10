#ifndef RX_BASIC_H
#define RX_BASIC_H

template <class T>
void noop(T args...);

template <class T0, class T1>
T0 identity(T0 x, T1 args...);

template <class T>
T now();

template <class T>
bool default_comparer(T x, T y);

template <class T>
T default_sub_comparer(T x, T y);

template <class T>
T default_key_serializer(T x);

template <class T>
void default_error(T err);

template <class T>
void default_crash(T err);

template <class T>
bool default_condition(T args...);

#endif // RX_BASIC_H