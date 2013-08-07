var slider = {};

$(document).ready(function(){

var $slides = $('.banners li');
var $actual = $slides.first();
var $tabs = $('.banners .tabs');

$slides.each(function(i){
	var onMouseDown = function(){
		$siguiente = $slides.eq(i);
		slider.action($siguiente);
		return false;
	};

	var $span = $('<span></span>')
		.text(i + 1)
		.mousedown(onMouseDown)
		.appendTo($tabs);

	if (i == 0){
		$span.addClass('selected');
	}
});

slider.nextSlide = function(){
	var $siguiente = $actual.next();
	
	if ($siguiente.length == 0){
		$siguiente = $slides.first();
	}
	slider.action($siguiente);
}

slider.prevSlide = function(){
	var $siguiente = $actual.prev();

	if ($siguiente.length == 0){
		$siguiente = $slides.last();
	}
	slider.action($siguiente);
}

slider.action = function($siguiente){
	if ($actual[0] == $siguiente[0]){
		return;
	}
	$siguiente.fadeIn();
	$actual.fadeOut();

	var $spans = $tabs.find('span');
	$spans.removeClass('selected');

	$slides.each(function(i){
		if ($siguiente[0] == this){
			$spans.eq(i).addClass('selected');
		}
	});

	$actual = $siguiente;
}

$('a.next').click(slider.nextSlide);
$('a.prev').click(slider.prevSlide);
});
