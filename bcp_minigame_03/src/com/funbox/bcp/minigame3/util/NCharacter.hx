package com.funbox.bcp.minigame3.util;
import com.minigloop.display.AtlasSprite;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class NCharacter {
	
	private var mX:Float;
	private var mY:Float; 
	private var mWidth:Float;
	private var mHeight:Float;
	private var mScaleX:Float;
	private var mScaleY:Float;
	
	private var mAlpha:Float;
	
	private var mFlip:Bool;

	private var mCanvas:Sprite;
	private var mAnimationCanvas:Sprite;
	
	private var mDictionary:Hash<AtlasSprite>;
	
	private var mCurrentState:String;
	private var mCurrentAnimation:AtlasSprite;
	
	private var mCallbackFunction:Dynamic;
	
	public function currentState():String 			{ return mCurrentState; }
	public function currentAnimation():AtlasSprite 	{ return mCurrentAnimation; }
	
	public function getScaleX():Float { return mScaleX; }
	public function getScaleY():Float { return mScaleY; }

	public function setScaleX(value:Float):Void { 
		mScaleX = value;
		
		var iterator:Iterator<AtlasSprite> = mDictionary.iterator();
		
		while (iterator.hasNext()) {
			var atlasSprite:AtlasSprite = iterator.next();
			atlasSprite.setScaleX(mScaleX);
		}
	}
	
	public function setScaleY(value:Float):Void { 
		mScaleY = value;
		
		var iterator:Iterator<AtlasSprite> = mDictionary.iterator();
		
		while (iterator.hasNext()) {
			var atlasSprite:AtlasSprite = iterator.next();
			atlasSprite.setScaleY(mScaleY);
		}
	}

	public function getX():Float 			{ return mX;  }
	public function setX(value:Float):Void 	{ mX = value; }
	
	public function getY():Float 			{ return mY;  }
	public function setY(value:Float):Void 	{ mY = value; }
	
	public function getWidth():Float 			{ return mWidth; }
	public function getHeight():Float 			{ return mHeight; }
	
	public function getAlpha():Float 			{ return mAlpha;  }
	public function setAlpha(value:Float):Void 	{ 
		mAlpha = value;
		
		var iterator:Iterator<AtlasSprite> = mDictionary.iterator();
		
		while (iterator.hasNext()) {
			var atlasSprite:AtlasSprite = iterator.next();
			atlasSprite.setAlpha(mAlpha);
		}
	}
	
	public function setFlip(value:Bool):Void 	{ 
		mFlip = value; 
		
		var iterator:Iterator<AtlasSprite> = mDictionary.iterator();
		
		while (iterator.hasNext()) {
			var atlasSprite:AtlasSprite = iterator.next();
			atlasSprite.setScaleX(mFlip ? -1 : 1);
		}
	}
	
	public function new(canvas:Sprite, scale:Float = 1.0) {
		mCanvas = canvas;
		
		mAnimationCanvas = new Sprite();
		mCanvas.addChild(mAnimationCanvas);
		
		mCurrentState = "";
		mCurrentAnimation = null;
		mDictionary = new Hash<AtlasSprite>();
		
		mX = 0;
		mY = 0; 
		mWidth = 0;
		mHeight = 0;
		mScaleX = 1;
		mScaleY = 1;
		mAlpha = 0;
		mFlip = false;
		mCallbackFunction = null;
	}
	
	public function onEndAnimationCallback(callbackFuncion:Dynamic = null):Void {
		mCallbackFunction = callbackFuncion;
	}
	
	public function addState(id:String, clipName:String, tileData:String, offsetX:Float = 0, offsetY:Float = 0):Void {
		var animation:AtlasSprite = new AtlasSprite(mAnimationCanvas, clipName, tileData);
		mDictionary.set(id, animation);
		
		animation.stop();
		animation.onEndAnimationCallback(sharedOnEndAnimation);
		animation.setOffsetX(offsetX);
		animation.setOffsetY(offsetY);
		
		mAnimationCanvas.removeChild(animation.container());
	}
	
	public function gotoState(state:String):Void {
		if (mCurrentState != state) {
			mCurrentState = state;

			if (mDictionary.exists(state)) {
				var newAnimation:AtlasSprite = mDictionary.get(state);
				newAnimation.gotoAndPlay(0);	
				mWidth = newAnimation.currentWidth();
				mHeight = newAnimation.currentHeight();
				newAnimation.position.x = mX;
				newAnimation.position.y = mY;
				newAnimation.update(16);
				
				if (mCurrentAnimation != null) {
					mAnimationCanvas.removeChild(mCurrentAnimation.container());
				}
				
				mCurrentAnimation = newAnimation;			
				
				mAnimationCanvas.addChild(mCurrentAnimation.container());
			}
		}
	}
	
	private function sharedOnEndAnimation():Void {
		if (mCallbackFunction != null) {
			mCallbackFunction();
		}
	}
	
	public function update(dt:Int):Void {
		if (mCurrentAnimation != null) {
			mWidth = mCurrentAnimation.currentWidth();
			mHeight = mCurrentAnimation.currentHeight();
			
			mCurrentAnimation.position.x = mX;
			mCurrentAnimation.position.y = mY;
			mCurrentAnimation.update(dt);
		}
	}
	
	public function free():Void {
		if (mDictionary != null) {
			var iteratorKeys:Iterator<String> = mDictionary.keys();
			
			while (iteratorKeys.hasNext()) {
				var keyValue:String = iteratorKeys.next();
				var atlasSprite:AtlasSprite = mDictionary.get(keyValue);
				atlasSprite.destroy();
				atlasSprite = null;
				mDictionary.remove(keyValue);
			}
			
			iteratorKeys = null;
			mDictionary = null;
		}
		
		mCanvas.removeChild(mAnimationCanvas);
		mCanvas = null;
		mAnimationCanvas = null;
		mCallbackFunction = null;
		mCurrentState = null;
		mCurrentAnimation = null;
	}
	
}