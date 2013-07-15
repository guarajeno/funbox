package com.funbox.bcp.minigame3.entities.enemy;
import com.funbox.bcp.minigame3.entities.TouchObject;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.util.NLinearMovement;
import com.funbox.bcp.minigame3.util.NMath;
import com.funbox.bcp.minigame3.util.NUtils;
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
		
		super(Enemy_Frog.ST_JUMP, Enemy_Frog.ST_JUMP, canvas,
			x, y, speed);
		
		mCharacter.addState(Enemy_Frog.ST_STAND, Enemy_Frog.ST_STAND,
			Enemy_Frog.ST_STAND);
		
		mCharacter.onEndAnimationCallback(onEndAnimation);
		
		mLinear = new NLinearMovement(x, y, Global.minigame.getVTEngine().getCashMachine().getX(),
			Global.minigame.getVTEngine().getCashMachine().getY(), 0.1);
	}
	
	private function onEndAnimation():Void {
		switch (mCharacter.currentState()) {
		case Enemy_Frog.ST_JUMP:
			mCharacter.gotoState(Enemy_Frog.ST_STAND);
		}
	}
	
	override public function update(dt:Int):Void {
		if (mLinear != null) {
			mX = mLinear.getX();
			mY = mLinear.getY();
			mLinear.update(dt);
		}
		
		super.update(dt);
	}
}