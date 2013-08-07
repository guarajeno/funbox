package com.minigloop.display;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class VisualObject
{
	private var _canvas:Sprite;
	
	public var position:Vector2D;
	
	public function new(canvas:Sprite) 
	{
		_canvas = canvas;
		
		position = new Vector2D(0, 0);
	}
	
	public function update(dt:Int):Void
	{
		
	}
}