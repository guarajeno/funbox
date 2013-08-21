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
import nme.errors.Error;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;

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
	
	private var _loaderScreen:LoaderScreen;
	private var _isPaused:Bool;
	private var _isEnd:Bool;
	
	private var _descriptions:Array<String>;
	private var _description:TextField;

	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_loaderScreen = new LoaderScreen(canvas, onLoaderScreenLoaded);
		_isPaused = true;
	}
	
	private function onLoaderScreenLoaded() 
	{
		// common
		_loaderScreen.addAsset("img/common/web_common_button_home_normal.png", "web_common_button_home_normal");
		_loaderScreen.addAsset("img/common/web_common_button_home_over.png", "web_common_button_home_over");
		_loaderScreen.addAsset("img/common/web_common_button_close_normal.png", "web_common_button_close_normal");
		_loaderScreen.addAsset("img/common/web_common_button_close_over.png", "web_common_button_close_over");
		_loaderScreen.addAsset("img/common/web_common_button_episodes_normal.png", "web_common_button_episodes_normal");
		_loaderScreen.addAsset("img/common/web_common_button_episodes_over.png", "web_common_button_episodes_over");
		_loaderScreen.addAsset("img/common/web_common_button_parentsandteachers_normal.png", "web_common_button_parentsandteachers_normal");
		_loaderScreen.addAsset("img/common/web_common_button_parentsandteachers_over.png", "web_common_button_parentsandteachers_over");
		_loaderScreen.addAsset("img/common/web_common_button_characters_normal.png", "web_common_button_characters_normal");
		_loaderScreen.addAsset("img/common/web_common_button_characters_over.png", "web_common_button_characters_over");
		_loaderScreen.addAsset("img/common/web_common_button_doityourself_normal.png", "web_common_button_doityourself_normal");
		_loaderScreen.addAsset("img/common/web_common_button_doityourself_over.png", "web_common_button_doityourself_over");
		_loaderScreen.addAsset("img/common/web_common_button_store_normal.png", "web_common_buttonstore_normal");
		_loaderScreen.addAsset("img/common/web_common_button_store_over.png", "web_common_button_store_over");
		_loaderScreen.addAsset("img/common/web_common_button_news_normal.png", "web_common_button_news_normal");
		_loaderScreen.addAsset("img/common/web_common_button_news_over.png", "web_common_button_news_over");
		
		// my garden
		_loaderScreen.addAsset("img/mygarden/web_mygarden_floor01.png", "web_mygarden_floor01");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_city.png", "web_mygarden_city");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_tree_01.png", "web_mygarden_tree_01");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_tree_02.png", "web_mygarden_tree_02");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_tree_03.png", "web_mygarden_tree_03");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_house.png", "web_mygarden_house");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_buttonback_normal.png", "web_mygarden_buttonback_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_buttonback_over.png", "web_mygarden_buttonback_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_buttonnext_normal.png", "web_mygarden_buttonnext_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_buttonnext_over.png", "web_mygarden_buttonnext_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_textsuport.png", "web_mygarden_textsuport");
		
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_1_normal.png", "web_mygarden_button_1_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_2_normal.png", "web_mygarden_button_2_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_3_normal.png", "web_mygarden_button_3_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_4_normal.png", "web_mygarden_button_4_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_5_normal.png", "web_mygarden_button_5_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_6_normal.png", "web_mygarden_button_6_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_7_normal.png", "web_mygarden_button_7_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_8_normal.png", "web_mygarden_button_8_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_9_normal.png", "web_mygarden_button_9_normal");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_10_normal.png", "web_mygarden_button_10_normal");
		
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_1_over.png", "web_mygarden_button_1_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_2_over.png", "web_mygarden_button_2_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_3_over.png", "web_mygarden_button_3_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_4_over.png", "web_mygarden_button_4_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_5_over.png", "web_mygarden_button_5_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_6_over.png", "web_mygarden_button_6_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_7_over.png", "web_mygarden_button_7_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_8_over.png", "web_mygarden_button_8_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_9_over.png", "web_mygarden_button_9_over");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_button_10_over.png", "web_mygarden_button_10_over");
		
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_1.png", "web_mygarden_characters_1");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_2.png", "web_mygarden_characters_2");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_3.png", "web_mygarden_characters_3");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_4.png", "web_mygarden_characters_4");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_5.png", "web_mygarden_characters_5");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_6.png", "web_mygarden_characters_6");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_7.png", "web_mygarden_characters_7");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_8.png", "web_mygarden_characters_8");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_9.png", "web_mygarden_characters_9");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_10.png", "web_mygarden_characters_10");
		
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_1_name.png", "web_mygarden_characters_1_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_2_name.png", "web_mygarden_characters_2_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_3_name.png", "web_mygarden_characters_3_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_4_name.png", "web_mygarden_characters_4_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_5_name.png", "web_mygarden_characters_5_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_6_name.png", "web_mygarden_characters_6_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_7_name.png", "web_mygarden_characters_7_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_8_name.png", "web_mygarden_characters_8_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_9_name.png", "web_mygarden_characters_9_name");
		_loaderScreen.addAsset("img/mygarden/web_mygarden_characters_10_name.png", "web_mygarden_characters_10_name");
		
		_loaderScreen.load(init);
	}
	
	private function init() 
	{
		_loaderScreen.destroy();
		
		_isPaused = false;
		trace("is paused true");
		
		// descriptions
		_descriptions = [
			"Es una niña juguetona y aventurera que ama la naturaleza. Representa el amor y nos recuerda la fuerza que llevamos en nuestro corazón para mejorar el mundo.",
			"Hermano mayor de Ania, es un niño genio que ama la tecnología. Representa la inteligencia y nos recuerda que hay que innovar para mejorar el mundo.",
			"Guardián de Meshi, y abuelo de Ania y Kin. Es un shaman amazónico que conoce mucho sobre plantas. Representa la sabiduría y nos recuerda el valor que tienen los adultos mayores y las culturas originarias para mejorar el mundo.",
			"Es el único árbol que produce semillas y flores de todas las plantas del mundo. Ella representa la vida y nos recuerda que somos hermanos con la naturaleza y hay que protegerla.",
			"",
			"Es una mariposa con una alita diferente. Representa la aceptación. Nos recuerda que todos tenemos algo especial para hacer la diferencia.",
			"Es una flor sensible y mejor amiga de Ania. Representa la compasión. Nos recuerda que con valor y determinación podemos lograr nuestros objetivos.",
			"Es un guacamayo amigo de Tawa que vive en las ramas de Meshi. Representa la buena comunicación y nos recuerda que hay que compartir con otros para mejorar el mundo.",
			"Es un pescadito que vive en el estanque del jardín. Representa la inclusión y nos recuerda que hay que ahorrar agua, y cuidar nuestros ríos, lagos y mares.",
			"Es el monstruo de la compostera del jardín. Representa el reciclaje de desechos orgánicos y nos recuerda que todos podemos vivir generando un impacto positivo en nuestro entorno."
		];
		
		_elementsCanvas = new Sprite();
		_charactersCanvas = new Sprite();
		_buttonsCanvas = new Sprite();
		_menuCanvas = new Sprite();
		
		_canvas.addChild(_elementsCanvas);
		_canvas.addChild(_charactersCanvas);
		_canvas.addChild(_buttonsCanvas);
		_canvas.addChild(_menuCanvas);
		
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
			"web_mygarden_buttonback_over",
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
			"web_mygarden_buttonnext_over",
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
		_support.x = 1300;
		_support.y = -_support.height;
		_buttonsCanvas.addChild(_support);
		
		_description = new TextField();
		_description.width = 200;
		_description.x = 1355;
		_description.y = -_description.height;
		_description.text = "";
		_description.multiline = true;
		_description.wordWrap = true;
		_description.defaultTextFormat = new TextFormat("Arial", 13, 0x000000, false, false, false, "", "", TextFormatAlign.CENTER);		
		_canvas.addChild(_description);
		
		_menuBar = new MenuBar(_menuCanvas);
		
		_index = 0;
		Actuate.timer(1.5).onComplete(showCharacter, [0]);
	}
	
	private function showCharacter(index:Int) 
	{
		if (_isEnd) return;
		
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
		_title.x = 1450 - _title.width / 2;
		_title.y = -_title.height;
		
		_description.text = _descriptions[index];
		_description.y = -_description.height;
		
		_buttonsCanvas.addChild(_title);
		
		Actuate.tween(_character, 0.8, { scaleY: 0.98 } ).ease(Elastic.easeOut).onUpdate(repositionCharacter);
		Actuate.tween(_support, 0.8, { y: -120 } ).ease(Elastic.easeOut);
		Actuate.tween(_title, 0.8, { y: 200 } ).ease(Elastic.easeOut);
		Actuate.tween(_description, 0.8, { y: 285 } ).ease(Elastic.easeOut);
		
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
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		
		_menuBar.destroy();
		/*_isEnd = true;
		
		var i:Int;
		for (i in 0...10)
		{
			_buttons[i].end(0);
		}
		
		_city.end(0);
		_tree_1.end(0);
		_tree_2.end(0);
		_tree_3.end(0);
		_house.end(0);
		_floor.end(0);
		_prev.end(0);
		_next.end(0);
		
		_buttonsCanvas.removeChild(_title);
		_buttonsCanvas.removeChild(_support);
		_charactersCanvas.removeChild(_character);*/
	}
	
	override public function update(dt:Int):Dynamic 
	{
		if (_isEnd) return;
		
		try {
			_loaderScreen.update(dt);
		}
		catch (e:Error)
		{
			
		}
		
		if (_isPaused) return;
		
		_menuBar.update(dt);
		_prev.update(dt);
		_next.update(dt);
		
		var i:Int;
		for (i in 0...10)
		{
			_buttons[i].update(dt);
		}
	}
}