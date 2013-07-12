package com.funbox.bcp.minigame2.util;
import com.minigloop.util.AssetsLoader;
import nme.display.Bitmap;
import nme.display.BitmapData;

/**
 * ...
 * @author Cristian F. Shute
 */
class NUtils
{

	public function new() {
		
	}
	
	public static function getAsset(assetName:String):Bitmap {
		var b:Bitmap = AssetsLoader.getAsset(assetName);
		var bd:BitmapData = b.bitmapData.clone();
		bd.draw(b);
		return new Bitmap(bd);
	}
	
	public static function getValueFromProbabilityChart(numOptions:Int, numProbabilitys:Int):Int {
		numProbabilitys = numProbabilitys <= numOptions ? numOptions + 1 : numProbabilitys;
		
		var choosenOption:Int = 0;
		var probabilityChart:Array<Int> = new Array<Int>();
		var optionCounter:Int = 0;
		
		var i:Int = 0;
		
		while (i < numProbabilitys) {
			probabilityChart.push(optionCounter);
			optionCounter++;
			if (optionCounter >= numOptions) { optionCounter = 0; }
			
			i++;
		}
		
		choosenOption = probabilityChart[Std.int(NMath.random(0, numProbabilitys -1))];
		
		return choosenOption;
	}
	
	public static function parseMillisecondsInClockFormat(milliseconds:Int):String {
		var minutes:Float = (milliseconds / 1000.0) / 60.0;
		var minutesFloor:Int = Math.floor(minutes);
		var secondsRaw:Float = minutes - minutesFloor;
		var seconds:Int = Std.int(secondsRaw * 60);
		var clockFormat:String = NUtils.getDigitsByValue(minutesFloor, 2) + ":" + NUtils.getDigitsByValue(seconds, 2);
		
		return clockFormat;
	}
	
	public static function getDigitsByValue(value:Int, num_digits:Int):String {
		var s:String = Std.string(value);
		var offset:Int = num_digits - s.length;
		
		var i:Int = 0;
		
		while (i < offset) {
			s = "0" + s;
			i++;
		}
		
		return s;
	}
}