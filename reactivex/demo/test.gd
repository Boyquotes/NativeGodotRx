extends Node

class Foo extends DisposableBase:
	func _init():
		pass



# Called when the node enters the scene tree for the first time.
func _ready():
	var n = Foo.new()
	n._ready()



# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
