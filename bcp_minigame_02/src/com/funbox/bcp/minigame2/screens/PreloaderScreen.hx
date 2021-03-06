package com.funbox.bcp.minigame2.screens;
import com.funbox.bcp.minigame2.Global;
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
		
		AssetsLoader.addAsset("images/minigame02/interfaces/loader/spMinigame02_guiloader.png", "guiloader");
		AssetsLoader.addAsset("images/minigame02/interfaces/spMinigame02_bg.jpg", "spMinigame02_bg");
		DataLoader.addData("images/minigame02/interfaces/loader/spMinigame02_guiloader.json", "guiloader");
		
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
		_canvas.addChild(AssetsLoader.getAsset("spMinigame02_bg"));
		
		//Draw loader
		loadas = new AtlasSprite(_canvas, "guiloader", "guiloader");
		loadas.position = new Vector2D(330, 180);
		//--
		
		DataLoader.init();
		AssetsLoader.init();
		SoundManager.init();
		
		// load sounds
		SoundManager.addSound("sound/bgm_juego_2.mp3", "bgm_juego_2");
		SoundManager.addSound("sound/fx_dinero.mp3", "fx_dinero");
		SoundManager.addSound("sound/scorecard.mp3", "scorecard");
		
		////////// minigame02 Assets ///////////
		AssetsLoader.addAsset("images/minigame02/interfaces/gui_text_tutorial_generic.png", "gui_text_tutorial_generic");
		
		////////////// interface - scorecard ///////////////////////
		AssetsLoader.addAsset("images/minigame02/interfaces/scorecard/btn_volver.png", "volver");
		AssetsLoader.addAsset("images/minigame02/interfaces/scorecard/btn_regresar.png", "regresar");
		AssetsLoader.addAsset("images/minigame02/interfaces/scorecard/gui_scorecard_twitter_over.png", "twitter");
		AssetsLoader.addAsset("images/minigame02/interfaces/scorecard/gui_scorecard_face_over.png", "facebook");
		AssetsLoader.addAsset("images/minigame02/interfaces/scorecard/minigame1_scorecard.png", "scorecard");
		/////////////////////////////////////////////////////////////
		
		// interfaces
		AssetsLoader.addAsset("images/minigame02/interfaces/hud/spMinigame02_background_score.png", 
			"spMinigame02_background_score");
			
		// tutorial assets
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_text.png", 
			"spMinigame02_tutorial_text");
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_bag_money.png", 
			"spMinigame02_tutorial_bag_money");
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_mouseHand.png", 
			"spMinigame02_tutorial_mouseHand");
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_ticket_money.png", 
			"spMinigame02_tutorial_ticket_money");
			
		// tutorial assets - check secure
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/check_secure/spMinigame02_tutorial_check_secure.png",
			"spMinigame02_tutorial_check_secure");
		DataLoader.addData("images/minigame02/interfaces/tutorial/check_secure/spMinigame02_tutorial_check_secure.json",
			"spMinigame02_tutorial_check_secure");
			
		// tutorial asset and data score effect
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/score_effect/spMinigame02_tutorial_score_100.png",
			"spMinigame02_tutorial_score_100");
		AssetsLoader.addAsset("images/minigame02/interfaces/tutorial/score_effect/spMinigame02_tutorial_score_500.png",
			"spMinigame02_tutorial_score_500");
			
		// bg and mask bg
		AssetsLoader.addAsset("images/minigame02/interfaces/spMinigame02_bg.jpg", "spMinigame02_bg");
		AssetsLoader.addAsset("images/minigame02/interfaces/spMinigame02_background_mask.png", 
			"spMinigame02_background_mask");
		
		// score of minigame02
		AssetsLoader.addAsset("images/minigame02/score_effect/spMinigame02_score_100.png", 
			"spMinigame02_score_100");
		AssetsLoader.addAsset("images/minigame02/score_effect/spMinigame02_score_500.png", 
			"spMinigame02_score_500");
		AssetsLoader.addAsset("images/minigame02/score_effect/spMinigame02_score_1000.png", 
			"spMinigame02_score_1000");
		
		// check secure
		AssetsLoader.addAsset("images/minigame02/check_secure/spMinigame02_check_secure.png",
			"spMinigame02_check_secure");
		DataLoader.addData("images/minigame02/check_secure/spMinigame02_check_secure.json",
			"spMinigame02_check_secure");
		
		// bag of money
		AssetsLoader.addAsset("images/minigame02/bag_money/spMinigame02_ani_bag_money.png",
			"spMinigame02_ani_bag_money");
		DataLoader.addData("images/minigame02/bag_money/spMinigame02_ani_bag_money.json",
			"spMinigame02_ani_bag_money");
		
		// ticket money
		AssetsLoader.addAsset("images/minigame02/ticket_money/spMinigame02_ani_ticket_money.png",
			"spMinigame02_ani_ticket_money");
		DataLoader.addData("images/minigame02/ticket_money/spMinigame02_ani_ticket_money.json",
			"spMinigame02_ani_ticket_money");
			
		// bot collector
		AssetsLoader.addAsset("images/minigame02/bot_collector/spMinigame02_ani_bot_collector.png",
			"spMinigame02_ani_bot_collector");
		DataLoader.addData("images/minigame02/bot_collector/spMinigame02_ani_bot_collector.json",
			"spMinigame02_ani_bot_collector");
			
		// effect puff
		AssetsLoader.addAsset("images/minigame02/effect_puff/spMinigame02_ani_effect_puff.png",
			"spMinigame02_ani_effect_puff");
		DataLoader.addData("images/minigame02/effect_puff/spMinigame02_ani_effect_puff.json",
			"spMinigame02_ani_effect_puff");
			
		// mouse mask
		AssetsLoader.addAsset("images/minigame02/mouse_mask/spMinigame02_mouseHand_click.png",
			"spMinigame02_mouseHand_click");
		DataLoader.addData("images/minigame02/mouse_mask/spMinigame02_mouseHand_click.json",
			"spMinigame02_mouseHand_click");
			
		// transition assets
		AssetsLoader.addAsset("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_01.png",
			"spMinigame02_gui_text_01");
		AssetsLoader.addAsset("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_02.png",
			"spMinigame02_gui_text_02");
		AssetsLoader.addAsset("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_03.png",
			"spMinigame02_gui_text_03");
		AssetsLoader.addAsset("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_start.png",
			"spMinigame02_gui_text_start");
		
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
		if (_isLoadingReady && loadas != null)
		{
			trace("_isLoadingReady");
			loadas.update(dt);
		}
		if (_isAssetsDownloaded && _isDataDownloaded && _isSoundsDownloaded && loadas != null)
		{
			trace("_isAssetsDownloaded && _isDataDownloaded && _isSoundsDownloaded");
			_isLoadingReady = false;
			loadas.destroy();
			ScreenManager.instance.gotoScreen(TutorialScreen);
		}
		
		super.update(dt);
	}
}