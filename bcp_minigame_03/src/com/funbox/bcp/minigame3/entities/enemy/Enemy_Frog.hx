package com.funbox.bcp.minigame3.entities.enemy;
import com.funbox.bcp.minigame3.entities.TouchObject;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.type.EnumTouchObjectType;
import com.funbox.bcp.minigame3.util.NInterval;
import com.funbox.bcp.minigame3.util.NLinearMovement;
import com.funbox.bcp.minigame3.util.NMath;
import com.funbox.bcp.minigame3.util.NUtils;
import com.minigloop.util.SoundManager;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class Enemy_Frog extends TouchObject {

	public static var ST_JUMP:String = "spMinigame03_frog_jump_back";
	public static var ST_STAND:String = "spMinigame03_frog_stand_back";
	
	private var mLinear:NLinearMovement;
	private var mTimeInterval:NInterval;
	
	private var mCanJump:Bool;
	
	public function new(canvas:Sprite, speed:Vector2D) {
		var x:Float = Global.StageWidth / 2;
		var y:Float = 0;
		
		var offsetAngle:Float = -Math.PI / 2;
		var radio:Float = 460;
		var ellipseYFactor:Float = 310;
		var minAngle:Float = offsetAngle + (Math.PI / 2);
		var maxAngle:Float = offsetAngle + (Math.PI + (Math.PI / 2));
		var randomAngle:Float = NMath.random(minAngle, maxAngle);
			
		x += radio * Math.cos(randomAngle);
		y += (radio + ellipseYFactor) * Math.sin(randomAngle);
		
		super(Enemy_Frog.ST_STAND, Enemy_Frog.ST_STAND, canvas,
			x, y, speed);
		
		mCharacter.addState(Enemy_Frog.ST_JUMP, Enemy_Frog.ST_JUMP,
			Enemy_Frog.ST_JUMP, 0, -30);
			
		mCharacter.gotoState(Enemy_Frog.ST_JUMP);
		
		mCharacter.onEndAnimationCallback(onEndAnimation);
		
		mTimeInterval = new NInterval(onEndInterval, 650);
		
		mLinear = new NLinearMovement(x, y, Global.minigame.getVTEngine().getCashMachine().getX(),
			Global.minigame.getVTEngine().getCashMachine().getY(), 0.1);
			
		mCanJump = true;
		
		mType = EnumTouchObjectType.FROG;
	}
	
	private function onEndInterval():Void {
		mCanJump = !mCanJump;
		mTimeInterval = new NInterval(onEndInterval, mCanJump ? 650 : 1000);
		
		if (mCanJump) {
			mCharacter.gotoState("spMinigame03_frog_jump_back");
		}
	}
	
	private function onEndAnimation():Void {
		switch (mCharacter.currentState()) {
		case Enemy_Frog.ST_JUMP:
			mCharacter.gotoState(Enemy_Frog.ST_STAND);
		}
	}
	
	override public function update(dt:Int):Void {
		if (mTimeInterval != null) {
			mTimeInterval.update(dt);
		}
		
		if (mLinear != null && mCanJump) {
			mX = mLinear.getX();
			mY = mLinear.getY();
			mLinear.update(dt);
		}
		
		if (this.hitTest(Global.minigame.getVTEngine().getCashMachine().getCollisionSprite())) {
			isDead = true;
			makePuffEffect();
			
			Global.minigame.onLoseByFrog();
		}
		
		super.update(dt);
	}
	
	override public function free():Void {
		mTimeInterval = null;
		mLinear = null;
		
		super.free();
	}
}