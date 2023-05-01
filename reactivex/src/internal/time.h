#ifndef RX_TIME_H
#define RX_TIME_H

#include <chrono>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "internal/basic.h"

class AbsoluteTime;
class RelativeTime;

typedef std::chrono::time_point<std::chrono::system_clock> time_point_;
typedef std::chrono::time_point<std::chrono::system_clock>::duration time_delta_;

using namespace godot;


class AbsoluteTime : public RefCounted {
    GDCLASS(AbsoluteTime, RefCounted);

public:
    time_point_ t;

protected:
	static void _bind_methods();

public:
    AbsoluteTime();
    AbsoluteTime(time_point_ t);
    ~AbsoluteTime();

    int64_t to_hrs();
    int64_t to_min();
    int64_t to_sec();
    int64_t to_msec();
    int64_t to_usec();
    int64_t to_nsec();

    Ref<RelativeTime> time_since_epoch();

    Ref<AbsoluteTime> timeshift(Ref<RelativeTime> dt);
    Ref<RelativeTime> timedelta(Ref<AbsoluteTime> t);

}; // END AbsoluteTime


class RelativeTime : public RefCounted {
    GDCLASS(RelativeTime, RefCounted);

public:
    time_delta_ dt;

protected:
	static void _bind_methods();

public:
    RelativeTime();
    RelativeTime(time_delta_ dt);
    ~RelativeTime();

    int64_t to_hrs();
    int64_t to_min();
    int64_t to_sec();
    int64_t to_msec();
    int64_t to_usec();
    int64_t to_nsec();

    Ref<RelativeTime> timedelta(Ref<RelativeTime> dt);
    Ref<AbsoluteTime> timeshift(Ref<AbsoluteTime> t);

}; // END RelativeTime

#endif // RX_TIME_H