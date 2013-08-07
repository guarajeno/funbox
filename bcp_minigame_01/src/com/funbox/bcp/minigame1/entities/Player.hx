package com.funbox.bcp.minigame1.entities;
import com.minigloop.display.AtlasSprite;
import com.minigloop.display.SpriteEntity;
import com.minigloop.display.VisualObject;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.SoundManager;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class Player extends SpriteEntity
{
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		addState("stand", "hand", null);
		addState("die", "die", "die");
		addState("hit", "hit", "hit");
		setState("stand");
		
		setCollision(-25, -40, 50, 80);
	}
	
	override public function update(dt:Int):Void 
	{
		if (isDead) return;
		
		super.update(dt);
	}
	
	override private function onEndAnimation():Void 
	{
		switch (state)
		{
			case "die":
			{
				isDead = true;
			}
			
			case "hit":
			{
				setState("stand");
			}
		}
	}
	
	override public function onHit():Void 
	{
		SoundManager.play("hit");
		setState("hit");
		super.onHit();
	}
}