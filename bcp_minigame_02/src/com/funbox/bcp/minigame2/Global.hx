package com.funbox.bcp.minigame2;
import nme.display.Stage;

/**
 * ...
 * @author 
 */
class Global
{
	static public var minPlayerSpeed = 10;
	static public var maxPlayerSpeed = 15;
	static public var enemyFrequency = 1000;
	
	static public var ScreenOffsetWidth = 50;
	static public var ScreenOffsetHeight = 15;
	
	static public var minigame:MiniGame2 = null;
	static public var stage:Stage = null;
	
	static public var StageWidth:Int = 0;
	static public var StageHeight:Int = 0;
	
	static public var totalPoints:Int = 0;

	public function new() {
		
	}
}