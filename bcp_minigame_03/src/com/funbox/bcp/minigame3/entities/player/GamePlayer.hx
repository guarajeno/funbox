package com.funbox.bcp.minigame3.entities.player;
import com.funbox.bcp.minigame3.entities.BaseActor;
import com.funbox.bcp.minigame3.entities.TouchObject;
import com.funbox.bcp.minigame3.Global;
import com.funbox.bcp.minigame3.screens.GameScreen;
import com.minigloop.ui.ScreenManager;
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
		
		mCharacter.setScaleX(0.7);
		mCharacter.setScaleY(0.7);
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
				
				
				mX = Global.minigame.getMouseX();
				mY = Global.minigame.getMouseY();
			}
		}
		
		
		
		super.update(dt);
	}
	
	override public function free():Void {
		Mouse.show();
		
		super.free();
	}
	
}