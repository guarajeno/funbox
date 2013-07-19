package com.funbox.bcp.minigame4.entities.player;
import com.funbox.bcp.minigame4.entities.BaseActor;
import com.funbox.bcp.minigame4.Global;
import com.funbox.bcp.minigame4.screens.GameScreen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.Vector2D;
import nme.display.Sprite;
import nme.ui.Mouse;

/**
 * ...
 * @author Cristian F. Shute
 */
class GamePlayer extends BaseActor {

	public function new(canvas:Sprite, x:Int, y:Int, offsetX:Float = 0, offsetY:Float = 0) {
		super("spMinigame04_player_stand", "spMinigame04_player_stand", 
			canvas, x, y);
		
		mCharacter.addState("spMinigame04_player_walk_right", "spMinigame04_player_walk_left",
			"spMinigame04_player_walk_left", 3, -3);
		mCharacter.addState("spMinigame04_player_walk_left", "spMinigame04_player_walk_right",
			"spMinigame04_player_walk_right", -7, -1);
			
		mCharacter.onEndAnimationCallback(onEndAnimation);
			
		mOffsetX = offsetX;
		mOffsetY = offsetY;
	}
	
	private function onEndAnimation():Void {
		switch (mCharacter.currentState()) {
		case "spMinigame04_player_walk_left":
			mCharacter.gotoState("spMinigame04_player_stand");
		case "spMinigame04_player_walk_right":
			mCharacter.gotoState("spMinigame04_player_stand");
		}
	}
	
	public function gotoState(state:String):Void {
		mCharacter.gotoState(state);
	}
	
	override public function update(dt:Int):Void {
		super.update(dt);
	}
	
	override public function free():Void {
		super.free();
	}
	
}