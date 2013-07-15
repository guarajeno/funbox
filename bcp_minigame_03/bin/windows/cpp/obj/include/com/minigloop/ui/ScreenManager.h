#ifndef INCLUDED_com_minigloop_ui_ScreenManager
#define INCLUDED_com_minigloop_ui_ScreenManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,ui,Screen)
HX_DECLARE_CLASS3(com,minigloop,ui,ScreenManager)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace minigloop{
namespace ui{


class ScreenManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ScreenManager_obj OBJ_;
		ScreenManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ScreenManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ScreenManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ScreenManager"); }

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual Void gotoScreen( ::Class screenClass);
		Dynamic gotoScreen_dyn();

		virtual Void init( ::native::display::Sprite canvas);
		Dynamic init_dyn();

		static ::com::minigloop::ui::ScreenManager instance; /* REM */ 
		static ::com::minigloop::ui::Screen _currentScreen; /* REM */ 
		static ::native::display::Sprite _canvas; /* REM */ 
		static ::com::minigloop::ui::ScreenManager getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace com
} // end namespace minigloop
} // end namespace ui

#endif /* INCLUDED_com_minigloop_ui_ScreenManager */ 
