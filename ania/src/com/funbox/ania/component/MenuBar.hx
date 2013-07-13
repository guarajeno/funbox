package com.funbox.ania.component;

import com.minigloop.display.Button;
import com.minigloop.display.VisualObject;
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
	private var _btnEpisodes:Button;
	private var _btnTeachers:Button;
	private var _btnMyWorld:Button;
	private var _btnMyGarden:Button;
	private var _btnMyProjects:Button;
	private var _logo:Bitmap;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_background = AssetsLoader.getAsset("web_common_buttonsuport");
		_background.x = 5;
		_background.y = -100;
		
		// logo
		_logo = AssetsLoader.getAsset("web_common_logo");
		_logo.x = 500;
		_logo.y = 0;
		
		_canvas.addChild(_background);
		_canvas.addChild(_logo);
		
		// episodes
		_btnEpisodes = new Button(canvas, "web_common_button_episodes_normal", "web_common_button_episodes_over", "web_common_button_episodes_over", onEpisodes_Click);
		_btnEpisodes.position.x = 100;
		_btnEpisodes.position.y = 110;
		_btnEpisodes.setCollision(-45, -20, 90, 40);
		
		// fathers and teachers
		_btnTeachers = new Button(canvas, "web_common_button_parentsandteachers_normal", "web_common_button_parentsandteachers_over", "web_common_button_parentsandteachers_normal", onTeachers_Click);
		_btnTeachers.position.x = 200;
		_btnTeachers.position.y = 110;
		_btnTeachers.setCollision(-85, -20, 170, 40);
		
		// my world
		_btnMyWorld = new Button(canvas, "web_common_button_myworld_normal", "web_common_button_myworld_over", "web_common_button_myworld_over", onMyWorld_Click);
		_btnMyWorld.position.x = 720;
		_btnMyWorld.position.y = 110;
		_btnMyWorld.setCollision(-55, -20, 110, 40);
		
		// my garden
		_btnMyGarden = new Button(canvas, "web_common_button_mygarden_normal", "web_common_button_mygarden_over", "web_common_button_mygarden_over", onMyGarden_Click);
		_btnMyGarden.position.x = 840;
		_btnMyGarden.position.y = 110;
		_btnMyGarden.setCollision(-75, -20, 150, 40);
		
		// my projects
		_btnMyProjects = new Button(canvas, "web_common_button_myprojects_normal", "web_common_button_myprojects_over", "web_common_button_myprojects_over", onMyProyects_Click);
		_btnMyProjects.position.x = 1010;
		_btnMyProjects.position.y = 110;
		_btnMyProjects.setCollision( -50, -20, 100, 40);
	}
	
	private function onMyProyects_Click() 
	{
		trace("MY PROJECTS");
	}
	
	private function onMyGarden_Click() 
	{
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
		_btnEpisodes.update(dt);
		_btnTeachers.update(dt);
		_btnMyWorld.update(dt);
		_btnMyGarden.update(dt);
		_btnMyProjects.update(dt);
	}
}