package com.funbox.bcp.minigame4.entities.card;
import com.funbox.bcp.minigame4.entities.BaseActor;
import com.funbox.bcp.minigame4.entities.enemy.MosaicosGroup;
import com.funbox.bcp.minigame4.entities.player.GamePlayer;
import com.funbox.bcp.minigame4.Global;
import com.funbox.bcp.minigame4.util.NInterval;
import com.funbox.bcp.minigame4.util.NLinearMovement;
import com.minigloop.display.AtlasSprite;
import nme.display.Sprite;

/**
 * ...
 * @author Cristian F. Shute
 */
class GameCard extends BaseActor {

	private var mCurrentState:Int;
	
	private var mPlayerRef:GamePlayer;
	private var mMosaicosGroupRef:MosaicosGroup;
	
	private var mCurrentAnimationPlayer:AtlasSprite;
	
	private var mLinearMovement:NLinearMovement;
	private var mCardFinishInterval:NInterval;
	
	private var mCardInitX:Float;
	
	public function new(canvas:Sprite, x:Int, y:Int, offsetX:Float = 0, offsetY:Float = 0) {
		super("spMinigame04_bcp_card", null, canvas, x, y);
		
		mCurrentState = -1;
		mBitmap.scaleX = mBitmap.scaleY = 0.5;
		
		mCardInitX = this.getX();
	}
	
	public function gotoState(state:Int):Void {
		mCurrentState = state;
		
		mCurrentAnimationPlayer = mPlayerRef.getCharacter().currentAnimation();
	}
	
	public function setReferences(player:GamePlayer, mosaicosGroup:MosaicosGroup):Void {
		mPlayerRef = player;
		mMosaicosGroupRef = mosaicosGroup;
	}
	
	public function onDisappearAll():Void {
		mCardFinishInterval = new NInterval(onFinishInterval, 1300);
	}
	
	private function onFinishInterval():Void {
		Global.minigame.onEndGame();
		
		//mCardFinishInterval.free();
		//mCardFinishInterval = null;
		
		//mLinearMovement = new NLinearMovement(mBitmap.x, mBitmap.y, mBitmap.x + 80, mBitmap.y - 150, 0.07);
		//mLinearMovement.setCallback(onFinishLinear);
	}
	
	private function onFinishLinear():Void {
		mLinearMovement.free();
		mLinearMovement = null;
		
		mCardFinishInterval = new NInterval(onFinishIntervalLinear, 1000);
	}
	
	private function onFinishIntervalLinear():Void {
		mCardFinishInterval.free();
		mCardFinishInterval = null;
		
		Global.minigame.onEndGame();
	}
	
	override public function update(dt:Int):Void {
		if (mLinearMovement != null) { 
			setX(mLinearMovement.getX());
			setY(mLinearMovement.getY());
			mBitmap.scaleX += 0.002;
			mBitmap.scaleY += 0.002;
			mLinearMovement.update(dt);
		}
		
		if (mCardFinishInterval != null) { mCardFinishInterval.update(dt); }
		
		var atlas:AtlasSprite = null;
		var currentIndex:Int = -1;
		var maxIndex:Int = -1;
		
		switch (mCurrentState) {
		case MosaicosGroup.ST_WALK_RIGHT:
			atlas = mPlayerRef.getCharacter().currentAnimation();
			currentIndex = atlas.getCurrentIndex();
			maxIndex = atlas.getLength();
			
			if (mCurrentAnimationPlayer != atlas) {
				mCurrentState = -1;
				this.setX(mCardInitX);
			}
			else {
				switch(currentIndex) {
				case 0: this.setX(mCardInitX - 4);
				case 1: this.setX(mCardInitX - 5);
				case 2: this.setX(mCardInitX - 6);
				case 3: this.setX(mCardInitX - 7);
				case 4: this.setX(mCardInitX - 8);
				case 5: this.setX(mCardInitX - 9);
				case 6: this.setX(mCardInitX - 9);
				case 7: this.setX(mCardInitX - 4);
				case 8: this.setX(mCardInitX);
				case 9: this.setX(mCardInitX + 3);
				case 10: this.setX(mCardInitX + 8);
				case 11: this.setX(mCardInitX + 8);
				case 12: this.setX(mCardInitX + 8);
				case 13: this.setX(mCardInitX + 8);
				} 
			}
		case MosaicosGroup.ST_WALK_LEFT:
			atlas = mPlayerRef.getCharacter().currentAnimation();
			currentIndex = atlas.getCurrentIndex();
			maxIndex = atlas.getLength();
			
			if (mCurrentAnimationPlayer != atlas) {
				mCurrentState = -1;
				this.setX(mCardInitX);
			}
			else {
				switch(currentIndex) {
				case 0: this.setX(mCardInitX + 4);
				case 1: this.setX(mCardInitX + 5);
				case 2: this.setX(mCardInitX + 6);
				case 3: this.setX(mCardInitX + 7);
				case 4: this.setX(mCardInitX + 8);
				case 5: this.setX(mCardInitX + 9);
				case 6: this.setX(mCardInitX + 9);
				case 7: this.setX(mCardInitX + 4);
				case 8: this.setX(mCardInitX);
				case 9: this.setX(mCardInitX - 6);
				case 10: this.setX(mCardInitX - 12);
				case 11: this.setX(mCardInitX - 12);
				case 12: this.setX(mCardInitX - 12);
				case 13: this.setX(mCardInitX - 12);
				}
			}
		}
		
		super.update(dt);
	}
}