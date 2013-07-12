package com.minigloop.util;
import nme.display.Bitmap;
import nme.display.Loader;
import nme.events.ErrorEvent;
import nme.events.Event;
import nme.media.Sound;
import nme.media.SoundChannel;
import nme.media.SoundTransform;
import nme.net.URLLoader;
import nme.net.URLRequest;
import nme.utils.ByteArray;

/**
 * ...
 * @author 
 */

class SoundManager
{
	static private var _sound:Sound;
	static private var _urls:Array<String>;
	static private var _ids:Array<String>;
	static private var _sounds:Array<Sound>;
	static private var _channels:Array<SoundChannel>;
	static private var _index:Int;
	static private var _callback:Dynamic;
	
	static private var _channel:SoundChannel;
	
	public function new() 
	{
		
	}
	
	static public function init():Void
	{
		_urls = new Array<String>();
		_ids = new Array<String>();
		_sounds = new Array<Sound>();
		_channels = new Array<SoundChannel>();
		
		_index = 0;
	}
	
	static public function addSound(url:String, id:String):Void
	{
		_urls.push(url);
		_ids.push(id);
	}
	
	static public function load(__callback:Dynamic):Void
	{
		_callback = __callback;
		
		// CAMBIAR ESTO: quitar callback y descomentar loadSound
		//_callback();
		loadSound();
	}
	
	static private function loadSound(e:Event = null):Void
	{
		if (_index < _urls.length)
		{
			var request:URLRequest = new URLRequest(_urls[_index]);
			_sound = new Sound();
			
			_sound.load(request);
			_sound.addEventListener(Event.COMPLETE, loadSound);
			_sound.addEventListener(ErrorEvent.ERROR, onError);
			
			_sounds.push(_sound);
			//_channels.push(null);
			
			trace("sound loaded: [" + _ids[_index] + "]");
			
			_index++;
		}
		else
		{
			_callback();
		}
	}
	
	static private function onError(e:ErrorEvent):Void 
	{
		trace("Error loading sound: " + _urls[_index]);
	}
	
	static public function getSound(id:String):Sound
	{
		var i:Int;
			
		for (i in 0...(_urls.length))
		{
			if (_ids[i] == id)
			{
				return _sounds[i];
			}
		}
		
		return null;
	}
	
	static public function getChannelId(id:String):Int
	{
		var i:Int;
			
		for (i in 0...(_urls.length))
		{
			if (_ids[i] == id)
			{
				return i;
			}
		}
		
		return -1;
	}
	
	static public function play(id:String, loop:Bool = false):Void
	{
		var channel:SoundChannel = getSound(id).play(0, loop ? 9999 : 0);
		_channels.push(channel);
	}
	
	static public function stopAll():Void
	{
		trace("stop all");
		trace(_channels.length);
		var i:Int;
		for (i in 0...(_sounds.length - 1))
		{
			_channels[i].stop();
			_channels[i] = null;
		}
		
		_channels = new Array<SoundChannel>();
	}
}