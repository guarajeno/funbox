package com.minigloop.util;
import nme.display.Bitmap;
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
		_ids = new Array<String>();
		_loaders = new Array<Loader>();
		
		_index = 0;
	}
	
	static public function addAsset(url:String, id:String):Void
	{
		_urls.push(url);
		_ids.push(id);
	}
	
	static public function load(__callback:Dynamic):Void
	{
		_callback = __callback;
		loadAsset();
	}
	
	static public function loadAsset(e:Event = null):Void
	{
		if (_index < _urls.length)
		{
			var request:URLRequest = new URLRequest(_urls[_index]);
			_loader = new Loader();
			_loader.load(request);
			_loader.contentLoaderInfo.addEventListener(Event.COMPLETE, loadAsset);
			
			_loaders.push(_loader);
			_index++;
		}
		else
		{
			_callback();
		}
	}
	
	static public function getAsset(id:String):Bitmap
	{
		var i:Int;
			
		for (i in 0...(_urls.length))
		{
			if (_ids[i] == id)
			{
				return cast(_loaders[i].content, Bitmap);
			}
		}
		
		return null;
	}
}