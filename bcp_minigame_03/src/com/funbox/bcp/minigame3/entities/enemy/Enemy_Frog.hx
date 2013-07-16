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

	public static var ST_JUMP:String = "spMinigame03_frog_jump_";
	public static var ST_STAND:String = "spMinigame03_frog_stand_";
	
	private var mLinear:NLinearMovement;
	private var mTimeInterval:NInterval;
	
	private var mCanJump:Bool;
	private var mDirAni:String;
	
	private var mParseAniStand:String;
	private var mParseAniJump:String;
	
	public function new(canvas:Sprite, speed:Vector2D) {
		var x:Float = Global.StageWidth / 2;
		var y:Float = 0;
		
		var offsetAngle:Float = -Math.PI / 2;
		var radio:Float = 460;
		var ellipseYFactor:Float = 310;
		var minAngle:Float = offsetAngle + (Math.PI / 2);
		var maxAngle:Float = offsetAngle + (Math.PI + (Math.PI / 2));
		var randomAngle:Float = NMath.random(minAngle, maxAngle);
			
		if (randomAngle >= 0 && randomAngle <= (Math.PI / 4)) {
			mDirAni = "left";
		}
		else if (randomAngle >= (Math.PI / 4) && randomAngle <= ((Math.PI / 4) * 3)) {
			mDirAni = "back";
		}
		else if (randomAngle >= ((Math.PI / 4) * 3) && randomAngle <= Math.PI) {
			mDirAni = "right";
		}
		
		mParseAniStand = Enemy_Frog.ST_STAND + mDirAni;
		mParseAniJump = Enemy_Frog.ST_JUMP + mDirAni;
		
		x += radio * Math.cos(randomAngle);
		y += (radio + ellipseYFactor) * Math.sin(randomAngle);
		
		super(mParseAniStand, mParseAniStand, canvas, x, y, speed);
		
		var offX:Float = 0;
		var offY:Float = 0;
		
		switch (mDirAni) {
		case "back":
			offX = 0;
			offY = -30;
		case "left":
			offX = 30;
			offY = -18;
		case "right":
			offX = -30;
			offY = -18;
		}
		
		mCharacter.addState(mParseAniJump, mParseAniJump, mParseAniJump, offX, offY);
			
		mCharacter.gotoState(mParseAniJump);
		
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
			mCharacter.gotoState(mParseAniJump);
		}
	}
	
	private function onEndAnimation():Void {
		switch (mCharacter.currentState()) {
		case mParseAniJump:
			mCharacter.gotoState(mParseAniStand);
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
		if (mTimeInterval != null) { mTimeInterval.free(); }
		mTimeInterval = null;
		
		mLinear = null;
		
		super.free();
	}
}