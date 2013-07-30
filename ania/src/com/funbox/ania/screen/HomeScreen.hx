package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.popup.VideoPopup;
import com.funbox.ania.screen.LoaderScreen;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
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
	
	private var _loaderScreen:LoaderScreen;
	private var _isPaused:Bool;
	
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
		
		AssetsLoader.load(preInit);
		
		update(0);
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
		_tree_1 = new ImagePopup(_canvas, "web_home_tree01", -350, 500, 0.7);
		_floor = new ImagePopup(_canvas, "web_home_floor", 0, 670, 0);
		_tree_2 = new ImagePopup(_canvas, "web_home_tree02", 610, 650, 0.7);
		_house = new ImagePopup(_canvas, "web_home_house", -500, 580, 0.9);
		_doit = new ImagePopup(_canvas, "web_home_doityourself", -300, 580, 1.0);
		_meshi = new ImagePopup(_canvas, "web_home_meshi", 490, 500, 0.7);
		_video = new ImagePopup(_canvas, "web_home_video", -50, 550, 1.2);
		
		_enter = new ButtonPopup(
			_canvas,
			210,
			660,
			"web_home_tadata_enter",
			"web_home_tadata_enter",
			"web_home_tadata_enter",
			1.5,
			onEnter_Click
		);
		
		_data = new ImagePopup(_canvas, "web_home_tadata", 300, 650, 1.5);
		
		_menuBar = new MenuBar(_canvas);
	}
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		// background
		//_background = AssetsLoader.getAsset("web_common_background");
		//_canvas.addChild(_background);
		
		// popups
		_city.end(1.2);
		_floor.end(1.2);
		_tree_1.end(1);
		_tree_2.end(1);
		_meshi.end(1);
		_house.end(0.7);
		_doit.end(0.5);
		_video.end(0);
		
		//_enter.end(0);
		//_data.end(0);
		
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
		if (_isPaused) return;
		_enter.update(dt);
		_menuBar.update(dt);
		
		super.update(dt);
	}
}