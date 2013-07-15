#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#define INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
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
namespace funbox{
namespace bcp{
namespace minigame2{
namespace entities{


class BaseActor_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BaseActor_obj OBJ_;
		BaseActor_obj();
		Void __construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y);

	public:
		static hx::ObjectPtr< BaseActor_obj > __new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BaseActor_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BaseActor"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual bool hitTestPoint( int x,int y);
		Dynamic hitTestPoint_dyn();

		virtual bool hitTest( ::com::funbox::bcp::minigame2::entities::BaseActor actor);
		Dynamic hitTest_dyn();

		virtual Void setFlip( bool value);
		Dynamic setFlip_dyn();

		virtual bool getFlip( );
		Dynamic getFlip_dyn();

		virtual Void setOffsetY( Float value);
		Dynamic setOffsetY_dyn();

		virtual Float getOffsetY( );
		Dynamic getOffsetY_dyn();

		virtual Void setOffsetX( Float value);
		Dynamic setOffsetX_dyn();

		virtual Float getOffsetX( );
		Dynamic getOffsetX_dyn();

		virtual Void setAlpha( Float value);
		Dynamic setAlpha_dyn();

		virtual Float getAlpha( );
		Dynamic getAlpha_dyn();

		virtual Void setY( Float value);
		Dynamic setY_dyn();

		virtual Float getY( );
		Dynamic getY_dyn();

		virtual Void setX( Float value);
		Dynamic setX_dyn();

		virtual Float getX( );
		Dynamic getX_dyn();

		virtual Float getHeight( );
		Dynamic getHeight_dyn();

		virtual Float getWidth( );
		Dynamic getWidth_dyn();

		bool mPauseAnimation; /* REM */ 
		bool mStaticImage; /* REM */ 
		bool mFlip; /* REM */ 
		::com::minigloop::display::AtlasSprite mAnimationBitmap; /* REM */ 
		::native::display::Bitmap mBitmap; /* REM */ 
		::native::display::Sprite mCanvas; /* REM */ 
		Float mAlpha; /* REM */ 
		Float mHeight; /* REM */ 
		Float mWidth; /* REM */ 
		Float mFlipOffsetX; /* REM */ 
		Float mOffsetY; /* REM */ 
		Float mOffsetX; /* REM */ 
		Float mY; /* REM */ 
		Float mX; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities

#endif /* INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor */ 
