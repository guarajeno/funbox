package com.funbox.bcp.minigame2.entities.item;

import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

class ItemCoin extends TouchObject {
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float, speed:Vector2D) {
		super(clipName, aniData, canvas, x, y, speed);
		
		setObjectType(EnumTouchObjectType.COIN);
		
		setOffsetX(getWidth() / 2);
		setOffsetY(getHeight() / 2);
	}
	
	override public function update(dt:Int):Void {
		if (!mStaticImage) {
			if (mAnimationBitmap.getCurrentIndex() == 0 && !mCanFall) {
				mAnimationBitmap.gotoAndStop(0);
				
				mPauseAnimation = true;
			}
		}
		
		super.update(dt);
	}
	
}