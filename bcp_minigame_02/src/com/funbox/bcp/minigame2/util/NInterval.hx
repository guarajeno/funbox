package com.funbox.bcp.minigame2.util;

/**
 * ...
 * @author Cristian F. Shute
 */
class NInterval{

	private var mCallbackFunc:Dynamic;
	private var mTimeLimit:Int;
	private var mTimeCounter:Int = 0;
	
	public function new(callbackFunc:Dynamic, timeLimit:Int) {
		mCallbackFunc = callbackFunc;
		mTimeLimit = timeLimit;
		trace("interval created");
	}
	
	public function update(dt:Int) {
		trace("interval update " + mTimeCounter + " " + dt + " " + mTimeLimit);
		
		if ((mTimeCounter + dt) > mTimeLimit) {
			mTimeCounter = 0;
			
			if (mCallbackFunc != null) {
				trace("callback");
				mCallbackFunc();
				mCallbackFunc = null;
			}
		}
		else {
			mTimeCounter += dt;
		}
	}
	
}