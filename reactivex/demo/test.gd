extends Node



# Called when the node enters the scene tree for the first time.
func _ready():
	var disp : Disposable = Disposable.Get(func(): print("!!!"))
	disp.dispose()
	disp.dispose()
	#n._ready()



# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
