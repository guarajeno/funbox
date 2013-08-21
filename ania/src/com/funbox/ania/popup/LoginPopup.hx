package com.funbox.ania.popup;

import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Quad;
import com.funbox.ania.component.ButtonPopup;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.component.MenuBar;
import com.funbox.ania.component.ImagePopup;
import com.funbox.ania.Global;
import com.funbox.ania.screen.HomeScreen;
import com.minigloop.display.Button;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import js.Lib;
import minimalcomps.InputText;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.text.TextField;
import nme.text.TextFieldType;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;

/**
 * ...
 * @author guarajeno
 */

class LoginPopup extends Screen
{
	private var _background:Bitmap;
	private var _login:Button;
	private var _close:Button;
	private var _register:Button;
	private var _user:TextField;
	private var _password:InputText;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		// background
		_background = AssetsLoader.getAsset("web_home_login_support");
		_background.x = 680;
		_background.y = 200;
		_canvas.addChild(_background);
		
		// login button
		_close = new Button(_canvas, "web_home_login_close02_normal", "web_home_login_close02_normal", "web_home_login_close02_normal", onClose_Click);
		_close.position.x = 1270;
		_close.position.y = 230;
		_close.setCollision(0, 0, 50, 50);
		
		// close button
		_login = new Button(_canvas, "web_home_register_register_normal", "web_home_register_register_normal", "web_home_register_register_normal", onLogin_Click);
		_login.position.x = 930;
		_login.position.y = 430;
		_login.setCollision(0, 0, 250, 60);
		
		// register button
		_register = new Button(_canvas, "transparent", "transparent", "transparent", onRegister_Click);
		_register.position.x = 780;
		_register.position.y = 520;
		_register.setCollision(0, 0, 200, 50);
		
		// user
		_user = new TextField();
		_user.x = 920;
		_user.y = 305;
		_user.width = 200;
		_user.height = 30;
		_user.defaultTextFormat = new TextFormat("Arial", 15, 0x000000, true, false, false, "", "", TextFormatAlign.LEFT);
		_user.selectable = true;
		_user.mouseEnabled = true;
		_user.text = "test";
		_canvas.addChild(_user);
		
		// password
		_password = new InputText(_canvas);
		//_password.edit
		_password.x = 920;
		_password.y = 375;
		_password.width = 200;
		_password.height = 30;
		//_password.defaultTextFormat = new TextFormat("Arial", 15, 0x000000, true, false, false, "", "", TextFormatAlign.LEFT);
		//_password.selectable = true;
		//_password.mouseEnabled = true;
		_password.text = "test";
		//_password.displayAsPassword = true;
		//_canvas.addChild(_password);
		
		var password = Lib.document.createElement("input");
		//div.style.background = "#FF0000";
		password.style.width = "100px";
		password.style.height = "100px";
		password.style.left = "100px";
		password.style.top = "100px";
		Lib.document.body.appendChild (password);
	}
	
	private function onRegister_Click() 
	{
		ScreenManager.closePopup();
		ScreenManager.showPopup(RegisterPopup);
	}
	
	private function onClose_Click() 
	{
		ScreenManager.closePopup();
	}
	
	private function onLogin_Click() 
	{
		ScreenManager.closePopup();
		cast(ScreenManager.currentScreen, HomeScreen).login();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_login.update(dt);
	}
	
	override public function destroy():Dynamic 
	{
		_canvas.removeChild(_background);
		_canvas.removeChild(_user);
		//_canvas.removeChild(_password);
		
		_close.destroy();
		_register.destroy();
		_login.destroy();
	}
}