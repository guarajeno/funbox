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
import com.minigloop.display.AtlasSprite;
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
	//private var _logo:Bitmap;
	private var _semicop:AtlasSprite;
	private var _menuSupport:Bitmap;
	private var _loadingText:Bitmap;
	
	private var _onEndLoad:Dynamic;
	private var _onEndAnimation:Dynamic;
	
	private var _isAssetsLoaded:Bool;
	private var _isDataLoaded:Bool;
	
	private var _isPreAssetsLoaded:Bool;
	private var _isPreDataLoaded:Bool;
	
	private var _callback:Dynamic;
	
	private var _tLoader:Float = 0;
	private var _isPaused = false;
	//private var STATE_PRELOADING:String = "preloading";
	//private var STATE_LOADING:String = "loading";
	//private var _state:String = "preloading";
	
	//private var _text:TextField;
	//private var _loaderCounter:Float = 0;
	
	public function new(canvas:Sprite, onEndLoad:Dynamic) 
	{
		super(canvas);
		
		_onEndLoad = onEndLoad;
		
		AssetsLoader.addAsset("img/common/animations/web_common_animations_loader.png", "web_common_animations_loader");
		AssetsLoader.addAsset("img/common/web_common_logo.png", "web_common_logo");
		AssetsLoader.addAsset("img/common/web_common_background.jpg", "web_common_background");
		AssetsLoader.addAsset("img/common/web_common_button_suport.png", "web_common_button_suport");
		AssetsLoader.addAsset("img/common/web_common_loader_text.png", "web_common_loader_text");
		AssetsLoader.load(function() {
			_isPreAssetsLoaded = true;
		});
		
		DataLoader.addData("img/common/animations/web_common_animations_loader.json", "web_common_animations_loader");
		DataLoader.load(function() {
			_isPreDataLoaded = true;
		});
	}
	
	private function init() 
	{
		//trace("init");
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		_menuSupport = AssetsLoader.getAsset("web_common_button_suport");
		_menuSupport.x = 500;
		_menuSupport.y = -400;
		_canvas.addChild(_menuSupport);
		
		_semicop = new AtlasSprite(
			_canvas,
			"web_common_animations_loader",
			"web_common_animations_loader"
		);
		
		_semicop.position.x = 890;
		_semicop.position.y = 200;
		
		_loadingText = AssetsLoader.getAsset("web_common_loader_text");
		_loadingText.x = 940;
		_loadingText.y = 500;
		_canvas.addChild(_loadingText);
		
		_onEndLoad();
		//animate();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		if (_semicop != null)
		{
			_semicop.update(dt);
		}
		
		if (_loadingText != null)
		{
			_tLoader += 0.07;
			
			if (_tLoader > 3.14)
			{
				_tLoader = 0;
			}
			
			_loadingText.alpha = Math.sin(_tLoader);
		}
		
		if (_isPaused) return;
		
		if (_isPreAssetsLoaded && _isPreDataLoaded)
		{
			_isPaused = true;
			_isPreAssetsLoaded = false;
			_isPreDataLoaded = false;
			init();
		}
		
		if (_isAssetsLoaded && _isDataLoaded)
		{
			_isPaused = true;
			_isAssetsLoaded = false;
			_isDataLoaded = false;
			animate();
		}
	}
	
	override public function destroy():Dynamic 
	{
		//_canvas.removeChild(_background);
		//_canvas.removeChild(_logo);
		_canvas.removeChild(_menuSupport);
		_semicop.destroy();
		
		//_background = null;
		//_logo = null;
	}
	
	public function addAsset(url:String, id:String) 
	{
		//trace("add asset");
		AssetsLoader.addAsset(url, id);
	}
	
	public function addData(url:String, id:String) 
	{
		//trace("add data");
		DataLoader.addData(url, id);
	}
	
	public function load(__callback:Dynamic) 
	{
		//trace("load");
		_isPaused = false;
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
		//trace("animate");
		Actuate.tween(_loadingText, 0.8, { y: -400 } ).ease(Elastic.easeInOut);
		Actuate.tween(_semicop.position, 0.8, { y: -300 } ).ease(Elastic.easeInOut);
		Actuate.tween(_menuSupport, 0.5, { y: 0 } ).delay(0.5).ease(Elastic.easeInOut).onUpdate(onAnimating).onComplete(_callback);
	}
	
	private function onAnimating() 
	{
		_tLoader += 0.05;
		_loadingText.alpha = Math.sin(_tLoader);
		
		_menuSupport.x = Global.stage.stageWidth / 2 - _menuSupport.width / 2;
	}
}