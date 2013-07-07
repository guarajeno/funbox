package com.funbox.bcp.minigame1.components;
import com.minigloop.display.Button;
import com.minigloop.display.VisualObject;
import com.minigloop.ui.Screen;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author 
 */

class FacebookBar extends VisualObject
{
	private var _nFriends:Int = 6;
	
	private var _background:Bitmap;
	private var _friends:Array<FriendFace>;
	private var _buttonLeft:Button;
	private var _buttonRight:Button;
	
	private var _friendsContainer:Sprite;
	private var _speedX:Float = 0;
	private var _acceleration:Float = 0.1;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_friends = new Array<FriendFace>();
		
		_background = AssetsLoader.getAsset("tab_support");
		_background.y = 480;
		canvas.addChild(_background);
		
		_friendsContainer = new Sprite();
		_canvas.addChild(_friendsContainer);
		
		// load friends
		var i:Int;
		for (i in 0 ... _nFriends)
		{
			var friend:FriendFace = new FriendFace(_friendsContainer);
			
			_friends.push(friend);
		}
		
		//_buttonLeft = new Button(canvas, "up", "over", "down", onLeftClick);
		//_buttonLeft.position.x = 10;
		//_buttonLeft.position.y = 560;
		//_buttonLeft.setCollision( -20, -20, 40, 40);
		
		//_buttonRight = new Button(canvas, "up", "over", "down", onRightClick);
		//_buttonRight.position.x = 580;
		//_buttonRight.position.y = 560;
		//_buttonRight.setCollision(-20, -20, 40, 40);
	}
	
	function onRightClick() 
	{
		_speedX = 20;
		trace("right");
	}
	
	function onLeftClick() 
	{
		_speedX = -20;
		trace("left");
	}
	
	override public function update(dt:Int):Dynamic 
	{		
		var i:Int;
		for (i in 0 ... _nFriends)
		{
			_friends[i].position.x = 40 + i * 95;
			_friends[i].position.y = 500;
			_friends[i].update(dt);
		}
		
		//_buttonLeft.update(dt);
		//_buttonRight.update(dt);
		
		_speedX *= 0.90;
		_friendsContainer.x += _speedX * dt / 30;
		
		if (_friendsContainer.x >= 0) _friendsContainer.x = 0;
		if (_friendsContainer.x <= -360) _friendsContainer.x = -360;
	}
}