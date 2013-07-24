package com.funbox.bcp.minigame3.entities;

import com.funbox.bcp.minigame3.engine.effectManager.BaseEffect;
import com.funbox.bcp.minigame3.engine.effectManager.SpriteAndTextEffect;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.type.EnumTouchObjectType;
import com.minigloop.util.SoundManager;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class TouchObject extends BaseActor {

	public var isDead:Bool;
	private var mAreTouchableItems:Bool;
	
	private var mType:Int;
	private var mAppWidth:Int;
	private var mAppHeight:Int;
	
	private var mSpeed:Vector2D;
	
	public function type():Int { return mType; }
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float, speed:Vector2D) {
		super(clipName, aniData, canvas, x, y);
		
		isDead = false;
		mAreTouchableItems = false;
		
		mAppWidth = Std.int(Global.StageWidth);
		mAppHeight = Std.int(Global.StageHeight);
		
		setSpeed(speed);
	}
	
	public function setSpeed(speed:Vector2D):Void {
		mSpeed = speed;
	}
	
	public function setObjectType(value:Int):Void {
		mType = value;
		
		switch(value) {
		case EnumTouchObjectType.PLAYER:
			mAreTouchableItems = false;
		case EnumTouchObjectType.FROG:
			mAreTouchableItems = true;
		}
	}
	
	public function makePuffEffect():Void {
		var clipScoreName:String = "";
			
		switch(mType) {
		case EnumTouchObjectType.FROG:
			clipScoreName = "spMinigame02_score_100";
		}
		
		Global.minigame.getVTEngine().getEffectManager().createEffect(mX + getWidth() / 2, 
			mY + getHeight() / 2, "spMinigame03_ani_effect_puff", "spMinigame03_ani_effect_puff");
			
		var baseEffect:BaseEffect = Global.minigame.getVTEngine().getEffectManager().createEffect(mX + getWidth() / 2, 
			mY + getHeight() / 2, "spMinigame03_score_100", null);
		baseEffect.DieWithAlpha(true);
	}
	
	override public function update(dt:Int):Void {
		if (Global.minigame.isMousePressed()) {
			var mouseX:Int = Std.int(Global.minigame.getMouseX());
			var mouseY:Int = Std.int(Global.minigame.getMouseY());
			
			if (hitTestPoint(mouseX, mouseY)) {
				isDead = true;
				makePuffEffect();
				
				var score_earned:Int = 0;
				
				switch(mType) {
				case EnumTouchObjectType.FROG:
					score_earned = 100;
				}
				
				SoundManager.play("fx_sapo");
				
				var newScore:Int = Global.minigame.getGameHud().GetScore();
				newScore += score_earned;
				Global.minigame.getGameHud().SetScore(newScore);
			}
		}
		
		if (mAreTouchableItems) {
			//TODO: Do something here...
		}
		
		super.update(dt);
	}
	
	override public function free():Void {
		mSpeed = null;
		
		super.free();
	}
	
}