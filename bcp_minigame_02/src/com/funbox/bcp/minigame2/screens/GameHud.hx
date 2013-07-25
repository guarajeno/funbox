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

	private var mPuntajeSprite:BaseActor;
	
	private var mScore:Int;
	private var mTime:Int;
	
	private var mTextFormat:TextFormat;
	private var mTF_Score:TextField;
	private var mTF_Time:TextField;
	
	public function GetScore():Int { return mScore; }
	public function SetScore(value:Int):Void { 
		mScore = value; 
		mTF_Score.text = NUtils.getDigitsByValue(mScore, 7);
	}
	
	public function GetTime():Int { return mTime; }
	public function SetTime(value:Int):Void { 
		mTime = value; 
		mTF_Time.text = NUtils.parseMillisecondsInClockFormat(mTime);
	}
	
	public function new(canvas:Sprite) {
		mCanvas = canvas;
		
		var posY:Float = 5;
		
		mPuntajeSprite = new BaseActor("spMinigame02_background_score", null,
			mCanvas, 5, 5);
			
		// texts
		mTextFormat = new TextFormat();
		mTextFormat.color = 0xFFFFFFFF;
		mTextFormat.size = 15;
		mTextFormat.bold = true;
		mTextFormat.font = "calibri";
		
		mTF_Score = new TextField();
		mTF_Score.setTextFormat(mTextFormat);
		mTF_Score.defaultTextFormat = mTextFormat;
		mTF_Score.text = "0000000";
		
		#if js
		mTF_Score.x = 72;
		mTF_Score.y = posY + 3;
		#end
		
		#if flash
		mTF_Score.x = 76;
		mTF_Score.y = posY + 1;
		#end
		
		mTF_Score.width = 180;
		mTF_Score.mouseEnabled = false;
		//mTF_Score.alwaysShowSelection = false;
		mTF_Score.selectable = false;
		
		mTF_Time = new TextField();
		mTF_Time.setTextFormat(mTextFormat);
		mTF_Time.defaultTextFormat = mTextFormat;
		mTF_Time.text = "00:00";
		
		#if js
		mTF_Time.x = 212;
		mTF_Time.y = posY + 3;
		#end
		
		#if flash
		mTF_Time.x = 215;
		mTF_Time.y = posY + 1;
		#end
		
		mTF_Time.width = 180;
		mTF_Time.mouseEnabled = false;
		//mTF_Time.alwaysShowSelection = false;
		mTF_Time.selectable = false;
		
		mCanvas.addChild(mTF_Score);
		mCanvas.addChild(mTF_Time);
		
		////
		SetScore(0);
		SetTime(0);
	}
	
	public function update(dt:Int):Void {
		mPuntajeSprite.update(dt);
	}
	
	public function free():Void {
		mPuntajeSprite.free();
		mPuntajeSprite = null;
		
		mCanvas.removeChild(mTF_Score);
		mCanvas.removeChild(mTF_Time);
		
		mTF_Score = null;
		mTF_Time = null;
		mCanvas = null;
	}
	
}