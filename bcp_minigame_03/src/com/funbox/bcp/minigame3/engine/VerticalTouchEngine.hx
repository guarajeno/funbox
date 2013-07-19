package com.funbox.bcp.minigame3.engine;

import com.funbox.bcp.minigame3.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame3.entities.BaseActor;
import com.funbox.bcp.minigame3.entities.player.GamePlayer;
import com.funbox.bcp.minigame3.entities.player.GamePlayerCashMachine;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.MiniGame2;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author Cristian F. Shute
 */
class VerticalTouchEngine {

	private var mGameCanvas:Sprite;
	private var mEntitiesCanvas:Sprite;
	private var mPlayerCanvas:Sprite;
	private var mEffectCanvas:Sprite;
	private var mBGCanvas:Sprite;
	
	private var mBGSprite:BaseActor;
	private var mBGMiniCollisionSprite:BaseActor;
	private var mBGMaskSprite:BaseActor;
	
	private var mPlayer:GamePlayer;
	private var mEntitiesController:EntitiesController;
	private var mEnemiesWaveManager:EnemiesWaveManager;
	private var mEffectManager:EffectManager;
	private var mGamePlayerCashMachine:GamePlayerCashMachine;
	
	private var mMinigameRef:MiniGame2;
	
	public function getEffectManager():EffectManager 			{ return mEffectManager; }
	public function getEntitiesController():EntitiesController 	{ return mEntitiesController; }
	public function getCashMachine():GamePlayerCashMachine 		{ return mGamePlayerCashMachine; }
	
	public function getPlayerCollision():BaseActor 				{ return mBGMiniCollisionSprite; }
	
	public function new(miniGameRef:MiniGame2, gameCanvas:Sprite) {
		mGameCanvas = gameCanvas;
		mMinigameRef = miniGameRef;
		
		mEntitiesCanvas = new Sprite();
		mPlayerCanvas = new Sprite();
		mEffectCanvas = new Sprite();
		mBGCanvas = new Sprite();
		
		mGameCanvas.addChild(mBGCanvas);
		mGameCanvas.addChild(mEntitiesCanvas);
		mGameCanvas.addChild(mPlayerCanvas);
		mGameCanvas.addChild(mEffectCanvas);

		mEffectManager = new EffectManager(mEffectCanvas);
		
		mEntitiesController = new EntitiesController(mEntitiesCanvas);
		mEnemiesWaveManager = new EnemiesWaveManager(mEntitiesController);
		mGamePlayerCashMachine = new GamePlayerCashMachine(mBGCanvas, Global.StageWidth / 2, 0);
		
		mPlayer = new GamePlayer("spMinigame03_mouseHand_click_attack", "spMinigame03_mouseHand_click_attack",
			mPlayerCanvas, -2, 15);
		
		mBGSprite = new BaseActor("spMinigame03_bg", null, mBGCanvas, 0, 0);
		
		mBGMaskSprite = new BaseActor("spMinigame03_background_mask", null, mGameCanvas, 0, 0);
			
		mEnemiesWaveManager.start();
	}
	
	public function update(dt:Int):Void {
		mPlayer.update(dt);
		
		mEntitiesController.update(dt);
		mEnemiesWaveManager.update(dt);
		mEffectManager.update(dt);
		mBGSprite.update(dt);
		mBGMaskSprite.update(dt);
		mGamePlayerCashMachine.update(dt);
	}
	
	public function free():Void {
		mEntitiesController.free();
		mEnemiesWaveManager.free();
		mEffectManager.free();
		mBGSprite.free();
		mBGMaskSprite.free();
		mPlayer.free();
		mGamePlayerCashMachine.free();
		
		mBGSprite = null;
		mEntitiesController = null;
		mEnemiesWaveManager = null;
		mEffectManager = null;
		mBGMaskSprite = null;
		mPlayer = null;
		mGamePlayerCashMachine = null;
		mMinigameRef = null;
		
		mGameCanvas.removeChild(mBGCanvas);
		mGameCanvas.removeChild(mEntitiesCanvas);
		mGameCanvas.removeChild(mPlayerCanvas);
		mGameCanvas.removeChild(mEffectCanvas);
		
		mBGCanvas = null;
		mEntitiesCanvas = null;
		mPlayerCanvas = null;
		mEffectCanvas = null;
	}
	
}