package com.funbox.bcp.minigame2.engine.effectManager;
import com.minigloop.display.AtlasSprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class SpriteAndTextEffect extends BaseEffect {

	private var mAnimationBitmapOther:AtlasSprite;
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float) {
		super(clipName, aniData, canvas, x, y);
	}
	
}