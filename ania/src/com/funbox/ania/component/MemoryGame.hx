package com.funbox.ania.component;

import com.eclecticdesignstudio.motion.Actuate;
import com.funbox.ania.Global;
import com.funbox.ania.screen.Episode01Screen;
import com.funbox.ania.screen.Episode02Screen;
import com.funbox.ania.screen.HomeScreen;
import com.funbox.ania.screen.MyGardenScreen;
import com.minigloop.display.Button;
import com.minigloop.display.VisualObject;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
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
	private var _minutes:Int;
	private var _seconds:Int;
	
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
		
		var i:Int;
		
		for (i in 0...12)
		{
			var r:Int = Math.floor(Math.random() * 6);
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
		
		_time = new TextField();
		_time.x = 1365;
		_time.y = 410;
		var format:TextFormat = new TextFormat("Arial", 40, 0xFFFFFF, true);
		_time.defaultTextFormat = format;
		_time.text = "3:00";
		_canvas.addChild(_time);
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
				//_selectedCover_1.visible = false;
				_selectedCover_1X = button.position.x;
				_selectedCover_1Y = button.position.y;
				_selectedCover_1.position.x = -300;
				_selectedCover_1.position.y = -300;
			}
			
			case STATE_ONE:
			{
				trace("one to two");
				_state = STATE_TWO;
				_selectedCover_2 = button;
				_selectedCover_2X = button.position.x;
				_selectedCover_2Y = button.position.y;
				_selectedCover_2.position.x = 0;
				_selectedCover_2.position.y = -100;
				
				Actuate.timer(1.2).onComplete(onTimerComplete);
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
		
		_state = STATE_NONE;
	}
	
	override public function update(dt:Int):Void 
	{
		var i:Int;
		for (i in 0...(_covers.length))
		{
			_covers[i].update(dt);
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