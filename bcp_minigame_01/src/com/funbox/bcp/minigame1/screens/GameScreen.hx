package com.funbox.bcp.minigame1.screens;
import com.funbox.bcp.minigame1.MiniGame1;
import com.funbox.bcp.minigame1.utils.ScaleTweener;
import com.minigloop.ui.Screen;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */
class GameScreen extends Screen
{
	private var _img_1:Bitmap;
	private var _img_2:Bitmap;
	private var _img_3:Bitmap;
	private var _start:Bitmap;
	
	//private var _t:Float = 0.5;
	//private var _factor:Float;
	
	private var _game:MiniGame1;
	private var _state:String;
	
	private var _scaleTweener:ScaleTweener;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		var val:Int = 20;
		
		trace("GAME SCREEN");
		_img_1 = AssetsLoader.getAsset("text_1");
		_img_2 = AssetsLoader.getAsset("text_2");
		_img_3 = AssetsLoader.getAsset("text_3");
		_start = AssetsLoader.getAsset("text_start");
		
		_game = new MiniGame1(canvas);
		_game.update(0);
		_game.setPause(true);
		
		_img_1.x = 310;
		_img_1.y = 220;
		_img_1.scaleX = 0;
		
		_img_2.x = 310;
		_img_2.y = 220;
		_img_2.scaleX = 0;
		
		_img_3.x = 310;
		_img_3.y = 220;
		_img_3.scaleX = 0;
		
		_start.x = 180;
		_start.y = 220;
		_start.scaleX = 0;
		
		canvas.addChild(_img_1);
		canvas.addChild(_img_2);
		canvas.addChild(_img_3);
		canvas.addChild(_start);
		
		_state = "tweening";
		
		_scaleTweener = new ScaleTweener(_img_1, tween2);
	}
	
	private function tween2():Void
	{
		_scaleTweener = new ScaleTweener(_img_2, tween3);
	}
	
	private function tween3():Void
	{
		_scaleTweener = new ScaleTweener(_img_3, tweenStart);
	}
	
	private function tweenStart():Void
	{
		_scaleTweener = new ScaleTweener(_start, endTweens);
	}
	
	private function endTweens():Void
	{
		_state = "init_game";
	}
	
	override public function update(dt:Int):Dynamic 
	{
		switch (_state)
		{
			case "tweening":
			{
				_scaleTweener.update(dt);
			}
			
			case "init_game":
			{
				SoundManager.play("bgm_1", true);
				_game.setPause(false);
				_state = "";
			}
		}
		
		_game.update(dt);
	}
}