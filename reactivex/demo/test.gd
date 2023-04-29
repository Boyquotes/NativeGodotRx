extends Node



# Called when the node enters the scene tree for the first time.
func _ready():
	var sd = SerialDisposable.Get()
	sd.disposable = Disposable.Get(func(): print("1"))
	sd.disposable = Disposable.Get(func(): print("2"))
	sd.disposable = Disposable.Get(func(): print("3"))
	sd.disposable = Disposable.Get(func(): print("4"))
	sd.dispose()
	print(">>> ", sd.is_disposed)
	#


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
