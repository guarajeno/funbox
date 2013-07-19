package com.funbox.bcp.minigame4.screens;

import com.funbox.bcp.minigame4.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame4.engine.effectManager.SpriteAndTextEffect;
import com.funbox.bcp.minigame4.entities.BaseActor;
import com.funbox.bcp.minigame4.Global;
import com.funbox.bcp.minigame4.util.AlphaTweener;
import com.funbox.bcp.minigame4.util.NInterval;
import com.funbox.bcp.minigame4.util.NUtils;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.Vector2D;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author 
 * 
 */

class TutorialScreen extends Screen {
	
	public static var STATE_SHOW_TUTORIAL:Int 		= 0;
	public static var STATE_WAIT:Int 				= 1;
	public static var STATE_DISAPPEAR_TUTORIAL:Int  = 2;
	public static var STATE_NOTHING:Int  			= 3;
	
	private var mBGSprite:BaseActor;
	private var mBGMaskSprite:BaseActor;
	private var mTutorialSprite:BaseActor;

	private var mCurrentState:Int;
	private var mInterval:NInterval;
	
	private var mEffectManager:EffectManager;
	
	private var mCanvasTutorial:Sprite;
	private var mCanvasEffect:Sprite;
	private var mCanvasMouse:Sprite;
	private var mCanvasTutoSprite:Sprite;
	
	private var mCardSprite:BaseActor;
	private var mPlayerSprite:BaseActor;
	private var mMosaicoSprite:BaseActor;
	
	public function new(canvas:Sprite) {
		super(canvas);
		
		mCurrentState = 0;
	
		mCanvasTutorial = new Sprite();
		mCanvasEffect = new Sprite();
		mCanvasMouse = new Sprite();
		mCanvasTutoSprite = new Sprite();
		
		_canvas.addChild(mCanvasTutorial);
		_canvas.addChild(mCanvasTutoSprite);
		_canvas.addChild(mCanvasEffect);
		_canvas.addChild(mCanvasMouse);
		
		mCardSprite = new BaseActor("spMinigame04_tutorial_bcp_card", null, mCanvasTutoSprite, 
			(Global.StageWidth / 2) - 70, (Global.StageHeight / 2) + 30);
		mCardSprite.getBitmap().scaleX = mCardSprite.getBitmap().scaleY = 0.5;
		
		mPlayerSprite = new BaseActor("spMinigame04_tutorial_player_walk_left", "spMinigame04_tutorial_player_walk_left",
			mCanvasTutoSprite, (Global.StageWidth / 2) - 100, (Global.StageHeight / 2) + 60);
			
		mMosaicoSprite = new BaseActor("spMinigame04_tutorial_mosaico_1_walk_right", "spMinigame04_tutorial_mosaico_1_walk_right",
			mCanvasTutoSprite, (Global.StageWidth / 2) + 60, (Global.StageHeight / 2) + 60);
		
		mEffectManager = new EffectManager(mCanvasEffect);
		
		mBGSprite = new BaseActor("spminigame04_bg", null, mCanvasTutorial, 0, 0);
		mBGMaskSprite = new BaseActor("spminigame04_background_mask", null, mCanvasTutorial, 0, 0);
		mTutorialSprite = new BaseActor("spminigame04_tutorial_text", null, mCanvasTutorial, 0, 0);

		mTutorialSprite.setX((Global.StageWidth / 2) - (mTutorialSprite.getWidth() / 2));
		mTutorialSprite.setY((Global.StageHeight / 2) - (mTutorialSprite.getHeight() / 2) - 20);

		mTutorialSprite.setAlpha(0.0);
		
		mCurrentState = TutorialScreen.STATE_SHOW_TUTORIAL;
	}
	
	private function onFinishWait():Void {
		mInterval = null;
		mCurrentState = TutorialScreen.STATE_DISAPPEAR_TUTORIAL;
	}
	
	private function onGoGame():Void {
		ScreenManager.instance.gotoScreen(GameScreen);
	}
	
	override public function update(dt):Void {
		mBGSprite.update(dt);
		mBGMaskSprite.update(dt);
		mTutorialSprite.update(dt);
		mEffectManager.update(dt);
		
		mCardSprite.update(dt);
		mPlayerSprite.update(dt);
		mMosaicoSprite.update(dt);
		
		switch(mCurrentState) {
		case TutorialScreen.STATE_SHOW_TUTORIAL:
			if (mTutorialSprite.getAlpha() >= 1.0) {
				mTutorialSprite.setAlpha(1.0);
				
				mCurrentState = TutorialScreen.STATE_DISAPPEAR_TUTORIAL;
			}
			else {
				mTutorialSprite.setAlpha(mTutorialSprite.getAlpha() + (0.0008 * dt));
			}
		case TutorialScreen.STATE_WAIT:
			if (mInterval != null) {
				mInterval.update(dt);
			}
		case TutorialScreen.STATE_DISAPPEAR_TUTORIAL:
			if (mTutorialSprite.getAlpha() <= 0.0) {
				mTutorialSprite.setAlpha(0.0);
				
				onGoGame();
				mCurrentState = TutorialScreen.STATE_NOTHING;
			}
			else {
				mTutorialSprite.setAlpha(mTutorialSprite.getAlpha() - (0.0005 * dt));
			}
		}
	}
	
	override public function destroy():Dynamic {
		mBGSprite.free();
		mBGMaskSprite.free();
		mTutorialSprite.free();
		mEffectManager.free();
		
		mPlayerSprite.free();
		mCardSprite.free();
		mMosaicoSprite.free();
		
		_canvas.removeChild(mCanvasEffect);
		_canvas.removeChild(mCanvasTutorial);
		_canvas.removeChild(mCanvasTutoSprite);
		
		mMosaicoSprite = null;
		mPlayerSprite = null;
		mCardSprite = null;
		mEffectManager = null;
		mBGSprite = null;
		mBGMaskSprite = null;
		mTutorialSprite = null;
		mInterval = null;
		mCanvasTutoSprite = null;
		
		super.destroy();
	}
}