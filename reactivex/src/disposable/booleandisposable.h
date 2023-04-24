#ifndef RX_DISPOABLE_BOOLEANDISPOSABLE_H
#define RX_DISPOABLE_BOOLEANDISPOSABLE_H

#include <mutex>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/disposable.h"
#include "exception/exception.h"

using namespace godot;

class BooleanDisposable : public DisposableBase {
    GDCLASS(BooleanDisposable, DisposableBase);

public:
    bool is_disposed;
    std::recursive_mutex lock;

protected:
	static void _bind_methods();

public:
    BooleanDisposable();
    ~BooleanDisposable();

    static BooleanDisposable* Get();

    virtual void dispose() override;
    virtual void dispose_with(Object* obj) override;
};

#endif // RX_DISPOABLE_BOOLEANDISPOSABLE_H