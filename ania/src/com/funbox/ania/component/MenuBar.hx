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
	private var _btnEpisodes:Button;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		_background = AssetsLoader.getAsset("web_common_buttonsuport");
		_background.x = 5;
		_background.y = -100;
		
		_canvas.addChild(_background);
		
		_btnEpisodes = new Button(canvas, "web_common_button_episodes_normal", "web_common_button_episodes_over", "web_common_button_episodes_over", _onEpisodes_Click);
		_btnEpisodes.position.x = 100;
		_btnEpisodes.position.y = 100;
	}
	
	private function _onEpisodes_Click() 
	{
		trace("ON EPISODES");
	}
	
	override public function update(dt:Int):Void 
	{
		_btnEpisodes.update(dt);
	}
}