#ifndef INCLUDED_com_minigloop_Engine
#define INCLUDED_com_minigloop_Engine

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(com,minigloop,Engine)
HX_DECLARE_CLASS3(com,minigloop,ui,Screen)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,display,Stage)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace minigloop{


class Engine_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Engine_obj OBJ_;
		Engine_obj();
		Void __construct(::native::display::Stage stage,::Class gameClass);

	public:
		static hx::ObjectPtr< Engine_obj > __new(::native::display::Stage stage,::Class gameClass);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Engine_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Engine"); }

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual Void loop( ::native::events::Event e);
		Dynamic loop_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		::Class _gameClass; /* REM */ 
		::native::display::Stage _stage; /* REM */ 
		::native::display::Sprite _statsCanvas; /* REM */ 
		::native::display::Sprite _bufferCanvas; /* REM */ 
		int _dt; /* REM */ 
		int _last; /* REM */ 
		int _now; /* REM */ 
};

} // end namespace com
} // end namespace minigloop

#endif /* INCLUDED_com_minigloop_Engine */ 
