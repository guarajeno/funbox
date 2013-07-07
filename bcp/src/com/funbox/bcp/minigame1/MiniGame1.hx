package com.funbox.bcp.minigame1;
import com.funbox.bcp.minigame1.components.FacebookBar;
import com.funbox.bcp.minigame1.components.Hud;
import com.funbox.bcp.minigame1.entities.Black;
import com.funbox.bcp.minigame1.entities.Enemy;
import com.funbox.bcp.minigame1.entities.Virus;
import com.funbox.bcp.minigame1.entities.Player;
import com.funbox.bcp.minigame1.screens.ScoreCardScreen;
import com.funbox.bcp.minigame1.screens.ShowPointsScreen;
import com.minigloop.display.AtlasSprite;
import com.minigloop.display.VisualObject;
import com.minigloop.Game;
import com.minigloop.input.Mouse;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.Vector2D;
import haxe.remoting.ExternalConnection;
import nme.errors.Error;
import nme.external.ExternalInterface;
import nme.geom.Rectangle;
#if js 
import js.Lib;
#end
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;

/**
 * ...
 * @author 
 */

class MiniGame1 extends Game
{
	private var _timelapse:Int = 0;
	
	private var _player:Player;
	private var _enemies:Array <Enemy>;
	private var _hotspot:Sprite;
	private var _mouseX:Float = 0;
	private var _mouseY:Float = 0;
	
	private var _playerCanvas:Sprite;
	private var _enemiesCanvas:Sprite;
	private var _enemiesMask:Sprite;
	
	private var _hud:Hud;
	private var _timeAux:Int = 0;
	//private var _fbBar:FacebookBar;
	
	public function new(canvas:Sprite)
	{
		super(canvas);
		
		_canvas.addChild(AssetsLoader.getAsset("background_1"));
		
		_enemiesCanvas = new Sprite();
		_canvas.addChild(_enemiesCanvas);
		
		_canvas.addChild(AssetsLoader.getAsset("background_2"));
		var score:Bitmap = AssetsLoader.getAsset("background_score");
		score.x = 50;
		score.y = 50;
		_canvas.addChild(score);
		
		_playerCanvas = new Sprite();
		_canvas.addChild(_playerCanvas);
		
		_hotspot = new Sprite();
		_hotspot.graphics.beginFill(0xFFFFFF, 0.01);
		_hotspot.graphics.drawRect(0, 0, 2000, 2000);
		_hotspot.graphics.endFill();
		_canvas.addChild(_hotspot);
		
		_hud = new Hud(canvas);
		_hud.position.x = 50;
		_hud.position.y = 50;
		//_canvas.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		
		_player = new Player(_playerCanvas);
		_enemies = new Array<Enemy>();
		
		Global.totalLives = 3;
		Global.totalPoints = 0;
		Global.totalTime = 30000;
	}

	private function onMouseMove(e:MouseEvent):Void 
	{
		//#if js
		//_mouseX = e.localX - Lib.document.getElementById("banner").offsetLeft;
		//#end
		//
		//trace(e.localX);
		//trace(Lib.document.getElementById("banner"));
		//trace(Lib.document.getElementById("banner").offsetLeft);
		//
		//#if flash
		//_mouseX = e.localX;
		//#end
	}
	
	override public function update(dt:Int):Dynamic 
	{
		#if js
		_mouseX = Mouse.position.x - Lib.document.getElementById("banner").offsetLeft;
		#end
		
		#if flash
		_mouseX = Mouse.position.x;
		#end
		
		if (_isPaused) return;
		
		Global.totalPoints += Std.int(dt / 10);
		Global.totalTime -= dt;
		
		if (Global.totalTime <= 0)
		{
			Global.totalTime = 0;
			
			trace("on send score");
			#if js
			try {
				Lib.eval("onSendScore(" + Global.totalPoints + ")");
			}
			catch (e:Error)
			{
				
			}
			#end
			ScreenManager.instance.gotoScreen(ShowPointsScreen);
		}
		
		_hud.setTime(Std.string(Std.int(Global.totalTime / 1000)));
		_hud.setPoints(Std.string(Std.int(Global.totalPoints / 1)));
		
		// enemy factory
		_timelapse += dt;
		if (_timelapse >= Global.enemyFrequency)
		{
			_timelapse = 0;
			createEnemy();
		}
		
		// player follow mouse
		_player.position.x += (_mouseX - _player.position.x) / 4 - 10;
		_player.position.y = 380;
		
		if (_player.position.x <= 40) _player.position.x = 40;
		if (_player.position.x >= 550) _player.position.x = 550;
		
		// check collisions
		var i:Int;
		for (i in 0...(_enemies.length - 1))
		{
			var r1:Rectangle = _enemies[i].collision.getBounds(_canvas);
			var r2:Rectangle = _player.collision.getBounds(_canvas);
			
			if (!_enemies[i].isHited && checkCollision(r1, r2))
			{
				_enemies[i].onHit();
				_player.onHit();
				
				_hud.setLifes(_player.numHits);
				
				Global.totalLives = 3 - _player.numHits;
				
				if (_player.numHits >= 3)
				{
					_player.setState("die");
				}
			}
		}
		
		// check dead
		if (_player.isDead)
		{
			destroy();
			trace("on send score");
			#if js
			try {
				Lib.eval("onSendScore(" + Global.totalPoints + ")");
			}
			catch (e:Error)
			{
				
			}
			#end
			ScreenManager.instance.gotoScreen(ScoreCardScreen);
		}
		
		i = 0;
		var total:Int = _enemies.length - 1;
		
		while (i <= total)
		{
			_enemies[i].update(dt);
			
			if (_enemies[i].isDead)
			{
				_enemies[i].destroy();
				_enemies.splice(i, 1);
				total--;
			}
			
			i++;
		}
		
		// updates
		_player.update(dt);
		_hud.update(dt);
	}
	
	function checkCollision(r1:Rectangle, r2:Rectangle):Bool
	{
		var dX:Float = Math.abs((r1.x + r1.width / 2) - (r2.x + r2.width / 2));
		var dY:Float = Math.abs((r1.y + r1.height/ 2) - (r2.y + r2.height / 2));
		
		if (2 * dX <= r1.width + r2.width && 2 * dY <= r1.height + r2.height)
		{
			return true;
		}
		
		return false;
	}
	
	private function createEnemy():Void
	{
		var enemy:Enemy;
		//var enemy2:Enemy;
		
		if (Math.random() > 0.5)
		{
			enemy = new Virus(_enemiesCanvas);
		}
		else
		{
			enemy = new Black(_enemiesCanvas);
		
		}
		
		//if (Math.random() > 0.5)
		//{
			//if (Math.random() > 0.5)
			//{
				//enemy2 = new Virus(_enemiesCanvas);
			//}
			//else
			//{
				//enemy2 = new Black(_enemiesCanvas);
			//}
			//
			//enemy2.position.y = 40;
			//enemy2.position.x = 30 + 166 * Std.int((85 + Math.random() * 485) / 166);
		//
			//_enemies.push(enemy2);
		//}
		
		enemy.position.y = 40;
		enemy.position.x = 40 + 120 * Std.int((Math.random() * 600) / 120);
		
		_enemies.push(enemy);
	}
	
	override public function destroy():Dynamic 
	{
		//_isPaused = true;
	}
}