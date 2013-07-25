package com.funbox.bcp.minigame3.entities.player;
import com.funbox.bcp.minigame3.engine.effectManager.BaseEffect;
import com.funbox.bcp.minigame3.entities.BaseActor;
import com.funbox.bcp.minigame3.entities.TouchObject;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.screens.GameScreen;
import com.funbox.bcp.minigame3.type.EnumTouchObjectType;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.SoundManager;
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
		
		mCharacter.setScaleX(1.1);
		mCharacter.setScaleY(1.1);
		mCharacter.currentAnimation().gotoAndStop(0);
		
		//Mouse.hide();
	}
	
	override public function update(dt:Int):Void {
		var gameScreen:GameScreen = GameScreen.instance;
		
		if (gameScreen != null) {
			if (!gameScreen.isPausedGame()) {
				
				
				if (Global.minigame.isMousePressed() && mCharacter.currentAnimation().getCurrentIndex() == 0) {
					mCharacter.currentAnimation().gotoAndPlay(0);
				}
				
				if (mCharacter.currentAnimation().getCurrentIndex() == (mCharacter.currentAnimation().getLength() - 1)) {
					mCharacter.currentAnimation().gotoAndStop(0);
				}
				
				/*var objsArray:Array<TouchObject> = Global.minigame.getVTEngine().getEntitiesController().getEntities();
				
				var i:Int = 0;
				var length:Int = objsArray.length - 1;
				
				while (i <= length) {
					var sObj:TouchObject = objsArray[i];
					
					if (sObj != null) {
						if (objsArray[i].hitTestPoint(Std.int(mX), Std.int(mY))) {
							objsArray[i].isDead = true;
							
							///////////////////////////
							var clipScoreName = "spMinigame02_score_100";
		
							Global.minigame.getVTEngine().getEffectManager().createEffect(objsArray[i].getX() + objsArray[i].getWidth() / 2, 
								objsArray[i].getY() + objsArray[i].getHeight() / 2, "spMinigame03_ani_effect_puff", "spMinigame03_ani_effect_puff");
								
							var baseEffect:BaseEffect = Global.minigame.getVTEngine().getEffectManager().createEffect(objsArray[i].getX() + objsArray[i].getWidth() / 2, 
								objsArray[i].getY() + objsArray[i].getHeight() / 2, "spMinigame03_score_100", null);
							baseEffect.DieWithAlpha(true);
							///////////////////////////
				
							var score_earned = 100;
							
							SoundManager.play("fx_sapo");
							
							var newScore:Int = Global.minigame.getGameHud().GetScore();
							newScore += score_earned;
							Global.minigame.getGameHud().SetScore(newScore);
						}
					}
					
					i++;
				}*/
				
				mX = Global.minigame.getMouseX();
				mY = Global.minigame.getMouseY();
				
				if (mY >= (Global.StageHeight - 40)) {
					mY = (Global.StageHeight - 40);
				}
			}
		}
		
		super.update(dt);
	}
	
	override public function free():Void {
		Mouse.show();
		
		super.free();
	}
	
}