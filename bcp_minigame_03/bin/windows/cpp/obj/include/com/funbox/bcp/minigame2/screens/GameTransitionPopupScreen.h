#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameTransitionPopupScreen
#define INCLUDED_com_funbox_bcp_minigame2_screens_GameTransitionPopupScreen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,GameTransitionPopupScreen)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,ScaleTweener)
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
namespace screens{


class GameTransitionPopupScreen_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GameTransitionPopupScreen_obj OBJ_;
		GameTransitionPopupScreen_obj();
		Void __construct(::native::display::Sprite canvas,Dynamic onCallbackFunction);

	public:
		static hx::ObjectPtr< GameTransitionPopupScreen_obj > __new(::native::display::Sprite canvas,Dynamic onCallbackFunction);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameTransitionPopupScreen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameTransitionPopupScreen"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual Void endTweens( );
		Dynamic endTweens_dyn();

		virtual Void tweenStart( );
		Dynamic tweenStart_dyn();

		virtual Void tween3( );
		Dynamic tween3_dyn();

		virtual Void tween2( );
		Dynamic tween2_dyn();

		Dynamic mOnCallbackFunction; /* REM */ 
		::com::funbox::bcp::minigame2::util::ScaleTweener _scaleTweener; /* REM */ 
		::String _state; /* REM */ 
		::native::display::Sprite mCanvas; /* REM */ 
		::native::display::Bitmap _start; /* REM */ 
		::native::display::Bitmap _img_3; /* REM */ 
		::native::display::Bitmap _img_2; /* REM */ 
		::native::display::Bitmap _img_1; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens

#endif /* INCLUDED_com_funbox_bcp_minigame2_screens_GameTransitionPopupScreen */ 
