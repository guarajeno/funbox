package com.funbox.bcp.minigame2.screens;

import com.funbox.bcp.minigame2.engine.effectManager.EffectManager;
import com.funbox.bcp.minigame2.engine.effectManager.SpriteAndTextEffect;
import com.funbox.bcp.minigame2.entities.BaseActor;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.util.AlphaTweener;
import com.funbox.bcp.minigame2.util.NInterval;
import com.funbox.bcp.minigame2.util.NUtils;
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
	public static var STATE_MOUSE_LEFT:Int  		= 4;
	public static var STATE_MOUSE_RIGHT:Int  		= 5;
	
	private var mBGSprite:BaseActor;
	private var mBGMaskSprite:BaseActor;
	private var mTutorialSprite:BaseActor;
	
	private var mTutorialHandSprite:BaseActor;
	private var mTutorialBagMoneySprite:BaseActor;
	private var mTutorialTicketMoneySprite:BaseActor;
	
	private var mCurrentState:Int;
	private var mInterval:NInterval;
	
	private var mBagInitX:Float;
	private var mMoneyInitX:Float;
	
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
		
		trace("ontutorialcreen");
		
		mCanvasTutorial = new Sprite();
		mCanvasEffect = new Sprite();
		mCanvasMouse = new Sprite();
		
		_canvas.addChild(mCanvasTutorial);
		_canvas.addChild(mCanvasEffect);
		_canvas.addChild(mCanvasMouse);
		
		mEffectManager = new EffectManager(mCanvasEffect);
		
		mBGSprite = new BaseActor("spMinigame02_bg", null, mCanvasTutorial, 0, 0);
		mBGMaskSprite = new BaseActor("spMinigame02_background_mask", null, mCanvasTutorial, 0, 0);
		mTutorialSprite = new BaseActor("spMinigame02_tutorial_text", null, mCanvasTutorial, 0, 0);
		
		mTutorialBagMoneySprite = new BaseActor("spMinigame02_tutorial_bag_money", null, mCanvasTutorial, 0, 0);
		mTutorialTicketMoneySprite = new BaseActor("spMinigame02_tutorial_ticket_money", null, mCanvasTutorial, 0, 0);
		mTutorialHandSprite = new BaseActor("spMinigame02_tutorial_mouseHand", null, mCanvasMouse, 0, 0);

		mTutorialBagMoneySprite.setX((Global.StageWidth / 2) - (mTutorialHandSprite.getWidth() / 2) - 100);
		mTutorialBagMoneySprite.setY((Global.StageWidth / 2) - (mTutorialHandSprite.getHeight() / 2));
		
		mTutorialTicketMoneySprite.setX((Global.StageWidth / 2) - (mTutorialTicketMoneySprite.getWidth() / 2) + 100);
		mTutorialTicketMoneySprite.setY((Global.StageWidth / 2) - (mTutorialTicketMoneySprite.getHeight() / 2));
		
		mTutorialSprite.setX((Global.StageWidth / 2) - (mTutorialSprite.getWidth() / 2));
		mTutorialSprite.setY((Global.StageHeight / 2) - (mTutorialSprite.getHeight() / 2) - 20);
		
		mTutorialHandSprite.setX((Global.StageWidth / 2) - (mTutorialHandSprite.getWidth() / 2));
		mTutorialHandSprite.setY((Global.StageWidth / 2) - (mTutorialHandSprite.getHeight() / 2) + 20);

		mTutorialSprite.setAlpha(0.0);
		
		mBagInitX = (Global.StageWidth / 2) - (mTutorialHandSprite.getWidth() / 2) - 100;
		mMoneyInitX = (Global.StageWidth / 2) - (mTutorialTicketMoneySprite.getWidth() / 2) + 100;
		
		mCurrentState = TutorialScreen.STATE_SHOW_TUTORIAL;
		
		trace("ontutorialcreen_2");
		
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
		trace("onfinish");
		mInterval = null;
		mCurrentState = TutorialScreen.STATE_DISAPPEAR_TUTORIAL;
	}
	
	private function onGoGame():Void {
		trace("gogame");
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
		
		trace("onupdate");
		mBGSprite.update(dt);
		mBGMaskSprite.update(dt);
		mTutorialSprite.update(dt);
		mEffectManager.update(dt);
		
		if (mTutorialHandSprite != null) { mTutorialHandSprite.update(dt); }
		if (mTutorialBagMoneySprite != null) { mTutorialBagMoneySprite.update(dt); }
		if (mTutorialTicketMoneySprite != null) { mTutorialTicketMoneySprite.update(dt); }
		
		switch(mCurrentState) {
		case TutorialScreen.STATE_SHOW_TUTORIAL:
			if (mTutorialSprite.getAlpha() >= 1.0) {
				mTutorialSprite.setAlpha(1.0);
				
				mCurrentState = TutorialScreen.STATE_MOUSE_LEFT;
			}
			else {
				mTutorialSprite.setAlpha(mTutorialSprite.getAlpha() + (0.0008 * dt));
			}
		case TutorialScreen.STATE_MOUSE_LEFT:
			var nx1:Float = mTutorialHandSprite.getX() - (0.15 * dt);
			mTutorialHandSprite.setX(nx1);
			
			if (nx1 <= mBagInitX) {
				mCurrentState = TutorialScreen.STATE_MOUSE_RIGHT;
				
				var effect:SpriteAndTextEffect = mEffectManager.createSpriteAndTextEffect(
					"spMinigame02_tutorial_check_secure", "spMinigame02_tutorial_check_secure",
					"spMinigame02_tutorial_score_500", null, 
					new Vector2D(mBagInitX + 20, mTutorialTicketMoneySprite.getY() + 7),
					new Vector2D( -20, -43));
				effect.DieWithAlpha(true);
				
				mEffectManager.createEffect(mBagInitX + 8, mTutorialTicketMoneySprite.getY() + 8,
					"spMinigame02_ani_effect_puff", "spMinigame02_ani_effect_puff");
				
				mTutorialBagMoneySprite.free();
				mTutorialBagMoneySprite = null;
			}
		case TutorialScreen.STATE_MOUSE_RIGHT:
			trace("state mouse right");
			var nx2:Float = mTutorialHandSprite.getX() + (0.15 * dt);
			mTutorialHandSprite.setX(nx2);
			
			if (nx2 >= mMoneyInitX) {
				trace("creating interval");
				mCurrentState = TutorialScreen.STATE_WAIT;
				mInterval = new NInterval(onFinishWait, 9000000);
				
				var effect2:SpriteAndTextEffect = mEffectManager.createSpriteAndTextEffect(
					"spMinigame02_tutorial_check_secure", "spMinigame02_tutorial_check_secure",
					"spMinigame02_tutorial_score_100", null, 
					new Vector2D(mMoneyInitX + 8, mTutorialTicketMoneySprite.getY() + 7),
					new Vector2D( -20, -43));
				effect2.DieWithAlpha(true);
				
				mEffectManager.createEffect(mMoneyInitX + 8, mTutorialTicketMoneySprite.getY() + 8,
					"spMinigame02_ani_effect_puff", "spMinigame02_ani_effect_puff");
				
				mTutorialTicketMoneySprite.free();
				mTutorialTicketMoneySprite = null;
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
		mTutorialHandSprite.free();
		
		if (mClickToContiue != null) {
			mClickToContiue.free();
		}
		
		mClickToContiue = null;
		
		if (mTutorialBagMoneySprite != null) {
			mTutorialBagMoneySprite.free();
		}
		
		if (mTutorialTicketMoneySprite != null) {
			mTutorialTicketMoneySprite.free();
		}
		
		mBGSprite.free();
		mBGMaskSprite.free();
		mTutorialSprite.free();
		mEffectManager.free();
		
		_canvas.removeChild(mCanvasEffect);
		_canvas.removeChild(mCanvasTutorial);
		
		mTutorialHandSprite = null;
		mTutorialBagMoneySprite = null;
		mTutorialTicketMoneySprite = null;
		
		mEffectManager = null;
		mBGSprite = null;
		mBGMaskSprite = null;
		mTutorialSprite = null;
		mInterval = null;
		
		super.destroy();
	}
}