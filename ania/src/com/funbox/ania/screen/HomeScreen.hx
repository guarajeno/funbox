package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.Seed;
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
	private var _meshi:ButtonPopup;
	private var _tree_1:ImagePopup;
	private var _tree_2:ImagePopup;
	private var _house:ImagePopup;
	private var _doit:ImagePopup;
	private var _video:ButtonPopup;
	private var _data:AtlasSprite;
	private var _enter:ButtonPopup;
	private var _cloud:Bitmap;
	
	private var _semicoptero:AtlasSprite;
	
	private var _loaderScreen:LoaderScreen;
	private var _isPaused:Bool;
	private var _news:Bitmap;
	private var _tNews:Float = 0;
	private var _tCloud:Float = 0;
	private var _tMeshi:Float = 0;
	private var _isMeshiAnimating:Bool = false;
	
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_loaderScreen = new LoaderScreen(canvas, onLoaderScreenLoaded);
		_isPaused = true;
	}
	
	private function onLoaderScreenLoaded() 
	{
		// home
		_loaderScreen.addAsset("img/home/web_home_floor.png", "web_home_floor");
		_loaderScreen.addAsset("img/home/web_home_city.png", "web_home_city");
		_loaderScreen.addAsset("img/home/web_home_tree01.png", "web_home_tree01");
		_loaderScreen.addAsset("img/home/web_home_tree02.png", "web_home_tree02");
		_loaderScreen.addAsset("img/home/web_home_house.png", "web_home_house");
		_loaderScreen.addAsset("img/home/web_home_doityourself.png", "web_home_doityourself");
		_loaderScreen.addAsset("img/home/web_home_video.png", "web_home_video");
		_loaderScreen.addAsset("img/home/web_home_tadata.png", "web_home_tadata");
		_loaderScreen.addAsset("img/home/web_home_tadata_enter.png", "web_home_tadata_enter");
		_loaderScreen.addAsset("img/home/web_home_meshi.png", "web_home_meshi");
		_loaderScreen.addAsset("img/home/web_home_news_support.png", "web_home_news_support");
		_loaderScreen.addAsset("img/home/web_home_seed.png", "web_home_seed");
		
		// common
		_loaderScreen.addAsset("img/common/web_common_videosupport.png", "web_common_videosupport");
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
		_loaderScreen.addAsset("img/common/web_common_tadata.png", "web_common_tadata");
		_loaderScreen.addAsset("img/common/web_common_cloud_01.png", "web_common_cloud_01");
		_loaderScreen.addAsset("img/common/animations/web_common_animations_loader.png", "web_common_animations_loader");
		_loaderScreen.addAsset("img/common/animations/web_common_animations_tadata.png", "web_common_animations_tadata");
		
		_loaderScreen.addData("img/common/animations/web_common_animations_loader.json", "web_common_animations_loader");
		_loaderScreen.addData("img/common/animations/web_common_animations_tadata.json", "web_common_animations_tadata");
		_loaderScreen.load(init);
	}
	
	private function init() 
	{
		_loaderScreen.destroy();
		
		_isPaused = false;
		
		// background
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		_cloud = AssetsLoader.getAsset("web_common_cloud_01");
		_cloud.x = 800;
		_cloud.y = 190;
		_canvas.addChild(_cloud);
		
		// popups
		_city = new ImagePopup(_canvas, "web_home_city", 0, 480, 1);
		_tree_1 = new ImagePopup(_canvas, "web_home_tree01", -350, 500, 1.5);
		_floor = new ImagePopup(_canvas, "web_home_floor", 0, 670, 0);
		_tree_2 = new ImagePopup(_canvas, "web_home_tree02", 610, 650, 1.5);
		_house = new ImagePopup(_canvas, "web_home_house", -500, 580, 2);
		_doit = new ImagePopup(_canvas, "web_home_doityourself", -300, 580, 2.5);
		
		_meshi = new ButtonPopup(
			_canvas,
			490,
			500,
			"web_home_meshi",
			"web_home_meshi",
			"web_home_meshi",
			2.2,
			null
		);
		
		_meshi.setCollision(270, 0, 450, 400);
		
		_meshi.onMouseOver = function() {
			_isMeshiAnimating = true;
		};
		
		_meshi.onMouseOut = function() {
			_isMeshiAnimating = false;
		};
		
		_video = new ButtonPopup(
			_canvas,
			-50,
			520,
			"web_home_video",
			"web_home_video",
			"web_home_video",
			3,
			onVideoClick
		);
		
		_video.setCollision(110, 0, 400, 220);
		
		_enter = new ButtonPopup(
			_canvas,
			240,
			690,
			"web_home_tadata_enter",
			"web_home_tadata_enter",
			"web_home_tadata_enter",
			2.5,
			onEnter_Click
		);
		
		_data = new AtlasSprite(
			_canvas,
			"web_common_animations_tadata",
			"web_common_animations_tadata"
		);
		
		_data.position.x = 1300;
		_data.position.y = 1000;
		
		Actuate.tween(_data.position, 0.8, { y: 570 } ).delay(2.5);
		
		_semicoptero = new AtlasSprite(
			_canvas,
			"web_common_animations_loader",
			"web_common_animations_loader"
		);
		
		_semicoptero.position.x = 0;
		_semicoptero.position.y = 150;
		
		Actuate.tween(_semicoptero.position, 1, { x: 180 } ).ease(Linear.easeNone).delay(0);
		
		_news = AssetsLoader.getAsset("web_home_news_support");
		_news.x = 1700;
		_news.y = 180;
		_canvas.addChild(_news);
		
		Actuate.tween(_news, 1, { x: 1400 } ).ease(Linear.easeNone).delay(0);
		
		_menuBar = new MenuBar(_canvas);
	}
	
	private function onVideoClick() 
	{
		trace("on video click");
		ScreenManager.gotoScreen(Episode01Screen);
	}
	
	private function emitSeeds() 
	{
		//var seed:Seed;
		new Seed(_canvas, 1400 + Math.floor(Math.random() * 60) - 30, 400 + Math.floor(Math.random() * 40) - 20);
		new Seed(_canvas, 1590 + Math.floor(Math.random() * 60) - 30, 400 + Math.floor(Math.random() * 40) - 20);
		new Seed(_canvas, 1750 + Math.floor(Math.random() * 60) - 30, 400 + Math.floor(Math.random() * 40) - 20);
	}
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		
		_menuBar.destroy();
		
		// background
		_canvas.removeChild(_background);
		
		// popups
		_city.end(1);
		_floor.end(1);
		_tree_1.end(0.5);
		_tree_2.end(0.5);
		_meshi.end(0.5);
		_house.end(0);
		_doit.end(0);
		_video.end(0);
		
		_enter.end(0);
		
		_canvas.removeChild(_news);
		_semicoptero.destroy();
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
		_loaderScreen.update(dt);
		
		if (_isPaused) return;
		
		_enter.update(dt);
		_menuBar.update(dt);
		_semicoptero.update(dt);
		_meshi.update(dt);
		_video.update(dt);
		_data.update(dt);
		
		_news.y = 150 + 10 * Math.sin(_tNews);
		_cloud.x = 800 + 600 * Math.sin(_tCloud);
		
		_tNews += 0.06;
		if (_tNews >= 3.14) _tNews = 0;
		
		_tCloud += 0.005;
		if (_tCloud >= 3.14) _tCloud = 0;
		
		super.update(dt);
		
		if (_isMeshiAnimating)
		{
			if (_tMeshi < 3.14)
			{
				_meshi.skin.scaleY = 1.1 + 0.02 * (Math.sin(_tMeshi));
				_meshi.position.y = 775 - _meshi.skin.height;
			}
			else
			{
				_meshi.skin.scaleY = 1.1;
			}
			
			_tMeshi += 0.13;
			
			if (_tMeshi >= 2 * 3.14)
			{
				emitSeeds();
				_tMeshi = 0;
			}
		}
		else
		{
			_meshi.skin.scaleY = 1.1;
			_meshi.position.y = 775 - _meshi.skin.height;
		}
	}
}