package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MemoryGame;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.popup.VideoPopup;
import com.funbox.ania.screen.LoaderScreen;
import com.minigloop.display.AtlasSprite;
import com.minigloop.display.Button;
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

class ActivitiesScreen extends Screen
{
	// menu bar
	private var _menuBar:MenuBar;
	
	// images
	private var _background:Bitmap;
	private var _activities:ButtonPopup;
	private var _back:ButtonPopup;
	private var _game:MemoryGame;
	
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
		
		// activities
		_loaderScreen.addAsset("img/activity/web_pages_activity_background.jpg", "web_pages_activity_background");
		_loaderScreen.addAsset("img/activity/web_activity_button_back_normal.png", "web_activity_button_back_normal");
		_loaderScreen.addAsset("img/activity/web_activity_button_back_over.png", "web_activity_button_back_over");
		_loaderScreen.addAsset("img/activity/web_activity_tittle_normal.png", "web_activity_tittle_normal");
		_loaderScreen.addAsset("img/activity/web_activity_tittle_normal.png", "web_activity_tittle_over");
		_loaderScreen.addAsset("img/activity/web_activity_play_normal.png", "web_activity_play_normal");
		_loaderScreen.addAsset("img/activity/web_activity_play_over.png", "web_activity_play_over");
		_loaderScreen.addAsset("img/activity/web_activity_support_lock.png", "web_activity_support_lock");
		_loaderScreen.addAsset("img/activity/web_activity_youwin.png", "web_activity_youwin");
		
		// game
		_loaderScreen.addAsset("img/activity/web_activity_support.png", "web_activity_support");
		_loaderScreen.addAsset("img/activity/web_activity_card01.png", "web_activity_card01");
		_loaderScreen.addAsset("img/activity/web_activity_card02.png", "web_activity_card02");
		_loaderScreen.addAsset("img/activity/web_activity_card03.png", "web_activity_card03");
		_loaderScreen.addAsset("img/activity/web_activity_card04.png", "web_activity_card04");
		_loaderScreen.addAsset("img/activity/web_activity_card05.png", "web_activity_card05");
		_loaderScreen.addAsset("img/activity/web_activity_card06.png", "web_activity_card06");
		_loaderScreen.addAsset("img/activity/web_activity_cardclose.png", "web_activity_cardclose");
		
		_loaderScreen.load(init);
		
		//DataLoader.addData("img/common/animations/web_common_animations_loader.json", "web_common_animations_loader");
		//DataLoader.load(onDataLoaded);
		
		//update(0);
	}
	
	private function init() 
	{
		_loaderScreen.destroy();
		
		_isPaused = false;
		Global.heightReference = 1000;
		
		// background
		_background = AssetsLoader.getAsset("web_pages_activity_background");
		_background.width = 2000;
		_canvas.addChild(_background);
		
		_activities = new ButtonPopup(
			_canvas,
			-360,
			170,
			"web_activity_tittle_normal",
			"web_activity_tittle_normal",
			"web_activity_tittle_normal",
			0,
			null
		);
		
		_activities.setCollision(0, 45, 240, 40);
		_back = new ButtonPopup(_canvas, 400, 150, "web_activity_button_back_over", "web_activity_button_back_over", "web_activity_button_back_over", 0, onBackClick);
		_back.setCollision(0, 35, 110, 40);
		
		_game = new MemoryGame(_canvas);
		
		_menuBar = new MenuBar(_canvas);
	}
	
	private function onBackClick() 
	{
		ScreenManager.gotoScreen(Episode01Screen);
	}
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		
		_menuBar.destroy();
		_game.destroy();
		_back.end(0);
		_activities.end(0);
		
		Global.heightReference = 820;
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_loaderScreen.update(dt);
		
		if (_isPaused) return;
		
		_menuBar.update(dt);
		_activities.update(dt);
		_back.update(dt);
		_game.update(dt);
	}
}