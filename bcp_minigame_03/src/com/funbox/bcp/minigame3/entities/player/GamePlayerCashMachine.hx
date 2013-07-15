package com.funbox.bcp.minigame3.entities.player;
import com.funbox.bcp.minigame3.entities.BaseActor;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class GamePlayerCashMachine {

	private var mX:Float;
	private var mY:Float;
	private var mBGMiniCollisionSprite:BaseActor;
	
	public function getX():Float 			{ return mX;  }
	public function setX(value:Float):Void 	{ mX = value; }
	
	public function getY():Float 			{ return mY;  }
	public function setY(value:Float):Void 	{ mY = value; }
	
	public function getCollisionSprite():BaseActor { return mBGMiniCollisionSprite;  }
	
	public function new(canvas:Sprite, x:Float, y:Float) {
		mX = x;
		mY = y;
		
		mBGMiniCollisionSprite = new BaseActor("spMinigame03_miniCollision_bg", null, canvas, 264 , 0);
	}
	
	public function update(dt:Int):Void {
		mBGMiniCollisionSprite.update(dt);
	}
	
	
	public function free():Void {
		mBGMiniCollisionSprite.free();
		mBGMiniCollisionSprite = null;
	}
}