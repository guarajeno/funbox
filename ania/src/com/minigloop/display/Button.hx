package com.minigloop.display;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
#if js
import js.Lib;
#end
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
	//private var _over:Bool;
	
	public function new(canvas:Sprite, upId:String, overId:String, downId:String, _callback:Dynamic) 
	{
		super(canvas);
		
		//_over = over;
		addState("up", upId, null);
		addState("over", overId, null);
		addState("down", downId, null);
		
		this._callback = _callback;
		
		setState("up");
		
		collision.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		collision.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		collision.addEventListener(MouseEvent.MOUSE_UP, onMouseUp);
		collision.addEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
		collision.addEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
		//collision.addEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
		
		collision.useHandCursor = true;
	}
	
	private function onMouseMove(e:MouseEvent):Void 
	{
		if (state != "down") setState("over");
	}
	
	private function onMouseDown(e:MouseEvent):Void 
	{
		setState("down");
	}
	
	private function onMouseOver(e:MouseEvent):Void 
	{
		//if (_over)
		//{
			//skin.scaleX = 1;
			//skin.scaleY = 1;
		//}
	}
	
	private function onMouseUp(e:MouseEvent):Void 
	{
		setState("up");
		_callback();
	}
	
	private function onMouseOut(e:MouseEvent):Void 
	{	
		//if (_over)
		//{
			//skin.scaleX = 0.9;
			//skin.scaleY = 0.9;
		//}
		
		setState("up");
	}
	
	override public function destroy():Void 
	{
		super.destroy();
		
		_canvas.removeEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		_canvas.removeEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		_canvas.removeEventListener(MouseEvent.MOUSE_UP, onMouseUp);
		_canvas.removeEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
	}
}