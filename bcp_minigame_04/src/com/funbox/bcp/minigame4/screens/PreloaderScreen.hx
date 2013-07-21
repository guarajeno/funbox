package com.funbox.bcp.minigame4.screens;
import com.funbox.bcp.minigame4.Global;
import com.minigloop.display.AtlasSprite;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
import com.minigloop.util.Vector2D;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */
class PreloaderScreen extends Screen
{
	private var _isAssetsDownloaded:Bool;
	private var _isDataDownloaded:Bool;
	private var _isSoundsDownloaded:Bool;
	
	private var _isLoadingAssetsLoaded:Bool;
	private var _isLoadingDataLoaded:Bool;
	private var _isLoadingReady:Bool;
		
	private var bg:Sprite;
	private var loadas:AtlasSprite;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_isAssetsDownloaded = false;
		_isDataDownloaded = false;
		_isSoundsDownloaded = false;
	
		_isLoadingAssetsLoaded = false;
		_isLoadingDataLoaded = false;
		_isLoadingReady = false;
		
		bg = null;
		loadas = null;
		
		Global.stage = canvas.stage;
		Global.StageWidth = 640;
		Global.StageHeight = 480;
		
		bg = new Sprite();
		bg.graphics.beginFill(0, 1);
		bg.graphics.drawRect(0, 0, 2000, 2000);
		bg.graphics.endFill();
		
		DataLoader.init();
		AssetsLoader.init();
		
		AssetsLoader.addAsset("images/minigame04/interfaces/loader/spMinigame04_guiloader.png", "guiloader");
		AssetsLoader.addAsset("images/minigame04/interfaces/spMinigame04_bg.jpg", "spminigame04_bg");
		DataLoader.addData("images/minigame04/interfaces/loader/spMinigame04_guiloader.json", "guiloader");
		
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
	
