package ;

import com.funbox.ania.screen.ActivitiesScreen;
import com.funbox.ania.screen.HomeScreen;
import com.funbox.ania.UserManager;
import com.funbox.ania.UserManager;
import com.funbox.ania.UserManager;
import com.minigloop.Engine;
import nme.display.Sprite;
import nme.events.Event;
import nme.Lib;

/**
 * ...
 * @author 
 */

class Main extends Sprite 
{
	var inited:Bool;

	function resize(e) 
	{
		if (!inited) init();
	}
	
	function init() 
	{
		if (inited) return;
		inited = true;
		
		js.Lib.eval("hideVideos();");
		UserManager.sendScore(10);
		UserManager.onLoginOk(null);
		//UserManager.showUser('usuario hola');
		
		new Engine(stage, HomeScreen);
	}

	public function new() 
	{
		super();	
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	function added(e) 
	{
		removeEventListener(Event.ADDED_TO_STAGE, added);
		stage.addEventListener(Event.RESIZE, resize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}
	
	public static function main() 
	{
		Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		Lib.current.addChild(new Main());
	}
}
