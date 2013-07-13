package com.minigloop.display;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.geom.Rectangle;
//import nme.display

/**
 * ...
 * @author 
 */

class Button extends SpriteEntity
{
	private var _callback:Dynamic;
	private var _button:Button;
	
	public function new(canvas:Sprite, upId:String, overId:String, downId:String, _callback:Dynamic) 
	{
		super(canvas);
		
		addState("up", upId, null);
		addState("over", overId, null);
		addState("down", downId, null);
		
		this._callback = _callback;
		
		setState("over");
		setState("down");
		setState("up");
		
		
		
		collision.buttonMode = true;
		collision.addEventListener(MouseEvent.MOUSE_DOWN, onDown);
		collision.addEventListener(MouseEvent.MOUSE_OVER, onOver);
		collision.addEventListener(MouseEvent.MOUSE_OUT, onOut);
		collision.addEventListener(MouseEvent.MOUSE_UP, onOut);
	}
	
	override public function update(dt:Int):Void 
	{
		super.update(dt);
	}
	
	private function onOver(e:MouseEvent):Void 
	{
		setState("over");
	}
	
	private function onOut(e:MouseEvent):Void 
	{
		setState("up");
	}
	
	private function onDown(e:MouseEvent):Void 
	{
		_callback();
		setState("down");
	}
}