package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.popup.VideoPopup;
import com.minigloop.display.AtlasSprite;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import js.Lib;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class Episode01Screen extends Screen
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
	private var _tree_3:ImagePopup;
	private var _previous:ButtonPopup;
	private var _activities:ButtonPopup;
	private var _data:AtlasSprite;
	private var _support:ButtonPopup;
	private var _face:AtlasSprite;
	
	//private var _previews:Array = [];
	
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
		_loaderScreen.addAsset("img/common/web_common_play.png", "web_common_play");
		
		// episode 01
		_loaderScreen.addAsset("img/episode01/web_epidose01_floor.png", "web_epidose01_floor");
		_loaderScreen.addAsset("img/episode01/web_epidose01_city.png", "web_epidose01_city");
		_loaderScreen.addAsset("img/episode01/web_epidose01_meshi.png", "web_epidose01_meshi");
		_loaderScreen.addAsset("img/episode01/web_epidose01_tree01.png", "web_epidose01_tree01");
		_loaderScreen.addAsset("img/episode01/web_epidose01_tree02.png", "web_epidose01_tree02");
		_loaderScreen.addAsset("img/episode01/web_epidose01_tree03.png", "web_epidose01_tree03");
		_loaderScreen.addAsset("img/episode01/web_epidose01_activities.png", "web_epidose01_activities");
		_loaderScreen.addAsset("img/episode01/web_epidose01_video_previous.png", "web_epidose01_video_previous");
		
		_loaderScreen.addAsset("img/episode01/animations/web_epidose01_meshi_face.png", "web_epidose01_meshi_face");
		_loaderScreen.addAsset("img/episode01/animations/web_epidose01_bird01.png", "web_epidose01_bird01");
		_loaderScreen.addAsset("img/episode01/animations/web_epidose01_bird02.png", "web_epidose01_bird02");
		_loaderScreen.addAsset("img/episode01/animations/web_epidose01_bird03.png", "web_epidose01_bird03");
		
		_loaderScreen.addData("img/episode01/animations/web_epidose01_meshi_face.json", "web_epidose01_meshi_face");
		_loaderScreen.addData("img/episode01/animations/web_epidose01_bird01.json", "web_epidose01_bird01");
		_loaderScreen.addData("img/episode01/animations/web_epidose01_bird02.json", "web_epidose01_bird02");
		_loaderScreen.addData("img/episode01/animations/web_epidose01_bird03.json", "web_epidose01_bird03");
		
		_loaderScreen.load(init);
	}

	private function init() 
	{
		_loaderScreen.destroy();
		
		// background
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		// popups
		_city = new ImagePopup(_canvas, "web_epidose01_city", 0, 570, 1);
		_tree_1 = new ImagePopup(_canvas, "web_epidose01_tree01", -480, 500, 1.5);
		_tree_2 = new ImagePopup(_canvas, "web_epidose01_tree02", 680, 500, 1.5);
		_tree_3 = new ImagePopup(_canvas, "web_epidose01_tree03", 820, 660, 1.5);
		_floor = new ImagePopup(_canvas, "web_epidose01_floor", 0, 670, 0);
		_meshi = new ImagePopup(_canvas, "web_epidose01_meshi", 190, 285, 2);
		
		//_face = new AtlasSprite(_canvas, "web_epidose01_meshi_face", "web_epidose01_meshi_face");
		//_face.position.x = 990;
		//_face.position.y = 800;
		//Actuate.tween(_face.position, 2, { y: 300 } ).delay(2).ease(Elastic.easeOut).onUpdate(onFaseUpdate);
		
		_support = new ButtonPopup(
			_canvas,
			450,
			200,
			"web_common_play",
			"web_common_play",
			"web_common_play",
			3,
			onActivitiesClick
		);
		
		_support.setCollision(0, 240, 220, 220);
		
		_previous = new ButtonPopup(
			_canvas,
			-350,
			500,
			"web_epidose01_video_previous",
			"web_epidose01_video_previous",
			"web_epidose01_video_previous",
			2.5,
			onPrevious_Click
		);
		
		_previous.setCollision(90, 20, 420, 250);
		
		_activities = new ButtonPopup(
			_canvas,
			-670,
			570,
			"web_epidose01_activities",
			"web_epidose01_activities",
			"web_epidose01_activities",
			2.5,
			onActivitiesClick
		);
		
		//_activities.setCollision(0, 0, 100, 80);
		
		_data = new AtlasSprite(
			_canvas,
			"web_common_animations_tadata",
			"web_common_animations_tadata"
		);
		
		_data.position.x = 1300;
		_data.position.y = 1000;
		
		Actuate.tween(_data.position, 0.8, { y: 570 } ).delay(2);
		
		_menuBar = new MenuBar(_canvas);
		
		_isPaused = false;
	}
	
	private function onPrevious_Click() 
	{
		trace("previous");
		Lib.eval("showVideo01(" + (Global.stage.fullScreenWidth / 2 - 560) + ", " + 30 + ")");
	}
	
	private function onActivitiesClick() 
	{
		ScreenManager.gotoScreen(ActivitiesScreen);
	}
	//
	//private function onFaseUpdate() 
	//{
		//trace("entro");
		//_face.update(0);
	//}
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		
		_menuBar.destroy();
		
		_city.end(0);
		_tree_1.end(0.5);
		_tree_2.end(0.5);
		_tree_3.end(0.5);
		_floor.end(0.3);
		_meshi.end(0);
		_activities.end(0);
		
		_data.destroy();
		
		_previous.destroy();
		_support.destroy();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		if (_loaderScreen != null) _loaderScreen.update(dt);
		
		if (_isPaused) return;
		
		_activities.update(dt);
		_support.update(dt);
		_data.update(dt);
		//_face.update(dt);
		
		if (_previous != null) _previous.update(dt);
		if (_menuBar != null) _menuBar.update(dt);
	}
}