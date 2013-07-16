package com.minigloop;
import nme.display.Sprite;

/**
 * ...
 * @author Jerson La Torre
 */

class Game 
{

	private var _isPaused:Bool;
	private var _canvas:Sprite;
	
	public function new(canvas:Sprite) 
	{
		_canvas = canvas;
		_isPaused = false;
	}
	
	public function update(dt:Int)
	{
		
	}
	
	public function setPause(val:Bool)
	{
		_isPaused = val;
	}
	
	public function destroy()
	{
		
	}
	
}