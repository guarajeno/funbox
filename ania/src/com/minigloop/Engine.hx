package com.minigloop;

import com.funbox.ania.Global;
import com.minigloop.input.Mouse;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.Stats;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.BlendMode;
import nme.display.Sprite;
import nme.display.Stage;
import nme.events.Event;
import nme.Lib;

/**
 * ...
 * @author Jerson La Torre
 */

class Engine
{
	private var _now:Int;
	private var _last:Int;
	private var _dt:Int;
	
	private var _bufferCanvas:Sprite;
	private var _statsCanvas:Sprite;
	private var _stage:Stage;
	private var _gameClass:Class<Screen>;

	public function new(stage:Stage, gameClass:Class<Screen>) 
	{
		_stage = stage;
		_gameClass = gameClass;
		init();
	}
	
	public function init()
	{
		_last = _now = Lib.getTimer();
		_stage = Lib.current.stage;
		
		_bufferCanvas = new Sprite();
		_statsCanvas = new Sprite();
		
		_stage.addChild(_bufferCanvas);
		_stage.addChild(_statsCanvas);
		
		Global.stage = _stage;
		
		//_statsCanvas.addChild(new Stats(false, true));
		
		Mouse.init(_stage);
		
		ScreenManager.init(_bufferCanvas);
		ScreenManager.gotoScreen(_gameClass);
		
		_stage.addEventListener(Event.ENTER_FRAME, loop);
	}
	
	public function loop(e:Event)
	{
		_now = Lib.getTimer();
		_dt = _now - _last;
		_last = _now;
		
		update(_dt);
	}
	
	public function update(dt:Int)
	{
		ScreenManager.update(dt);
	}
}