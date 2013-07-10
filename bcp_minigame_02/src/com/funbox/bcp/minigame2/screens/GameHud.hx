package com.funbox.bcp.minigame2.screens;
import com.funbox.bcp.minigame2.entities.BaseActor;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.util.NUtils;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author Cristian F. Shute
 */
class GameHud {

	private var mCanvas:Sprite;
	
	private var mLifeSprite_1:BaseActor;
	private var mLifeSprite_2:BaseActor;
	private var mLifeSprite_3:BaseActor;
	
	private var mPuntajeSprite:BaseActor;
	
	private var mScore:Int;
	
	private var mTextFormat:TextFormat;
	private var mTextField:TextField;
	
	public function GetScore():Int { return mScore; }
	public function SetScore(value:Int):Void { 
		mScore = value; 
		mTextField.text = NUtils.getDigitsByValue(mScore, 7);
	}
	
	public function new(canvas:Sprite) {
		mCanvas = canvas;
		
		mLifeSprite_1 = new BaseActor("spMinigame02_life_on", null, mCanvas,
			Global.stage.stageWidth - 90, 3);
		mLifeSprite_2 = new BaseActor("spMinigame02_life_on", null, mCanvas,
			Global.stage.stageWidth - 65, 3);
		mLifeSprite_3 = new BaseActor("spMinigame02_life_on", null, mCanvas,
			Global.stage.stageWidth - 40, 3);
			
		mPuntajeSprite = new BaseActor("spMinigame02_background_score", null,
			mCanvas, 40, 45);
			
		mScore = 0;
		
		// texts
		mTextFormat = new TextFormat();
		mTextFormat.color = 0xFFFFFFFF;
		mTextFormat.size = 15;
		mTextFormat.bold = true;
		mTextFormat.font = "calibri";
		
		mTextField = new TextField();
		mTextField.setTextFormat(mTextFormat);
		mTextField.defaultTextFormat = mTextFormat;
		mTextField.text = "0000000";
		mTextField.x = 111;
		mTextField.y = 46;
		mTextField.width = 180;
		mTextField.mouseEnabled = false;
		mTextField.alwaysShowSelection = false;
		mTextField.selectable = false;
		
		mCanvas.addChild(mTextField);
	}
	
	public function update(dt:Int):Void {
		mLifeSprite_1.update(dt);
		mLifeSprite_2.update(dt);
		mLifeSprite_3.update(dt);
		mPuntajeSprite.update(dt);
	}
	
	public function free():Void {
		mLifeSprite_1.free();
		mLifeSprite_2.free();
		mLifeSprite_3.free();
		mPuntajeSprite.free();
		
		mLifeSprite_1 = null;
		mLifeSprite_2 = null;
		mLifeSprite_3 = null;
		mPuntajeSprite = null;
	}
	
}