#ifndef INCLUDED_com_minigloop_util_Stats
#define INCLUDED_com_minigloop_util_Stats

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,minigloop,util,Stats)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,display,Stage)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,Rectangle)
HX_DECLARE_CLASS2(native,text,TextField)
namespace com{
namespace minigloop{
namespace util{


class Stats_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Stats_obj OBJ_;
		Stats_obj();
		Void __construct(hx::Null< bool >  __o_alignRight,hx::Null< bool >  __o_fastUpdate);

	public:
		static hx::ObjectPtr< Stats_obj > __new(hx::Null< bool >  __o_alignRight,hx::Null< bool >  __o_fastUpdate);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Stats_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Stats"); }

		virtual int normalizeMem( Float _mem);
		Dynamic normalizeMem_dyn();

		virtual Void update( ::native::events::Event e);
		Dynamic update_dyn();

		virtual Void destroy( ::native::events::Event e);
		Dynamic destroy_dyn();

		virtual Void init( ::native::events::Event e);
		Dynamic init_dyn();

		::String htmlText; /* REM */ 
		::String msStr; /* REM */ 
		::String memMaxStr; /* REM */ 
		::String memStr; /* REM */ 
		::String fpsStr; /* REM */ 
		::native::display::Stage _stage; /* REM */ 
		int mem_max_graph; /* REM */ 
		int ms_graph; /* REM */ 
		int mem_graph; /* REM */ 
		int fps_graph; /* REM */ 
		bool fastUpdate; /* REM */ 
		bool alignRight; /* REM */ 
		::native::geom::Rectangle rectangle; /* REM */ 
		::native::display::BitmapData graph; /* REM */ 
		Float mem_max; /* REM */ 
		Float mem; /* REM */ 
		int ms_prev; /* REM */ 
		int ms; /* REM */ 
		int fps; /* REM */ 
		int timer; /* REM */ 
		::native::text::TextField text; /* REM */ 
		static int GRAPH_WIDTH; /* REM */ 
		static int XPOS; /* REM */ 
		static int GRAPH_HEIGHT; /* REM */ 
		static int TEXT_HEIGHT; /* REM */ 
};

} // end namespace com
} // end namespace minigloop
} // end namespace util

#endif /* INCLUDED_com_minigloop_util_Stats */ 
