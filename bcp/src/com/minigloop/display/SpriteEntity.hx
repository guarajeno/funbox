package com.minigloop.display;
import nme.display.MovieClip;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class SpriteEntity extends VisualObject
{
	private var _animations:Hash<AtlasSprite>;
	private var _animation:AtlasSprite;
	public var state:String;
	
	public var skin:MovieClip;
	public var collision:MovieClip;
	
	public var isHited:Bool;
	public var numHits:Int = 0;
	public var isDead:Bool;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		skin = new MovieClip();
		_canvas.addChild(skin);
		
		collision = new MovieClip();
		_canvas.addChild(collision);
		
		_animations = new Hash<AtlasSprite>();
	}
	
	public function setCollision(x:Float, y:Float, width:Float, height:Float):Void
	{
		collision.graphics.clear();
		collision.graphics.beginFill(0xFFFFFF, 0.01);
		collision.graphics.drawRect(x + width / 2, y + height / 2, width, height);
		collision.graphics.endFill();
	}
	
	public function addState(id:String, sourceId:String, atlasId:String):Void
	{
		_animations.set(id, new AtlasSprite(_canvas, sourceId, atlasId, "center", onEndAnimation));
	}
	
	public function setState(state:String):Void
	{
		if (this.state == state) return;
		
		this.state = state;
		if (skin.numChildren > 0) skin.removeChildAt(0);
		_animation = _animations.get(state);
		skin.addChild(_animation.container);
	}
	
	private function onEndAnimation():Void
	{
		
	}
	
	public function onHit():Void
	{
		isHited = true;
		numHits++;
	}
	
	override public function update(dt:Int):Void
	{
		skin.x = position.x;
		skin.y = position.y;
		
		collision.x = position.x;
		collision.y = position.y;
		
		if (_animation != null) _animation.update(dt);
	}
	
	public function destroy():Void
	{
		if (skin.numChildren > 0) skin.removeChildAt(0);
		if (_canvas.contains(skin)) _canvas.removeChild(skin);
	}
}