package com.funbox.bcp.minigame4.engine;
import com.funbox.bcp.minigame4.engine.effectManager.BaseEffect;
import com.funbox.bcp.minigame4.entities.card.GameCard;
import com.funbox.bcp.minigame4.entities.enemy.MosaicosGroup;
import com.funbox.bcp.minigame4.entities.player.GamePlayer;
import com.funbox.bcp.minigame4.Global;
import com.funbox.bcp.minigame4.util.NInterval;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class PullAndPushController {

	public static var WAVE_1:Int = 0;
	public static var WAVE_2:Int = 1;
	public static var WAVE_3:Int = 2;
	
	private var mPlayerRef:GamePlayer;
	private var mMosaicosGroupRef:MosaicosGroup;
	private var mGameCardRef:GameCard;
	
	private var mCurrentWave:Int;
	private var mCurrentClicks:Int;
	
	private var mMouseClickWave_1:Int;
	private var mMouseClickWave_2:Int;
	private var mMouseClickWave_3:Int;
	
	private var mOldIndex:Int;
	private var mSinFactor:Float;
	private var mPullFactor:Float;
	
	private var mInterval:NInterval;
	private var mMouseInterval:NInterval;
	private var mParentCanvas:Sprite;
	
	private var mDoPushEnemies:Bool;
	
	public function new(player:GamePlayer, mosaicosGroup:MosaicosGroup, 
		gameCard:GameCard, parentCanvas:Sprite) {
		
		mPlayerRef = player;
		mGameCardRef = gameCard;
		mMosaicosGroupRef = mosaicosGroup;
		mParentCanvas = parentCanvas;
		
		mMouseClickWave_1 = 20;
		mMouseClickWave_2 =	40;
		mMouseClickWave_3 = 60;
		mCurrentWave = PullAndPushController.WAVE_1;
		
		mOldIndex = -1;
		mSinFactor = 0;
		mPullFactor = 15;
		mCurrentClicks = 0;
		mDoPushEnemies = true;
		
		mGameCardRef.setReferences(mPlayerRef, mMosaicosGroupRef);
		
		Global.minigame.setMouseCallbacks(onMouseClick);
		
		mInterval = new NInterval(onEndInterval, 1500);
	}
	
	private function onEndInterval():Void {
		mInterval.free();
		mInterval = null;
		
		mInterval = new NInterval(onEndInterval, 750);
		
		if (mDoPushEnemies) {
			mPlayerRef.gotoState("spMinigame04_player_walk_right");
			mMosaicosGroupRef.gotoState(MosaicosGroup.ST_WALK_RIGHT);
			mGameCardRef.gotoState(MosaicosGroup.ST_WALK_RIGHT);
			
			mParentCanvas.x += mPullFactor;
			
			if (mParentCanvas.x >= 375) {
				//perdiste
				Global.minigame.onEndGame();
			}
		}
		else {
			mPlayerRef.gotoState("spMinigame04_player_walk_left");
			mMosaicosGroupRef.gotoState(MosaicosGroup.ST_WALK_LEFT);
			mGameCardRef.gotoState(MosaicosGroup.ST_WALK_LEFT);
			
			mParentCanvas.x -= 10;
			
			if (mParentCanvas.x <= -80) {
				mParentCanvas.x = -80;
			}
		}
	}
	
	private function onMouseIntervalFinish():Void {
		mDoPushEnemies = true;
		
		mMouseInterval.free();
		mMouseInterval = null;
	}
	
	private function onMouseClick():Void {
		mCurrentClicks++;
		
		switch(mCurrentWave) {
		case PullAndPushController.WAVE_1:
			if (mCurrentClicks >= mMouseClickWave_1) {
				mCurrentClicks = 0;
				mPullFactor += 5;
				mCurrentWave = PullAndPushController.WAVE_2;
				
				mMosaicosGroupRef.appearNextMosaico();
			}
		case PullAndPushController.WAVE_2:
			if (mCurrentClicks >= mMouseClickWave_2) {
				mCurrentClicks = 0;
				mPullFactor += 5;
				mCurrentWave = PullAndPushController.WAVE_3;
				
				mMosaicosGroupRef.appearNextMosaico();
			}
		case PullAndPushController.WAVE_3:
			if (mCurrentClicks >= mMouseClickWave_3) {
				mCurrentClicks = 0;
				
				// ganaste !!!
				Global.minigame.onEndGame();
			}
		}
		
		if (mMouseInterval == null) {
			mDoPushEnemies = false;
			
			mMouseInterval = new NInterval(onMouseIntervalFinish, 150);
		}
		
		Global.minigame.getGameHud().SetScore(Global.minigame.getGameHud().GetScore() + 100);
		
		//var effect:BaseEffect = Global.minigame.getVTEngine().getEffectManagerScore().createEffect(
		//	Global.minigame.getMouseX(), Global.minigame.getMouseY(), "spMinigame04_score_100", null);
		//effect.DieWithAlpha(true);
	}
	
	public function update(dt:Int):Void {
		if (mInterval != null) { mInterval.update(dt); }
		if (mMouseInterval != null) { mMouseInterval.update(dt); }
	}
	
	public function free():Void {
		mPlayerRef = null;
		mMosaicosGroupRef = null;
	}
	
}