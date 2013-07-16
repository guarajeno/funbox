package com.funbox.bcp.minigame3.screens;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.MiniGame2;
import com.minigloop.ui.Screen;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */
class GameScreen extends Screen
{
	public static var instance:GameScreen = null;
	
	private var _game:MiniGame2;
	private var _gameHud:GameHud;
	
	private var _gameTransition:GameTransitionPopupScreen;
	
	private var mGameCanvas:Sprite;
	private var mHudCanvas:Sprite;
	private var mFrontCanvas:Sprite;
	
	private var mPausedGame:Bool;
	
	public function isPausedGame():Bool { return mPausedGame; }
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		instance = this;

		mGameCanvas = new Sprite();
		mHudCanvas = new Sprite();
		mFrontCanvas = new Sprite();
		
		_canvas.addChild(mGameCanvas);
		_canvas.addChild(mHudCanvas);
		_canvas.addChild(mFrontCanvas);
		
		_gameHud = new GameHud(mHudCanvas);
		_game = new MiniGame2(mGameCanvas, _gameHud);
		
		_gameTransition = new GameTransitionPopupScreen(mFrontCanvas, onFinishTransition);
		
		mPausedGame = true;
		
		// update to draw
		_gameHud.update(33);
		_game.update(33);
	}
	
	private function onFinishTransition():Void {
		SoundManager.play("bgm_3", true);
		
		_gameTransition.free();
		_gameTransition = null;
		
		mPausedGame = false;
	}
	
	override public function update(dt:Int):Dynamic {
		if (_gameTransition != null) { _gameTransition.update(dt); }
		
		if (!mPausedGame) {
			_gameHud.update(dt);
			_game.update(dt);
		}
	}
	
	override public function destroy():Dynamic {
		if (_gameTransition != null) { 
			_gameTransition.free();
		}
		
		_game.destroy();
		_game = null;
		
		_gameHud.free();
		_gameHud = null;
	
		_canvas.removeChild(mGameCanvas);
		_canvas.removeChild(mHudCanvas);
		_canvas.removeChild(mFrontCanvas);
		
		mGameCanvas = null;
		mHudCanvas = null;
		mFrontCanvas = null;
		
		super.destroy();
	}
}