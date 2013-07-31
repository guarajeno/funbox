package com.funbox.bcp.minigame1.screens;
import com.funbox.bcp.minigame1.Global;
import com.funbox.bcp.minigame1.utils.AlphaTweener;
import com.funbox.bcp.minigame1.utils.AlphaTweener2;
import com.funbox.bcp.minigame1.utils.AlphaTweener3;
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
	private var _continue:Bitmap;
	private var _alphaTweener:AlphaTweener2;
	private var _alphaTweenerPlayer:AlphaTweener2;
	private var _t:Float = 0;
	private var _hotspot:Sprite;
	
	private var _counter:Int = 0;
	private var _alphaTweenerContinue:AlphaTweener3;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_background_1 = AssetsLoader.getAsset("background_tutorial_1");
		_background_2 = AssetsLoader.getAsset("background_tutorial_2");
		_player = AssetsLoader.getAsset("hand_tutorial");
		_continue = AssetsLoader.getAsset("gui_text_tutorial_generic");
		
		_background_1.alpha = 0;
		_background_2.alpha = 0;
		_player.alpha = 0;
		
		canvas.addChild(_background_1);
		canvas.addChild(_background_2);
		canvas.addChild(_player);
		canvas.addChild(_continue);
		
		_continue.x = 220;
		_continue.y = 405;
		
		_player.x = 300;
		_player.y = 320;
		
		_hotspot = new Sprite();
		_hotspot.graphics.beginFill(0xFF0000, 0.1);
		_hotspot.graphics.drawRect(0, 0, 640, 480);
		_hotspot.addEventListener(MouseEvent.CLICK, onClick);
		canvas.addChild(_hotspot);
		
		_alphaTweener = new AlphaTweener2(_background_1, 0.02, null);
		_alphaTweenerPlayer = new AlphaTweener2(_player, 0.02, null);
		_alphaTweenerContinue = new AlphaTweener3(_continue, 0.03, null);
	}

	function onClick(e:MouseEvent) 
	{
		trace("hotspot click");
		_canvas.removeEventListener(MouseEvent.CLICK, onClick);
		ScreenManager.instance.gotoScreen(GameScreen);
	}
	
	override public function update(dt):Void 
	{
		_alphaTweener.update(dt);
		_alphaTweenerPlayer.update(dt);
		_alphaTweenerContinue.update(dt);
		
		_t += 0.06;
		_player.x = 300 + 50 * Math.sin(_t);
	}
}