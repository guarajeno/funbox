package com.funbox.bcp.minigame1.screens;
import com.funbox.bcp.minigame1.Global;
import com.minigloop.ui.Screen;
import com.minigloop.ui.ScreenManager;
import com.minigloop.util.AssetsLoader;
import com.minigloop.util.DataLoader;
import com.minigloop.util.SoundManager;
import nme.ui.Mouse;
#if js
import js.Lib;
#end
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author 
 * 
 */

class ScoreCardScreen extends Screen
{
	private var _message:TextField;
	private var _box_1:Sprite;
	private var _mouseX:Float;
	private var _mouseY:Float;
	
	private var _volver:Bitmap;
	private var _regresar:Bitmap;
	private var _fb:Bitmap;
	private var _tw:Bitmap;
	
	public function new(canvas:Sprite) 
	{
		super(canvas);
		
		var tf:TextFormat = new TextFormat();
		tf.size = 16;
		tf.color = 0xFFFFFF;
		tf.italic = true;
		tf.bold = true;
		tf.font = "Arial";
		
		_canvas.addChild(AssetsLoader.getAsset("scorecard"));
		
		_message = new TextField();
		_message.setTextFormat(tf);
		_message.text = "Hiciste " + Global.totalPoints + " puntos mientras practicabas para prevenir este fraude.";
		_message.width = 800;
		_message.height = 400;
		_message.multiline = true;
		_message.x = 55;
		_message.y = 200;
		_message.setTextFormat(tf);
		_canvas.addChild(_message);
		
		SoundManager.play("scorecard");
		
		
		
		//_volver = AssetsLoader.getAsset("volver");
		//_volver.x = 325;
		//_volver.y = 341;
		//_volver.visible = false;
		//
		//_regresar = AssetsLoader.getAsset("regresar");
		//_regresar.x = 165;
		//_regresar.y = 342;
		//_regresar.visible = false;
		
		_fb = AssetsLoader.getAsset("facebook");
		_fb.x = 280;
		_fb.y = 290;
		_fb.visible = false;
		
		_tw = AssetsLoader.getAsset("twitter");
		_tw.x = 320;
		_tw.y = 290;
		//_tw.visible = false;
		
		_canvas.addChild(_volver);
		_canvas.addChild(_regresar);
		_canvas.addChild(_fb);
		_canvas.addChild(_tw);
		
		//_canvas.addEventListener(MouseEvent.CLICK, onClick);
		//_canvas.addEventListener(MouseEvent.MOUSE_MOVE, onMove);
	}
	
	private function onMove(e:MouseEvent):Void 
	{		
		#if js
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 165 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 165 + 140)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 345 && e.stageY - Lib.document.getElementById("banner").offsetTop < 345 + 40)
			{
				_regresar.visible = true;
			}
		}
		else
		{
			_regresar.visible = false;
		}
		
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 325 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 325 + 140)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 345 && e.stageY - Lib.document.getElementById("banner").offsetTop < 345 + 40)
			{
				_volver.visible = true;
			}
		}
		else
		{
			_volver.visible = false;
		}
		
		
		
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 280 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 280 + 33)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 290 && e.stageY - Lib.document.getElementById("banner").offsetTop < 290 + 33)
			{
				trace("post facebook");
				Lib.eval("postFacebook(" + Global.totalPoints + ")");
				_fb.visible = true;
			}
		}
		else
		{
			_fb.visible = false;
		}
		
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 320 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 320 + 33)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 290 && e.stageY - Lib.document.getElementById("banner").offsetTop < 290 + 33)
			{
				trace("post twitter");
				Lib.eval("postTwitter(" + Global.totalPoints + ")");
				_tw.visible = true;
			}
		}
		else
		{
			_tw.visible = false;
		}
		#end
	}
	
	private function onClick(e:MouseEvent):Void 
	{
		#if js
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 165 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 165 + 140)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 345 && e.stageY - Lib.document.getElementById("banner").offsetTop < 345 + 40)
			{
				Lib.eval("window.open('http://www.juntossomosmasseguros.com', '_self')");
			}
		}
		
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 325 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 325 + 140)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 345 && e.stageY - Lib.document.getElementById("banner").offsetTop < 345 + 40)
			{
				SoundManager.stopAll();
				ScreenManager.instance.gotoScreen(GameScreen);
			}
		}
		
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 280 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 280 + 33)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 290 && e.stageY - Lib.document.getElementById("banner").offsetTop < 290 + 33)
			{
				trace("post facebook");
				Lib.eval("postFacebook(" + Global.totalPoints + ")");
			}
		}
		
		if (e.stageX - Lib.document.getElementById("banner").offsetLeft > 320 && e.stageX - Lib.document.getElementById("banner").offsetLeft < 320 + 33)
		{
			if (e.stageY - Lib.document.getElementById("banner").offsetTop > 290 && e.stageY - Lib.document.getElementById("banner").offsetTop < 290 + 33)
			{
				trace("post twitter");
				Lib.eval("postTwitter(" + Global.totalPoints + ")");
			}
		}
		#end
		
		#if flash
		if (e.stageX > 165 && e.stageX < 165 + 140)
		{
			if (e.stageY > 345 && e.stageY < 345 + 40)
			{
				#if js
				//Lib.eval("window.open('www.juntossomosmasseguros.com', '_self')");
				#end
			}
		}
		
		if (e.stageX > 325 && e.stageX < 325 + 140)
		{
			if (e.stageY > 345 && e.stageY < 345 + 40)
			{
				//trace("toco 2");
				SoundManager.stopAll();
				ScreenManager.instance.gotoScreen(GameScreen);
			}
		}
		
		if (e.stageX > 280 && e.stageX < 280 + 33)
		{
			if (e.stageY > 290 && e.stageY < 290 + 33)
			{
				trace("post facebook");
				//Lib.eval("postFacebook(" + Global.totalPoints + ")");
			}
		}
		
		if (e.stageX > 320 && e.stageX < 320 + 33)
		{
			if (e.stageY > 290 && e.stageY < 290 + 33)
			{
				trace("post twitter");
				//Lib.eval("postTwitter(" + Global.totalPoints + ")");
			}
		}
		#end
	}
	
	override public function update(dt:Int):Dynamic 
	{
		
	}
	
	override public function destroy():Void
	{
		while (_canvas.numChildren > 0)
		{
			_canvas.removeChildAt(0);
		}
	}
}