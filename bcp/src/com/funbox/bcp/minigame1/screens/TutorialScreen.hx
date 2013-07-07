package com.funbox.bcp.minigame1.screens;
import com.funbox.bcp.minigame1.Global;
import com.funbox.bcp.minigame1.utils.AlphaTweener;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author 
 * 
 */

class TutorialScreen extends Screen
{
	private var _background_1:Bitmap;
	private var _background_2:Bitmap;
	private var _player:Bitmap;
	private var _alphaTweener:AlphaTweener;
	private var _alphaTweenerPlayer:AlphaTweener;
	private var _t:Float = 0;
	
	private var _counter:Int = 0;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_background_1 = AssetsLoader.getAsset("background_tutorial_1");
		_background_2 = AssetsLoader.getAsset("background_tutorial_2");
		_player = AssetsLoader.getAsset("hand_tutorial");
		
		_background_1.alpha = 0;
		_background_2.alpha = 0;
		_player.alpha = 0;
		
		canvas.addChild(_background_1);
		canvas.addChild(_background_2);
		canvas.addChild(_player);
		
		_player.x = 300;
		_player.y = 320;
		
		show1();
	}
	
	function show1() 
	{
		_alphaTweener = new AlphaTweener(_background_1, 0.01, show2);
		_alphaTweenerPlayer = new AlphaTweener(_player, 0.01, null);
	}
	
	function show2() 
	{
		_player.alpha = 0;
		_alphaTweener = new AlphaTweener(_background_2, 0.005, show3);
	}
	
	function show3() 
	{
		ScreenManager.instance.gotoScreen(GameScreen);
	}
	
	override public function update(dt):Void 
	{
		_alphaTweener.update(dt);
		_alphaTweenerPlayer.update(dt);
		
		_t += 0.06;
		_player.x = 300 + 50 * Math.sin(_t);
	}
}