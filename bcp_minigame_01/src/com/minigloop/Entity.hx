package com.minigloop;
import nme.display.DisplayObject;
import nme.display.Sprite;
import Type;

/**
 * ...
 * @author Jerson La Torre
 */

class Entity 
{
	private var _canvas:Sprite;
	private var _skin:Sprite;
	private var _state:String;
	
	private var _animations:Dynamic;
	
	public var x:Float;
	public var y:Float;
	public var dX:Float;
	public var dY:Float;
	public var rotation:Float = 0;
	public var scaleX:Float = 1;
	public var scaleY:Float = 1;
	
	public function new(canvas:Sprite) 
	{
		_canvas = canvas;
		_skin = new Sprite();
		_canvas.addChild(_skin);
		_animations = {};
		

		//var swf:SWF = new SWF(Assets.getBytes("assets/swf/assets.swf"));
		//var mc = swf.createMovieClip("Player_Stand");
		//_skin.addChild(mc);

		x = 0;
		y = 0;
		dX = 0;
		dY = 0;
	}
	
	public function update(dt:Int)
	{
		_skin.x = x;
		_skin.y = y;
		_skin.rotation = rotation;
		_skin.scaleX = scaleX;
		_skin.scaleY = scaleY;
	}
	
	public function addState(name:String, animation:Dynamic)
	{
		//untyped
		//{
			Reflect.setProperty(_animations, name, animation);
		//}
	}
	
	public function setState(state:String)
	{
		if (_state == state) return;
		if (_skin.numChildren > 0) 
		{
			var child = _skin.getChildAt(0);
			
			//if (Type.enumEq(Type.typeof(child), ValueType.TClass(SingleSprite)))
			//{
				//cast(child, SingleSprite).destroy();
			//}
			
			if (Type.enumEq(Type.typeof(child), ValueType.TClass(AnimatedSprite)))
			{
				cast(child, AnimatedSprite).stop();
			}
			
			
			_skin.removeChildAt(0);
			child = null;
		}
		
		_skin.addChild(Reflect.getProperty(_animations, state));

		var child = _skin.getChildAt(0);
			
		//if (Type.enumEq(Type.typeof(child), ValueType.TClass(SingleSprite)))
		//{
			//cast(child, SingleSprite).destroy();
		//}
		
		if (Type.enumEq(Type.typeof(child), ValueType.TClass(AnimatedSprite)))
		{
			cast(child, AnimatedSprite).play();
		}
		
		_state = state;
		//trace(_state);
	}
}