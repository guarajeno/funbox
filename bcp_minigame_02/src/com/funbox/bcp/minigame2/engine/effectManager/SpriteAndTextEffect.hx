package com.funbox.bcp.minigame2.engine.effectManager;
import com.funbox.bcp.minigame2.util.NUtils;
import com.minigloop.display.AtlasSprite;
import com.minigloop.util.Vector2D;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class SpriteAndTextEffect extends BaseEffect {

	private var mBitmapOther:Bitmap;
	private var mAnimationBitmapOther:AtlasSprite;
	
	private var mOtherX:Float;
	private var mOtherY:Float;
	
	public function new(clipName:String, aniData:String, clipNameOther:String, aniDataOther:String,
		canvas:Sprite, pos1:Vector2D, pos2:Vector2D) {
		super(clipName, aniData, canvas, pos1.x, pos1.y);
		
		mOtherX = pos2.x;
		mOtherY = pos2.y;
		
		if (clipNameOther != null && aniDataOther != null) {
			mAnimationBitmapOther = new AtlasSprite(mCanvas, clipNameOther, aniDataOther);
				mAnimationBitmapOther.position.x = mX + mOtherX;
				mAnimationBitmapOther.position.y = mY + mOtherY;
		}
		else {
			mBitmapOther = NUtils.getAsset(clipNameOther);
			mBitmapOther.x = mX + mOtherX;
			mBitmapOther.y = mY + mOtherY;
			
			mCanvas.addChild(mBitmapOther);
		}
	}

	override public function update(dt:Int):Void {
		if (!mPauseAnimation) {
			if (mAnimationBitmapOther != null) {
				mAnimationBitmapOther.position.x = mX + mOtherX;
				mAnimationBitmapOther.position.y = mY + mOtherY;
				mAnimationBitmapOther.update(dt);
			}
			
			if (mBitmapOther != null) {
				mBitmapOther.x = mX + mOtherX;
				mBitmapOther.y = mY + mOtherY;
			}
		}
		
		if (mAnimationBitmapOther != null) {
			if (mAnimationBitmapOther.getCurrentIndex() == (mAnimationBitmapOther.getLength() - 1)) {
				mAnimationBitmapOther.stop();
				
				mAnimationBitmapOther.currentFrame().alpha -= 0.1;
				
				if (mAnimationBitmapOther.currentFrame().alpha <= 0) {
					mAnimationBitmapOther.currentFrame().alpha = 0;
					isDead = true;
				}
			}
		}
		
		super.update(dt);
	}
	
	override public function free():Void {
		if (mBitmapOther != null) {
			mCanvas.removeChild(mBitmapOther);
			mBitmapOther.bitmapData.dispose();
		}
		
		if (mAnimationBitmapOther != null) {
			mAnimationBitmapOther.destroy();
			mAnimationBitmapOther = null;
		}
		
		super.free();
	}
}