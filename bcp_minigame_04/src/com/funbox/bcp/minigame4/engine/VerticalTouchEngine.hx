package com.funbox.bcp.minigame4.engine;

import com.funbox.bcp.minigame4.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame4.entities.BaseActor;
import com.funbox.bcp.minigame4.entities.card.GameCard;
import com.funbox.bcp.minigame4.entities.enemy.MosaicosGroup;
import com.funbox.bcp.minigame4.entities.player.GamePlayer;
import com.funbox.bcp.minigame4.Global;
import com.funbox.bcp.minigame4.MiniGame2;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author Cristian F. Shute
 */
class VerticalTouchEngine {

	private var mGameCanvas:Sprite;
	private var mPlayerCanvas:Sprite;
	private var mEffectCanvas:Sprite;
	private var mEffectScoreCanvas:Sprite;
	private var mMosaicosCanvas:Sprite;
	private var mCardCanvas:Sprite;
	private var mGameEverythingCanvas:Sprite;
	private var mBGCanvas:Sprite;
	
	private var mBGSprite:BaseActor;
	private var mBGMiniCollisionSprite:BaseActor;
	private var mBGMaskSprite:BaseActor;
	
	private var mPlayer:GamePlayer;
	private var mGameCard:GameCard;
	private var mMosaicosGroup:MosaicosGroup;
	private var mEffectManager:EffectManager;
	private var mEffectManagerScore:EffectManager;
	private var mPullAndPushController:PullAndPushController;
	
	private var mMinigameRef:MiniGame2;
	
	public function getEffectManager():EffectManager 			{ return mEffectManager; }
	public function getEffectManagerScore():EffectManager 		{ return mEffectManagerScore; }
	
	public function getPlayerCollision():BaseActor 				{ return mBGMiniCollisionSprite; }
	
	public function new(miniGameRef:MiniGame2, gameCanvas:Sprite) {
		mGameCanvas = gameCanvas;
		mMinigameRef = miniGameRef;
		
		mPlayerCanvas = new Sprite();
		mEffectCanvas = new Sprite();
		mBGCanvas = new Sprite();
		mMosaicosCanvas = new Sprite();
		mCardCanvas = new Sprite();
		mGameEverythingCanvas = new Sprite();
		mEffectScoreCanvas = new Sprite();
		
		mGameCanvas.addChild(mBGCanvas);
		mGameCanvas.addChild(mGameEverythingCanvas);
		mGameCanvas.addChild(mEffectScoreCanvas);
		
		mGameEverythingCanvas.addChild(mCardCanvas);
		mGameEverythingCanvas.addChild(mMosaicosCanvas);
		mGameEverythingCanvas.addChild(mPlayerCanvas);
		mGameEverythingCanvas.addChild(mEffectCanvas);

		mEffectManager = new EffectManager(mEffectCanvas);
		mEffectManagerScore = new EffectManager(mEffectScoreCanvas);
		
		var sumX:Int = 100;
		
		mPlayer = new GamePlayer(mPlayerCanvas, 150 + sumX, 300);
		mMosaicosGroup = new MosaicosGroup(mMosaicosCanvas, 310 + sumX, 300, mEffectManager);
		mGameCard = new GameCard(mCardCanvas, 185 + sumX, 260);
		
		mPullAndPushController = new PullAndPushController(mPlayer, mMosaicosGroup, 
			mGameCard, mGameEverythingCanvas);
		
		mBGSprite = new BaseActor("spminigame04_bg", null, mBGCanvas, 0, 0);
		mBGMaskSprite = new BaseActor("spminigame04_background_mask", null, mGameCanvas, 0, 0);
	}
	
	public function update(dt:Int):Void {
		mPlayer.update(dt);
		mMosaicosGroup.update(dt);
		mPullAndPushController.update(dt);
		mGameCard.update(dt);
		
		mEffectManager.update(dt);
		mEffectManagerScore.update(dt);
		mBGSprite.update(dt);
		mBGMaskSprite.update(dt);
	}
	
	public function free():Void {
		mEffectManager.free();
		mEffectManagerScore.free();
		mBGSprite.free();
		mBGMaskSprite.free();
		mPlayer.free();
		mMosaicosGroup.free();
		mPullAndPushController.free();
		mGameCard.free();
		
		mEffectManagerScore = null;
		mPullAndPushController = null;
		mMosaicosGroup = null;
		mBGSprite = null;
		mEffectManager = null;
		mBGMaskSprite = null;
		mPlayer = null;
		mMinigameRef = null;
		mGameCard = null;
		
		mGameCanvas.removeChild(mBGCanvas);
		mGameCanvas.removeChild(mGameEverythingCanvas);
		mGameCanvas.removeChild(mEffectScoreCanvas);
		
		mGameEverythingCanvas.removeChild(mCardCanvas);
		mGameEverythingCanvas.removeChild(mMosaicosCanvas);
		mGameEverythingCanvas.removeChild(mPlayerCanvas);
		mGameEverythingCanvas.removeChild(mEffectCanvas);
		
		mBGCanvas = null;
		mPlayerCanvas = null;
		mEffectCanvas = null;
		mCardCanvas = null;
		mMosaicosCanvas = null;
		mEffectScoreCanvas = null;
		mGameEverythingCanvas = null;
	}
	
}