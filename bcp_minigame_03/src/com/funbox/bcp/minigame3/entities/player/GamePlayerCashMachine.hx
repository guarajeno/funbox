package com.funbox.bcp.minigame3.entities.player;

/**
 * ...
 * @author Cristian F. Shute
 */
class GamePlayerCashMachine {

	private var mX:Float;
	private var mY:Float;
	
	public function getX():Float 			{ return mX;  }
	public function setX(value:Float):Void 	{ mX = value; }
	
	public function getY():Float 			{ return mY;  }
	public function setY(value:Float):Void 	{ mY = value; }
	
	public function new(x:Float, y:Float) {
		mX = x;
		mY = y;
	}
	
}