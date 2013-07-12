package com.funbox.bcp.minigame2.engine;

import com.funbox.bcp.minigame2.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame2.entities.BaseActor;
import com.funbox.bcp.minigame2.entities.enemy.BotCollector;
import com.funbox.bcp.minigame2.entities.player.GamePlayer;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.MiniGame2;
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
	private var mBotCanvas:Sprite;
	private var mEffectCanvas:Sprite;
	private var mBGCanvas:Sprite;
	
	private var mBGSprite:BaseActor;
	private var mBGMaskSprite:BaseActor;
	
	private var mPlayer:GamePlayer;
	private var mBotCollector:BotCollector;
	private var mEntitiesController:EntitiesController;
	private var mFallingObjectManager:FallingObjectManager;
	private var mEffectManager:EffectManager;
	
	private var mMinigameRef:MiniGame2;
	
	public function getBotCollector():BotCollector { return mBotCollector; }
	public function getEffectManager():EffectManager { return mEffectManager; }
	public function getEntitiesController():EntitiesController { return mEntitiesController; }
	
	public function new(miniGameRef:MiniGame2, gameCanvas:Sprite) {
		mGameCanvas = gameCanvas;
		mMinigameRef = miniGameRef;
		
		mEntitiesCanvas = new Sprite();
		mPlayerCanvas = new Sprite();
		mBotCanvas = new Sprite();
		mEffectCanvas = new Sprite();
		mBGCanvas = new Sprite();
		
		mGameCanvas.addChild(mBGCanvas);
		mGameCanvas.addChild(mEntitiesCanvas);
		mGameCanvas.addChild(mBotCanvas);
		mGameCanvas.addChild(mPlayerCanvas);
		mGameCanvas.addChild(mEffectCanvas);

		mEffectManager = new EffectManager(mEffectCanvas);
		
		mEntitiesController = new EntitiesController(mEntitiesCanvas);
		mFallingObjectManager = new FallingObjectManager(mEntitiesController);
		
		mPlayer = new GamePlayer("spMinigame02_mouseHand_click", "spMinigame02_mouseHand_click",
			mPlayerCanvas, 2, 24);
		
		mBotCollector = new BotCollector("spMinigame02_ani_bot_collector", 
			"spMinigame02_ani_bot_collector", mBotCanvas);
		
		mBGSprite = new BaseActor("spMinigame02_bg", null, mBGCanvas, 0, 0);
		mBGMaskSprite = new BaseActor("spMinigame02_background_mask", null, mGameCanvas, 0, 0);
			
		mFallingObjectManager.start();
	}
	
	public function update(dt:Int):Void {
		mPlayer.update(dt);
		
		mEntitiesController.update(dt);
		mFallingObjectManager.update(dt);
		mBotCollector.update(dt);
		mEffectManager.update(dt);
		mBGSprite.update(dt);
		mBGMaskSprite.update(dt);
	}
	
	public function free():Void {
		mEntitiesController.free();
		mFallingObjectManager.free();
		mBotCollector.free();
		mEffectManager.free();
		mBGSprite.free();
		mBGMaskSprite.free();
		mPlayer.free();
		
		mBGSprite = null;
		mBotCollector = null;
		mEntitiesController = null;
		mFallingObjectManager = null;
		mEffectManager = null;
		mBGMaskSprite = null;
		mPlayer = null;
		
		mGameCanvas.removeChild(mBGCanvas);
		mGameCanvas.removeChild(mEntitiesCanvas);
		mGameCanvas.removeChild(mBotCanvas);
		mGameCanvas.removeChild(mPlayerCanvas);
		mGameCanvas.removeChild(mEffectCanvas);
		
		mBGCanvas = null;
		mEntitiesCanvas = null;
		mBotCanvas = null;
		mPlayerCanvas = null;
		mEffectCanvas = null;
	}
	
}