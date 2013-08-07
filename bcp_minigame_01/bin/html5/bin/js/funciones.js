!(function($){
	var $window = $(window);
	var $document = $(document);
	var $container;
	var slider = {};
	var $slides = $('.banners li');
	var $actual = $slides.first();
	var $tabs = $('.banners .tabs');

	var background_loader = function(url){
		//if( $('html').hasClass('lt-ie9') ){
			var theWindow, $bg, aspectRatio, img, body;
			
			function resizeBg() {
				var ww = theWindow.width(),
					wh = theWindow.height();

				if ( (ww / wh ) < aspectRatio ) {
				    //$bg.css({width:'100%', height:'100%', top:0});
					//$bg.css({left: (Math.abs($bg.width() - ww) * +0.5) + 'px'});
				} else {
				    //$bg.css({width:'100%', height:'100%', left:0});
			    	//$bg.css({top: (Math.abs($bg.height() - wh) * -0.5) + 'px'});
				}
			}

			function image_loaded() {
				theWindow   = $(window);
				$bg         = $(img);
				aspectRatio = $bg.width() / $bg.height();

				$bg
					.css({ opacity:0.0, display: 'block' })
					.animate({opacity:1.0}, 300, function(){
						/*
						$('#wrapper, #msg')
							.css({opacity: 0.0, display: 'block'})
							.animate({opacity:1.0, marginTop: '+=10px'});
						*/
					});

				//theWindow.on('resize', resizeBg).trigger("resize");
				
				theWindow.resize(function() {
					resizeBg();
				}).trigger("resize");
			}
			
			img = document.createElement('img');
			img.id  = "bg";
			img.style.display = 'none';
			img.style.position = 'absolute';
			img.style.top = '63px';
			img.style.left = 0;
			img.style.zIndex = -2;
			
			img.onload = image_loaded;
			img.src = url;	

			body = document.body || document.getElementsByTagName('body')[0];
			body.appendChild( img );
		//}

	}
	/* END */
	var background2 = function(m){
		//$('#seccion'+m).fadeIn('fast');
		if(m==1){
			$('#seccion'+m).fadeIn('fast');
			$('#seccion2').fadeOut('fast');$('#seccion3').fadeOut('fast');$('#seccion4').fadeOut('fast');$('#seccion5').fadeOut('fast');
		} else if(m==2){
			$('#seccion'+m).fadeIn('fast');
			$('#seccion3').fadeOut('fast');$('#seccion4').fadeOut('fast');$('#seccion5').fadeOut('fast');$('#seccion1').fadeOut('fast');
		} else if(m==3){
			$('#seccion'+m).fadeIn('fast');
			$('#seccion4').fadeOut('fast');$('#seccion5').fadeOut('fast');$('#seccion1').fadeOut('fast');$('#seccion2').fadeOut('fast');
		} else if(m==4){
			$('#seccion'+m).fadeIn('fast');
			$('#seccion5').fadeOut('fast');$('#seccion1').fadeOut('fast');$('#seccion2').fadeOut('fast');$('#seccion3').fadeOut('fast');
		} else if(m==5){
			$('#seccion'+m).fadeIn('fast');
			$('#seccion1').fadeOut('fast');$('#seccion2').fadeOut('fast');$('#seccion3').fadeOut('fast');$('#seccion4').fadeOut('fast');
		}
	}
	
	
	$document.one('ready', function(){
		//background_loader('img/secciones/s1_02.jpg');		
	}); // .ready
	
	// slide
	
	$slides.each(function(i){
		var onMouseDown = function(){
			$siguiente = $slides.eq(i);
			slider.action($siguiente);
			return false;
		};
		
		var onMouseDown2 = function(i){
			$siguiente = $slides.eq(i);
			slider.action($siguiente);
			return false;
		};
		
	
		var $span = $('<span></span>')
			.text(i + 1)
			.mousedown(onMouseDown)
			.appendTo($tabs);
		
		$('ul.nav li#s1').click(function(i){
			onMouseDown2(0);
		});
		
		$('ul.nav li#s2').click(function(i){
			onMouseDown2(1);
		});
		
		$('ul.nav li#s3').click(function(i){
			onMouseDown2(2);
		});
		
		$('ul.nav li#s4').click(function(i){
			onMouseDown2(3);
		});
		
		$('ul.nav li#s5').click(function(i){
			onMouseDown2(4);
		});
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
	
	slider.nextSlide2 = function(){
		var $siguiente = $actual.next();
		//alert($siguiente);
		//alert($siguiente.length);
		/*if ($siguiente.length == 0){
			$siguiente = $slides.first();
		}*/
		slider.action($siguiente);
		//$('')
		
		
	}
	
	slider.action = function($siguiente){
	if ($actual[0] == $siguiente[0]){
		return;
	}
	
	$siguiente.fadeIn();
	$actual.fadeOut();

	var $spans = $('ul.nav li');
		$spans.removeClass('active');
	
		$slides.each(function(i){
			if ($siguiente[0] == this){
				$spans.eq(i).addClass('active');								
				if(i==0){
					//background_loader('img/secciones/s1_02.jpg');
					//$('#seccion1').fadeIn('fadeIn');
					background2(1);			
				} else if(i==1){
					//background_loader('img/secciones/s2_02.jpg');
					//$('#seccion2').fadeIn('fadeIn');
					background2(2);
				} else if(i==2){
					//background_loader('img/secciones/s3_02.jpg');
					//$('#seccion1').fadeIn('fadeIn');
					background2(3);
				} else if(i==3){
					//background_loader('img/secciones/s4_02.jpg');
					//$('#seccion1').fadeIn('fadeIn');
					background2(4);
				} else if(i==4){
					//background_loader('img/secciones/s5_02.jpg');
					//$('#seccion1').fadeIn('fadeIn');
					background2(5);
				}
							
			}
		});
	
		$actual = $siguiente;
		
	}
	
	$('a.next').click(slider.nextSlide);
	$('a.prev').click(slider.prevSlide);	
	$('#cinta').click(function(){
		location.href = "index.php";
	});
	
	var anim2 = setTimeout(slider.nextSlide2, 5000);
	
	// end slide	
	$document.ready(function(){
		
		$(window).load(function(){ // On load
			$('#lightbox').css({'height':(($(window).height()))+'px'});
		});
		
		$(window).resize(function(){ // On resize
			$('#lightbox').css({'height':(($(window).height()))+'px'});
		});
		
		$('#youtube1').click(function(){
			abreLightbox();
			$("#lightbox-contenido-youtube").html("<iframe width='410' height='304' src='http://www.youtube.com/embed/QV7PmO6_gO8' frameborder='0' allowfullscreen></iframe>");
		});
		$('img#youtube2').click(function(){
			abreLightbox();
			$("#lightbox-contenido-youtube").html("<iframe width='410' height='304' src='http://www.youtube.com/embed/DfkH04hpyYA' frameborder='0' allowfullscreen></iframe>");
		});
		$('img#youtube3').click(function(){
			abreLightbox();
			$("#lightbox-contenido-youtube").html("<iframe width='410' height='304' src='http://www.youtube.com/embed/7zpn9pkJ6cA' frameborder='0' allowfullscreen></iframe>");
		});
		$('img#youtube4').click(function(){
			abreLightbox();
			$("#lightbox-contenido-youtube").html("<iframe width='410' height='304' src='http://www.youtube.com/embed/wRDXMQRdtLg' frameborder='0' allowfullscreen></iframe>");
		});
		
		
	});
})(jQuery);
function abreLightbox(){
	$("#lightbox").fadeIn('fast');
	$("#lightbox-panel-youtube").fadeIn('slow');
    
}
function cerrarLightbox(){
	$("#lightbox").fadeOut('fast');
	$("#lightbox-panel-youtube").fadeOut("slow");
    $("#lightbox-contenido-youtube").html("");
}