package com.funbox.bcp.minigame2.engine;
import com.funbox.bcp.minigame2.entities.TouchObject;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.funbox.bcp.minigame2.util.NInterval;
import com.funbox.bcp.minigame2.util.NMath;
import com.funbox.bcp.minigame2.util.NUtils;
import com.minigloop.util.Vector2D;

/**
 * ...
 * @author Cristian F. Shute
 */
class FallingObjectManager {

	private var mEntitiesController:EntitiesController;
	
	private var mIntervalCreation_1:NInterval;
	private var mIntervalCreation_2:NInterval;
	
	private var mStarted:Bool;
	private var mTouchObjectsToChoose:Array<Int>;
	
	public function new(entitiesController:EntitiesController) {
		mEntitiesController = entitiesController;
		mStarted = false;
		
		mTouchObjectsToChoose = new Array<Int>();
		
		mTouchObjectsToChoose.push(EnumTouchObjectType.COIN);
		mTouchObjectsToChoose.push(EnumTouchObjectType.MONEY);
		
		mIntervalCreation_1 = new NInterval(onFinishThenCreate_1, 950);
		mIntervalCreation_2 = new NInterval(onFinishThenCreate_2, 1500);
	}
	
	private function onFinishThenCreate_1():Void {
		onCreateEntitie();
		
		mIntervalCreation_1 = new NInterval(onFinishThenCreate_1, 950);
	}
	
	private function onFinishThenCreate_2():Void {
		onCreateEntitie();
		
		mIntervalCreation_2 = new NInterval(onFinishThenCreate_2, 1500);
	}
	
	public function start():Void {
		mStarted = true;
	}
	
	private function onCreateEntitie():Void {
		var x:Float = NMath.random(30, 610);
		var y:Float = -80;
		var speed:Vector2D = new Vector2D(0, NMath.random(0.03, 0.3));
		var typeToChoose:Int = mTouchObjectsToChoose[NUtils.getValueFromProbabilityChart(mTouchObjectsToChoose.length, 10)];
		
		var tObj:TouchObject = mEntitiesController.createEntitie(0, 0, speed, typeToChoose);
		tObj.setX(NMath.random(tObj.getWidth() + Global.ScreenOffsetWidth, 
			Global.StageWidth - tObj.getWidth() - Global.ScreenOffsetWidth));
		tObj.setY(-tObj.getHeight());
	}
	
	public function update(dt:Int):Void {
		if (mStarted) {
			if (mIntervalCreation_1 != null) { mIntervalCreation_1.update(dt); }
			if (mIntervalCreation_2 != null) { mIntervalCreation_2.update(dt); }
		}
	}
	
	public function free():Void {
		mTouchObjectsToChoose = null;
		mEntitiesController = null;
		
		if (mIntervalCreation_1 != null) { mIntervalCreation_1 = null; }
		if (mIntervalCreation_2 != null) { mIntervalCreation_2 = null; }
	}
	
}