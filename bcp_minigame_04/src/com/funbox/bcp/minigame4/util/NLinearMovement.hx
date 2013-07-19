package com.funbox.bcp.minigame4.util;

/**
 * ...
 * @author Cristian F. Shute
 */
class NLinearMovement {

	private var mVX:Float;
    private var mVFX:Float;
	
    private var mVY:Float;
    private var mVFY:Float;
	
	private var mX:Float;
    private var mY:Float;
    private var mInitX:Float;
    private var mInitY:Float;
    private var mFinalX:Float;
    private var mFinalY:Float;
    private var mTime:Float;
	
    private var mSpeed:Float;
	private var mOldDistance:Float;
	
	private var mOnFinish:Dynamic;
	
	private var mOnFinishMovement:Bool;
	
	public function getX():Float { return mX; }
    public function getY():Float { return mY; }
	
	public function new(ix:Float, iy:Float, fx:Float, fy:Float, speed:Float) {
		mX = mInitX = ix;
        mY = mInitY = iy;
		
		mFinalX = fx;
        mFinalY = fy;
		
		mSpeed = speed;
        
		mOnFinish = null;
		
        var dx:Float = mInitX - mFinalX;
        var dy:Float = mInitY - mFinalY;
        var angle:Float = Math.atan2(dy, dx) + Math.PI;
		
        mOldDistance = Math.sqrt(dx * dx + dy * dy);

        mVX = Math.cos(angle);
        mVY = Math.sin(angle);
		
        mTime = 0;
		
		mOnFinishMovement = false;
	}
	
	public function setCallback(onCallback:Dynamic = null):Void {
		mOnFinish = onCallback;
	}
	
	public function update(dt:Int):Void {
		if (!mOnFinishMovement) {
            var newSpeed:Float = dt * mSpeed;
			
            mVFX = mVX * newSpeed;
            mVFY = mVY * newSpeed;

            mX += mVFX;
            mY += mVFY;

            var dx:Float = mX - mFinalX;
            var dy:Float = mY - mFinalY;
            var newDistance:Float = Math.sqrt(dx * dx + dy * dy);

            if (mOldDistance < newDistance) {
                mX = mFinalX;
                mY = mFinalY;
                mOnFinishMovement = true;
				
                if (mOnFinish != null) { 
					mOnFinish();
					mOnFinish = null;
				}
            }
            else { mOldDistance = newDistance; }
        }
	}
	
	public function free():Void {
		mOnFinish = null;
	}
}