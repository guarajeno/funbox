#ifndef INCLUDED_com_minigloop_input_Mouse
#define INCLUDED_com_minigloop_input_Mouse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,input,Mouse)
HX_DECLARE_CLASS3(com,minigloop,util,Vector2D)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Stage)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,MouseEvent)
namespace com{
namespace minigloop{
namespace input{


class Mouse_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Mouse_obj OBJ_;
		Mouse_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Mouse_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Mouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mouse"); }

		static ::native::display::Stage _stage; /* REM */ 
		static ::com::minigloop::util::Vector2D position; /* REM */ 
		static ::com::minigloop::util::Vector2D lastPosition; /* REM */ 
		static Void init( ::native::display::Stage stage);
		static Dynamic init_dyn();

		static Void onMouseMove( ::native::events::MouseEvent e);
		static Dynamic onMouseMove_dyn();

};

} // end namespace com
} // end namespace minigloop
} // end namespace input

#endif /* INCLUDED_com_minigloop_input_Mouse */ 
