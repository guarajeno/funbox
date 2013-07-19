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

class Episode02Screen extends Screen
{
	// menu bar
	private var _menuBar:MenuBar;
	
	// images
	private var _background:Bitmap;
	
	// popups
	private var _floor:ImagePopup;
	private var _flower:ImagePopup;
	private var _flowers:ImagePopup;
	private var _tree_1:ImagePopup;
	private var _tree_2:ImagePopup;
	private var _tree_3:ImagePopup;
	private var _previous:ButtonPopup;
	private var _activities:ImagePopup;
	private var _data:ImagePopup;
	private var _title:ImagePopup;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		// background
		_background = AssetsLoader.getAsset("web_epidose02_background");
		_canvas.addChild(_background);
		
		// popups
		_tree_1 = new ImagePopup(canvas, "web_epidose02_tree01", -400, 500, 0.7);
		_tree_2 = new ImagePopup(canvas, "web_epidose02_tree02", 600, 500, 0.7);
		_floor = new ImagePopup(canvas, "web_epidose02_floor", 0, 670, 0);
		_tree_3 = new ImagePopup(canvas, "web_epidose02_floor_front", 0, 730, 0.7);
		_flowers = new ImagePopup(canvas, "web_epidose02_flowers", 190, 560, 1);
		_flower = new ImagePopup(canvas, "web_epidose02_bea_flower", 200, 500, 1.2);
		//_title = new ImagePopup(canvas, "web_epidose02_title", 700, 0, 1.2);
		
		_previous = new ButtonPopup(
			canvas,
			-450,
			500,
			"web_epidose02_video_previous",
			"web_epidose02_video_previous",
			"web_epidose02_video_previous",
			1,
			onPrevious_Click
		);
		
		_previous.setCollision(40, 20, 420, 250);
		
		_activities = new ImagePopup(canvas, "web_epidose02_activities", -670, 570, 1);
		_data = new ImagePopup(canvas, "web_common_tadata", 620, 620, 1);
		
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