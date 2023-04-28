/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "internal/basic.h"

#include "exception/exceptionwrapper.h"

#include "abstract/disposable.h"
#include "abstract/scheduler.h"
#include "abstract/observer.h"
#include "abstract/observable.h"
#include "abstract/subject.h"

#include "disposable/disposable.h"
#include "disposable/booleandisposable.h"
#include "disposable/compositedisposable.h"
#include "disposable/multiassignmentdisposable.h"
#include "disposable/refcountdisposable.h"

using namespace godot;

void initialize_rx_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	// exception
	ClassDB::register_abstract_class<RxError>();
	// abstract
	ClassDB::register_abstract_class<DisposableBase>();
	ClassDB::register_abstract_class<SchedulerBase>();
	ClassDB::register_abstract_class<ObservableBase>();
	ClassDB::register_abstract_class<ObserverBase>();
	ClassDB::register_abstract_class<SubjectAsObserver>();
	ClassDB::register_abstract_class<SubjectAsObservable>();
	// disposable
	ClassDB::register_class<Disposable>();
	ClassDB::register_class<BooleanDisposable>();
	ClassDB::register_class<CompositeDisposable>();
	ClassDB::register_class<MultiAssignmentDisposable>();
	ClassDB::register_class<InnerDisposable>();
	ClassDB::register_class<RefCountDisposable>();
}

void uninitialize_rx_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT rx_library_init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_initializer(initialize_rx_module);
	init_obj.register_terminator(uninitialize_rx_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
