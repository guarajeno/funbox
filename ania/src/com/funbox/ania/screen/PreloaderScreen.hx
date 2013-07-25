package com.funbox.ania.screen;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
#if js
import js.Lib;
#end
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class PreloaderScreen extends Screen
{
	private var _isAssetsDownloaded:Bool;
	private var _isDataDownloaded:Bool = true;
	private var _isSoundsDownloaded:Bool = true;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		AssetsLoader.init();
		
		// mouse cursor
		//AssetsLoader.addAsset("img/common/hand_cursor.png", "hand_cursor");
		
		// common
		AssetsLoader.addAsset("img/common/web_common_logo.png", "web_common_logo");
		AssetsLoader.addAsset("img/common/web_common_background.jpg", "web_common_background");
		AssetsLoader.addAsset("img/common/web_common_videosupport.png", "web_common_videosupport");
		AssetsLoader.addAsset("img/common/web_common_button_home_normal.png", "web_common_button_home_normal");
		AssetsLoader.addAsset("img/common/web_common_button_home_over.png", "web_common_button_home_over");
		AssetsLoader.addAsset("img/common/web_common_button_close_normal.png", "web_common_button_close_normal");
		AssetsLoader.addAsset("img/common/web_common_button_close_over.png", "web_common_button_close_over");
		AssetsLoader.addAsset("img/common/web_common_button_suport.png", "web_common_button_suport");
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
		
		// episode 01
		AssetsLoader.addAsset("img/episode01/web_epidose01_floor.png", "web_epidose01_floor");
		AssetsLoader.addAsset("img/episode01/web_epidose01_city.png", "web_epidose01_city");
		AssetsLoader.addAsset("img/episode01/web_epidose01_meshi.png", "web_epidose01_meshi");
		AssetsLoader.addAsset("img/episode01/web_epidose01_tree01.png", "web_epidose01_tree01");
		AssetsLoader.addAsset("img/episode01/web_epidose01_tree02.png", "web_epidose01_tree02");
		AssetsLoader.addAsset("img/episode01/web_epidose01_tree03.png", "web_epidose01_tree03");
		AssetsLoader.addAsset("img/episode01/web_epidose01_activities.png", "web_epidose01_activities");
		AssetsLoader.addAsset("img/episode01/web_epidose01_video_previous.png", "web_epidose01_video_previous");
		
		// episode 02
		AssetsLoader.addAsset("img/episode02/web_epidose02_background.jpg", "web_epidose02_background");
		AssetsLoader.addAsset("img/episode02/web_epidose02_floor.png", "web_epidose02_floor");
		AssetsLoader.addAsset("img/episode02/web_epidose02_video_previous.png", "web_epidose02_video_previous");
		AssetsLoader.addAsset("img/episode02/web_epidose02_activities.png", "web_epidose02_activities");
		AssetsLoader.addAsset("img/episode02/web_epidose02_tree01.png", "web_epidose02_tree01");
		AssetsLoader.addAsset("img/episode02/web_epidose02_tree02.png", "web_epidose02_tree02");
		AssetsLoader.addAsset("img/episode02/web_epidose02_floor_front.png", "web_epidose02_floor_front");
		AssetsLoader.addAsset("img/episode02/web_epidose02_flowers.png", "web_epidose02_flowers");
		AssetsLoader.addAsset("img/episode02/web_epidose02_bea_flower.png", "web_epidose02_bea_flower");
		AssetsLoader.addAsset("img/episode02/web_epidose02_title.png", "web_epidose02_title");
		
		// my garden
		AssetsLoader.addAsset("img/mygarden/web_mygarden_floor01.png", "web_mygarden_floor01");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_city.png", "web_mygarden_city");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_tree_01.png", "web_mygarden_tree_01");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_tree_02.png", "web_mygarden_tree_02");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_tree_03.png", "web_mygarden_tree_03");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_house.png", "web_mygarden_house");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_buttonback_normal.png", "web_mygarden_buttonback_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_buttonback_over.png", "web_mygarden_buttonback_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_buttonnext_normal.png", "web_mygarden_buttonnext_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_buttonnext_over.png", "web_mygarden_buttonnext_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_textsuport.png", "web_mygarden_textsuport");
		
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_1_normal.png", "web_mygarden_button_1_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_2_normal.png", "web_mygarden_button_2_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_3_normal.png", "web_mygarden_button_3_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_4_normal.png", "web_mygarden_button_4_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_5_normal.png", "web_mygarden_button_5_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_6_normal.png", "web_mygarden_button_6_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_7_normal.png", "web_mygarden_button_7_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_8_normal.png", "web_mygarden_button_8_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_9_normal.png", "web_mygarden_button_9_normal");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_10_normal.png", "web_mygarden_button_10_normal");
		
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_1_over.png", "web_mygarden_button_1_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_2_over.png", "web_mygarden_button_2_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_3_over.png", "web_mygarden_button_3_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_4_over.png", "web_mygarden_button_4_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_5_over.png", "web_mygarden_button_5_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_6_over.png", "web_mygarden_button_6_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_7_over.png", "web_mygarden_button_7_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_8_over.png", "web_mygarden_button_8_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_9_over.png", "web_mygarden_button_9_over");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_button_10_over.png", "web_mygarden_button_10_over");
		
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_1.png", "web_mygarden_characters_1");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_2.png", "web_mygarden_characters_2");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_3.png", "web_mygarden_characters_3");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_4.png", "web_mygarden_characters_4");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_5.png", "web_mygarden_characters_5");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_6.png", "web_mygarden_characters_6");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_7.png", "web_mygarden_characters_7");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_8.png", "web_mygarden_characters_8");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_9.png", "web_mygarden_characters_9");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_10.png", "web_mygarden_characters_10");
		
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_1_name.png", "web_mygarden_characters_1_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_2_name.png", "web_mygarden_characters_2_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_3_name.png", "web_mygarden_characters_3_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_4_name.png", "web_mygarden_characters_4_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_5_name.png", "web_mygarden_characters_5_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_6_name.png", "web_mygarden_characters_6_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_7_name.png", "web_mygarden_characters_7_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_8_name.png", "web_mygarden_characters_8_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_9_name.png", "web_mygarden_characters_9_name");
		AssetsLoader.addAsset("img/mygarden/web_mygarden_characters_10_name.png", "web_mygarden_characters_10_name");
		
		
		//-------------------------------------------------------
		DataLoader.init();
		
		AssetsLoader.load(onAssetsLoaded);
		DataLoader.load(onDataLoaded);
		//SoundManager.load(onSoundsLoaded);
		
		#if js
		Lib.document.getElementsByTagName("body")[0].style.overflowX = "hidden";
		#end
	}

	function onSoundsLoaded() 
	{
		_isSoundsDownloaded = true;
		trace("SOUNDS LOADED");
	}
	
	function onAssetsLoaded() 
	{
		_isAssetsDownloaded = true;
		trace("ASSETS LOADED");
	}
	
	function onDataLoaded() 
	{
		_isDataDownloaded = true;
		trace("DATA LOADED");
	}
	
	override public function update(dt:Int):Dynamic 
	{
		if (_isAssetsDownloaded && _isDataDownloaded && _isSoundsDownloaded)
		{
			ScreenManager.gotoScreen(Episode01Screen);
		}
		
		super.update(dt);
	}
}