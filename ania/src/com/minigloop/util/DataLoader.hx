package com.minigloop.util;
import nme.display.Bitmap;
import nme.display.Loader;
import nme.events.ErrorEvent;
import nme.events.Event;
import nme.net.URLLoader;
import nme.net.URLRequest;
import nme.utils.ByteArray;
/**
 * ...
 * @author 
 */

class DataLoader
{
	static private var _loader:URLLoader;
	static private var _urls:Array<String>;
	static private var _tempUrls:Array<String>;
	static private var _ids:Array<String>;
	static private var _loaders:Array<URLLoader>;
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
		_loaders = new Array<URLLoader>();
		
		//_index = 0;
	}
	
	static public function addData(url:String, id:String):Void
	{
		_tempUrls.push(url);
		_ids.push(id);
	}
	
	static public function load(__callback:Dynamic):Void
	{
		trace("--- INIT LOAD DATA ---");
		_index = 0;
		_callback = __callback;
		loadData();
	}
	
	static public function loadData(e:Event = null):Void
	{
		if (_index < _tempUrls.length)
		{
			var request:URLRequest = new URLRequest(_tempUrls[_index]);
			_loader = new URLLoader();
			_loader.load(request);
			_loader.addEventListener(Event.COMPLETE, loadData);
			_loader.addEventListener(ErrorEvent.ERROR, onError);
			
			_loaders.push(_loader);
			
			trace("data loaded: [" + _tempUrls[_index] + "]");
			
			_index++;
		}
		else
		{
			_tempUrls = new Array<String>();
			_callback();
		}
	}
	
	static private function onError(e:ErrorEvent):Void 
	{
		trace("Error loading file: " + _urls[_index]);
	}
	
	static public function getData(id:String):String
	{
		var i:Int;
			
		for (i in 0...(_ids.length))
		{
			if (_ids[i] == id)
			{
				return _loaders[i].data;
			}
		}
		
		return null;
	}
}