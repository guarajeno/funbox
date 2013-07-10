package com.funbox.bcp.minigame2.engine;
import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.funbox.bcp.minigame2.util.NMath;
import com.funbox.bcp.minigame2.util.NUtils;
import com.minigloop.util.Vector2D;

/**
 * ...
 * @author Cristian F. Shute
 */
class FallingObjectManager {

	private var mEntitiesController:EntitiesController;

	private var mTimeCounter:Int;
	private var mTimeLimit:Int;
	
	private var mStarted:Bool;
	private var mTouchObjectsToChoose:Array<Int>;
	
	public function new(entitiesController:EntitiesController) {
		mEntitiesController = entitiesController;
		
		mTimeCounter = 0;
		mTimeLimit = 1500;
		
		mStarted = false;
		
		mTouchObjectsToChoose = new Array<Int>();
		
		mTouchObjectsToChoose.push(EnumTouchObjectType.COIN);
		mTouchObjectsToChoose.push(EnumTouchObjectType.MONEY);
	}
	
	public function start():Void {
		mStarted = true;
		
		mTimeCounter = mTimeLimit;
	}
	
	private function onCreateEntitie():Void {
		var x:Float = NMath.random(30, 610);
		var y:Float = -80;
		var speed:Vector2D = new Vector2D(0, NMath.random(0.05, 0.4));
		var typeToChoose:Int = mTouchObjectsToChoose[NUtils.getValueFromProbabilityChart(mTouchObjectsToChoose.length, 10)];
		
		var tObj:TouchObject = mEntitiesController.createEntitie(0, 0, speed, typeToChoose);
		tObj.setX(NMath.random(tObj.getWidth(), Global.stage.stageWidth - tObj.getWidth()));
		tObj.setY(-tObj.getHeight());
	}
	
	public function update(dt:Int):Void {
		if (mStarted) {
			if ((mTimeCounter + (dt >> 1)) > mTimeLimit) {
				mTimeCounter = 0;
				
				// create entitie
				onCreateEntitie();
			}
			else { mTimeCounter += dt; }
		}
	}
	
	public function free():Void {
		
	}
	
}