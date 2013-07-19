package com.funbox.bcp.minigame4.entities.enemy;
import com.funbox.bcp.minigame4.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame4.entities.BaseActor;
import com.funbox.bcp.minigame4.Global;
import com.funbox.bcp.minigame4.util.NInterval;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class MosaicosGroup {

	public static var ST_STAND:Int = 0;
	public static var ST_WALK_RIGHT:Int = 1;
	public static var ST_WALK_LEFT:Int = 2;
	
	private var mX:Int;
	private var mY:Int;
	
	private var mCanvas:Sprite;
	
	private var mMosaicoCanvas_1:Sprite;
	private var mMosaicoCanvas_2:Sprite;
	private var mMosaicoCanvas_3:Sprite;
	
	private var mMosaico_1:BaseActor;
	private var mMosaico_2:BaseActor;
	private var mMosaico_3:BaseActor;
	
	private var mEffectManager:EffectManager;
	
	private var mTimeIntervalDisappear_Mosaico_1:NInterval;
	private var mTimeIntervalDisappear_Mosaico_2:NInterval;
	private var mTimeIntervalDisappear_Mosaico_3:NInterval;
	
	private var mMosaicoCount:Int;
	
	public function new(canvas:Sprite, x:Int, y:Int, effectManager:EffectManager) {
		mX = x;
		mY = y;
		mCanvas = canvas;
		mEffectManager = effectManager;
		
		mMosaicoCanvas_1 = new Sprite();
		mMosaicoCanvas_2 = new Sprite();
		mMosaicoCanvas_3 = new Sprite();
		
		mCanvas.addChild(mMosaicoCanvas_1);
		mCanvas.addChild(mMosaicoCanvas_2);
		mCanvas.addChild(mMosaicoCanvas_3);
			
		mMosaico_1 = new BaseActor("spMinigame04_mosaico_1_stand", "spMinigame04_mosaico_1_stand",
			mMosaicoCanvas_3, mX, mY);
		mMosaico_1.getCharacter().addState("spMinigame04_mosaico_1_walk_left", "spMinigame04_mosaico_1_walk_left",
			"spMinigame04_mosaico_1_walk_left", -4, -7);
		mMosaico_1.getCharacter().addState("spMinigame04_mosaico_1_walk_right", "spMinigame04_mosaico_1_walk_right",
			"spMinigame04_mosaico_1_walk_right", 7, -7);
		mMosaico_1.getCharacter().onEndAnimationCallback(onEndAnimationMosaico_1);
			
		mMosaicoCount = 1;
	}
	
	public function onDisappearAll():Void {
		mTimeIntervalDisappear_Mosaico_1 = new NInterval(onDisappearMosaico_1, 33);
		mTimeIntervalDisappear_Mosaico_2 = new NInterval(onDisappearMosaico_2, 250);
		mTimeIntervalDisappear_Mosaico_3 = new NInterval(onDisappearMosaico_3, 500);
	}
	
	private function onDisappearMosaico_1():Void {
		var mx_1:Float = mMosaico_1.getX();
		
		mMosaico_1.free();
		mMosaico_1 = null;
			
		mEffectManager.createEffect(mx_1, mY, "spMinigame04_ani_effect_puff",
			"spMinigame04_ani_effect_puff");
			
		mTimeIntervalDisappear_Mosaico_1.free();
		mTimeIntervalDisappear_Mosaico_1 = null;
	}
	
	private function onDisappearMosaico_2():Void {
		var mx_2:Float = mMosaico_2.getX();
		
		mMosaico_2.free();
		mMosaico_2 = null;
			
		mEffectManager.createEffect(mx_2, mY, "spMinigame04_ani_effect_puff",
			"spMinigame04_ani_effect_puff");
		
		mTimeIntervalDisappear_Mosaico_2.free();
		mTimeIntervalDisappear_Mosaico_2 = null;
	}
	
	private function onDisappearMosaico_3():Void {
		var mx_3:Float = mMosaico_3.getX();
		
		mMosaico_3.free();
		mMosaico_3 = null;
			
		mEffectManager.createEffect(mx_3, mY, "spMinigame04_ani_effect_puff",
			"spMinigame04_ani_effect_puff");
		
		mTimeIntervalDisappear_Mosaico_3.free();
		mTimeIntervalDisappear_Mosaico_3 = null;
	}
	
	private function onEndAnimationMosaico_1():Void {
		switch (mMosaico_1.getCharacter().currentState()) {
		case "spMinigame04_mosaico_1_walk_left":
			mMosaico_1.getCharacter().gotoState("spMinigame04_mosaico_1_stand");
		case "spMinigame04_mosaico_1_walk_right":
			mMosaico_1.getCharacter().gotoState("spMinigame04_mosaico_1_stand");
		}
	}
	
	private function onEndAnimationMosaico_2():Void {
		switch (mMosaico_2.getCharacter().currentState()) {
		case "spMinigame04_mosaico_2_walk_left":
			mMosaico_2.getCharacter().gotoState("spMinigame04_mosaico_2_stand");
		case "spMinigame04_mosaico_2_walk_right":
			mMosaico_2.getCharacter().gotoState("spMinigame04_mosaico_2_stand");
		}
	}
	
	private function onEndAnimationMosaico_3():Void {
		switch (mMosaico_3.getCharacter().currentState()) {
		case "spMinigame04_mosaico_3_walk_left":
			mMosaico_3.getCharacter().gotoState("spMinigame04_mosaico_3_stand");
		case "spMinigame04_mosaico_3_walk_right":
			mMosaico_3.getCharacter().gotoState("spMinigame04_mosaico_3_stand");
		}
	}
	
	public function gotoState(stateIdentifier:Int):Void {
		var newState_1:String = "";
		var newState_2:String = "";
		var newState_3:String = "";
		
		switch (stateIdentifier) {
		case MosaicosGroup.ST_STAND:
			newState_1 = "spMinigame04_mosaico_1_stand";
			newState_2 = "spMinigame04_mosaico_2_stand";
			newState_3 = "spMinigame04_mosaico_3_stand";
		case MosaicosGroup.ST_WALK_LEFT:
			newState_1 = "spMinigame04_mosaico_1_walk_left";
			newState_2 = "spMinigame04_mosaico_2_walk_left";
			newState_3 = "spMinigame04_mosaico_3_walk_left";
		case MosaicosGroup.ST_WALK_RIGHT:
			newState_1 = "spMinigame04_mosaico_1_walk_right";
			newState_2 = "spMinigame04_mosaico_2_walk_right";
			newState_3 = "spMinigame04_mosaico_3_walk_right";
		}
		
		if (mMosaico_1 != null) { mMosaico_1.getCharacter().gotoState(newState_1); }
		if (mMosaico_2 != null) { mMosaico_2.getCharacter().gotoState(newState_2); }
		if (mMosaico_3 != null) { mMosaico_3.getCharacter().gotoState(newState_3); }
	}
	
	public function appearNextMosaico():Void {
		mMosaicoCount++;		
		
		if (mMosaicoCount == 2) {
			var mx_1:Float = mMosaico_1.getX() + mMosaico_1.getWidth() - mMosaico_1.getWidth() / 4;
			
			mEffectManager.createEffect(mx_1, mY, "spMinigame04_ani_effect_puff",
				"spMinigame04_ani_effect_puff");
				
			mMosaico_2 = new BaseActor("spMinigame04_mosaico_2_stand", "spMinigame04_mosaico_2_stand",
				mMosaicoCanvas_2, mx_1, mY);
			mMosaico_2.getCharacter().addState("spMinigame04_mosaico_2_walk_left", "spMinigame04_mosaico_2_walk_left",
				"spMinigame04_mosaico_2_walk_left", -4, -7);
			mMosaico_2.getCharacter().addState("spMinigame04_mosaico_2_walk_right", "spMinigame04_mosaico_2_walk_right",
				"spMinigame04_mosaico_2_walk_right", 7, -7);
			mMosaico_2.getCharacter().onEndAnimationCallback(onEndAnimationMosaico_2);
		}
		else if (mMosaicoCount == 3) {
			var mx_2:Float = mMosaico_2.getX() + mMosaico_2.getWidth() - mMosaico_2.getWidth() / 4;
			
			mEffectManager.createEffect(mx_2, mY, "spMinigame04_ani_effect_puff",
				"spMinigame04_ani_effect_puff");
			mMosaico_3 = new BaseActor("spMinigame04_mosaico_3_stand", "spMinigame04_mosaico_3_stand",
				mMosaicoCanvas_1, mx_2, mY);
			mMosaico_3.getCharacter().addState("spMinigame04_mosaico_3_walk_left", "spMinigame04_mosaico_3_walk_left",
				"spMinigame04_mosaico_3_walk_left", -4, -7);
			mMosaico_3.getCharacter().addState("spMinigame04_mosaico_3_walk_right", "spMinigame04_mosaico_3_walk_right",
				"spMinigame04_mosaico_3_walk_right", 7, -7);
			mMosaico_3.getCharacter().onEndAnimationCallback(onEndAnimationMosaico_3);
		}
	}
	
	public function update(dt:Int):Void {
		if (mMosaico_1 != null) { mMosaico_1.update(dt); }
		if (mMosaico_2 != null) { mMosaico_2.update(dt); }
		if (mMosaico_3 != null) { mMosaico_3.update(dt); }
		
		if (mTimeIntervalDisappear_Mosaico_1 != null) { mTimeIntervalDisappear_Mosaico_1.update(dt); }
		if (mTimeIntervalDisappear_Mosaico_2 != null) { mTimeIntervalDisappear_Mosaico_2.update(dt); }
		if (mTimeIntervalDisappear_Mosaico_3 != null) { mTimeIntervalDisappear_Mosaico_3.update(dt); }
	}

	public function free():Void {
		if (mMosaico_1 != null) { mMosaico_1.free(); }
		if (mMosaico_2 != null) { mMosaico_2.free(); }
		if (mMosaico_3 != null) { mMosaico_3.free(); }
		
		mMosaico_1 = null;
		mMosaico_2 = null;
		mMosaico_3 = null;
	}
}