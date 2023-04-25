#ifndef RX_DISPOABLE_MULTIASSIGNMENTDISPOSABLE_H
#define RX_DISPOABLE_MULTIASSIGNMENTDISPOSABLE_H

#include <mutex>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/disposable.h"
#include "exception/exception.h"

using namespace godot;

class MultiAssignmentDisposable : public DisposableBase {
    GDCLASS(MultiAssignmentDisposable, DisposableBase);

public:
    Ref<DisposableBase> current;
    bool is_disposed;
    std::recursive_mutex lock;

protected:
	static void _bind_methods();

public:
    MultiAssignmentDisposable();
    ~MultiAssignmentDisposable();

    static MultiAssignmentDisposable* Get();

    void dispose() override;
    void dispose_with(Object* obj) override;

    Ref<DisposableBase> get_disposable();
    void set_disposable(DisposableBase* value);
};

#endif // RX_DISPOABLE_MULTIASSIGNMENTDISPOSABLE_H