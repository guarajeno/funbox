package com.funbox.bcp.minigame2.entities;

import com.funbox.bcp.minigame2.engine.effectManager.SpriteAndTextEffect;
import com.funbox.bcp.minigame2.entities.enemy.BotCollector;
import com.funbox.bcp.minigame2.Global;
import com.funbox.bcp.minigame2.type.EnumTouchObjectType;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class TouchObject extends BaseActor {

	public var isDead:Bool;
	private var mCanFall:Bool;
	private var mAreTouchableItems:Bool;
	
	private var mType:Int;
	private var mAppWidth:Int;
	private var mAppHeight:Int;
	
	private var mSpeed:Vector2D;
	
	public function type():Int { return mType; }
	public function getCanFall():Bool { return mCanFall; }
	
	public function new(clipName:String, aniData:String, canvas:Sprite, x:Float, y:Float, speed:Vector2D) {
		super(clipName, aniData, canvas, x, y);
		
		isDead = false;
		mCanFall = true;
		mAreTouchableItems = false;
		
		mAppWidth = Std.int(Global.stage.stageWidth);
		mAppHeight = Std.int(Global.stage.stageHeight);
		
		setSpeed(speed);
	}
	
	public function setSpeed(speed:Vector2D):Void {
		mSpeed = speed;
	}
	
	public function setObjectType(value:Int):Void {
		mType = value;
		
		switch(value) {
		case EnumTouchObjectType.PLAYER:
			mCanFall = false;
			mAreTouchableItems = false;
		case EnumTouchObjectType.COIN:
			mAreTouchableItems = true;
		case EnumTouchObjectType.MONEY:
			mAreTouchableItems = true;
		}
	}
	
	public function makePuffEffect():Void {
		if (mCanFall) {
			var clipScoreName:String = "";
			
			switch(mType) {
			case EnumTouchObjectType.COIN:
				clipScoreName = "spMinigame02_score_500";
			case EnumTouchObjectType.MONEY:
				clipScoreName = "spMinigame02_score_100";
			}
			
			var effect:SpriteAndTextEffect = Global.minigame.getVTEngine().getEffectManager().createSpriteAndTextEffect(
				"spMinigame02_check_secure", "spMinigame02_check_secure", clipScoreName, null, 
				new Vector2D(mX + getWidth() / 2, mY + getHeight() / 2), new Vector2D( -20, -43));
			effect.DieWithAlpha(true);
		}
		
		Global.minigame.getVTEngine().getEffectManager().createEffect(mX + getWidth() / 2, 
			mY + getHeight() / 2, "spMinigame02_ani_effect_puff", "spMinigame02_ani_effect_puff");
	}
	
	override public function update(dt:Int):Void {
		if (Global.minigame.isMousePressed() && mCanFall) {
			var mouseX:Int = Std.int(Global.minigame.getMouseX());
			var mouseY:Int = Std.int(Global.minigame.getMouseY());
			
			if (hitTestPoint(mouseX, mouseY)) {
				isDead = true;
				makePuffEffect();
				
				var score_earned:Int = 0;
				
				switch(mType) {
				case EnumTouchObjectType.COIN:
					score_earned = 500;
				case EnumTouchObjectType.MONEY:
					score_earned = 100;
				}
				
				var newScore:Int = Global.minigame.getGameHud().GetScore();
				newScore += score_earned;
				Global.minigame.getGameHud().SetScore(newScore);
			}
		}
		
		if (mAreTouchableItems) {
			if (mCanFall) {
				mX += mSpeed.x * dt;
				mY += mSpeed.y * dt;
				
				if (mY > (mAppHeight - getHeight() - Global.ScreenOffsetHeight)) {
					mCanFall = false;
					mY = mAppHeight - getHeight() - Global.ScreenOffsetHeight;
					
					var bot:BotCollector = Global.minigame.getVTEngine().getBotCollector();
					bot.addObjectInGround(this);
					Global.minigame.getVTEngine().getEntitiesController().removeEntitie(this);
				}
			}
		}
		
		super.update(dt);
	}
	
	override public function free():Void {
		mSpeed = null;
		
		super.free();
	}
	
}