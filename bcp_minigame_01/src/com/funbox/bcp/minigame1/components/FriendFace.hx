package com.funbox.bcp.minigame1.components;
import com.minigloop.display.VisualObject;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author 
 */

class FriendFace extends VisualObject
{
	private var _container:Sprite;
	private var _background:Bitmap;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_container = new Sprite();
		canvas.addChild(_container);
		
		_background = AssetsLoader.getAsset("rank_support");
		_container.addChild(_background);
	}
	
	override public function update(dt:Int):Void 
	{
		_container.x = position.x;
		_container.y = position.y;
	}
}