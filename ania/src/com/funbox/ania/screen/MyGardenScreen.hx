package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.CharacterButton;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.popup.VideoPopup;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;

/**
 * ...
 * @author guarajeno
 */

class MyGardenScreen extends Screen
{
	// menu bar
	private var _menuBar:MenuBar;
	
	// images
	private var _background:Bitmap;
	
	// elements
	private var _floor:ImagePopup;
	private var _city:ImagePopup;
	private var _tree_1:ImagePopup;
	private var _tree_2:ImagePopup;
	private var _tree_3:ImagePopup;
	private var _house:ImagePopup;
	
	// gallery
	private var _index:Int;
	private var _elementsCanvas:Sprite;
	private var _charactersCanvas:Sprite;
	private var _buttonsCanvas:Sprite;
	private var _menuCanvas:Sprite;
	private var _prev:ButtonPopup;
	private var _next:ButtonPopup;
	private var _buttons:Array<CharacterButton>;
	private var _character:Bitmap;
	private var _support:Bitmap;
	private var _title:Bitmap;
	private var _text:TextField;

	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_elementsCanvas = new Sprite();
		_charactersCanvas = new Sprite();
		_buttonsCanvas = new Sprite();
		_menuCanvas = new Sprite();
		
		canvas.addChild(_elementsCanvas);
		canvas.addChild(_charactersCanvas);
		canvas.addChild(_buttonsCanvas);
		canvas.addChild(_menuCanvas);
		
		// background
		_background = AssetsLoader.getAsset("web_common_background");
		_elementsCanvas.addChild(_background);
		
		// popups
		_city = new ImagePopup(_elementsCanvas, "web_mygarden_city", 0, 570, 0.5);
		_tree_1 = new ImagePopup(_elementsCanvas, "web_mygarden_tree_01", -500, 470, 0.7);
		_tree_2 = new ImagePopup(_elementsCanvas, "web_mygarden_tree_02", 500, 490, 0.7);
		_tree_3 = new ImagePopup(_elementsCanvas, "web_mygarden_tree_03", -50, 290, 0.7);
		_house = new ImagePopup(_elementsCanvas, "web_mygarden_house", -700, 570, 0.9);
		_floor = new ImagePopup(_elementsCanvas, "web_mygarden_floor01", 0, 670, 0);
		
		// gallery
		_prev = new ButtonPopup(
			_buttonsCanvas,
			-350,
			580,
			"web_mygarden_buttonback_normal",
			"web_mygarden_buttonback_normal",
			"web_mygarden_buttonback_over",
			1.1,
			onPrev_Click
		);
		
		_prev.setCollision(110, 20, 120, 100);
		
		_next = new ButtonPopup(
			_buttonsCanvas,
			300,
			580,
			"web_mygarden_buttonnext_normal",
			"web_mygarden_buttonnext_normal",
			"web_mygarden_buttonnext_over",
			1.1,
			onNext_Click
		);
		
		_next.setCollision(20, 20, 120, 100);
		
		// character buttons
		_buttons = [];
		var button:CharacterButton;
		
		var i:Int;
		
		for (i in 0...10)
		{
			if (i == 4)
			{
				button = new CharacterButton(
					_buttonsCanvas,
					-440 + i * 100,
					722,
					"web_mygarden_button_" + (i + 1) + "_normal",
					"web_mygarden_button_" + (i + 1) + "_over",
					"web_mygarden_button_" + (i + 1) + "_over",
					1.1,
					onCharacter_Click,
					i
				);
				
				button.setCollision(10, 20, 80, 80);
			}
			else if (i == 5)
			{
				button = new CharacterButton(
					_buttonsCanvas,
					-430 + i * 100,
					704,
					"web_mygarden_button_" + (i + 1) + "_normal",
					"web_mygarden_button_" + (i + 1) + "_over",
					"web_mygarden_button_" + (i + 1) + "_over",
					1.1,
					onCharacter_Click,
					i
				);
				
				button.setCollision(0, 50, 80, 80);
			}
			else
			{
				button = new CharacterButton(
					_buttonsCanvas,
					-440 + i * 100,
					730,
					"web_mygarden_button_" + (i + 1) + "_normal",
					"web_mygarden_button_" + (i + 1) + "_over",
					"web_mygarden_button_" + (i + 1) + "_over",
					1.1,
					onCharacter_Click,
					i
				);
				
				button.setCollision(0, 0, 80, 80);
			}
			
			_buttons.push(button);
		}
		
		_support = AssetsLoader.getAsset("web_mygarden_textsuport");
		_support.x = 1000;
		_support.y = -_support.height;
		_buttonsCanvas.addChild(_support);
		
		_menuBar = new MenuBar(_menuCanvas);
		
		_index = 0;
		Actuate.timer(1.5).onComplete(showCharacter, [_index]);
	}
	
	private function showCharacter(index:Int) 
	{
		if (_charactersCanvas.contains(_character))
		{
			_charactersCanvas.removeChild(_character);
		}
		
		_character = AssetsLoader.getAsset("web_mygarden_characters_" + (index + 1));
		_character.x = Global.stage.stageWidth / 2 - _character.width / 2 - 70;
		_character.y = 650 - _character.height;
		_character.scaleY = 0;
		
		_support.y = -_support.height;
		
		if (_title != null && _buttonsCanvas.contains(_title))
		{
			_buttonsCanvas.removeChild(_title);
			_title = null;
		}
		
		_title = AssetsLoader.getAsset("web_mygarden_characters_" + (index + 1) + "_name");
		_title.x = 1155 - _title.width / 2;
		_title.y = -_title.height;
		
		_buttonsCanvas.addChild(_title);
		
		Actuate.tween(_character, 0.5, { scaleY: 0.98 } ).ease(Elastic.easeOut).onUpdate(repositionCharacter);
		Actuate.tween(_support, 0.5, { y: -120 } ).ease(Elastic.easeOut);
		Actuate.tween(_title, 0.5, { y: 200 } ).ease(Elastic.easeOut);
		
		_charactersCanvas.addChild(_character);
	}
	
	private function repositionCharacter() 
	{
		_character.y = 650 - _character.height;
	}
	
	private function onCharacter_Click(index:Int) 
	{
		showCharacter(index);
	}
	
	private function onPrev_Click() 
	{
		_index--;
		
		if (_index < 0)
		{
			_index = 9;
		}
		
		showCharacter(_index);
	}
	
	private function onNext_Click() 
	{
		_index++;
		
		if (_index > 9)
		{
			_index = 0;
		}
		
		showCharacter(_index);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_menuBar.update(dt);
		_prev.update(dt);
		_next.update(dt);
		
		var i:Int;
		for (i in 0...10)
		{
			_buttons[i].update(dt);
		}
		
		super.update(dt);
	}
}