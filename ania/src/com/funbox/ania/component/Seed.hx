package com.funbox.ania.component;
import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Sine;
import com.funbox.ania.Global;
import com.minigloop.display.Button;
import com.minigloop.display.SpriteEntity;
import com.minigloop.display.VisualObject;
import com.minigloop.util.AssetsLoader;
import haxe.Timer;
import nme.display.Bitmap;
import nme.display.MovieClip;
import nme.display.Sprite;
import nme.events.MouseEvent;

/**
 * ...
 * @author 
 */

class Seed extends SpriteEntity
{
	private var _timer:Timer;
	private var _isActive:Bool;
	
	public function new(canvas:Sprite, x:Int, y:Int) 
	{
		super(canvas);
		addState("stand", "web_home_seed", null);
		setState("stand");
		
		_timer = new Timer(60);
		_timer.run = move;
		
		this.position.x = x;
		this.position.y = y;
		
		_isActive = true;
	}
	
	private function move() 
	{	
		position.y += 0.2 * 30;
		
		if (position.y >= 620)
		{
			Actuate.tween(skin, 0.5, { alpha: 0 } ).onComplete(destroy);
			_isActive = false;
			_timer.stop();
		}
		
		super.update(30);
	}
	
	override public function update(dt:Int):Void 
	{
		if (!_isActive) return;
	}
	
	override public function destroy():Void 
	{
		super.destroy();
	}
}