package com.funbox.ania.screen;

import com.funbox.ania.component.MenuBar;
import com.minigloop.ui.Screen;
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class HomeScreen extends Screen
{
	private var _menuBar:MenuBar;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_menuBar = new MenuBar(canvas);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_menuBar.update(dt);
	}
}