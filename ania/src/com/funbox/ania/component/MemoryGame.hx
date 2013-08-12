package com.funbox.ania.component;

import com.eclecticdesignstudio.motion.Actuate;
import com.funbox.ania.Global;
import com.funbox.ania.Global;
import com.funbox.ania.screen.Episode01Screen;
import com.funbox.ania.screen.Episode02Screen;
import com.funbox.ania.screen.HomeScreen;
import com.funbox.ania.screen.MyGardenScreen;
import com.minigloop.display.Button;
import com.minigloop.display.VisualObject;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import js.Lib;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author guarajeno
 */

class MemoryGame extends VisualObject
{
	private var STATE_NONE:String = "none";
	private var STATE_ONE:String = "one";
	private var STATE_TWO:String = "two";
	
	private var _background:Bitmap;
	
	// buttons
	private var _cards:Array<Bitmap>;
	private var _covers:Array<Button>;
	private var _urls:Array<String>;

	private var _selectedCover_1:Button;
	private var _selectedCover_1X:Float;
	private var _selectedCover_1Y:Float;
	private var _selectedCover_2:Button;
	private var _selectedCover_2X:Float;
	private var _selectedCover_2Y:Float;
	private var _state:String;
	
	private var _time:TextField;
	private var _scoreTF:TextField;
	private var _score:Int;
	private var _minutes:Int;
	private var _seconds:Float;
	private var _play:Button;
	private var _win:Button;
	private var _lock:Bitmap;
	private var _isLocked:Bool;
	private var _uncoveredCards:Float = 0;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_state = STATE_NONE;
		
		_background = AssetsLoader.getAsset("web_activity_support");
		_background.x = 520;
		_background.y = 230;
		_canvas.addChild(_background);
		
		_cards = new Array<Bitmap>();
		_covers = new Array<Button>();
		_urls = new Array<String>();
		
		var numbers:Array<Int> = [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5];
		numbers.sort(randomSort);
		
		var i:Int;
		
		for (i in 0...12)
		{
			var r:Int = numbers[i];
			var row:Int = Math.floor(i / 3);
			var col:Int = i % 3;
			
			var card:Bitmap = AssetsLoader.getAsset("web_activity_card0" + (r + 1));
			card.x = 650 + row * 160;
			card.y = 380 + col * 160;
			_canvas.addChild(card);
			
			var cover:Button = new Button(
				_canvas,
				"web_activity_cardclose",
				"web_activity_cardclose",
				"web_activity_cardclose",
				onCoverClick
			);
			
			cover.index = i;
			cover.setCollision(15, 15, 140, 140);
			cover.position.x = 650 + row * 160;
			cover.position.y = 380 + col * 160;
			
			_cards.push(card);
			_covers.push(cover);
			_urls.push("web_activity_card0" + (r + 1));
		}
		
		_minutes = 1;
		_seconds = 59;
		
		// time
		_time = new TextField();
		_time.x = 1365;
		_time.y = 410;
		
		_time.defaultTextFormat = new TextFormat("Arial", 40, 0xFFFFFF, true);
		_time.text = _minutes + ":" + ((Math.floor(_seconds) < 10) ? "0" + Math.floor(_seconds) : "" + Math.floor(_seconds));
		_canvas.addChild(_time);
		
		// score
		
		_score = 0;
		_scoreTF = new TextField();
		_scoreTF.x = 1365;
		_scoreTF.y = 560;
		
		_scoreTF.defaultTextFormat = new TextFormat("Arial", 40, 0xFFFFFF, true);
		_scoreTF.text = Std.string(_score);
		_canvas.addChild(_scoreTF);
		
		// lock
		_isLocked = true;
		_lock = AssetsLoader.getAsset("web_activity_support_lock");
		_lock.alpha = 0.9;
		_lock.x = 520;
		_lock.y = 230;
		_canvas.addChild(_lock);
		
		// play button
		_play = new Button(
			_canvas,
			"web_activity_play_normal",
			"web_activity_play_normal",
			"web_activity_play_over",
			onPlayClick
		);
		
		_play.position.x = 925;
		_play.position.y = -100;
		_play.setCollision(0, 0, 240, 120);
		Actuate.tween(_play.position, 0.5, { y: 550 } );
		
		_win = new Button(
			_canvas,
			"web_activity_youwin",
			"web_activity_youwin",
			"web_activity_youwin",
			onPlayClick
		);
		
