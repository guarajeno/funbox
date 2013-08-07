package com.funbox.bcp.minigame1.entities;
import com.funbox.bcp.minigame1.Global;
import com.minigloop.display.AtlasSprite;
import com.minigloop.display.VisualObject;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class Virus extends Enemy
{
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		addState("stand", "virus", "virus");
		setState("stand");
		setCollision(-25, -25, 60, 60);
		
		_speed = Math.random() * Global.minVirusSpeed + Global.maxVirusSpeed;
	}
}