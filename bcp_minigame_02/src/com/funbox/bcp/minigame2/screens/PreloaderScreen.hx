package com.funbox.bcp.minigame2.screens;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
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
		
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		DataLoader.init();
		AssetsLoader.init();
		
		////////// minigame02 Assets ///////////
		// interfaces
		AssetsLoader.addAsset("images/minigame02/interfaces/hud/spMinigame02_background_score.png", 
			"spMinigame02_background_score");
		AssetsLoader.addAsset("images/minigame02/interfaces/hud/spMinigame02_life_off.png", 
			"spMinigame02_life_off");
		AssetsLoader.addAsset("images/minigame02/interfaces/hud/spMinigame02_life_on.png", 
			"spMinigame02_life_on");
			
		AssetsLoader.addAsset("images/minigame02/interfaces/spMinigame02_bg.jpg", 
			"spMinigame02_bg");
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
		
		AssetsLoader.load(onAssetsLoaded);
		DataLoader.load(onDataLoaded);
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
		if (_isAssetsDownloaded && _isDataDownloaded)
		{
			ScreenManager.instance.gotoScreen(GameScreen);
		}
		super.update(dt);
	}
}