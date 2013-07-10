package com.funbox.bcp.minigame2.screens;
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
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_game = new MiniGame2(canvas);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_game.update(dt);
	}
}