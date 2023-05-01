#include "time.h"

AbsoluteTime::AbsoluteTime() : t(basic::now<time_point_>()) {}
AbsoluteTime::AbsoluteTime(time_point_ t) : t(t) {}
AbsoluteTime::~AbsoluteTime() {}

void AbsoluteTime::_bind_methods() {
    ClassDB::bind_method(D_METHOD("to_hrs"), &AbsoluteTime::to_hrs);
    ClassDB::bind_method(D_METHOD("to_min"), &AbsoluteTime::to_min);
    ClassDB::bind_method(D_METHOD("to_sec"), &AbsoluteTime::to_sec);
    ClassDB::bind_method(D_METHOD("to_msec"), &AbsoluteTime::to_msec);
    ClassDB::bind_method(D_METHOD("to_usec"), &AbsoluteTime::to_usec);
    ClassDB::bind_method(D_METHOD("to_nsec"), &AbsoluteTime::to_nsec);
    ClassDB::bind_method(D_METHOD("time_since_epoch"), &AbsoluteTime::time_since_epoch);
    ClassDB::bind_method(D_METHOD("timeshift", "dt"), &AbsoluteTime::timeshift);
    ClassDB::bind_method(D_METHOD("timedelta", "t"), &AbsoluteTime::timedelta);
}

int64_t AbsoluteTime::to_hrs() {
    return std::chrono::duration_cast<std::chrono::hours>(this->t.time_since_epoch()).count();
}
int64_t AbsoluteTime::to_min() {
    return std::chrono::duration_cast<std::chrono::minutes>(this->t.time_since_epoch()).count();
}
int64_t AbsoluteTime::to_sec() {
    return std::chrono::duration_cast<std::chrono::seconds>(this->t.time_since_epoch()).count();
}
int64_t AbsoluteTime::to_msec() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(this->t.time_since_epoch()).count();
}
int64_t AbsoluteTime::to_usec() {
    return std::chrono::duration_cast<std::chrono::microseconds>(this->t.time_since_epoch()).count();
}
int64_t AbsoluteTime::to_nsec() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(this->t.time_since_epoch()).count();
}

Ref<RelativeTime> AbsoluteTime::time_since_epoch() {
    return memnew(RelativeTime(t.time_since_epoch()));
}

Ref<AbsoluteTime> AbsoluteTime::timeshift(Ref<RelativeTime> dt) {
    return memnew(AbsoluteTime(this->t + dt->dt));
}

Ref<RelativeTime> AbsoluteTime::timedelta(Ref<AbsoluteTime> t) {
    return memnew(RelativeTime(t->t - this->t));
}


RelativeTime::RelativeTime() : dt(basic::now<time_point_>().time_since_epoch()) {}
RelativeTime::RelativeTime(time_delta_ dt) : dt(dt) {}
RelativeTime::~RelativeTime() {}

void RelativeTime::_bind_methods() {
    ClassDB::bind_method(D_METHOD("to_hrs"), &RelativeTime::to_hrs);
    ClassDB::bind_method(D_METHOD("to_min"), &RelativeTime::to_min);
    ClassDB::bind_method(D_METHOD("to_sec"), &RelativeTime::to_sec);
    ClassDB::bind_method(D_METHOD("to_msec"), &RelativeTime::to_msec);
    ClassDB::bind_method(D_METHOD("to_usec"), &RelativeTime::to_usec);
    ClassDB::bind_method(D_METHOD("to_nsec"), &RelativeTime::to_nsec);
    ClassDB::bind_method(D_METHOD("timeshift", "dt"), &RelativeTime::timeshift);
    ClassDB::bind_method(D_METHOD("timedelta", "t"), &RelativeTime::timedelta);
}

int64_t RelativeTime::to_hrs() {
    return std::chrono::duration_cast<std::chrono::hours>(this->dt).count();
}
int64_t RelativeTime::to_min() {
    return std::chrono::duration_cast<std::chrono::minutes>(this->dt).count();
}
int64_t RelativeTime::to_sec() {
    return std::chrono::duration_cast<std::chrono::seconds>(this->dt).count();
}
int64_t RelativeTime::to_msec() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(this->dt).count();
}
int64_t RelativeTime::to_usec() {
    return std::chrono::duration_cast<std::chrono::microseconds>(this->dt).count();
}
int64_t RelativeTime::to_nsec() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(this->dt).count();
}

Ref<RelativeTime> RelativeTime::timedelta(Ref<RelativeTime> dt) {
    return memnew(RelativeTime(dt->dt - this->dt));
}

Ref<AbsoluteTime> RelativeTime::timeshift(Ref<AbsoluteTime> t) {
    return memnew(AbsoluteTime(t->t + this->dt));
}