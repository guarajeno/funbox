package com.funbox.ania.component;
import nme.display.Sprite;
import nme.events.MouseEvent;

/**
 * ...
 * @author 
 */

class CharacterButton extends ButtonPopup
{
	private var _index:Int;
	
	public function new(canvas:Sprite, x:Float, y:Float, upId:String, overId:String, downId:String, delay:Float, _callback:Dynamic, index:Int) 
	{
		super(canvas, x, y, upId, overId, downId, delay, _callback);
		
		_index = index;
	}
	
	override private function onMouseUp(e:MouseEvent):Void 
	{
		setState("up");
		_callback(_index);
	}
}