package com.minigloop.util;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Loader;
import nme.events.Event;
import nme.net.URLRequest;

/**
 * ...
 * @author 
 */

class AssetsLoader
{
	static private var _loader:Loader;
	static private var _urls:Array<String>;
	static private var _tempUrls:Array<String>;
	static private var _ids:Array<String>;
	static private var _loaders:Array<Loader>;
	static private var _index:Int;
	static private var _callback:Dynamic;
	
	public function new() 
	{
		
	}
	
	static public function init():Void
	{
		_urls = new Array<String>();
		_tempUrls = new Array<String>();
		_ids = new Array<String>();
		_loaders = new Array<Loader>();
		
		//_index = 0;
	}
	
	static public function addAsset(url:String, id:String):Void
	{
		_tempUrls.push(url);
		_ids.push(id);
	}
	
	static public function load(__callback:Dynamic):Void
	{
		trace("--- INIT LOAD ASSETS ---");
		_index = 0;
		_callback = __callback;
		loadAsset();
	}
	
	static public function loadAsset(e:Event = null):Void
	{
		if (_index < _tempUrls.length)
		{
			var request:URLRequest = new URLRequest(_tempUrls[_index]);
			_loader = new Loader();
			_loader.load(request);
			_loader.contentLoaderInfo.addEventListener(Event.COMPLETE, loadAsset);
			
			_loaders.push(_loader);
			
			trace("asset loaded: [" + _tempUrls[_index] + "]");
			
			_index++;
		}
		else
		{
			_tempUrls = new Array<String>();
			_callback();
		}
	}
	
	static public function getAsset(id:String):Bitmap
	{
		var i:Int;
			
		for (i in 0...(_ids.length))
		{
			if (_ids[i] == id)
			{
				var bm:Bitmap = cast(_loaders[i].content, Bitmap);
				var bmd:BitmapData = new BitmapData(Std.int(bm.width), Std.int(bm.height), true, 0x00FFFFFF);
				bmd.draw(bm);
				
				var bm:Bitmap = new Bitmap(bmd);
				bm.cacheAsBitmap = true;
				
				return bm;
			}
		}
		
		return null;
	}
}