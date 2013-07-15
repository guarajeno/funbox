package com.funbox.bcp.minigame3.util;

/**
 * ...
 * @author Cristian F. Shute
 */
class NMath {

	public function new() {
		
	}
	
	public static function random(min:Float, max:Float):Float {
		return (Math.random() * (max - min)) + min;
	}
	
}