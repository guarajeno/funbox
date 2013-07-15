#ifndef INCLUDED_com_minigloop_display_AtlasSprite
#define INCLUDED_com_minigloop_display_AtlasSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/minigloop/display/VisualObject.h>
HX_DECLARE_CLASS3(com,minigloop,display,AtlasSprite)
HX_DECLARE_CLASS3(com,minigloop,display,VisualObject)
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace minigloop{
namespace display{


class AtlasSprite_obj : public ::com::minigloop::display::VisualObject_obj{
	public:
		typedef ::com::minigloop::display::VisualObject_obj super;
		typedef AtlasSprite_obj OBJ_;
		AtlasSprite_obj();
		Void __construct(::native::display::Sprite canvas,::String imgId,::String atlasId,::String __o_align);

	public:
		static hx::ObjectPtr< AtlasSprite_obj > __new(::native::display::Sprite canvas,::String imgId,::String atlasId,::String __o_align);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AtlasSprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AtlasSprite"); }

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void update( int dt);

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void gotoAndStop( int frame);
		Dynamic gotoAndStop_dyn();

		virtual Void gotoAndPlay( int frame);
		Dynamic gotoAndPlay_dyn();

		virtual Void setScaleY( Float value);
		Dynamic setScaleY_dyn();

		virtual Void setScaleX( Float value);
		Dynamic setScaleX_dyn();

		virtual int getLength( );
		Dynamic getLength_dyn();

		virtual int getCurrentIndex( );
		Dynamic getCurrentIndex_dyn();

		virtual Float getScaleY( );
		Dynamic getScaleY_dyn();

		virtual Float getScaleX( );
		Dynamic getScaleX_dyn();

		virtual Float currentHeight( );
		Dynamic currentHeight_dyn();

		virtual Float currentWidth( );
		Dynamic currentWidth_dyn();

		virtual bool playing( );
		Dynamic playing_dyn();

		virtual ::native::display::Bitmap currentFrame( );
		Dynamic currentFrame_dyn();

		virtual Void setAlpha( Float value);
		Dynamic setAlpha_dyn();

		virtual Float getAlpha( );
		Dynamic getAlpha_dyn();

		bool mCanPlay; /* REM */ 
		Float _scaleY; /* REM */ 
		Float _scaleX; /* REM */ 
		Float mAlpha; /* REM */ 
		Float _offsetY; /* REM */ 
		Float _offsetX; /* REM */ 
		int _sourceHeight; /* REM */ 
		int _sourceWidth; /* REM */ 
		int _currentIndex; /* REM */ 
		Array< ::native::display::Bitmap > _frames; /* REM */ 
		::native::display::Sprite _container; /* REM */ 
};

} // end namespace com
} // end namespace minigloop
} // end namespace display

#endif /* INCLUDED_com_minigloop_display_AtlasSprite */ 
