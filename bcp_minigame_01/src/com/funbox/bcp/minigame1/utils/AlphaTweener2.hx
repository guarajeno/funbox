package com.funbox.bcp.minigame1.utils;
import nme.display.Bitmap;

/**
 * ...
 * @author 
 */

class AlphaTweener2
{
	private var _obj:Bitmap;
	private var _callback:Dynamic;
	
	private var _t:Float = 0;
	private var _dt:Float;
	private var _value:Float = 0;
	
	private var _isPaused:Bool;
	
	public function new(bitmap:Bitmap, _dt:Float, __callback:Dynamic) 
	{
		_obj = bitmap;
		_callback = __callback;
		this._dt = _dt;
		
		_t = 0;
		_value = 0;
		_isPaused = false;
		
		update(0);
	}
	
	public function update(dt):Void
	{
		if (_isPaused) return;
		
		_obj.alpha = _value;
		
		_value = Math.sin(_t);
		_t += _dt;
		
		if (_t >= 1.7)
		{
			_obj.alpha = 1;
			_isPaused = true;
			if (_callback != null) _callback();
		}
	}
}