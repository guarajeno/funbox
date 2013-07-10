package com.funbox.bcp.minigame2.engine.effectManager;
import com.funbox.bcp.minigame2.entities.BaseActor;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class BaseEffect extends BaseActor {

	public var isDead:Bool;
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float) {
		super(clipName, aniData, canvas, x, y);
		
		isDead = false;
	}
	
	override public function update(dt:Int):Void {
		if (!mStaticImage) {
			if (mAnimationBitmap.getCurrentIndex() == (mAnimationBitmap.getLength() - 1)) {
				isDead = true;
			}
		}
		
		if (!isDead) {
			super.update(dt);
		}
	}
	
}