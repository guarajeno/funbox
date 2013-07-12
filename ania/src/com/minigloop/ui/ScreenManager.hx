package com.minigloop.ui;
import nme.display.Sprite;

/**
 * ...
 * @author Jerson La Torre
 */

class ScreenManager 
{
	public static var instance(getInstance, null):ScreenManager;
	private static var _currentScreen:Screen;
	private static var _canvas:Sprite;
	
	public function new()
	{
	}
	
	public function init(canvas:Sprite)
	{
		_canvas = canvas;
		_currentScreen = null;
	}
	
	public function gotoScreen(screenClass)
	{
		if (_currentScreen != null)
		{
			_currentScreen.destroy();
		}
		
		_currentScreen = Type.createInstance(screenClass, [_canvas]);
	}
	
	public function update(dt:Int)
	{
		if (_currentScreen != null)
		{
			_currentScreen.update(dt);
		}
	}
	
	private static function getInstance():ScreenManager 
	{
		if (instance == null)
		{
			instance = new ScreenManager();
		}
		
		return instance;
	}
}