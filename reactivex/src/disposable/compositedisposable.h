#ifndef RX_DISPOABLE_COMPOSITEDISPOSABLE_H
#define RX_DISPOABLE_COMPOSITEDISPOSABLE_H

#include <mutex>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "abstract/disposable.h"
#include "exception/exception.h"

using namespace godot;

class CompositeDisposable : public DisposableBase {
    GDCLASS(CompositeDisposable, DisposableBase);

public:
    Array disposable;
    bool is_disposed;
    std::recursive_mutex lock;

protected:
	static void _bind_methods();

public:
    CompositeDisposable();
    ~CompositeDisposable();

    static CompositeDisposable* Get(Array items);

    virtual void dispose() override;
    virtual void dispose_with(Object* obj) override;

    void add(DisposableBase* item);
    void remove(DisposableBase* item);
    void clear();
    bool contains(DisposableBase* item);
    Array to_list();
    int size();
};

#endif // RX_DISPOABLE_COMPOSITEDISPOSABLE_H