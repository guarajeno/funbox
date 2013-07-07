package com.funbox.bcp.minigame1.screens;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
import com.minigloop.util.Vector2D;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;
import com.minigloop.display.AtlasSprite;

/**
 * ...
 * @author 
 */

class PreloaderScreen extends Screen
{
	private var _isLoadingAssetsLoaded:Bool;
	private var _isLoadingDataLoaded:Bool;
	private var _isLoadingReady:Bool;
	
	private var _isAssetsDownloaded:Bool;
	private var _isDataDownloaded:Bool;
	private var _isSoundsDownloaded:Bool;
	
	//private var _loader:Bitmap;
		
	private var bg:Sprite;
	private var loadas:AtlasSprite;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		bg = new Sprite();
		bg.graphics.beginFill(0, 1);
		bg.graphics.drawRect(0, 0, 2000, 2000);
		bg.graphics.endFill();
		
		AssetsLoader.init();
		AssetsLoader.addAsset("images/minigame1_guiloader.png", "guiloader");
		AssetsLoader.addAsset("images/minigame1_background_1.jpg", "background_1");
		
		DataLoader.init();
		DataLoader.addData("atlas/minigame1_guiloader.json", "guiloader");
		
		AssetsLoader.load(onLoadingAssetsLoaded);
		DataLoader.load(onLoadingDataLoaded);
	}
	
	function onLoadingAssetsLoaded() 
	{
		_isLoadingAssetsLoaded = true;
		trace("LOADING ASSETS LOADED");
	}
	
	function onLoadingDataLoaded() 
	{
		_isLoadingDataLoaded = true;
		trace("LOADING DATA LOADED");
	}
	
	function onLoadingLoaded()
	{
		//Draw background
		_canvas.addChild(AssetsLoader.getAsset("background_1"));
		
		//Draw loader
		loadas = new AtlasSprite(_canvas, "guiloader", "guiloader");
		loadas.position = new Vector2D(270, 180);
		//--
		
		AssetsLoader.init();
		AssetsLoader.addAsset("images/minigame1_virus.png", "virus");
		AssetsLoader.addAsset("images/minigame1_black.png", "black");
		AssetsLoader.addAsset("images/minigame1_hand.png", "hand");
		AssetsLoader.addAsset("images/minigame1_hand_hit.png", "hit");
		AssetsLoader.addAsset("images/minigame1_explode.png", "die");
		AssetsLoader.addAsset("images/minigame1_background_1.jpg", "background_1");
		AssetsLoader.addAsset("images/minigame1_background_2.png", "background_2");
		AssetsLoader.addAsset("images/minigame1_background_score.png", "background_score");
		
		AssetsLoader.addAsset("images/minigame1_background_tutorial_1.png", "background_tutorial_1");
		AssetsLoader.addAsset("images/minigame1_background_tutorial_2.png", "background_tutorial_2");
		AssetsLoader.addAsset("images/minigame1_hand_tutorial.png", "hand_tutorial");
		AssetsLoader.addAsset("images/minigame1_hand_tutorial.png", "hand_tutorial");
		AssetsLoader.addAsset("images/btn_volver.png", "volver");
		AssetsLoader.addAsset("images/btn_regresar.png", "regresar");
		
		AssetsLoader.addAsset("images/mockup_tab.jpg", "facebookbar");
		AssetsLoader.addAsset("images/minigame1_scorecard.png", "scorecard");
		
		AssetsLoader.addAsset("images/facebookbar/tab_support.png", "tab_support");
		AssetsLoader.addAsset("images/facebookbar/rank_support.png", "rank_support");
		
		AssetsLoader.addAsset("images/facebookbar/button_next_press.png", "down");
		AssetsLoader.addAsset("images/facebookbar/button_next_over.png", "over");
		AssetsLoader.addAsset("images/facebookbar/button_next_normal.png", "up");
		
		AssetsLoader.addAsset("images/gui_text_01.png", "text_3");
		AssetsLoader.addAsset("images/gui_text_02.png", "text_2");
		AssetsLoader.addAsset("images/gui_text_03.png", "text_1");
		AssetsLoader.addAsset("images/gui_text_start.png", "text_start");
		AssetsLoader.addAsset("images/minigame1_life_on.png", "life_on");
		AssetsLoader.addAsset("images/minigame1_life_off.png", "life_off");
		AssetsLoader.addAsset("images/gui_text_score01.png", "score_500");
		AssetsLoader.addAsset("images/gui_text_score02.png", "score_1000");
		
		DataLoader.init();
		DataLoader.addData("atlas/minigame1_virus.json", "virus");
		DataLoader.addData("atlas/minigame1_black.json", "black");
		DataLoader.addData("atlas/minigame1_explode.json", "die");
		DataLoader.addData("atlas/minigame1_hand_hit.json", "hit");
		
		SoundManager.init();
		SoundManager.addSound("sound/pts.mp3", "points");
		SoundManager.addSound("sound/scorecard.mp3", "scorecard");
		SoundManager.addSound("sound/hit.mp3", "hit");
		SoundManager.addSound("sound/bgm_1.mp3", "bgm_1");
		
		AssetsLoader.load(onAssetsLoaded);
		DataLoader.load(onDataLoaded);
		SoundManager.load(onSoundsLoaded);
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
		if (_isLoadingAssetsLoaded && _isLoadingDataLoaded)
		{
			_isLoadingAssetsLoaded = false;
			_isLoadingDataLoaded = false;
			_isLoadingReady = true;
			onLoadingLoaded();
		}
		if (_isLoadingReady)
		{
			loadas.update(dt);
		}
		if (_isAssetsDownloaded && _isDataDownloaded && _isSoundsDownloaded)
		{
			_isLoadingReady = false;
			loadas.destroy();
			ScreenManager.instance.gotoScreen(TutorialScreen);
		}
		super.update(dt);
	}
}