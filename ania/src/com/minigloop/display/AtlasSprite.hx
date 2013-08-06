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
	public var container:Bitmap;
	private var _containerData:BitmapData;
	private var _sourceBitmap:Bitmap;
	
	private var _frames:Array<Bitmap>;
	private var _currentIndex:Int;
	private var _sourceWidth:Int;
	private var _sourceHeight:Int;
	private var _offsetX:Float = 0;
	private var _offsetY:Float = 0;
	private var _onEndAnimation:Dynamic;
	private var _frameCounter:Int = 0;
	
	private var _atlas:Dynamic;
	
	public function new(canvas:Sprite, imgId:String, atlasId:String, align:String = "center", onEndAnimation:Dynamic = null) 
	{
		super(canvas);
		
		_currentIndex = 0;
		_sourceBitmap = AssetsLoader.getAsset(imgId);
		
		if (atlasId != null)
		{
			_atlas = Json.parse(DataLoader.getData(atlasId));
			_sourceWidth = _atlas.frames[0].sourceSize.w;
			_sourceHeight = _atlas.frames[0].sourceSize.h;
			_containerData = new BitmapData(_sourceWidth, _sourceWidth, true, 0x000000);
			container = new Bitmap(_containerData);
		}
		else
		{
			container = AssetsLoader.getAsset(imgId);
			trace("container: " + imgId + " " + container);
		}
		
		_canvas.addChild(container);
		
		//switch (align)
		//{
			//case "center":
			//{
				//_offsetX = 0;//-_sourceWidth / 2;
				//_offsetY = 0;//-_sourceHeight / 2;
			//}
		//}
		
		//_offsetX = -_sourceWidth / 2;
		//_offsetY = -_sourceHeight / 2;
		
		_onEndAnimation = onEndAnimation;
	}
	
	override public function update(dt:Int):Void
	{
		container.x = position.x + _offsetX;
		container.y = position.y + _offsetY;
		
		_frameCounter++;
		_frameCounter = _frameCounter % 2;
		
		if (_frameCounter == 0) return;
		
		if (_atlas != null)
		{
			var frame = _atlas.frames[_currentIndex];
			
			_containerData.fillRect(new Rectangle(0, 0, _sourceWidth, _sourceHeight), 0x00000000);
			
			_containerData.copyPixels(_sourceBitmap.bitmapData, new Rectangle(frame.frame.x, frame.frame.y, frame.frame.w, frame.frame.h), new Point(frame.spriteSourceSize.x, frame.spriteSourceSize.y));
			
			_currentIndex++;
			if (_currentIndex == _atlas.frames.length)
			{
				_currentIndex = 0;
				if (_onEndAnimation != null) _onEndAnimation();
			}
		}
	}
	
	public function destroy() 
	{
		_canvas.removeChild(container);
	}
}