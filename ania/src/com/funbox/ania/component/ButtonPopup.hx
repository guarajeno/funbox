package com.funbox.ania.component;
import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Sine;
import com.funbox.ania.Global;
import com.minigloop.display.Button;
import com.minigloop.display.VisualObject;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.MovieClip;
import nme.display.Sprite;
import nme.events.MouseEvent;

/**
 * ...
 * @author 
 */

class ButtonPopup extends Button
{
	public function new(canvas:Sprite, x:Float, y:Float, upId:String, overId:String, downId:String, delay:Float, _callback:Dynamic) 
	{
		super(canvas, upId, overId, downId, _callback);
		position.x = Global.stage.stageWidth / 2 - skin.width / 2 + x;
		position.y = Global.stage.stageHeight;
		
		update(0);
		
		Actuate.tween(this.position, 0.8, { y:(y - skin.height / 2) }).delay(delay).ease(Elastic.easeInOut);
	}
	
	override public function update(dt:Int):Void
	{
		super.update(dt);
	}
}