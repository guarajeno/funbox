package com.funbox.bcp.minigame1.components;
import com.minigloop.display.SpriteEntity;
import com.minigloop.display.VisualObject;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author 
 */

class Hud extends VisualObject
{
	public var score:TextField;
	public var time:TextField;
	private var _tf:TextFormat;
	private var _life_1:SpriteEntity;
	private var _life_2:SpriteEntity;
	private var _life_3:SpriteEntity;
	
	private var _skin:Sprite;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_skin = new Sprite();
		_canvas.addChild(_skin);
		
		_tf = new TextFormat();
		_tf.size = 15;
		_tf.color = 0xFFFFFF;
		_tf.bold = true;
		_tf.font = "calibri";
		
		score = new TextField();
		score.x = 75;
		score.y = 3;
		score.text = "00000";
		score.setTextFormat(_tf);
		score.defaultTextFormat = _tf;
		_skin.addChild(score);
		
		time = new TextField();
		time.x = 210;
		time.y = 3;
		time.text = "0";
		time.setTextFormat(_tf);
		time.defaultTextFormat = _tf;
		//_skin.addChild(time);
		
		_life_1 = new SpriteEntity(_canvas);
		_life_1.addState("on", "life_on", null);
		_life_1.addState("off", "life_off", null);
		_life_1.position.x = 600;
		_life_1.position.y = 3;
		_life_1.setState("off");
		_life_1.setState("on");
		
		_life_2 = new SpriteEntity(_canvas);
		_life_2.addState("on", "life_on", null);
		_life_2.addState("off", "life_off", null);
		_life_2.position.x = 575;
		_life_2.position.y = 3;
		_life_2.setState("off");
		_life_2.setState("on");
		
		_life_3 = new SpriteEntity(_canvas);
		_life_3.addState("on", "life_on", null);
		_life_3.addState("off", "life_off", null);
		_life_3.position.x = 550;
		_life_3.position.y = 3;
		_life_3.setState("off");
		_life_3.setState("on");
	}
	
	public function setLifes(lifes:Int)
	{
		switch (lifes)
		{
			case 1:
			{
				_life_1.setState("off");
				_life_2.setState("on");
				_life_3.setState("on");
			}
			
			case 2:
			{
				_life_1.setState("off");
				_life_2.setState("off");
				_life_3.setState("on");
			}
			
			case 3:
			{
				_life_1.setState("off");
				_life_2.setState("off");
				_life_3.setState("off");
			}
		}
	}
	
	public function setTime(string:String) 
	{
		time.text = string;
		time.setTextFormat(_tf);
	}
	
	public function setPoints(string:String) 
	{
		score.text = string;
		score.setTextFormat(_tf);
	}
	
	override public function update(dt:Int):Void 
	{
		_life_1.update(dt);
		_life_2.update(dt);
		_life_3.update(dt);
		
		_skin.x = position.x;
		_skin.y = position.y;
	}
}