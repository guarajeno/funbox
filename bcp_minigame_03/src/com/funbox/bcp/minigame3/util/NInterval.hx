package com.funbox.bcp.minigame3.util;

/**
 * ...
 * @author Cristian F. Shute
 */
class NInterval{

	private var mCallbackFunc:Dynamic;
	private var mTimeLimit:Int;
	private var mTimeCounter:Int = 0;
	
	public function new(callbackFunc:Dynamic, timeLimit:Int) {
		mTimeLimit = 0;
		mTimeCounter = 0;
		mCallbackFunc =  null;
		
		mCallbackFunc = callbackFunc;
		mTimeLimit = timeLimit;
	}
	
	public function update(dt:Int) {
		if ((mTimeCounter + dt) > mTimeLimit) {
			mTimeCounter = 0;
			
			if (mCallbackFunc != null) {
				mCallbackFunc();
				mCallbackFunc = null;
			}
		}
		else {
			mTimeCounter += dt;
		}
	}
	
	public function free():Void {
		mCallbackFunc = null;
	}
	
}