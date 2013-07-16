package com.funbox.bcp.minigame3.screens;
import com.funbox.bcp.minigame3.Global;
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
		
		AssetsLoader.addAsset("images/minigame03/interfaces/loader/spMinigame03_guiloader.png", "guiloader");
		AssetsLoader.addAsset("images/minigame03/interfaces/spMinigame03_bg.jpg", "spMinigame03_bg");
		DataLoader.addData("images/minigame03/interfaces/loader/spMinigame03_guiloader.json", "guiloader");
		
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
		_canvas.addChild(AssetsLoader.getAsset("spMinigame03_bg"));
		
		//Draw loader
		loadas = new AtlasSprite(_canvas, "guiloader", "guiloader");
		loadas.position = new Vector2D(330, 180);
		//--
		
		DataLoader.init();
		AssetsLoader.init();
		SoundManager.init();
		
		// load sounds
		SoundManager.addSound("sound/scorecard.mp3", "scorecard");
		SoundManager.addSound("sound/fx_sapo.mp3", "fx_sapo");
		SoundManager.addSound("sound/bgm_3.mp3", "bgm_3");
		
		////////// minigame03 Assets ///////////
		////////////// interface - scorecard ///////////////////////
		AssetsLoader.addAsset("images/minigame03/interfaces/scorecard/btn_volver.png", "volver");
		AssetsLoader.addAsset("images/minigame03/interfaces/scorecard/btn_regresar.png", "regresar");
		AssetsLoader.addAsset("images/minigame03/interfaces/scorecard/gui_scorecard_twitter_over.png", "twitter");
		AssetsLoader.addAsset("images/minigame03/interfaces/scorecard/gui_scorecard_face_over.png", "facebook");
		AssetsLoader.addAsset("images/minigame03/interfaces/scorecard/minigame03_scorecard.png", "scorecard");
		/////////////////////////////////////////////////////////////
			
		// bg and mask bg
		AssetsLoader.addAsset("images/minigame03/interfaces/spMinigame03_bg.jpg", "spMinigame03_bg");
		AssetsLoader.addAsset("images/minigame03/interfaces/spMinigame03_miniCollision_bg.jpg",
			"spMinigame03_miniCollision_bg");
		AssetsLoader.addAsset("images/minigame03/interfaces/spMinigame03_background_mask.png", 
			"spMinigame03_background_mask");
			
		// transition assets
		AssetsLoader.addAsset("images/minigame03/interfaces/popup_start_sequence/spMinigame03_gui_text_01.png",
			"spMinigame03_gui_text_01");
		AssetsLoader.addAsset("images/minigame03/interfaces/popup_start_sequence/spMinigame03_gui_text_02.png",
			"spMinigame03_gui_text_02");
		AssetsLoader.addAsset("images/minigame03/interfaces/popup_start_sequence/spMinigame03_gui_text_03.png",
			"spMinigame03_gui_text_03");
		AssetsLoader.addAsset("images/minigame03/interfaces/popup_start_sequence/spMinigame03_gui_text_start.png",
			"spMinigame03_gui_text_start");
			
		// hud
		AssetsLoader.addAsset("images/minigame03/interfaces/hud/spMinigame03_background_score.png",
			"spMinigame03_background_score");
			
		// tutorial
		AssetsLoader.addAsset("images/minigame03/interfaces/tutorial/spMinigame03_tutorial_text.png",
			"spMinigame03_tutorial_text");
		AssetsLoader.addAsset("images/minigame03/interfaces/tutorial/spMinigame03_tutorial_mouseHand_click.png",
			"spMinigame03_tutorial_mouseHand_click");
		AssetsLoader.addAsset("images/minigame03/interfaces/tutorial/spMinigame03_tutorial_frog_stand_front.png",
			"spMinigame03_tutorial_frog_stand_front");
		AssetsLoader.addAsset("images/minigame03/interfaces/tutorial/spMinigame03_tutorial_ani_effect_puff.png",
			"spMinigame03_tutorial_ani_effect_puff");
			
		// mouse mask
		AssetsLoader.addAsset("images/minigame03/mouse_mask/spMinigame03_mouseHand_click.png",
			"spMinigame03_mouseHand_click");
			
		AssetsLoader.addAsset("images/minigame03/mouse_mask/spMinigame03_mouseHand_click_attack.png",
			"spMinigame03_mouseHand_click_attack");
		DataLoader.addData("images/minigame03/mouse_mask/spMinigame03_mouseHand_click_attack.json",
			"spMinigame03_mouseHand_click_attack");
			
		// score effect
		AssetsLoader.addAsset("images/minigame03/score_effect/spMinigame03_score_100.png",
			"spMinigame03_score_100");
		AssetsLoader.addAsset("images/minigame03/score_effect/spMinigame03_score_1000.png",
			"spMinigame03_score_1000");
			
		// effect puff
		AssetsLoader.addAsset("images/minigame03/effect_puff/spMinigame03_ani_effect_puff.png",
			"spMinigame03_ani_effect_puff");
		DataLoader.addData("images/minigame03/effect_puff/spMinigame03_ani_effect_puff.json",
			"spMinigame03_ani_effect_puff");
			
		// frog back jump
		AssetsLoader.addAsset("images/minigame03/frog/back/spMinigame03_frog_jump_back.png",
			"spMinigame03_frog_jump_back");
		DataLoader.addData("images/minigame03/frog/back/spMinigame03_frog_jump_back.json",
			"spMinigame03_frog_jump_back");
		// frog back stand
		AssetsLoader.addAsset("images/minigame03/frog/back/spMinigame03_frog_stand_back.png",
			"spMinigame03_frog_stand_back");
		DataLoader.addData("images/minigame03/frog/back/spMinigame03_frog_stand_back.json",
			"spMinigame03_frog_stand_back");
			
		// frog front jump
		AssetsLoader.addAsset("images/minigame03/frog/front/spMinigame03_frog_jump_front.png",
			"spMinigame03_frog_jump_front");
		DataLoader.addData("images/minigame03/frog/front/spMinigame03_frog_jump_front.json",
			"spMinigame03_frog_jump_front");
		// frog front stand
		AssetsLoader.addAsset("images/minigame03/frog/front/spMinigame03_frog_stand_front.png",
			"spMinigame03_frog_stand_front");
		DataLoader.addData("images/minigame03/frog/front/spMinigame03_frog_stand_front.json",
			"spMinigame03_frog_stand_front");
			
		// frog left jump
		AssetsLoader.addAsset("images/minigame03/frog/left/spMinigame03_frog_jump_left.png",
			"spMinigame03_frog_jump_left");
		DataLoader.addData("images/minigame03/frog/left/spMinigame03_frog_jump_left.json",
			"spMinigame03_frog_jump_left");
		// frog left stand
		AssetsLoader.addAsset("images/minigame03/frog/left/spMinigame03_frog_stand_left.png",
			"spMinigame03_frog_stand_left");
		DataLoader.addData("images/minigame03/frog/left/spMinigame03_frog_stand_left.json",
			"spMinigame03_frog_stand_left");
			
		// frog right jump
		AssetsLoader.addAsset("images/minigame03/frog/right/spMinigame03_frog_jump_right.png",
			"spMinigame03_frog_jump_right");
		DataLoader.addData("images/minigame03/frog/right/spMinigame03_frog_jump_right.json",
			"spMinigame03_frog_jump_right");
		// frog right stand
		AssetsLoader.addAsset("images/minigame03/frog/right/spMinigame03_frog_stand_right.png",
			"spMinigame03_frog_stand_right");
		DataLoader.addData("images/minigame03/frog/right/spMinigame03_frog_stand_right.json",
			"spMinigame03_frog_stand_right");

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