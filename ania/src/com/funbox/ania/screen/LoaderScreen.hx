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
import com.minigloop.util.DataLoader;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

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
	
	private var _isAssetsLoaded:Bool;
	private var _isDataLoaded:Bool;
	private var _callback:Dynamic;
	
	private var _text:TextField;
	private var _loaderCounter:Float = 0;
	
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
		_menuSupport.x = 500;
		_menuSupport.scaleX = 0;
		_canvas.addChild(_menuSupport);
		
		_logo = AssetsLoader.getAsset("web_common_logo");
		_logo.x = Global.stage.stageWidth / 2 - _logo.width / 2;
		_logo.y = Global.stage.fullScreenHeight / 2 - _logo.height / 2;
		_canvas.addChild(_logo);
		
		_text = new TextField();
		_text.defaultTextFormat = new TextFormat("Arial", 28, 0x000000, true);
		_text.text = "Cargando...";
		_text.x = 930;
		_text.y = 500;
		_canvas.addChild(_text);
		
		_onEndLoad();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_loaderCounter += dt / 500;
		
		if (_loaderCounter > 4)
		{
			_loaderCounter = 0;
		}
		
		_text.text = "Cargando";
		
		var i:Int;
		for (i in 0...(Math.floor(_loaderCounter)))
		{
			_text.text += ".";
		}
		
		if (_isAssetsLoaded && _isDataLoaded)
		{
			_isAssetsLoaded = false;
			_isDataLoaded = false;
			
			animate();
		}
	}
	
	override public function destroy():Dynamic 
	{
		//_canvas.removeChild(_background);
		_canvas.removeChild(_logo);
		_canvas.removeChild(_menuSupport);
		
		//_background = null;
		//_logo = null;
	}
	
	public function addAsset(url:String, id:String) 
	{
		AssetsLoader.addAsset(url, id);
	}
	
	public function addData(url:String, id:String) 
	{
		DataLoader.addData(url, id);
	}
	
	public function load(__callback:Dynamic) 
	{
		_callback = __callback;
		AssetsLoader.load(onAssetsLoaded);
		DataLoader.load(onLoadedLoaded);
	}
	
	private function onLoadedLoaded() 
	{
		_isDataLoaded = true;
	}
	
	private function onAssetsLoaded() 
	{
		_isAssetsLoaded = true;
	}
	
	public function animate() 
	{
		_text.visible = false;
		Actuate.tween(_logo, 0.5, { y: 0 } ).ease(Elastic.easeInOut);
		//Actuate.tween(_text, 0.5, { y: 0 } ).ease(Elastic.easeInOut);
		Actuate.tween(_menuSupport, 0.1, { scaleX: 0.95 } ).delay(0.5).ease(Linear.easeNone).onUpdate(onAnimating).onComplete(_callback);
	}
	
	private function onAnimating() 
	{
		_menuSupport.x = Global.stage.stageWidth / 2 - _menuSupport.width / 2;
	}
}