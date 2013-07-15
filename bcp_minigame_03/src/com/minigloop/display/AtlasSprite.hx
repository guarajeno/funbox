package com.minigloop.display;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.Vector2D;
import haxe.Json;
import haxe.Resource;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Sprite;
import nme.geom.Point;
import nme.geom.Rectangle;

/**
 * ...
 * @author 
 */

class AtlasSprite extends VisualObject
{
	private var _container:Sprite;
	private var _frames:Array<Bitmap>;
	private var _currentIndex:Int;
	private var _sourceWidth:Int;
	private var _sourceHeight:Int;
	private var _offsetX:Float;
	private var _offsetY:Float;
	
	private var mImageOffsetX:Float;
	private var mImageOffsetY:Float;
	
	private var mAlpha:Float;
	
	private var _scaleX:Float;
	private var _scaleY:Float;
	
	private var mCanPlay:Bool;
	
	private var mCallbackFunction:Dynamic;
	
	private var mTimeCounter:Int;
	private var mTimeLimitByFrame:Float;
	
	public function getAlpha():Float 			{ return mAlpha;  }
	public function setAlpha(value:Float):Void 	{ 
		mAlpha = value;
		_container.alpha = mAlpha;
	}
	
	public function setOffsetX(value:Float):Void { mImageOffsetX = value; }
	public function setOffsetY(value:Float):Void { mImageOffsetY = value; }
	
	public function container():Sprite { return _container; }
	
	public function currentFrame():Bitmap { return _frames[_currentIndex]; }
	public function playing():Bool { return mCanPlay; }
	
	public function currentWidth():Float { return _frames[_currentIndex].width; }
	public function currentHeight():Float { return _frames[_currentIndex].height; }
	
	public function getScaleX():Float { return _scaleX; }
	public function getScaleY():Float { return _scaleY; }
	
	public function getCurrentIndex():Int { return _currentIndex; }
	public function getLength():Int { return _frames.length; }
	
	public function setScaleX(value:Float):Void { _scaleX = value; }
	public function setScaleY(value:Float):Void { _scaleY = value; }
	
	public function new(canvas:Sprite, imgId:String, atlasId:String, align:String = "center") 
	{
		super(canvas);
		
		_scaleX = 1;
		_scaleY = 1;
		
		mCallbackFunction = null;
		
		mImageOffsetX = 0;
		mImageOffsetY = 0;
		mTimeCounter = 0;
		mTimeLimitByFrame = Math.round(1000 / 30); // because needs to run in 30 fps
		
		mCanPlay = true;
		
		_container = new Sprite();
		_canvas.addChild(_container);
		
		_currentIndex = 0;
		_frames = new Array<Bitmap>();
		
		var obj:Dynamic = Json.parse(DataLoader.getData(atlasId));

		var i:Int;
		for (i in 0...(obj.frames.length)) {
			var frame = obj.frames[i];
			_sourceWidth = frame.spriteSourceSize.w;
			_sourceHeight = frame.spriteSourceSize.h;
			
			var src:BitmapData = AssetsLoader.getAsset(imgId).bitmapData;
			var bmd:BitmapData = new BitmapData(frame.sourceSize.w, frame.sourceSize.h, true, 0x00000000);
			bmd.copyPixels(src, new Rectangle(frame.frame.x, frame.frame.y, frame.frame.w, frame.frame.h), new Point(frame.spriteSourceSize.x, frame.spriteSourceSize.y));
			
			var bm:Bitmap = new Bitmap(bmd);
			_frames.push(bm);
		}
		
		switch (align)
		{
			case "center":
			{
				_offsetX = -_sourceWidth / 2;
				_offsetY = -_sourceHeight / 2;
			}
		}
	}
	
	public function onEndAnimationCallback(callbackFuncion:Dynamic = null):Void {
		mCallbackFunction = callbackFuncion;
	}
	
	public function gotoAndPlay(frame:Int):Void {
		if (_container.numChildren > 0) {
			_container.removeChildAt(0);
		}
		
		_container.addChild(_frames[frame]);
		_frames[frame].scaleX = _scaleX;
		_frames[frame].alpha = mAlpha;
		
		_container.x = position.x + _offsetX + mImageOffsetX;
		_container.y = position.y + _offsetY + mImageOffsetY;
		
		_currentIndex = frame;
		mCanPlay = true;
	}
	
	public function gotoAndStop(frame:Int):Void {
		if (_container.numChildren > 0) {
			_container.removeChildAt(0);
		}
		
		_container.addChild(_frames[frame]);
		_frames[frame].scaleX = _scaleX;
		_frames[frame].alpha = mAlpha;
		
		_container.x = position.x + _offsetX + mImageOffsetX;
		_container.y = position.y + _offsetY + mImageOffsetY;
		
		_currentIndex = frame;
		mCanPlay = false;
	}
	
	public function stop():Void {
		mCanPlay = false;
	}
	
	override public function update(dt:Int):Void {
		if (mCanPlay) {
			if (_container.numChildren > 0) {
				_container.removeChildAt(0);
			}
			
			_container.addChild(_frames[_currentIndex]);
			_frames[_currentIndex].scaleX = _scaleX;
			
			if ((mTimeCounter + dt) >= mTimeLimitByFrame) {
				mTimeCounter = 0;
				_currentIndex++;
			}
			else { mTimeCounter += dt; }
			
			if (_currentIndex == _frames.length) {
				if (mCallbackFunction != null) {
					mCallbackFunction();
				}
				
				_currentIndex = 0;
			}
		}
		
		_container.x = position.x + _offsetX + mImageOffsetX;
		_container.y = position.y + _offsetY + mImageOffsetY;
	}
	
	public function destroy() {
		if (_canvas.contains(_container)) {
			_canvas.removeChild(_container);
		}
		
		_container = null;
		_frames = null;
		mCallbackFunction = null;
	}
}