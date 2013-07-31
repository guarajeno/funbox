package com.minigloop.ui;
import com.funbox.ania.Global;
import nme.display.Sprite;

/**
 * ...
 * @author Jerson La Torre
 */

class Screen 
{
	private var _canvas:Sprite;
	
	public function new(canvas:Sprite) 
	{
		_canvas = canvas;
	}
	
	public function update(dt:Int)
	{
		_canvas.x = Global.stage.fullScreenWidth / 2 - 800;
	}
	
	public function end()
	{
		
	}
	
	public function destroy()
	{
		
	}
}