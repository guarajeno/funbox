package com.funbox.bcp.minigame2.entities.enemy;

import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class BotCollector extends TouchObject {

	private var mEntities:Array <TouchObject>;
	
	private var mTouchObjectToCatch:TouchObject;
	
	public function new(clipName:String, aniData:String, canvas:Sprite) {
		super(clipName, aniData, canvas, 0, 0, new Vector2D());
		
		setObjectType(EnumTouchObjectType.BOT_COLLECTOR);
		
		mX = (Global.StageWidth >> 1) - (getWidth() / 2);
		mY = Global.StageHeight - getHeight() - Global.ScreenOffsetHeight;
		
		mEntities = new Array<TouchObject>();
		
		mSpeed.x = 0.2;
		mCanFall = false;
		
		setOffsetX(getWidth() / 2);
		setOffsetY(getHeight() / 2);
		
		mAnimationBitmap.gotoAndStop(0);
	}
	
	public function addObjectInGround(touchableObject:TouchObject):Void {
		mEntities.push(touchableObject);
	}
	
	override public function update(dt:Int):Void {
		var i:Int = 0;
		var length:Int = mEntities.length - 1;
		
		while (i <= length) {
			var sObj:TouchObject = mEntities[i];
			
			if (sObj != null) {
				if (!sObj.isDead) {
					sObj.update(dt);
					
					if (!sObj.getCanFall()) {
						if (sObj.hitTest(this)) {
							if (mTouchObjectToCatch == sObj) {
								mTouchObjectToCatch = null;
							}
							
							sObj.makePuffEffect();
							sObj.free();
							sObj = null;
							
							mEntities.splice(i, 1);
							length--;
						}
						else if (mTouchObjectToCatch == null) {
							mTouchObjectToCatch = sObj;
						}
					}
				}
				else {
					sObj.free();
					sObj = null;
					
					mEntities.splice(i, 1);
					length--;
				}
			}
			
			i++;
		}
		
		if (mTouchObjectToCatch != null) {
			var tx:Float = mTouchObjectToCatch.getX();
			var ty:Float = mTouchObjectToCatch.getY();
			
			var dir:Bool = (mX + getWidth() / 2) > (tx + mTouchObjectToCatch.getWidth() / 2);
			
			if (dir) { 
				mX -= mSpeed.x * dt;
				setFlip(true);
			}
			else { 
				mX += mSpeed.x * dt;
				setFlip(false);
			}
			
			if (!mAnimationBitmap.playing()) {
				mAnimationBitmap.gotoAndPlay(0);
			}
		}
		else {
			if (mAnimationBitmap.playing()) {
				mAnimationBitmap.gotoAndStop(0);
			}
		}
		
		super.update(dt);
	}
	
}