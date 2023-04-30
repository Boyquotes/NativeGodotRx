#include "scheduler.h"

#include <godot_cpp/variant/callable.hpp>

#include "internal/basic.h"
#include "disposable/disposable.h"

Scheduler::Scheduler(){}
Scheduler::~Scheduler(){}

Scheduler* Scheduler::Get() {
    return memnew(Scheduler);
}

void Scheduler::_bind_methods() {
    ClassDB::bind_static_method("Scheduler", D_METHOD("Get"), &Scheduler::Get);
    ClassDB::bind_method(D_METHOD("now"), &Scheduler::now);
    ClassDB::bind_method(D_METHOD("invoke_action", "action", "state"), &Scheduler::invoke_action);
}

float Scheduler::to_seconds(time_point_ t) {
    auto dt = t.time_since_epoch();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(dt).count();
    return seconds;
}

float Scheduler::to_timedelta(time_point_ t) {
    auto now = std::chrono::system_clock::now();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(t - now).count();
    return seconds;
}

float Scheduler::to_datetime(time_delta_ dt) {
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(dt).count();
    return seconds;
}

float Scheduler::now() {
    return Scheduler::to_seconds(basic::now<time_point_>());
}

 Ref<DisposableBase> Scheduler::invoke_action(Callable action, Variant state) {
    auto res = action.callv(Array::make(Ref<SchedulerBase>(this), state));
    if (auto ret = Object::cast_to<DisposableBase>(res)) {
        return ret;
    }
    return Disposable::Empty();
 }