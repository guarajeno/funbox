package com.funbox.bcp.minigame4.engine.effectManager;
import com.minigloop.util.Vector2D;
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
	
	public function createSpriteAndTextEffect(clipName:String, aniData:String, clipNameOther:String,
		aniDataOther:String, pos1:Vector2D, pos2:Vector2D):SpriteAndTextEffect {
		
		var touchObj:SpriteAndTextEffect = null;
		
		touchObj = new SpriteAndTextEffect(clipName, aniData, clipNameOther, 
			aniDataOther, mCanvas, pos1, pos2);
		
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
		var i:Int = 0;
		var length:Int = mEffectsRepo.length - 1;
		
		while (i <= length) {
			var sObj:BaseEffect = mEffectsRepo[i];
			
			if (sObj != null) {
				sObj.free();
				sObj = null;
				
				mEffectsRepo.splice(i, 1);
				length--;
			}
			
			i++;
		}
		
		mEffectsRepo = null;
		mCanvas = null;
	}
	
}