		_win.position.x = 800;
		_win.position.y = -500;
		_win.setCollision(180, 170, 220, 50);
	}
	
	private function restartGame() 
	{
		_uncoveredCards = 0;
		_score = 0;
		_scoreTF.text = Std.string(_score);
		
		var numbers:Array<Int> = [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5];
		numbers.sort(randomSort);
		
		var i:Int;
		
		for (i in 0...12)
		{
			var r:Int = numbers[i];
			
			var row:Int = Math.floor(i / 3);
			var col:Int = i % 3;
			
			var card:Bitmap = _cards[i];
			card.x = 650 + row * 160;
			card.y = 380 + col * 160;
			
			var cover:Button = _covers[i];
			cover.position.x = 650 + row * 160;
			cover.position.y = 380 + col * 160;
		}
	}
	
	private function randomSort(x:Int, y:Int):Int
	{
		return Math.random() > 0.5 ? 1 : -1;
	}
	
	private function onPlayClick() 
	{
		restartGame();
		
		_minutes = 1;
		_seconds = 59;
		_time.text = _minutes + ":" + ((Math.floor(_seconds) < 10) ? "0" + Math.floor(_seconds) : "" + Math.floor(_seconds));
		
		_lock.visible = false;
		
		//_play.position.y = -100;
		Actuate.tween(_play.position, 0.5, { y: -100 } );
		//_win.position.y = -500;
		Actuate.tween(_win.position, 0.5, { y: -500 } );
		
		_isLocked = false;
	}
	
	function onCoverClick(button:Button) 
	{
		if (_state == STATE_TWO) return;
		
		switch(_state)
		{
			case STATE_NONE:
			{
				trace("none to one");
				_state = STATE_ONE;
				_selectedCover_1 = button;
				_selectedCover_1X = button.position.x;
				_selectedCover_1Y = button.position.y;
				_selectedCover_1.position.y = -400;
			}
			
			case STATE_ONE:
			{
				trace("one to two");
				_state = STATE_TWO;
				_selectedCover_2 = button;
				_selectedCover_2X = button.position.x;
				_selectedCover_2Y = button.position.y;
				_selectedCover_2.position.y = -400;
				
				if (_urls[_selectedCover_1.index] != _urls[_selectedCover_2.index])
				{
					Actuate.timer(0.8).onComplete(onTimerComplete);
				}
				else
				{
					onTimerComplete();
				}
			}
		}
	}
	
	private function onTimerComplete() 
	{
		if (_urls[_selectedCover_1.index] != _urls[_selectedCover_2.index])
		{
			_selectedCover_1.position.x = _selectedCover_1X;
			_selectedCover_1.position.y = _selectedCover_1Y;
			
			_selectedCover_2.position.x = _selectedCover_2X;
			_selectedCover_2.position.y = _selectedCover_2Y;
		}
		else
		{
			_score += 50;
			_scoreTF.text = Std.string(_score);
			_uncoveredCards += 2;
		}
		
		_state = STATE_NONE;
		
		if (_uncoveredCards == 12)
		{
			win();
		}
	}
	
	private function win() 
	{
		_isLocked = true;
		_lock.visible = true;
		//_win.position.y = 480;
		Actuate.tween(_win.position, 0.5, { y: 440 } );
		
		trace("saveScore(" + Global.userId + ", " + Global.gameId + ", " + _score + ", " + Math.floor(_minutes * 60 + _seconds) + ");");
		Lib.eval("saveScore(" + Global.userId + ", " + Global.gameId + ", " + _score + ", " + Math.floor(_minutes * 60 + _seconds) + ");");
		
		trace("win");
	}
	
	private function lose() 
	{
		_isLocked = true;
		_lock.visible = true;
		//_play.position.y = 550;
		Actuate.tween(_play.position, 0.5, { y: 550 } );
		
		trace("lose");
	}
	
	override public function update(dt:Int):Void 
	{
		var i:Int;
		for (i in 0...(_covers.length))
		{
			_covers[i].update(dt);
		}
		
		_play.update(dt);
		_win.update(dt);
		
		if (!_isLocked)
		{
			_seconds -= dt / 1000;
			
			if (_seconds < 0)
			{
				_seconds = 59;
				_minutes--;
				
				if (_minutes < 0)
				{
					_minutes = 1;
					lose();
				}
			}
			
			_time.text = _minutes + ":" + ((Math.floor(_seconds) < 10) ? "0" + Math.floor(_seconds) : "" + Math.floor(_seconds));
		}
	}
	
	public function destroy():Void
	{
		var i:Int;
		
		for (i in 0...(_covers.length))
		{
			_covers[i].destroy();
		}
		
		for (i in 0...(_cards.length))
		{
			_canvas.removeChild(_cards[i]);
		}
		
		_canvas.removeChild(_background);
	}
}