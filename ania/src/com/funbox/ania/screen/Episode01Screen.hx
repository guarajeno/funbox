package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.popup.VideoPopup;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
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
	private var _activities:ImagePopup;
	private var _data:ImagePopup;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		// background
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		// popups
		_city = new ImagePopup(canvas, "web_epidose01_city", 0, 570, 0.5);
		_tree_1 = new ImagePopup(canvas, "web_epidose01_tree01", -480, 500, 0.7);
		_tree_2 = new ImagePopup(canvas, "web_epidose01_tree02", 680, 500, 0.7);
		_tree_3 = new ImagePopup(canvas, "web_epidose01_tree03", 820, 660, 0.7);
		_floor = new ImagePopup(canvas, "web_epidose01_floor", 0, 670, 0);
		_meshi = new ImagePopup(canvas, "web_epidose01_meshi", 190, 285, 0.7);
		
		_previous = new ButtonPopup(
			canvas,
			-450,
			500,
			"web_epidose01_video_previous",
			"web_epidose01_video_previous",
			"web_epidose01_video_previous",
			1,
			onPrevious_Click
		);
		
		_previous.setCollision(40, 20, 420, 250);
		
		_activities = new ImagePopup(canvas, "web_epidose01_activities", -670, 570, 1);
		_data = new ImagePopup(canvas, "web_common_tadata", 0, 620, 1);
		
		_menuBar = new MenuBar(canvas);
	}
	
	private function onPrevious_Click() 
	{
		trace("click en previous");
		ScreenManager.showPopup(VideoPopup);
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_previous.update(dt);
		_menuBar.update(dt);
		
		super.update(dt);
	}
}