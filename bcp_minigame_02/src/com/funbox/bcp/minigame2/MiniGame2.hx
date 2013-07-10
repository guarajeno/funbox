package com.funbox.bcp.minigame2;

import com.funbox.bcp.minigame2.engine.VerticalTouchEngine;
import com.funbox.bcp.minigame2.entities.BaseActor;
import com.minigloop.display.AtlasSprite;
import com.minigloop.Game;
import com.minigloop.input.Mouse;
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

	private var mVTEngine:VerticalTouchEngine;
	
	private var mMouseX:Float;
	private var mMouseY:Float;
	private var mMousePressed:Bool;
	
	public function getMouseX():Float { return mMouseX; }
	public function getMouseY():Float { return mMouseY; }
	public function isMousePressed():Bool { return mMousePressed; }
	
	public function getVTEngine():VerticalTouchEngine { return mVTEngine; }
	
	public function new(canvas:Sprite) {
		super(canvas);
		
		Global.minigame = this;
		Global.stage = _canvas.stage;
		
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
		_canvas.addChild(mGhostGameMask);
	}
	
	private function onMouseHandler(e:MouseEvent):Void {
		switch(e.type) {
		case MouseEvent.MOUSE_MOVE:
			#if js
			mMouseX = e.localX - Lib.document.getElementById("banner").offsetLeft;
			mMouseY = e.localY - Lib.document.getElementById("banner").offsetLeft;
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
	}
}