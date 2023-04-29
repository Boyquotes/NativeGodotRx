extends Node



# Called when the node enters the scene tree for the first time.
func _ready():
	var disp : Disposable = Disposable.Get(func(): print("!!!"))
	
	var cd = CompositeDisposable.Get([
		Disposable.Get(func(): print("1")), 
		Disposable.Get(func(): print("2"))
	])
	cd.add(disp)
	cd.add(Disposable.Get(func(): print("3")))
	cd.remove(disp)
	cd.dispose()
	
	var mad = MultiAssignmentDisposable.Get()
	mad.disposable = Disposable.Get(func(): print("<!>"))
	mad.dispose()
	
	var bd = BooleanDisposable.Get()
	var l : RLock = bd.lock
	l.lock()
	l.unlock()
	print(">>> ", bd.lock.get_instance_id())
	print(">>> ", l.get_instance_id())
	
	var rcd = RefCountDisposable.Get(mad)
	var dref1 = rcd.disposable
	var dref2 = rcd.disposable
	print(">>> ", dref1.get_instance_id())
	print(">>> ", dref2.get_instance_id())
	print(">>> ", rcd.count)
	dref1.dispose()
	
	var d = Disposable.Get(func(): print(":("))
	d.action = func(): print(":)")
	d.dispose()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
