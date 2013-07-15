package com.funbox.bcp.minigame3.entities.player;
import com.funbox.bcp.minigame3.entities.BaseActor;
import com.funbox.bcp.minigame3.entities.TouchObject;
import com.funbox.bcp.minigame3.Global;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;
import nme.ui.Mouse;

/**
 * ...
 * @author Cristian F. Shute
 */
class GamePlayer extends BaseActor {

	public function new(clipName:String, aniData:String, canvas:Sprite, offsetX:Float, offsetY:Float) {
		super(clipName, aniData, canvas, Global.StageWidth / 2, Global.StageHeight / 2);
		
		mOffsetX = offsetX;
		mOffsetY = offsetY;
		
		//Mouse.hide();
	}
	
	override public function update(dt:Int):Void {
		mX = Global.minigame.getMouseX();
		mY = Global.minigame.getMouseY();
		
		super.update(dt);
	}
	
	override public function free():Void {
		Mouse.show();
		
		super.free();
	}
	
}