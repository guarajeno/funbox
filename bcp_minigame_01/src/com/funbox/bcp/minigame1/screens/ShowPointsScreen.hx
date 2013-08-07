package com.funbox.bcp.minigame1.screens;
import com.funbox.bcp.minigame1.Global;
import com.funbox.bcp.minigame1.utils.ScaleTweener;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.SoundManager;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class ShowPointsScreen extends Screen
{
	private var _score_500:Bitmap;
	private var _score_1000:Bitmap;
	private var _lives:Int;
	
	private var _scaleTweener:ScaleTweener;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		_lives = Global.totalLives;
		_score_500 = AssetsLoader.getAsset("score_500");
		_score_1000 = AssetsLoader.getAsset("score_1000");
		
		_score_500.x = 300;
		_score_500.y = 220;
		
		_score_1000.x = 300;
		_score_1000.y = 220;
		
		_score_500.scaleX = 0;
		_score_1000.scaleX = 0;
		
		_canvas.addChild(_score_1000);
		_canvas.addChild(_score_500);
		
		show_1000();
	}
	
	private function show_1000():Void
	{
		SoundManager.play("points");
		_scaleTweener = new ScaleTweener(_score_1000, onShow_End);
	}
	
	private function onShow_End():Void
	{
		if (_lives > 0)
		{
			show_500();
		}
		else
		{
			ScreenManager.instance.gotoScreen(ScoreCardScreen);
		}
	}
	
	private function show_500():Void
	{
		SoundManager.play("points");
		_lives--;
		_scaleTweener = new ScaleTweener(_score_500, onShow_End);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		if (_scaleTweener != null) _scaleTweener.update(dt);
	}
}