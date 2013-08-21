package com.funbox.ania.screen;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Linear;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.Seed;
import com.funbox.ania.Global;
import com.funbox.ania.popup.LoginPopup;
import com.funbox.ania.popup.VideoPopup;
import com.funbox.ania.screen.LoaderScreen;
import com.minigloop.display.AtlasSprite;
import com.minigloop.display.Button;
import com.minigloop.display.SpriteEntity;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import js.Lib;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;

/**
 * ...
 * @author guarajeno
 */

class HomeScreen extends Screen
{
	// menu bar
	private var _menuBar:MenuBar;
	
	// images
	private var _background:Bitmap;
	
	// popups
	private var _floor:ImagePopup;
	private var _city:ImagePopup;
	
	private var _meshi:Bitmap;
	private var _meshiHotspot:Button;
	private var _meshiFace:AtlasSprite;
	private var _meshiCanvas:Sprite;
	
	private var _tree_1:ImagePopup;
	private var _tree_2:ImagePopup;
	private var _house:ImagePopup;
	private var _doit:ImagePopup;
	private var _video:ButtonPopup;
	
	private var _data:AtlasSprite;
	//private var _enter:ButtonPopup;
	private var _user:SpriteEntity;
	private var _name:TextField;
	
	private var _cloud:Bitmap;
	private var _semicoptero:AtlasSprite;
	private var _hotspotPreview:ButtonPopup;
	private var _hotspotTdata:ButtonPopup;
	
	private var _loaderScreen:LoaderScreen;
	private var _isPaused:Bool;
	private var _news:Bitmap;
	private var _tNews:Float = 0;
	private var _tCloud:Float = 0;
	private var _tMeshi:Float = 0;
	private var _isMeshiAnimating:Bool = false;
	private var _isTdataAnimating:Bool = false;
	private var _tdataLocker:Int = 0;
	
