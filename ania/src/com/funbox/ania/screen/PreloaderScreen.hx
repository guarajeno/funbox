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
		
		
		//
		
		//
		// episode 02
		//AssetsLoader.addAsset("img/episode02/web_epidose02_background.jpg", "web_epidose02_background");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_floor.png", "web_epidose02_floor");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_video_previous.png", "web_epidose02_video_previous");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_activities.png", "web_epidose02_activities");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_tree01.png", "web_epidose02_tree01");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_tree02.png", "web_epidose02_tree02");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_floor_front.png", "web_epidose02_floor_front");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_flowers.png", "web_epidose02_flowers");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_bea_flower.png", "web_epidose02_bea_flower");
		//AssetsLoader.addAsset("img/episode02/web_epidose02_title.png", "web_epidose02_title");
		//
		
		
		
		//-------------------------------------------------------
		DataLoader.init();
		
		AssetsLoader.load(onAssetsLoaded);
		DataLoader.load(onDataLoaded);
		//SoundManager.load(onSoundsLoaded);
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
			ScreenManager.gotoScreen(HomeScreen);
		}
		
		super.update(dt);
	}
}