package com.minigloop.ui;
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
	
	public function new()
	{
	}
	
	static public function init(canvas:Sprite)
	{
		_canvas = canvas;
		_currentScreen = null;
	}
	
	static public function gotoScreen(screenClass)
	{
		if (_currentScreen != null)
		{
			_currentScreen.destroy();
		}
		
		_currentScreen = Type.createInstance(screenClass, [_canvas]);
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