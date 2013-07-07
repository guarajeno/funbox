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

class Black extends Enemy
{	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		addState("stand", "black", "black");
		setState("stand");
		setCollision(-40, -20, 80, 40);
		
		_speed = Math.random() * Global.minBlackSpeed + Global.maxBlackSpeed;
	}
}