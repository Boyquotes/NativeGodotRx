#ifndef RX_DISPOABLE_DISPOSABLE_H
#define RX_DISPOABLE_DISPOSABLE_H

#include <mutex>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/callable.hpp>

#include "abstract/disposable.h"
#include "exception/exception.h"

using namespace godot;

class Disposable : public DisposableBase {
    GDCLASS(Disposable, DisposableBase);

public:
    bool is_disposed;
    Callable action;
    std::recursive_mutex lock;

protected:
	static void _bind_methods();

public:
    Disposable();
    ~Disposable();

    static Disposable* Get(Callable action);

    void dispose() override;
    void dispose_with(Object* obj) override;
};

#endif // RX_DISPOABLE_DISPOSABLE_H