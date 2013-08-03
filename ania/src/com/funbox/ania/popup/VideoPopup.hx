package com.funbox.ania.popup;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.minigloop.display.Button;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class VideoPopup extends Screen
{
	private var _background:Sprite;
	private var _support:Bitmap;
	private var _close:Button;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		// background
		_background = new Sprite();
		_background.graphics.beginFill(0, 0.4);
		_background.graphics.drawRect(0, 0, 1600, 800);
		_background.graphics.endFill();
		
		_background.x = 0;
		_background.y = 0;
		
		_canvas.addChild(_background);
		
		// support
		_support = AssetsLoader.getAsset("web_common_videosupport");
		_support.x = Global.stage.stageWidth / 2 - _support.width / 2;
		_support.y = 40;
		_canvas.addChild(_support);
		
		// close button
		_close = new Button(canvas, "web_common_button_close_normal", "web_common_button_close_normal", "web_common_button_close_over", onClose_Click);
		_close.setCollision(0, 0, 195, 65);
		_close.position.x = 1150;
		_close.position.y = 0;
		_close.update(0);
	}
	
	private function onClose_Click() 
	{
		ScreenManager.closePopup();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		
	}
	
	override public function destroy():Dynamic 
	{
		_canvas.removeChild(_background);
		_canvas.removeChild(_support);
		_close.destroy();
	}
}