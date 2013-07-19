package com.funbox.bcp.minigame4.entities;

import com.funbox.bcp.minigame4.util.NCharacter;
import com.funbox.bcp.minigame4.util.NUtils;
import com.minigloop.display.AtlasSprite;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class BaseActor {

	private var mX:Float;
	private var mY:Float; 
	private var mOffsetX:Float; 
	private var mOffsetY:Float; 
	
	private var mFlipOffsetX:Float; 
	
	private var mWidth:Float;
	private var mHeight:Float;
	
	private var mAlpha:Float;
	
	private var mCanvas:Sprite;
	private var mBitmap:Bitmap;
	private var mCharacter:NCharacter;
	
	private var mFlip:Bool;
	private var mStaticImage:Bool;
	private var mPauseAnimation:Bool;
	
	public function getBitmap():Bitmap 			{ return mBitmap; }
	
	public function getWidth():Float 			{ return mWidth; }
	public function getHeight():Float 			{ return mHeight; }
	
	public function getX():Float 			{ return mX;  }
	public function setX(value:Float):Void 	{ mX = value; }
	
	public function getY():Float 			{ return mY;  }
	public function setY(value:Float):Void 	{ mY = value; }
	
	public function getAlpha():Float 			{ return mAlpha;  }
	public function setAlpha(value:Float):Void 	{ 
		mAlpha = value;
		
		if (mStaticImage) {
			mBitmap.alpha = mAlpha;
		}
		else {
			mCharacter.setAlpha(mAlpha);
		}
	}
	
	public function getOffsetX():Float 				{ return mOffsetX; }
	public function setOffsetX(value:Float):Void 	{ mOffsetX = value; }
	
	public function getOffsetY():Float 				{ return mOffsetY; }
	public function setOffsetY(value:Float):Void 	{ mOffsetY = value; }
	
	public function getFlip():Bool 					{ return mFlip; }
	public function getCharacter():NCharacter 		{ return mCharacter; }
	
	public function setFlip(value:Bool):Void 	{ 
		mFlip = value; 
		
		if (mStaticImage) {
			mBitmap.scaleX = mFlip ? -1 : 1;
		}
		else {
			mCharacter.setScaleX(mFlip ? -1 : 1);
		}
		
		mFlipOffsetX = mFlip ? mWidth : 0;
	}

	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float) {
		mX = x;
		mY = y;
		mCanvas = canvas;
		
		mOffsetX = 0;
		mOffsetY = 0;
		mFlipOffsetX = 0;
		mWidth = 0;
		mHeight = 0;
		mAlpha = 1;
		
		mFlip = false;
		mStaticImage = true;
		mPauseAnimation = false;
		
		if (clipName != null && aniData == null) {
			mStaticImage = true;
			
			mBitmap = NUtils.getAsset(clipName);

			mBitmap.x = mX + mOffsetX + mFlipOffsetX;
			mBitmap.y = mY + mOffsetY;
			
			mWidth = mBitmap.width;
			mHeight = mBitmap.height;
			
			mCanvas.addChild(mBitmap);
		}
		else {
			mStaticImage = false;
			
			mCharacter = new NCharacter(mCanvas);
			mCharacter.setX(mX + mOffsetX + mFlipOffsetX);
			mCharacter.setY(mY + mOffsetY);
			
			mCharacter.addState(clipName, clipName, aniData);
			mCharacter.gotoState(clipName);
			
			mWidth = mCharacter.getWidth();
			mHeight = mCharacter.getHeight();
		}
		
		setAlpha(1.0);
	}
	
	public function hitTest(actor:BaseActor):Bool {
        var secondOBjX:Float = actor.getX();
        var secondOBjY:Float = actor.getY();

        if ((mX + mWidth) >= secondOBjX && (secondOBjX + actor.getWidth()) >= mX &&
            (mY + mHeight) >= secondOBjY && (secondOBjY + actor.getHeight()) >= mY) { 
            return true; 
        }
        return false;
	}
	
	public function hitTestPoint(x:Int, y:Int):Bool {
        if (x > mX && x < (mX + mWidth) && y > mY && y < (mY + mHeight)) { 
            return true; 
        }
        return false;
	}
	
	public function update(dt:Int):Void {
		if (mStaticImage) {
			mBitmap.x = mX + mOffsetX + mFlipOffsetX;
			mBitmap.y = mY + mOffsetY;
		}
		else {
			mCharacter.setX(mX + mOffsetX + mFlipOffsetX);
			mCharacter.setY(mY + mOffsetY);
			
			if (!mPauseAnimation) {
				mCharacter.update(dt);
			}
		}
	}
	
	public function free():Void {
		if (mStaticImage) {
			mCanvas.removeChild(mBitmap);
			mBitmap.bitmapData.dispose();
		}
		else {
			mCharacter.free();
			mCharacter = null;
		}
		
		mBitmap = null;
		mCanvas = null;
	}
	
}