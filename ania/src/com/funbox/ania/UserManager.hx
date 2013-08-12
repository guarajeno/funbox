package com.funbox.ania;

/**
 * ...
 * @author 
 */

@:expose("UserManager")
class UserManager
{
	static public var r:Int;
	
	static public function sendScore(score:Int) 
	{
		trace("SCORE RECIEVED: " + score);
	}
}