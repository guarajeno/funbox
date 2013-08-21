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

class RegisterPopup extends Screen
{
	private var _background:Bitmap;
	private var _register:Button;
	private var _close:Button;
	private var _name:TextField;
	private var _lastname:TextField;
	private var _user:TextField;
	private var _password:TextField;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		// background
		_background = AssetsLoader.getAsset("web_home_register_support");
		_background.x = 730;
		_background.y = 150;
		_canvas.addChild(_background);
		
		// login button
		_close = new Button(_canvas, "web_home_login_close02_normal", "web_home_login_close02_normal", "web_home_login_close02_normal", onClose_Click);
		_close.position.x = 1290;
		_close.position.y = 150;
		_close.setCollision(0, 0, 50, 50);
		
		// _register button
		_register = new Button(_canvas, "web_home_register_register_normal", "web_home_register_register_normal", "web_home_register_register_normal", onRegister_Click);
		_register.position.x = 950;
		_register.position.y = 600;
		_register.setCollision(0, 0, 250, 60);
		
		// user
		_name = new TextField();
		_name.x = 940;
		_name.y = 285;
		_name.width = 200;
		_name.height = 30;
		_name.defaultTextFormat = new TextFormat("Arial", 15, 0x000000, true, false, false, "", "", TextFormatAlign.LEFT);
		_name.selectable = true;
		_name.mouseEnabled = true;
		_name.text = "Usuario";
		_canvas.addChild(_name);
		
		// password
		_lastname = new TextField();
		_lastname.x = 940;
		_lastname.y = 355;
		_lastname.width = 200;
		_lastname.height = 30;
		_lastname.defaultTextFormat = new TextFormat("Arial", 15, 0x000000, true, false, false, "", "", TextFormatAlign.LEFT);
		_lastname.selectable = true;
		_lastname.mouseEnabled = true;
		_lastname.text = "Prueba";
		_canvas.addChild(_lastname);
		
		// user
		_user = new TextField();
		_user.x = 940;
		_user.y = 490;
		_user.width = 200;
		_user.height = 30;
		_user.defaultTextFormat = new TextFormat("Arial", 15, 0x000000, true, false, false, "", "", TextFormatAlign.LEFT);
		_user.selectable = true;
		_user.mouseEnabled = true;
		_user.text = "test";
		_canvas.addChild(_user);
		
		// password
		_password = new TextField();
		_password.x = 940;
		_password.y = 560;
		_password.width = 200;
		_password.height = 30;
		_password.defaultTextFormat = new TextFormat("Arial", 15, 0x000000, true, false, false, "", "", TextFormatAlign.LEFT);
		_password.selectable = true;
		_password.mouseEnabled = true;
		_password.text = "test";
		_canvas.addChild(_password);
	}
	
	private function onRegister_Click() 
	{
		//ScreenManager.showPopup(RegisterPopup);
		ScreenManager.closePopup();
	}
	
	private function onClose_Click() 
	{
		ScreenManager.closePopup();
	}
	
	override public function update(dt:Int):Dynamic 
	{
		_close.update(dt);
		_register.update(dt);
	}
	
	override public function destroy():Dynamic 
	{
		_canvas.removeChild(_background);
		_canvas.removeChild(_name);
		_canvas.removeChild(_lastname);
		_canvas.removeChild(_user);
		_canvas.removeChild(_password);
		
		_close.destroy();
		_register.destroy();
	}
}