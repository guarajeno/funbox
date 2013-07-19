package com.funbox.bcp.minigame4.util;
import nme.display.Bitmap;

/**
 * ...
 * @author 
 */

class ScaleTweener
{
	private var _obj:Bitmap;
	private var _callback:Dynamic;
	
	private var _t:Float = 0;
	private var _value:Float = 0;
	
	public var _factor:Float = 0.025;
	
	private var _isPaused:Bool;
	
	private var mTimeCounter:Int;
	private var mTimeLimitByFrame:Float;
	
	public function new(bitmap:Bitmap, __callback:Dynamic) 
	{
		_obj = bitmap;
		_callback = __callback;
		
		_t = 0;
		_value = 0;
		_isPaused = false;
		
		mTimeCounter = 0;
		mTimeLimitByFrame = Math.round(1000 / 30); // because needs to run in 30 fps
		
		update(0);
	}
	
	public function update(dt):Void
	{
		if (_isPaused) return;
		
		_obj.scaleX = _value;
		_obj.scaleY = _value;
		
		_value = Math.sin(_t);
		
		if ((mTimeCounter + dt) >= mTimeLimitByFrame) {
			mTimeCounter = 0;
			_t += _factor;
		}
		else { mTimeCounter += dt; }

		if (_t == 1) _t = 0.99;
		
		if (_t >= 3)
		{
			_obj.scaleX = 0;
			_isPaused = true;
			_callback();
		}
	}
}