	function onLoadingLoaded() {
		//Draw background
		_canvas.addChild(AssetsLoader.getAsset("spminigame04_bg"));
		
		//Draw loader
		loadas = new AtlasSprite(_canvas, "guiloader", "guiloader");
		loadas.position = new Vector2D(330, 180);
		//--
		
		DataLoader.init();
		AssetsLoader.init();
		SoundManager.init();
		
		// load sounds
		SoundManager.addSound("sound/scorecard.mp3", "scorecard");
		SoundManager.addSound("sound/bgm_4.mp3", "bgm_4");
		
		////////// minigame04 Assets ///////////
		// tutorial black and white
		AssetsLoader.addAsset("images/minigame04/interfaces/tutorial/spMinigame04_tutorial_bcp_card.png", 
			"spMinigame04_tutorial_bcp_card");
		
		AssetsLoader.addAsset("images/minigame04/interfaces/tutorial/spMinigame04_tutorial_mosaico_1_walk_right.png", 
			"spMinigame04_tutorial_mosaico_1_walk_right");
		DataLoader.addData("images/minigame04/interfaces/tutorial/spMinigame04_tutorial_mosaico_1_walk_right.json", 
			"spMinigame04_tutorial_mosaico_1_walk_right");
			
		AssetsLoader.addAsset("images/minigame04/interfaces/tutorial/spMinigame04_tutorial_player_walk_left.png", 
			"spMinigame04_tutorial_player_walk_left");
		DataLoader.addData("images/minigame04/interfaces/tutorial/spMinigame04_tutorial_player_walk_left.json", 
			"spMinigame04_tutorial_player_walk_left");
		
		//mosaico 1
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_1/spMinigame04_mosaico_1_stand.png", 
			"spMinigame04_mosaico_1_stand");
		DataLoader.addData("images/minigame04/enemies/mosaico_1/spMinigame04_mosaico_1_stand.json", 
			"spMinigame04_mosaico_1_stand");
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_1/spMinigame04_mosaico_1_walk_left.png", 
			"spMinigame04_mosaico_1_walk_left");
		DataLoader.addData("images/minigame04/enemies/mosaico_1/spMinigame04_mosaico_1_walk_left.json", 
			"spMinigame04_mosaico_1_walk_left");
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_1/spMinigame04_mosaico_1_walk_right.png", 
			"spMinigame04_mosaico_1_walk_right");
		DataLoader.addData("images/minigame04/enemies/mosaico_1/spMinigame04_mosaico_1_walk_right.json", 
			"spMinigame04_mosaico_1_walk_right");
			
		//mosaico 2
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_2/spMinigame04_mosaico_2_stand.png", 
			"spMinigame04_mosaico_2_stand");
		DataLoader.addData("images/minigame04/enemies/mosaico_2/spMinigame04_mosaico_2_stand.json", 
			"spMinigame04_mosaico_2_stand");
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_2/spMinigame04_mosaico_2_walk_left.png", 
			"spMinigame04_mosaico_2_walk_left");
		DataLoader.addData("images/minigame04/enemies/mosaico_2/spMinigame04_mosaico_2_walk_left.json", 
			"spMinigame04_mosaico_2_walk_left");
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_2/spMinigame04_mosaico_2_walk_right.png", 
			"spMinigame04_mosaico_2_walk_right");
		DataLoader.addData("images/minigame04/enemies/mosaico_2/spMinigame04_mosaico_2_walk_right.json", 
			"spMinigame04_mosaico_2_walk_right");
			
		//mosaico 3
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_3/spMinigame04_mosaico_3_stand.png", 
			"spMinigame04_mosaico_3_stand");
		DataLoader.addData("images/minigame04/enemies/mosaico_3/spMinigame04_mosaico_3_stand.json", 
			"spMinigame04_mosaico_3_stand");
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_3/spMinigame04_mosaico_3_walk_left.png", 
			"spMinigame04_mosaico_3_walk_left");
		DataLoader.addData("images/minigame04/enemies/mosaico_3/spMinigame04_mosaico_3_walk_left.json", 
			"spMinigame04_mosaico_3_walk_left");
		AssetsLoader.addAsset("images/minigame04/enemies/mosaico_3/spMinigame04_mosaico_3_walk_right.png", 
			"spMinigame04_mosaico_3_walk_right");
		DataLoader.addData("images/minigame04/enemies/mosaico_3/spMinigame04_mosaico_3_walk_right.json", 
			"spMinigame04_mosaico_3_walk_right");
		
		//puff effect
		AssetsLoader.addAsset("images/minigame04/puff/spMinigame04_ani_effect_puff.png", "spMinigame04_ani_effect_puff");
		DataLoader.addData("images/minigame04/puff/spMinigame04_ani_effect_puff.json", "spMinigame04_ani_effect_puff");
		
		// card
		AssetsLoader.addAsset("images/minigame04/card/spMinigame04_bcp_card.png", "spMinigame04_bcp_card");
		
		// player
		AssetsLoader.addAsset("images/minigame04/player/spMinigame04_player_stand.png", "spMinigame04_player_stand");
		AssetsLoader.addAsset("images/minigame04/player/spMinigame04_player_walk_left.png", "spMinigame04_player_walk_left");
		AssetsLoader.addAsset("images/minigame04/player/spMinigame04_player_walk_right.png", "spMinigame04_player_walk_right");
		
		DataLoader.addData("images/minigame04/player/spMinigame04_player_stand.json", "spMinigame04_player_stand");
		DataLoader.addData("images/minigame04/player/spMinigame04_player_walk_left.json", "spMinigame04_player_walk_left");
		DataLoader.addData("images/minigame04/player/spMinigame04_player_walk_right.json", "spMinigame04_player_walk_right");
		
		////////////// interface - scorecard ///////////////////////
		AssetsLoader.addAsset("images/minigame04/interfaces/scorecard/btn_volver.png", "volver");
		AssetsLoader.addAsset("images/minigame04/interfaces/scorecard/btn_regresar.png", "regresar");
		AssetsLoader.addAsset("images/minigame04/interfaces/scorecard/gui_scorecard_twitter_over.png", "twitter");
		AssetsLoader.addAsset("images/minigame04/interfaces/scorecard/gui_scorecard_face_over.png", "facebook");
		AssetsLoader.addAsset("images/minigame04/interfaces/scorecard/minigame04_scorecard.png", "scorecard");
		/////////////////////////////////////////////////////////////
			
		// bg and mask bg
		AssetsLoader.addAsset("images/minigame04/interfaces/spMinigame04_bg.jpg", "spminigame04_bg");
		AssetsLoader.addAsset("images/minigame04/interfaces/spMinigame04_background_mask.png", 
			"spminigame04_background_mask");
			
		// transition assets
		AssetsLoader.addAsset("images/minigame04/interfaces/popup_start_sequence/spMinigame04_gui_text_01.png",
			"spminigame04_gui_text_01");
		AssetsLoader.addAsset("images/minigame04/interfaces/popup_start_sequence/spMinigame04_gui_text_02.png",
			"spminigame04_gui_text_02");
		AssetsLoader.addAsset("images/minigame04/interfaces/popup_start_sequence/spMinigame04_gui_text_03.png",
			"spminigame04_gui_text_03");
		AssetsLoader.addAsset("images/minigame04/interfaces/popup_start_sequence/spMinigame04_gui_text_start.png",
			"spminigame04_gui_text_start");
			
		// hud
		AssetsLoader.addAsset("images/minigame04/interfaces/hud/spMinigame04_background_score.png",
			"spminigame04_background_score");
			
		// tutorial
		AssetsLoader.addAsset("images/minigame04/interfaces/tutorial/spMinigame04_tutorial_text.png",
			"spminigame04_tutorial_text");
			
		// score effect
		AssetsLoader.addAsset("images/minigame04/score_effect/spMinigame04_score_100.png",
			"spMinigame04_score_100");
			
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
			trace("_isLoadingAssetsLoaded && _isLoadingDataLoaded");
			
			_isLoadingAssetsLoaded = false;
			_isLoadingDataLoaded = false;
			_isLoadingReady = true;
			onLoadingLoaded();
		}
		if (_isLoadingReady)
		{
			trace("_isLoadingReady");
			loadas.update(dt);
		}
		if (_isAssetsDownloaded && _isDataDownloaded && _isSoundsDownloaded)
		{
			trace("_isAssetsDownloaded && _isDataDownloaded && _isSoundsDownloaded");
			_isLoadingReady = false;
			loadas.destroy();
			ScreenManager.instance.gotoScreen(TutorialScreen);
		}
		
		super.update(dt);
	}
}