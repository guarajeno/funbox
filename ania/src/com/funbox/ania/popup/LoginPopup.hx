package com.funbox.ania.popup;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.minigloop.display.Button;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class LoginPopup extends Screen
{
	private var _background:Bitmap;
	private var _login:Button;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		// background
		_background = AssetsLoader.getAsset("web_home_login_support");
		_background.x = 100;
		_background.y = 100;
		_canvas.addChild(_background);
		
		// _login button
		_login = new Button(canvas, "web_home_register_register_normal", "web_home_register_register_normal", "web_home_register_register_normal", onLogin_Click);
		_login.setCollision(0, 0, 195, 65);
		_login.position.x = 1150;
		_login.position.y = 0;
	}
	
	private function onLogin_Click() 
	{
		ScreenManager.closePopup();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_login.update(dt);
	}
	
	override public function destroy():Dynamic 
	{
		_canvas.removeChild(_background);
		_login.destroy();
	}
}