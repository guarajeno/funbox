package com.funbox.bcp.minigame2.entities.item;

import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

class ItemMoney extends TouchObject {
	
	private var mAcceleration:Float;
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float, speed:Vector2D) {
		super(clipName, aniData, canvas, x, y, speed);
		
		setObjectType(EnumTouchObjectType.MONEY);
		
		setOffsetX(getWidth() / 2);
		setOffsetY(getHeight() / 2);
		
		mAcceleration = 0;
	}
	
	override public function update(dt:Int):Void {
		if (!mStaticImage) {
			if (mAnimationBitmap.getCurrentIndex() == 12 && !mCanFall) {
				mAnimationBitmap.gotoAndStop(12);
				mPauseAnimation = true;
			}
		}
		
		if (mCanFall) {
			mX += Math.cos(mAcceleration) * 2;
			mAcceleration += 0.003 * dt;
		}
		
		super.update(dt);
	}
}