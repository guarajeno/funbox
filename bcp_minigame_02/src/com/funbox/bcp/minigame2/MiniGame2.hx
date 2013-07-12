package com.funbox.bcp.minigame2;

import com.funbox.bcp.minigame2.engine.VerticalTouchEngine;
import com.funbox.bcp.minigame2.entities.BaseActor;
import com.funbox.bcp.minigame2.screens.GameHud;
import com.funbox.bcp.minigame2.screens.ScoreCardScreen;
import com.minigloop.display.AtlasSprite;
import com.minigloop.Game;
import com.minigloop.input.Mouse;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.Vector2D;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.display.Stage;

#if js 
import js.Lib;
#end

class MiniGame2 extends Game {

	private var mGhostGameMask:Sprite;
	private var mGameCanvas:Sprite;

	private var mGameHud:GameHud;
	private var mVTEngine:VerticalTouchEngine;
	
	private var mMouseX:Float;
	private var mMouseY:Float;
	private var mMousePressed:Bool;
	
	private var mLevelTime:Int;
	
	public function getMouseX():Float { return mMouseX; }
	public function getMouseY():Float { return mMouseY; }
	public function isMousePressed():Bool { return mMousePressed; }
	
	public function getVTEngine():VerticalTouchEngine { return mVTEngine; }
	public function getGameHud():GameHud { return mGameHud; }
	
	public function new(canvas:Sprite, gameHud:GameHud) {
		super(canvas);
		
		Global.minigame = this;
		
		mGameHud = gameHud;
		
		mMouseX = 0;
		mMouseY = 0;
		
		mLevelTime = 30100;
		mMousePressed = false;
		
		// mask created for listening the mouse events of the window
		mGhostGameMask = new Sprite();
		mGhostGameMask.graphics.beginFill(0xFFFFFF, 0);
		mGhostGameMask.graphics.drawRect(0, 0, 2000, 2000);
		mGhostGameMask.graphics.endFill();
		
		mGhostGameMask.addEventListener(MouseEvent.MOUSE_MOVE, onMouseHandler);
		mGhostGameMask.addEventListener(MouseEvent.MOUSE_DOWN, onMouseHandler);
		mGhostGameMask.addEventListener(MouseEvent.MOUSE_UP, onMouseHandler);
		mGhostGameMask.addEventListener(MouseEvent.MOUSE_OUT, onMouseHandler);
		mGhostGameMask.addEventListener(MouseEvent.ROLL_OUT, onMouseHandler);
		
		// create the game canvas
		mGameCanvas = new Sprite();
		_canvas.addChild(mGameCanvas);
		
		mVTEngine = new VerticalTouchEngine(this, mGameCanvas);
		
		// add to render
		Global.stage.addChild(mGhostGameMask);
	}
	
	private function onMouseHandler(e:MouseEvent):Void {
		switch(e.type) {
		case MouseEvent.MOUSE_MOVE:
			#if js
			mMouseX = e.localX - Lib.document.getElementById("banner").offsetLeft;
			mMouseY = e.localY - Lib.document.getElementById("banner").offsetTop;
			#end
			
			#if flash
			mMouseX = e.localX;
			mMouseY = e.localY;
			#end
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
	
	override public function update(dt:Int):Dynamic {
		mVTEngine.update(dt);
		
		mLevelTime -= dt;
		
		if (mLevelTime <= 0) { 
			mLevelTime = 0;
			mGameHud.SetTime(mLevelTime);
			
			Global.totalPoints = mGameHud.GetScore();
			ScreenManager.instance.gotoScreen(ScoreCardScreen);
		}
		else {
			mGameHud.SetTime(mLevelTime);
		}
	}
	
	override public function destroy():Dynamic {
		mVTEngine.free();
		mVTEngine = null;
		
		Global.stage.removeChild(mGhostGameMask);
		mGhostGameMask = null;
		
		_canvas.removeChild(mGameCanvas);
		mGameCanvas = null;
		
		
		super.destroy();
	}
}