	private var _previews:Array<Bitmap>;
	private var _nextPreview:Bitmap;
	private var _currentPreview:Bitmap;
	private var _currentPreviewIndex:Int = 1;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_loaderScreen = new LoaderScreen(canvas, onLoaderScreenLoaded);
		_isPaused = true;
	}
	
	private function onLoaderScreenLoaded() 
	{
		// home
		_loaderScreen.addAsset("img/home/web_home_floor.png", "web_home_floor");
		_loaderScreen.addAsset("img/home/web_home_city.png", "web_home_city");
		_loaderScreen.addAsset("img/home/web_home_tree01.png", "web_home_tree01");
		_loaderScreen.addAsset("img/home/web_home_tree02.png", "web_home_tree02");
		_loaderScreen.addAsset("img/home/web_home_house.png", "web_home_house");
		_loaderScreen.addAsset("img/home/web_home_doityourself.png", "web_home_doityourself");
		_loaderScreen.addAsset("img/home/web_home_video.png", "web_home_video");
		_loaderScreen.addAsset("img/home/web_home_tadata.png", "web_home_tadata");
		_loaderScreen.addAsset("img/home/web_home_tadata_enter.png", "web_home_tadata_enter");
		_loaderScreen.addAsset("img/home/web_home_meshi.png", "web_home_meshi");
		_loaderScreen.addAsset("img/home/web_home_news_support.png", "web_home_news_support");
		_loaderScreen.addAsset("img/home/web_home_seed.png", "web_home_seed");
		_loaderScreen.addAsset("img/home/web_home_video01.png", "web_home_video01");
		_loaderScreen.addAsset("img/home/web_home_video02.png", "web_home_video02");
		_loaderScreen.addAsset("img/home/web_home_video03.png", "web_home_video03");
		_loaderScreen.addAsset("img/home/web_home_video04.png", "web_home_video04");
		_loaderScreen.addAsset("img/home/web_home_video05.png", "web_home_video05");
		_loaderScreen.addAsset("img/home/web_home_tadata_user.png", "web_home_tadata_user");
		_loaderScreen.addAsset("img/transparent.png", "transparent");
		
		// common
		_loaderScreen.addAsset("img/common/web_common_videosupport.png", "web_common_videosupport");
		_loaderScreen.addAsset("img/common/web_common_button_home_normal.png", "web_common_button_home_normal");
		_loaderScreen.addAsset("img/common/web_common_button_home_over.png", "web_common_button_home_over");
		_loaderScreen.addAsset("img/common/web_common_button_close_normal.png", "web_common_button_close_normal");
		_loaderScreen.addAsset("img/common/web_common_button_close_over.png", "web_common_button_close_over");
		_loaderScreen.addAsset("img/common/web_common_button_episodes_normal.png", "web_common_button_episodes_normal");
		_loaderScreen.addAsset("img/common/web_common_button_episodes_over.png", "web_common_button_episodes_over");
		_loaderScreen.addAsset("img/common/web_common_button_parentsandteachers_normal.png", "web_common_button_parentsandteachers_normal");
		_loaderScreen.addAsset("img/common/web_common_button_parentsandteachers_over.png", "web_common_button_parentsandteachers_over");
		_loaderScreen.addAsset("img/common/web_common_button_characters_normal.png", "web_common_button_characters_normal");
		_loaderScreen.addAsset("img/common/web_common_button_characters_over.png", "web_common_button_characters_over");
		_loaderScreen.addAsset("img/common/web_common_button_doityourself_normal.png", "web_common_button_doityourself_normal");
		_loaderScreen.addAsset("img/common/web_common_button_doityourself_over.png", "web_common_button_doityourself_over");
		_loaderScreen.addAsset("img/common/web_common_button_store_normal.png", "web_common_buttonstore_normal");
		_loaderScreen.addAsset("img/common/web_common_button_store_over.png", "web_common_button_store_over");
		_loaderScreen.addAsset("img/common/web_common_button_news_normal.png", "web_common_button_news_normal");
		_loaderScreen.addAsset("img/common/web_common_button_news_over.png", "web_common_button_news_over");
		_loaderScreen.addAsset("img/common/web_common_tadata.png", "web_common_tadata");
		_loaderScreen.addAsset("img/common/web_common_cloud_01.png", "web_common_cloud_01");
		_loaderScreen.addAsset("img/home/web_home_login_support.png", "web_home_login_support");
		_loaderScreen.addAsset("img/home/web_home_register_register_normal.png", "web_home_register_register_normal");
		_loaderScreen.addAsset("img/home/web_home_register_register_over.png", "web_home_register_register_over");
		_loaderScreen.addAsset("img/home/web_home_login_close02_normal.png", "web_home_login_close02_normal");
		_loaderScreen.addAsset("img/home/web_home_register_support.png", "web_home_register_support");
		_loaderScreen.addAsset("img/home/web_home_register_register_normal.png", "web_home_register_register_normal");
		
		_loaderScreen.addAsset("img/common/animations/web_common_animations_loader.png", "web_common_animations_loader");
		_loaderScreen.addAsset("img/common/animations/web_common_animations_tadata.png", "web_common_animations_tadata");
		_loaderScreen.addAsset("img/episode01/animations/web_epidose01_meshi_face.png", "web_epidose01_meshi_face");
		
		_loaderScreen.addData("img/common/animations/web_common_animations_loader.json", "web_common_animations_loader");
		_loaderScreen.addData("img/common/animations/web_common_animations_tadata.json", "web_common_animations_tadata");
		_loaderScreen.addData("img/episode01/animations/web_epidose01_meshi_face.json", "web_epidose01_meshi_face");
		
		_loaderScreen.load(init);
	}
	
	private function init() 
	{
		_loaderScreen.destroy();
		
		_isPaused = false;
		
		// background
		_background = AssetsLoader.getAsset("web_common_background");
		_canvas.addChild(_background);
		
		_cloud = AssetsLoader.getAsset("web_common_cloud_01");
		_cloud.x = 800;
		_cloud.y = 190;
		_canvas.addChild(_cloud);
		
		// popups
		_city = new ImagePopup(_canvas, "web_home_city", 0, 480, 1);
		_tree_1 = new ImagePopup(_canvas, "web_home_tree01", -350, 500, 1.5);
		_floor = new ImagePopup(_canvas, "web_home_floor", 0, 670, 0);
		_tree_2 = new ImagePopup(_canvas, "web_home_tree02", 610, 650, 1.5);
		_house = new ImagePopup(_canvas, "web_home_house", -500, 580, 2);
		_doit = new ImagePopup(_canvas, "web_home_doityourself", -300, 580, 2.5);
		
		// meshi power trio
		_meshi = AssetsLoader.getAsset("web_home_meshi");
		_meshi.x = 1340;
		_meshi.y = 1000;
		_canvas.addChild(_meshi);
		
		trace(_meshi);
		
		Actuate.tween(_meshi, 0.8, { y: 300 } ).ease(Elastic.easeInOut).delay(2.2);
		
		_meshiFace = new AtlasSprite(
			_canvas,
			"web_epidose01_meshi_face",
			"web_epidose01_meshi_face"
		);
		
		_meshiFace.position.x = 1545;
		_meshiFace.position.y = 600;
		_meshiFace.container.scaleX = 0.5;
		_meshiFace.container.scaleY = 0.5;
		_meshiFace.container.visible = false;
		
		Actuate.timer(3.5).onComplete(function() {
			_meshiFace.container.visible = true;
		});
		
		//Actuate.tween(_meshiFace.position, 0.8, { x: 600 } ).ease(Elastic.easeInOut).delay(2.2);
		
		_meshiHotspot = new ButtonPopup(
			_canvas,
			390,
			350,
			"transparent",
			"transparent",
			"transparent",
			2.2,
			onMeshiClick
		);
		
		_meshiHotspot.setCollision(0, 0, 450, 400);
		
		//_meshiHotspot.onMouseOver = function() {
			//_isMeshiAnimating = true;
		//};
		//
		//_meshiHotspot.onMouseOut = function() {
			//_isMeshiAnimating = false;
		//};
		
		
		_video = new ButtonPopup(
			_canvas,
			-50,
			520,
			"web_home_video",
			"web_home_video",
			"web_home_video",
			3,
			null
		);
		
		//_video.setCollision(130, 0, 380, 220);
		
		_previews = new Array<Bitmap>();
		
		var i:Int;
		for (i in 1...6)
		{
			var p:Bitmap = AssetsLoader.getAsset("web_home_video0" + i);
			p.x = 864;
			p.y = 408;
			p.alpha = 0;
			_previews.push(p);
			_canvas.addChild(p);
		}
		
		_hotspotPreview = new ButtonPopup(
			_canvas,
			-150,
			390,
			"transparent",
			"transparent",
			"transparent",
			3,
			onVideoClick
		);
		
		_hotspotPreview.setCollision(0, 0, 380, 220);
		
		_currentPreviewIndex = 0;
		
		Actuate.timer(4).onComplete(showPreview);
		
		_user = new SpriteEntity(_canvas);
		_user.addState("loged", "web_home_tadata_user", null);// , AssetsLoader.getAsset("web_home_tadata_user");
		_user.addState("nologed", "web_home_tadata_enter", null);
		_user.setState("loged");
		_user.setState("nologed");
		
		_user.position.x = 1150;
		_user.position.y = Global.stage.stageHeight;
		
		_name = new TextField();
		_name.defaultTextFormat = new TextFormat("Arial", 13, 0x000000, true, false, false, null, null, TextFormatAlign.LEFT);
		_name.text = Global.userName + " " + Global.userLastname;
		_name.x = 1233;
		_name.y = 1200;
		_name.visible = false;
		_canvas.addChild(_name);
		
		Actuate.tween(_user.position, 0.8, { y: 660 } ).ease(Elastic.easeInOut).delay(2.5);
		Actuate.tween(_name, 0.8, { y: 695 } ).ease(Elastic.easeInOut).delay(2.5);
		
		_data = new AtlasSprite(
			_canvas,
			"web_common_animations_tadata",
			"web_common_animations_tadata"
		);
		
		_data.position.x = 1300;
		_data.position.y = 1000;
		
		_hotspotTdata = new ButtonPopup(
			_canvas,
			160,
			600,
			"transparent",
			"transparent",
			"transparent",
			2.5,
			onTdata_Click
		);
		
		_hotspotTdata.setCollision(0, 0, 290, 230);
		
		_hotspotTdata.onMouseOver = function() 
		{
			_isTdataAnimating = true;
		};
		
		_hotspotTdata.onMouseOut = function() 
		{
			_isTdataAnimating = false;
		};
		
		Actuate.tween(_data.position, 0.8, { y: 570 } ).delay(2.5);
		
		_semicoptero = new AtlasSprite(
			_canvas,
			"web_common_animations_loader",
			"web_common_animations_loader"
		);
		
		_semicoptero.position.x = 0;
		_semicoptero.position.y = 150;
		
		Actuate.tween(_semicoptero.position, 1, { x: 410 } ).ease(Linear.easeNone).delay(0);
		
		_news = AssetsLoader.getAsset("web_home_news_support");
		_news.x = 1700;
		_news.y = 180;
		_canvas.addChild(_news);
		
		Actuate.tween(_news, 1, { x: 1400 } ).ease(Linear.easeNone).delay(0);
		
		_menuBar = new MenuBar(_canvas);
	}
	
	private function onTdata_Click() 
	{
		Lib.eval("showLoginPopup()");
		//ScreenManager.showPopup(LoginPopup);
	}
	
	private function onMeshiClick() 
	{
		
	}
	
	//public function login():Void
	//{
		//Lib.eval("getUser('funbox' , '123');");
		//Global.isUserLoged = true;
		//_user.setState("loged");
		//_name.visible = true;
	//}
	
	public function logged(data):Void
	{
		Global.isUserLoged = true;
		Global.userId = data.id;
		Global.userName = data.name;
		Global.userLastname = data.lastname;
		Global.userScore = data.score;
		//Global. = data.date_birthday;
		
		_hotspotTdata.position.y = -1000;
		trace("moviendo hotspot");
		
		_user.setState("loged");
		_name.visible = true;
		_name.text = data.name;
		_name.alpha = 0;
		
		Actuate.tween(_name, 0.3, { alpha: 1 } ).ease(Linear.easeNone);
	}
	
	private function showPreview() 
	{
		var i:Int;
		for (i in 0...5)
		{
			_previews[i].alpha = 0;
		}
		
		_currentPreview	= _previews[_currentPreviewIndex];
		
		_currentPreviewIndex++;
		
		if (_currentPreviewIndex > 4)
		{
			_currentPreviewIndex = 0;
			_nextPreview = _previews[0];
		}
		else
		{
			_nextPreview = _previews[_currentPreviewIndex];
		}
		
		_currentPreview.alpha = 1;
		_nextPreview.alpha = 0;
		
		Actuate.tween(_currentPreview, 1.3, { alpha: 0 } ).delay(2);
		Actuate.tween(_nextPreview, 1.3, { alpha: 1 } ).delay(2).onComplete(showPreview);
	}
	
	private function onVideoClick() 
	{
		trace("on video click");
		ScreenManager.gotoScreen(Episode01Screen);
	}
	
	private function emitSeeds() 
	{
		var r1:Float = Math.random();
		var r2:Float = Math.random();
		var r3:Float = Math.random();
		
		Actuate.tween(_canvas, 0.5, {}).onComplete(function() {
			new Seed(_canvas, 1400 + Math.floor(Math.random() * 60) - 30, 400 + Math.floor(Math.random() * 40) - 20);
		});
		
		Actuate.tween(_canvas, 0, {}).onComplete(function() {
			new Seed(_canvas, 1590 + Math.floor(Math.random() * 80) - 40, 400 + Math.floor(Math.random() * 40) - 20);
		});
		
		Actuate.tween(_canvas, 0.7, {}).onComplete(function() {
			new Seed(_canvas, 1750 + Math.floor(Math.random() * 60) - 30, 400 + Math.floor(Math.random() * 40) - 20);
		});
	}
	
	override public function end():Dynamic 
	{
		trace("ENDING");
		
		_menuBar.destroy();
		
		// background
		_canvas.removeChild(_background);
		
		// popups
		_city.end(1);
		_floor.end(1);
		_tree_1.end(0.5);
		_tree_2.end(0.5);
		
		_canvas.removeChild(_news);
		_canvas.removeChild(_meshi);
		_canvas.removeChild(_name);
		//_canvas.removeChild(_user);
		
		_semicoptero.destroy();
		_meshiFace.destroy();
		_meshiHotspot.destroy();
		_data.destroy();
		_video.destroy();
		_user.destroy();
		_house.destroy();
		_doit.destroy();
		
		var i:Int;
		for (i in 0...3)
		{
			_canvas.removeChild(_previews[i]);
		}
	}
	
	private function onEnter_Click() 
	{
		
	}
	
	private function onPrevious_Click() 
	{
		trace("click en previous");
		ScreenManager.showPopup(VideoPopup);
	}
	
	//private function show
	
	override public function update(dt:Int):Dynamic 
	{
		_loaderScreen.update(dt);
		
		if (_isPaused) return;
		
		//_enter.update(dt);
		_user.update(dt);
		_menuBar.update(dt);
		_semicoptero.update(dt);
		_meshiFace.update(dt);
		_meshiHotspot.update(dt);
		_video.update(dt);
		_hotspotPreview.update(dt);
		_hotspotTdata.update(dt);
		
		//trace("entro a update");
		_tdataLocker++;
		
		if (_tdataLocker <= 100)
		{
			//trace("update");
			_data.update(dt);
		}
		
		if (_isTdataAnimating)
		{
			_data.update(dt);
		}
		
		_news.y = 150 + 10 * Math.sin(_tNews);
		
		_cloud.x += 2;
		if (_cloud.x >= 2000)
		{
			_cloud.x = -_cloud.width;
		}
		
		_tNews += 0.06;
		if (_tNews >= 3.14) _tNews = 0;
		
		_tCloud += 0.005;
		if (_tCloud >= 3.14) _tCloud = 0;
		
		
		_tMeshi += 0.01;
		if (_tMeshi >= 1)
		{
			_tMeshi = 0;
			//emitSeeds();
		}
		//if (_isMeshiAnimating)
		//{
			//_tMeshi += 0.01;
			//
			//if (_tMeshi >= 1)
			//{
				//_tMeshi = 0;
				//Actuate.tween(_meshi, 0.07, { scaleY: 0.97 } ).ease(Linear.easeNone).onComplete(onMeshiScaleUpEnd).onUpdate(onMeshiScaleUpdate);
			//}
		//}
		
		super.update(dt);
	}
	
	//private function onMeshiScaleUpdate() 
	//{
		//_meshi.y = 720 - _meshi.height;
	//}
	//
	//private function onMeshiScaleUpEnd() 
	//{
		//Actuate.tween(_meshi, 0.4, { scaleY: 0.99 } ).ease(Linear.easeNone).onComplete(onMeshiScaleDownEnd).onUpdate(onMeshiScaleUpdate);
	//}
	//
	//private function onMeshiScaleDownEnd() 
	//{
		//emitSeeds();
	//}
}