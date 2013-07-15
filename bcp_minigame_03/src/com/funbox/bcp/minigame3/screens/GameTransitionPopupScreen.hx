package com.funbox.bcp.minigame3.screens;
import com.funbox.bcp.minigame3.util.NUtils;
import com.funbox.bcp.minigame3.util.ScaleTweener;
import com.minigloop.util.SoundManager;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class GameTransitionPopupScreen
{
	
	private var _img_1:Bitmap;
	private var _img_2:Bitmap;
	private var _img_3:Bitmap;
	private var _start:Bitmap;
	
	private var mCanvas:Sprite;
	
	private var _state:String;
	
	private var _scaleTweener:ScaleTweener;
	
	private var mOnCallbackFunction:Dynamic;

	public function new(canvas:Sprite, onCallbackFunction:Dynamic) {
		mCanvas = canvas;
		mOnCallbackFunction = onCallbackFunction;
		
		_img_1 = NUtils.getAsset("spMinigame03_gui_text_03");
		_img_2 = NUtils.getAsset("spMinigame03_gui_text_02");
		_img_3 = NUtils.getAsset("spMinigame03_gui_text_01");
		_start = NUtils.getAsset("spMinigame03_gui_text_start");
		
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
		
		mCanvas.addChild(_img_1);
		mCanvas.addChild(_img_2);
		mCanvas.addChild(_img_3);
		mCanvas.addChild(_start);
		
		_state = "tweening";
		
		_scaleTweener = new ScaleTweener(_img_1, tween2);
		_scaleTweener._factor = 0.1;
	}
	
	private function tween2():Void
	{
		_scaleTweener = new ScaleTweener(_img_2, tween3);
		_scaleTweener._factor = 0.1;
	}
	
	private function tween3():Void
	{
		_scaleTweener = new ScaleTweener(_img_3, tweenStart);
		_scaleTweener._factor = 0.1;
	}
	
	private function tweenStart():Void
	{
		_scaleTweener = new ScaleTweener(_start, endTweens);
		_scaleTweener._factor = 0.1;
	}
	
	private function endTweens():Void
	{
		_state = "init_game";
	}
	
	public function update(dt:Int):Void {
		switch (_state){
		case "tweening":
			_scaleTweener.update(dt);
		case "init_game":
			if (mOnCallbackFunction != null) {
				mOnCallbackFunction();
				mOnCallbackFunction = null;
			}
			_state = "";
		}
	}
	
	public function free():Void {
		_scaleTweener = null;
		
		mCanvas.removeChild(_img_1);
		mCanvas.removeChild(_img_2);
		mCanvas.removeChild(_img_3);
		mCanvas.removeChild(_start);
		
		_img_1 = null;
		_img_2 = null;
		_img_3 = null;
		_start = null;
		
		mCanvas = null;
	}
	
}