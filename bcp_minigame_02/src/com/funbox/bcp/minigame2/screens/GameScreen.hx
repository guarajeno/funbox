package com.funbox.bcp.minigame2.screens;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.MiniGame2;
import com.minigloop.ui.Screen;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */
class GameScreen extends Screen
{
	private var _game:MiniGame2;
	private var _gameHud:GameHud;
	
	private var mGameCanvas:Sprite;
	private var mHudCanvas:Sprite;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		Global.stage = canvas.stage;
		
		mGameCanvas = new Sprite();
		mHudCanvas = new Sprite();
		
		_canvas.addChild(mGameCanvas);
		_canvas.addChild(mHudCanvas);
		
		_gameHud = new GameHud(mHudCanvas);
		_game = new MiniGame2(mGameCanvas, _gameHud);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_game.update(dt);
		_gameHud.update(dt);
	}
}