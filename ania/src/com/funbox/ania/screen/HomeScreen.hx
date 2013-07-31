package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.popup.VideoPopup;
import com.funbox.ania.screen.LoaderScreen;
import com.minigloop.display.AtlasSprite;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class HomeScreen extends Screen
{
	// menu bar
	private var _menuBar:MenuBar;
	
	// images
	private var _background:Bitmap;
	
	// popups
	private var _floor:ImagePopup;
	private var _city:ImagePopup;
	private var _meshi:ImagePopup;
	private var _tree_1:ImagePopup;
	private var _tree_2:ImagePopup;
	private var _house:ImagePopup;
	private var _doit:ImagePopup;
	private var _video:ImagePopup;
	private var _data:ImagePopup;
	private var _enter:ButtonPopup;
	
	private var _semicoptero:AtlasSprite;
	
	private var _loaderScreen:LoaderScreen;
	private var _isPaused:Bool;
	private var _isAssetsLoaded:Bool;
	private var _isDataLoaded:Bool;
	private var _news:Bitmap;
	private var _t:Float = 0;
	
	public function new(canvas:Sprite) 
	{
		
		super(canvas);
		
		_loaderScreen = new LoaderScreen(canvas, onLoaderScreenLoaded);
		_isPaused = true;
	}
	
	private function onLoaderScreenLoaded() 
	{
		// home
		AssetsLoader.addAsset("img/home/web_home_floor.png", "web_home_floor");
		AssetsLoader.addAsset("img/home/web_home_city.png", "web_home_city");
		AssetsLoader.addAsset("img/home/web_home_tree01.png", "web_home_tree01");
		AssetsLoader.addAsset("img/home/web_home_tree02.png", "web_home_tree02");
		AssetsLoader.addAsset("img/home/web_home_house.png", "web_home_house");
		AssetsLoader.addAsset("img/home/web_home_doityourself.png", "web_home_doityourself");
		AssetsLoader.addAsset("img/home/web_home_video.png", "web_home_video");
		AssetsLoader.addAsset("img/home/web_home_tadata.png", "web_home_tadata");
		AssetsLoader.addAsset("img/home/web_home_tadata_enter.png", "web_home_tadata_enter");
		AssetsLoader.addAsset("img/home/web_home_meshi.png", "web_home_meshi");
		
		// common
		AssetsLoader.addAsset("img/common/web_common_videosupport.png", "web_common_videosupport");
		AssetsLoader.addAsset("img/common/web_common_button_home_normal.png", "web_common_button_home_normal");
		AssetsLoader.addAsset("img/common/web_common_button_home_over.png", "web_common_button_home_over");
		AssetsLoader.addAsset("img/common/web_common_button_close_normal.png", "web_common_button_close_normal");
		AssetsLoader.addAsset("img/common/web_common_button_close_over.png", "web_common_button_close_over");
		AssetsLoader.addAsset("img/common/web_common_button_episodes_normal.png", "web_common_button_episodes_normal");
		AssetsLoader.addAsset("img/common/web_common_button_episodes_over.png", "web_common_button_episodes_over");
		AssetsLoader.addAsset("img/common/web_common_button_parentsandteachers_normal.png", "web_common_button_parentsandteachers_normal");
		AssetsLoader.addAsset("img/common/web_common_button_parentsandteachers_over.png", "web_common_button_parentsandteachers_over");
		AssetsLoader.addAsset("img/common/web_common_button_characters_normal.png", "web_common_button_characters_normal");
		AssetsLoader.addAsset("img/common/web_common_button_characters_over.png", "web_common_button_characters_over");
		AssetsLoader.addAsset("img/common/web_common_button_doityourself_normal.png", "web_common_button_doityourself_normal");
		AssetsLoader.addAsset("img/common/web_common_button_doityourself_over.png", "web_common_button_doityourself_over");
		AssetsLoader.addAsset("img/common/web_common_button_store_normal.png", "web_common_buttonstore_normal");
		AssetsLoader.addAsset("img/common/web_common_button_store_over.png", "web_common_button_store_over");
		AssetsLoader.addAsset("img/common/web_common_button_news_normal.png", "web_common_button_news_normal");
		AssetsLoader.addAsset("img/common/web_common_button_news_over.png", "web_common_button_news_over");
		AssetsLoader.addAsset("img/common/web_common_tadata.png", "web_common_tadata");
		AssetsLoader.addAsset("img/common/animations/web_common_animations_loader.png", "web_common_animations_loader");
		AssetsLoader.addAsset("img/home/web_home_news_support.png", "web_home_news_support");
		
		AssetsLoader.load(onAssetsLoaded);
		
		DataLoader.addData("img/common/animations/web_common_animations_loader.json", "web_common_animations_loader");
		DataLoader.load(onDataLoaded);
		
		update(0);
	}
	
	private function onAssetsLoaded() 
	{
		_isAssetsLoaded = true;
	}
	
	private function onDataLoaded() 
	{
		_isDataLoaded = true;
	}
	
	private function preInit() 
	{
		_loaderScreen.animate(init);
	}
	
	private function init() 
	{
		_loaderScreen.destroy();
		
		_isPaused = false;
		
		// background
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		// popups
		_city = new ImagePopup(_canvas, "web_home_city", 0, 480, 0.5);
		_tree_1 = new ImagePopup(_canvas, "web_home_tree01", -350, 500, 0.5);
		_floor = new ImagePopup(_canvas, "web_home_floor", 0, 670, 0);
		_tree_2 = new ImagePopup(_canvas, "web_home_tree02", 610, 650, 0.5);
		_house = new ImagePopup(_canvas, "web_home_house", -500, 580, 1.2);
		_doit = new ImagePopup(_canvas, "web_home_doityourself", -300, 580, 1.2);
		_meshi = new ImagePopup(_canvas, "web_home_meshi", 490, 500, 1.0);
		_video = new ImagePopup(_canvas, "web_home_video", -50, 520, 1.2);
		
		_enter = new ButtonPopup(
			_canvas,
			240,
			690,
			"web_home_tadata_enter",
			"web_home_tadata_enter",
			"web_home_tadata_enter",
			0,
			onEnter_Click
		);
		
		_data = new ImagePopup(_canvas, "web_home_tadata", 330, 680, 0);
		
		_semicoptero = new AtlasSprite(_canvas, "web_common_animations_loader", "web_common_animations_loader");
		_semicoptero.position.x = 0;
		_semicoptero.position.y = 150;
		
		Actuate.tween(_semicoptero.position, 1, { x: 180 } ).ease(Linear.easeNone).delay(0);
		
		_news = AssetsLoader.getAsset("web_home_news_support");
		_news.x = 1600;
		_news.y = 180;
		_canvas.addChild(_news);
		
		Actuate.tween(_news, 1, { x: 1400 } ).ease(Linear.easeNone).delay(0);
		
		_menuBar = new MenuBar(_canvas);
	}
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		// background
		//_background = AssetsLoader.getAsset("web_common_background");
		//_canvas.addChild(_background);
		
		// popups
		_city.end(0.3);
		_floor.end(0.3);
		_tree_1.end(0.3);
		_tree_2.end(0.3);
		_meshi.end(0.3);
		_house.end(0);
		_doit.end(0);
		_video.end(0);
		
		_enter.end(0);
		_data.end(0);
		
		_canvas.removeChild(_news);
		_semicoptero.destroy();
		
		//_menuBar.end();
	}
	
	private function onEnter_Click() 
	{
		
	}
	
	private function onPrevious_Click() 
	{
		trace("click en previous");
		ScreenManager.showPopup(VideoPopup);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		if (_isAssetsLoaded && _isDataLoaded && _isPaused)
		{
			preInit();
			_isPaused = false;
		}
		
		if (_isPaused) return;
		
		_enter.update(dt);
		_menuBar.update(dt);
		_semicoptero.update(dt);
		
		_news.y = 150 + 10 * Math.sin(_t);
		
		_t += 0.06;
		if (_t >= 3.14) _t = 0;
		
		super.update(dt);
	}
}