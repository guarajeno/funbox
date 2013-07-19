package com.minigloop.input;
import com.minigloop.util.Vector2D;
import flash.display.Sprite;
import nme.display.Stage;
import nme.events.MouseEvent;

/**
 * ...
 * @author 
 */

class Mouse
{
	// ------ NOTE: STAGE OR SPRITE!!!!!!!!!!!!!-----
	//
	static private var _stage:Stage;
	//
	// ----------------------------------------------
	
	static public var position:Vector2D;
	static public var lastPosition:Vector2D;
	
	public function new() 
	{
		
	}
	
	static public function init(stage:Stage):Void
	{
		_stage = stage;
		_stage.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		_stage.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		
		position = new Vector2D(0, 0);
		lastPosition = new Vector2D(0, 0);
	}
	
	static private function onMouseMove(e:MouseEvent):Void 
	{
		lastPosition.x = position.x;
		lastPosition.y = position.y;
		
		position.x = e.localX;
		position.y = e.localY;
	}
}