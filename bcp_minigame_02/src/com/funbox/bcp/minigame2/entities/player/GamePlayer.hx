package com.funbox.bcp.minigame2.entities.player;

import com.funbox.bcp.minigame2.entities.BaseActor;
import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.screens.GameScreen;
import nme.display.Sprite;
import nme.ui.Mouse;

class GamePlayer extends BaseActor {

	public function new(clipName:String, aniData:String, canvas:Sprite, offsetX:Float, offsetY:Float) {
		super(clipName, aniData, canvas, Global.StageWidth / 2, Global.StageHeight / 2);
		
		mOffsetX = offsetX;
		mOffsetY = offsetY;
		
		mAnimationBitmap.setScaleX(1.1);
		mAnimationBitmap.setScaleY(1.1);
		mAnimationBitmap.gotoAndStop(0);
		
		Mouse.hide();
	}
	
	override public function update(dt:Int):Void {
		if (GameScreen.instance != null) {
			if (!GameScreen.instance.isPauseGame()) {
				mX = Global.minigame.getMouseX();
				mY = Global.minigame.getMouseY();
				
				if (Global.minigame.isMousePressed() && mAnimationBitmap.getCurrentIndex() == 0) {
					mAnimationBitmap.gotoAndPlay(0);
				}
				
				if (mAnimationBitmap.getCurrentIndex() == (mAnimationBitmap.getLength() - 1)) {
					mAnimationBitmap.gotoAndStop(0);
				}
			}
		}
		super.update(dt);
	}
	
	override public function free():Void {
		Mouse.show();
		
		super.free();
	}
	
}