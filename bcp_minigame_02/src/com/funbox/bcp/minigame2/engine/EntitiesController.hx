package com.funbox.bcp.minigame2.engine;

import com.funbox.bcp.minigame2.entities.BaseActor;
import com.funbox.bcp.minigame2.entities.item.ItemCoin;
import com.funbox.bcp.minigame2.entities.item.ItemMoney;
import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

class EntitiesController {

	private var mCanvas:Sprite;
	private var mEntities:Array <TouchObject>;
	
	public function new(canvas:Sprite) {
		mCanvas = canvas;
		
		mEntities = new Array<TouchObject>();
	}
	
	public function createEntitie(x:Float, y:Float, speed:Vector2D, type:Int):TouchObject {
		var touchObj:TouchObject = null;
		
		switch (type) {
		case EnumTouchObjectType.MONEY:
			touchObj = new ItemMoney("spMinigame02_ani_ticket_money", "spMinigame02_ani_ticket_money",
				mCanvas, x, y, speed);
		case EnumTouchObjectType.COIN:
			touchObj = new ItemCoin("spMinigame02_ani_bag_money", "spMinigame02_ani_bag_money",
				mCanvas, x, y, speed);
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
		
	}
	
}