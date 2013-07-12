package com.funbox.bcp.minigame2.util;

/**
 * ...
 * @author Cristian F. Shute
 */
class NInterval{

	private var mCallbackFunc:Dynamic;
	private var mTimeLimit:Int;
	private var mTimeCounter:Int;
	
	public function new(callbackFunc:Dynamic, timeLimit:Int) {
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
	
}