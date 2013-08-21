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
	public var visible:Bool = true;
	public var index:Int;
	
	private var _callback:Dynamic;
	private var _button:Button;
	
	public var onMouseOver:Dynamic;
	public var onMouseOut:Dynamic;
	
	public function new(canvas:Sprite, upId:String, overId:String, downId:String, _callback:Dynamic) 
	{
		super(canvas);
		
		//_over = over;
		addState("up", upId, null);
		addState("over", overId, null);
		addState("down", downId, null);
		
		this._callback = _callback;
		
		setState("up");
		
		collision.addEventListener(MouseEvent.MOUSE_MOVE, _onMouseMove);
		collision.addEventListener(MouseEvent.MOUSE_DOWN, _onMouseDown);
		collision.addEventListener(MouseEvent.MOUSE_UP, _onMouseUp);
		collision.addEventListener(MouseEvent.MOUSE_OUT, _onMouseOut);
		collision.addEventListener(MouseEvent.MOUSE_OVER, _onMouseOver);
		
		
		collision.useHandCursor = true;
	}
	
	private function _onMouseMove(e:MouseEvent):Void 
	{
		if (state != "down") setState("over");
	}
	
	private function _onMouseDown(e:MouseEvent):Void 
	{
		setState("down");
	}
	
	private function _onMouseOver(e:MouseEvent):Void 
	{
		if (onMouseOver != null)
		{
			onMouseOver();
		}
		//if (_over)
		//{
			//skin.scaleX = 1;
			//skin.scaleY = 1;
		//}
	}
	
	private function _onMouseUp(e:MouseEvent):Void 
	{
		setState("up");
		if (_callback != null)
		{
			_callback(this);
		}
	}
	
	private function _onMouseOut(e:MouseEvent):Void 
	{	
		//if (_over)
		//{
			//skin.scaleX = 0.9;
			//skin.scaleY = 0.9;
		//}
		
		this.skin.filters = 
		if (onMouseOut != null)
		{
			onMouseOut();
		}
		
		setState("up");
	}
	
	override public function destroy():Void 
	{
		super.destroy();
		
		_canvas.removeEventListener(MouseEvent.MOUSE_MOVE, _onMouseMove);
		_canvas.removeEventListener(MouseEvent.MOUSE_DOWN, _onMouseDown);
		_canvas.removeEventListener(MouseEvent.MOUSE_UP, _onMouseUp);
		_canvas.removeEventListener(MouseEvent.MOUSE_OUT, _onMouseOut);
		_canvas.removeEventListener(MouseEvent.MOUSE_OVER, _onMouseOver);
	}
	
	override public function update(dt:Int):Void 
	{
		super.update(dt);
		
		skin.visible = visible;
	}
}