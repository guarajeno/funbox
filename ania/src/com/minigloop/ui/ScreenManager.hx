package com.minigloop.ui;
import com.eclecticdesignstudio.motion.Actuate;
import nme.display.Sprite;

/**
 * ...
 * @author Jerson La Torre
 */

class ScreenManager 
{
	private static var _currentScreen:Screen;
	private static var _currentPopup:Screen;
	private static var _canvas:Sprite;
	static private var _screenClass:Class<Screen>;
	
	public function new()
	{
	}
	
	static public function init(canvas:Sprite)
	{
		_canvas = canvas;
		_currentScreen = null;
	}
	
	static public function gotoScreen(screenClass:Class<Screen>)
	{
		if (_currentScreen != null)
		{
			_currentScreen.end();
		}
		
		_screenClass = screenClass;
		
		//Actuate.timer(1).onComplete(createScreen);
		createScreen();
	}
	
	static private function createScreen() 
	{
		if (_currentScreen != null)
		{
			_currentScreen.destroy();
		}
		
		_currentScreen = Type.createInstance(_screenClass, [_canvas]);
	}
	
	static public function showPopup(popupClass)
	{
		closePopup();
		_currentPopup = Type.createInstance(popupClass, [_canvas]);
	}
	
	static public function closePopup()
	{
		if (_currentPopup != null)
		{
			_currentPopup.destroy();
			_currentPopup = null;
		}
	}
	
	static public function update(dt:Int)
	{
		if (_currentScreen != null)
		{
			_currentScreen.update(dt);
		}
	}
}