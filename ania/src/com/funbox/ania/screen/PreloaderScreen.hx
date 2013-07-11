package com.funbox.ania.screen;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
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
		AssetsLoader.addAsset("img/common/web_common_buttonsuport.png", "web_common_buttonsuport");
		AssetsLoader.addAsset("img/common/web_common_button_episodes_normal.png", "web_common_button_episodes_normal");
		AssetsLoader.addAsset("img/common/web_common_button_episodes_over.png", "web_common_button_episodes_over");
		
		DataLoader.init();
		//DataLoader.addData("atlas/minigame1_guiloader.json", "guiloader");
		
		//SoundManager.init();
		//SoundManager.addSound("sound/pts.mp3", "points");
		//SoundManager.addSound("sound/scorecard.mp3", "scorecard");
		//SoundManager.addSound("sound/hit.mp3", "hit");
		//SoundManager.addSound("sound/bgm_1.mp3", "bgm_1");
		
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
			ScreenManager.instance.gotoScreen(HomeScreen);
		}
		
		super.update(dt);
	}
}