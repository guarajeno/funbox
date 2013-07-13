package com.funbox.bcp.minigame2.engine.effectManager;
import com.funbox.bcp.minigame2.entities.BaseActor;
import nme.display.BlendMode;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class BaseEffect extends BaseActor {

	public var isDead:Bool;
	
	private var mDelayToStart:Int;
	private var mDieWithAlpha:Bool;
	private var mAniEndStartAlpha:Bool;
	
	private var mAlphaFactor:Float;
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float) {
		super(clipName, aniData, canvas, x, y);
		
		isDead = false;
		mDelayToStart = 0;
		mAlphaFactor = 0.06;
		mDieWithAlpha = false;
		mAniEndStartAlpha = false;
	}
	
	public function DieWithAlpha(value:Bool):Void {
		mDieWithAlpha = value;
	}
	
	public function SetDelayTimeToStart(time:Int):Void {
		mDelayToStart = time;
		mPauseAnimation = true;
	}
	
	override public function update(dt:Int):Void {
		if (mDelayToStart < 0) {
			mDelayToStart = 0;
			mPauseAnimation = false;
		}
		
		if (mAniEndStartAlpha) {
			if (mAnimationBitmap != null) {
				mAnimationBitmap.setAlpha(mAnimationBitmap.getAlpha() - mAlphaFactor);
						
				if (mAnimationBitmap.getAlpha() <= 0) {
					mAnimationBitmap.setAlpha(0);
					isDead = true;
				}
			}
			
			if (mBitmap != null) {
				mBitmap.alpha -= mAlphaFactor;
						
				if (mBitmap.alpha <= 0) {
					mBitmap.alpha = 0;
					isDead = true;
				}
			}
		}
		
		if (!mDieWithAlpha) {
			if (!mStaticImage) {
				if (mAnimationBitmap.getCurrentIndex() == (mAnimationBitmap.getLength() - 1)) {
					isDead = true;
				}
			}
		}
		else {
			if (!mStaticImage) {
				if (mAnimationBitmap.getCurrentIndex() == (mAnimationBitmap.getLength() - 1)) {
					mAnimationBitmap.stop();
					mAniEndStartAlpha = true;
				}
			}
			else {
				if (mBitmap != null) {
					mAniEndStartAlpha = true;
				}
			}
		}
		
		if (!isDead) {
			super.update(dt);
		}
	}
	
}