package com.funbox.bcp.minigame2.engine.effectManager;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class EffectManager
{
	private var mCanvas:Sprite;
	private var mEffectsRepo:Array <BaseEffect>;

	public function new(canvas:Sprite) {
		mCanvas = canvas;
		
		mEffectsRepo = new Array<BaseEffect>();
	}
	
	public function createEffect(x:Float, y:Float, clipName:String, aniData:String):BaseEffect {
		var touchObj:BaseEffect = null;
		
		touchObj = new BaseEffect(clipName, aniData, mCanvas, x, y);
		
		if (touchObj != null) {
			mEffectsRepo.push(touchObj);
		}
		
		return touchObj;
	}
	
	public function update(dt:Int):Void {
		var i:Int = 0;
		var length:Int = mEffectsRepo.length - 1;
		
		while (i <= length) {
			var sObj:BaseEffect = mEffectsRepo[i];
			
			if (sObj != null) {
				if (!sObj.isDead) {
					sObj.update(dt);
				}
				else {
					sObj.free();
					sObj = null;
					
					mEffectsRepo.splice(i, 1);
					length--;
				}
			}
			
			i++;
		}
	}
	
	public function free():Void {
		
	}
	
}