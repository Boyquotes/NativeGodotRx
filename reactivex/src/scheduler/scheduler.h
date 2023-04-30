#ifndef RX_SCHEDULER_SCHEDULER_H
#define RX_SCHEDULER_SCHEDULER_H

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/scheduler.h"

using namespace godot;

typedef std::chrono::time_point<std::chrono::system_clock> time_point_;
typedef std::chrono::time_point<std::chrono::system_clock>::duration time_delta_;

class Scheduler : public SchedulerBase {
    GDCLASS(Scheduler, SchedulerBase);

public:
    static const int UTC_ZERO = 0;
    static const int UTC_DELTA = 0;

protected:
	static void _bind_methods();

public:

    Scheduler();
    ~Scheduler();

    static Scheduler* Get();

    float now() override;
    Ref<DisposableBase> invoke_action(Callable action, Variant state = Variant());

    static float to_seconds(time_point_ t);
    static float to_timedelta(time_point_ t);
    static float to_datetime(time_delta_ dt);

};

#endif // RX_SCHEDULER_SCHEDULER_H