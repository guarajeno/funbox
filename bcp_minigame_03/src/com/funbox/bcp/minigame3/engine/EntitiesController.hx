package com.funbox.bcp.minigame3.engine;

import com.funbox.bcp.minigame3.entities.BaseActor;
import com.funbox.bcp.minigame3.entities.enemy.Enemy_Frog;
import com.funbox.bcp.minigame3.entities.TouchObject;
import com.funbox.bcp.minigame3.type.EnumTouchObjectType;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

class EntitiesController {

	private var mCanvas:Sprite;
	private var mEntities:Array <TouchObject>;
	
	public function getEntities():Array < TouchObject > { return mEntities; }
	
	public function new(canvas:Sprite) {
		mCanvas = canvas;
		
		mEntities = new Array<TouchObject>();
	}
	
	public function createEntitie(speed:Vector2D, type:Int):TouchObject {
		var touchObj:TouchObject = null;
		
		switch (type) {
		case EnumTouchObjectType.FROG:
			touchObj = new Enemy_Frog(mCanvas, speed);
			touchObj.setOffsetX(touchObj.getWidth() / 2);
			touchObj.setOffsetY(touchObj.getHeight() / 2);
		}
		
		if (touchObj != null) {
			mEntities.push(touchObj);
		}
		
		return touchObj;
	}
	
	public function removeEntitie(obj:TouchObject):Void {
		mEntities.remove(obj);
	}
	
	public function update(dt:Int):Void {
		var i:Int = 0;
		var length:Int = mEntities.length - 1;
		
		while (i <= length) {
			var sObj:TouchObject = mEntities[i];
			
			if (sObj != null) {
				if (!sObj.isDead) {
					sObj.update(dt);
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
	}
	
	public function free():Void {
		var i:Int = 0;
		var length:Int = mEntities.length - 1;
		
		while (i <= length) {
			var sObj:TouchObject = mEntities[i];
			
			if (sObj != null) {
				sObj.free();
				sObj = null;
				
				mEntities.splice(i, 1);
				length--;
			}
			
			i++;
		}
		
		mEntities = null;
		mCanvas = null;
	}
	
}