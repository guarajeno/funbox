package com.funbox.ania.component;
import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Elastic;
import com.eclecticdesignstudio.motion.easing.Sine;
import com.funbox.ania.Global;
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

class ImagePopup extends VisualObject
{
	private var _img:Bitmap;
	private var _callback:Dynamic;
	
	public function new(canvas:Sprite, idImg:String, x:Float, y:Float, delay:Float) 
	{
		super(canvas);
		
		_img = AssetsLoader.getAsset(idImg);
		_img.x = Global.stage.stageWidth / 2 - _img.width / 2 + x;
		_img.y = Global.stage.stageHeight;
		
		_canvas.addChild(_img);
		
		Actuate.tween(_img, 0.8, { y:(y - _img.height / 2) }).delay(delay).ease(Elastic.easeInOut);
	}
}