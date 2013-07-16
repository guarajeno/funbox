package com.funbox.ania.component;

import com.funbox.ania.Global;
import com.funbox.ania.screen.Episode01Screen;
import com.funbox.ania.screen.MyGardenScreen;
import com.minigloop.display.Button;
import com.minigloop.display.VisualObject;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.Sprite;

/**
 * ...
 * @author guarajeno
 */

class MenuBar extends VisualObject
{
	private var _background:Bitmap;
	
	// buttons
	private var _btnLogo:Button;
	private var _btnEpisodes:Button;
	private var _btnTeachers:Button;
	private var _btnMyWorld:Button;
	private var _btnMyGarden:Button;
	private var _btnMyProjects:Button;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_background = AssetsLoader.getAsset("web_common_buttonsuport");
		_background.x = Global.stage.stageWidth / 2 - _background.width / 2;
		_background.y = -140;
		
		_canvas.addChild(_background);
		
		// logo
		_btnLogo = new Button(canvas, "web_common_logo", "web_common_logo", "web_common_logo", onLogo_Click);
		_btnLogo.setCollision(0, 0, 200, 200);
		_btnLogo.position.x = Global.stage.stageWidth / 2 - _btnLogo.collision.width / 2;
		_btnLogo.position.y = 0;
		
		// episodes
		_btnEpisodes = new Button(canvas, "web_common_button_episodes_normal", "web_common_button_episodes_over", "web_common_button_episodes_normal", onEpisodes_Click);
		_btnEpisodes.setCollision(-0, -0, 90, 40);
		_btnEpisodes.position.x = Global.stage.stageWidth / 2 - _btnEpisodes.collision.width / 2 - 470;
		_btnEpisodes.position.y = 70;
		
		// fathers and teachers
		_btnTeachers = new Button(canvas, "web_common_button_parentsandteachers_normal", "web_common_button_parentsandteachers_over", "web_common_button_parentsandteachers_normal", onTeachers_Click);
		_btnTeachers.setCollision(0, 0, 170, 40);
		_btnTeachers.position.x = Global.stage.stageWidth / 2 - _btnEpisodes.collision.width / 2 - 360;
		_btnTeachers.position.y = 70;
		
		// my world
		_btnMyWorld = new Button(canvas, "web_common_button_myworld_normal", "web_common_button_myworld_over", "web_common_button_myworld_normal", onMyWorld_Click);
		_btnMyWorld.setCollision(0, 0, 110, 40);
		_btnMyWorld.position.x = Global.stage.stageWidth / 2 - _btnEpisodes.collision.width / 2 + 150;
		_btnMyWorld.position.y = 70;
		
		// my garden
		_btnMyGarden = new Button(canvas, "web_common_button_mygarden_normal", "web_common_button_mygarden_over", "web_common_button_mygarden_normal", onMyGarden_Click);
		_btnMyGarden.setCollision(0, 0, 150, 40);
		_btnMyGarden.position.x = Global.stage.stageWidth / 2 - _btnEpisodes.collision.width / 2 + 280;
		_btnMyGarden.position.y = 70;
		
		// my projects
		_btnMyProjects = new Button(canvas, "web_common_button_myprojects_normal", "web_common_button_myprojects_over", "web_common_button_myprojects_normal", onMyProyects_Click);
		_btnMyProjects.setCollision(0, 0, 100, 40);
		_btnMyProjects.position.x = Global.stage.stageWidth / 2 - _btnEpisodes.collision.width / 2 + 450;
		_btnMyProjects.position.y = 70;
	}
	
	private function onLogo_Click() 
	{
		ScreenManager.gotoScreen(Episode01Screen);
		trace("HOME");
	}
	
	private function onMyProyects_Click() 
	{
		trace("MY PROJECTS");
	}
	
	private function onMyGarden_Click() 
	{
		ScreenManager.gotoScreen(MyGardenScreen);
		trace("MY GARDEN");
	}
	
	private function onMyWorld_Click() 
	{
		trace("MY WORLD");
	}
	
	private function onTeachers_Click() 
	{
		trace("TEACHERS");
	}
	
	private function onEpisodes_Click() 
	{
		trace("ON EPISODES");
	}
	
	override public function update(dt:Int):Void 
	{
		_btnLogo.update(dt);
		_btnEpisodes.update(dt);
		_btnTeachers.update(dt);
		_btnMyWorld.update(dt);
		_btnMyGarden.update(dt);
		_btnMyProjects.update(dt);
	}
}