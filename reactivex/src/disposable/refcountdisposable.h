#ifndef RX_DISPOABLE_REFCOUNTDISPOSABLE_H
#define RX_DISPOABLE_REFCOUNTDISPOSABLE_H

#include <mutex>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/disposable.h"
#include "exception/exception.h"

using namespace godot;


class RefCountDisposable : public DisposableBase {
    GDCLASS(RefCountDisposable, DisposableBase);

public:
    Ref<DisposableBase> underlying_disposable;
    bool is_primary_disposed;
    bool is_disposed;
    std::recursive_mutex lock;
    int count;

protected:
	static void _bind_methods();

public:
    RefCountDisposable();
    ~RefCountDisposable();

    static RefCountDisposable* Get(DisposableBase* disp);

    virtual void dispose() override;
    virtual void dispose_with(Object* obj) override;

    void release();
    Ref<DisposableBase> get_disposable();
};


class InnerDisposable : public DisposableBase {
    GDCLASS(InnerDisposable, DisposableBase);

public:
    Ref<RefCountDisposable> parent;
    bool is_disposed;
    std::recursive_mutex lock;

protected:
	static void _bind_methods();

public:
    InnerDisposable();
    ~InnerDisposable();

    static InnerDisposable* Get(RefCountDisposable* parent);

    void dispose() override;
};

#endif // RX_DISPOABLE_REFCOUNTDISPOSABLE_H