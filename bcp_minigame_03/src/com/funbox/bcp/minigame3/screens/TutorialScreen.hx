package com.funbox.bcp.minigame3.screens;

import com.funbox.bcp.minigame3.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame3.engine.effectManager.SpriteAndTextEffect;
import com.funbox.bcp.minigame3.entities.BaseActor;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.util.AlphaTweener;
import com.funbox.bcp.minigame3.util.NInterval;
import com.funbox.bcp.minigame3.util.NUtils;
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
	public static var STATE_TOUCH_FROG:Int  		= 4;
	
	private var mBGSprite:BaseActor;
	private var mBGMaskSprite:BaseActor;
	private var mTutorialSprite:BaseActor;
	
	private var mHandSprite:BaseActor;
	private var mFrogAnimation:BaseActor;
	
	private var mCurrentState:Int;
	private var mInterval:NInterval;
	
	private var mBagInitX:Float;
	private var mMoneyInitX:Float;
	
	private var mFrogInitX:Float;
	
	private var mEffectManager:EffectManager;
	
	private var mCanvasTutorial:Sprite;
	private var mCanvasEffect:Sprite;
	private var mCanvasMouse:Sprite;
	
	private var mMousePressed:Bool;
	private var mMousePressedCancel:Bool;
	private var mClickOneWay:Bool;
	private var mClickToContiue:BaseActor;
	
	public function new(canvas:Sprite) {
		super(canvas);
		
		mCurrentState = 0;
	
		mBagInitX = 0;
		mMoneyInitX = 0;
		mMousePressed = false;
		mMousePressedCancel = false;

		mCanvasTutorial = new Sprite();
		mCanvasEffect = new Sprite();
		mCanvasMouse = new Sprite();
		
		_canvas.addChild(mCanvasTutorial);
		_canvas.addChild(mCanvasEffect);
		_canvas.addChild(mCanvasMouse);
		
		mEffectManager = new EffectManager(mCanvasEffect);
		
		mBGSprite = new BaseActor("spMinigame03_bg", null, mCanvasTutorial, 0, 0);
		mBGMaskSprite = new BaseActor("spMinigame03_background_mask", null, mCanvasTutorial, 0, 0);
		mTutorialSprite = new BaseActor("spMinigame03_tutorial_text", null, mCanvasTutorial, 0, 0);
		
		mHandSprite = new BaseActor("spMinigame03_tutorial_mouseHand_click", null, 
			mCanvasMouse, (Global.StageWidth / 2), (Global.StageHeight / 2) + 60);
			
		mFrogInitX = (Global.StageWidth / 2) - 100;
			
		mFrogAnimation = new BaseActor("spMinigame03_tutorial_frog_stand_front", 
			"spMinigame03_frog_stand_front", mCanvasTutorial, mFrogInitX,
			(Global.StageHeight / 2) + 60);
		
		mTutorialSprite.setX((Global.StageWidth / 2) - (mTutorialSprite.getWidth() / 2));
		mTutorialSprite.setY((Global.StageHeight / 2) - (mTutorialSprite.getHeight() / 2) - 20);

		mTutorialSprite.setAlpha(0.0);
		
		mCurrentState = TutorialScreen.STATE_SHOW_TUTORIAL;
		
		mClickOneWay = true;
		
		mClickToContiue = new BaseActor("gui_text_tutorial_generic", null, mCanvasTutorial, 0, 0);
		mClickToContiue.setX((Global.StageWidth / 2) - (mClickToContiue.getWidth() / 2));
		mClickToContiue.setY((Global.StageHeight) - (mClickToContiue.getHeight() / 2) - 20);
		
		canvas.addEventListener(MouseEvent.MOUSE_MOVE, onMouseHandler);
		canvas.addEventListener(MouseEvent.MOUSE_DOWN, onMouseHandler);
		canvas.addEventListener(MouseEvent.MOUSE_UP, onMouseHandler);
		canvas.addEventListener(MouseEvent.MOUSE_OUT, onMouseHandler);
		canvas.addEventListener(MouseEvent.ROLL_OUT, onMouseHandler);
	}
	
	private function onMouseHandler(e:MouseEvent):Void {
		switch(e.type) {
		case MouseEvent.MOUSE_DOWN:
			mMousePressed = true;
		case MouseEvent.MOUSE_UP:
			mMousePressed = false;
		case MouseEvent.MOUSE_OUT:
			mMousePressed = false;
		case MouseEvent.ROLL_OUT:
			mMousePressed = false;
		}
	}
	
	private function onFinishWait():Void {
		mInterval = null;
		mCurrentState = TutorialScreen.STATE_DISAPPEAR_TUTORIAL;
	}
	
	private function onGoGame():Void {
		ScreenManager.instance.gotoScreen(GameScreen);
	}
	
	override public function update(dt):Void {
		if (mClickToContiue != null) {
			if (mClickOneWay) {
				if (mClickToContiue.getAlpha() <= 0) {
					mClickToContiue.setAlpha(0);
					mClickOneWay = false;
				}
				else {
					mClickToContiue.setAlpha(mClickToContiue.getAlpha() - (0.0008 * dt));
				}
			}
			else {
				if (mClickToContiue.getAlpha() >= 1) {
					mClickToContiue.setAlpha(1);
					mClickOneWay = true;
				}
				else {
					mClickToContiue.setAlpha(mClickToContiue.getAlpha() + (0.0008 * dt));
				}
			}
			
			if (mMousePressed && !mMousePressedCancel) {
				mMousePressedCancel = true;
				
				mClickToContiue.free();
				mClickToContiue = null;
				mCurrentState = TutorialScreen.STATE_DISAPPEAR_TUTORIAL;
			}
			
			if (mClickToContiue != null) {
				mClickToContiue.update(dt);
			}
		}
		
		mBGSprite.update(dt);
		mBGMaskSprite.update(dt);
		mTutorialSprite.update(dt);
		mEffectManager.update(dt);
		mHandSprite.update(dt);
		
		if (mFrogAnimation != null) {
			mFrogAnimation.update(dt);
		}
		
		switch(mCurrentState) {
		case TutorialScreen.STATE_SHOW_TUTORIAL:
			if (mTutorialSprite.getAlpha() >= 1.0) {
				mTutorialSprite.setAlpha(1.0);
				
				mCurrentState = TutorialScreen.STATE_TOUCH_FROG;
			}
			else {
				mTutorialSprite.setAlpha(mTutorialSprite.getAlpha() + (0.0008 * dt));
			}
		case TutorialScreen.STATE_TOUCH_FROG:
			if (mHandSprite.getX() <= mFrogInitX) {
				mHandSprite.setX(mFrogInitX);
				mCurrentState = TutorialScreen.STATE_WAIT;
				
				mInterval = new NInterval(onFinishWait, 500);
				
				mFrogAnimation.free();
				mFrogAnimation = null;
				
				mEffectManager.createEffect(mHandSprite.getX(), mHandSprite.getY(), 
					"spMinigame03_tutorial_ani_effect_puff", "spMinigame03_ani_effect_puff");
			}
			else {
				mHandSprite.setX(mHandSprite.getX() - (0.1 * dt));
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
		mHandSprite.free();
		
		if (mClickToContiue != null) {
			mClickToContiue.free();
		}
		
		mClickToContiue = null;
		
		if (mFrogAnimation != null) {
			mFrogAnimation.free();
		}
		
		_canvas.removeChild(mCanvasEffect);
		_canvas.removeChild(mCanvasTutorial);
		
		mFrogAnimation = null;
		mHandSprite = null;
		mEffectManager = null;
		mBGSprite = null;
		mBGMaskSprite = null;
		mTutorialSprite = null;
		mInterval = null;
		
		super.destroy();
	}
}