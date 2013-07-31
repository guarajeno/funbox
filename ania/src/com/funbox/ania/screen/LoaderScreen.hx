package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Linear;
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

class LoaderScreen extends Screen
{
	// images
	private var _background:Bitmap;
	private var _logo:Bitmap;
	private var _menuSupport:Bitmap;
	private var _onEndLoad:Dynamic;
	private var _onEndAnimation:Dynamic;
	
	public function new(canvas:Sprite, onEndLoad:Dynamic) 
	{
		super(canvas);
		
		_onEndLoad = onEndLoad;
		
		AssetsLoader.addAsset("img/common/web_common_logo.png", "web_common_logo");
		AssetsLoader.addAsset("img/common/web_common_background.jpg", "web_common_background");
		AssetsLoader.addAsset("img/common/web_common_button_suport.png", "web_common_button_suport");
		AssetsLoader.load(init);
	}
	
	private function init() 
	{
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		_menuSupport = AssetsLoader.getAsset("web_common_button_suport");
		_menuSupport.x = Global.stage.fullScreenWidth / 2;// - _menuSupport.width / 2;
		_menuSupport.scaleX = 0;
		_canvas.addChild(_menuSupport);
		
		_logo = AssetsLoader.getAsset("web_common_logo");
		_logo.x = Global.stage.fullScreenWidth / 2 - _logo.width / 2;
		_logo.y = Global.stage.fullScreenHeight / 2 - _logo.height / 2;
		_canvas.addChild(_logo);
		
		_onEndLoad();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		super.update(dt);
	}
	
	override public function destroy():Dynamic 
	{
		_canvas.removeChild(_background);
		_canvas.removeChild(_logo);
		_canvas.removeChild(_menuSupport);
		
		_background = null;
		_logo = null;
	}
	
	public function animate(onEndAnimation:Dynamic) 
	{
		_onEndAnimation = onEndAnimation;
		
		Actuate.tween(_logo, 0.5, { y: 0 } ).ease(Elastic.easeInOut);
		Actuate.tween(_menuSupport, 0.1, { scaleX: 0.95 } ).delay(0.5).ease(Linear.easeNone).onUpdate(onAnimating).onComplete(_onEndAnimation);
		//Actuate.tween(_menuSupport, 0.5, { x: 0 } ).delay(0.5).ease(Linear.easeNone);
	}
	
	private function onAnimating() 
	{
		_menuSupport.x = Global.stage.stageWidth / 2 - _menuSupport.width / 2;
	}
}