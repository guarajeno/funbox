package com.funbox.bcp.minigame1.entities;
import com.funbox.bcp.minigame1.Global;
import com.minigloop.display.AtlasSprite;
import com.minigloop.display.SpriteEntity;
import com.minigloop.display.VisualObject;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class Enemy extends SpriteEntity
{
	private var _speed:Float;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
	}
	
	override public function update(dt:Int):Void 
	{
		position.y += _speed * dt / 30;
		
		if (position.y >= 550)
		{
			isDead = true;
		}
		
		super.update(dt);
	}
}