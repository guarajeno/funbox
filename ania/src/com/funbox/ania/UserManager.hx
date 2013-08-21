package com.funbox.ania;
import com.funbox.ania.screen.HomeScreen;
import com.minigloop.ui.ScreenManager;

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
	
	static public function onLoginOk(data:Dynamic) 
	{
		if (data == null)
		{
			trace("ON LOGIN OK NULL");
			return;
		}
		
		Global.isUserLoged = true;
		
		trace("USER RECIEVED: " + data);
		if (ScreenManager.currentScreen != null)
		{
			cast(ScreenManager.currentScreen, HomeScreen).logged(data);
		}
	}
}