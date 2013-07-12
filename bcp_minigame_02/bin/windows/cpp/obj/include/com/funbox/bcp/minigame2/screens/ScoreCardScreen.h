#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_ScoreCardScreen
#define INCLUDED_com_funbox_bcp_minigame2_screens_ScoreCardScreen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/minigloop/ui/Screen.h>
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,ScoreCardScreen)
HX_DECLARE_CLASS3(com,minigloop,ui,Screen)
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,MouseEvent)
HX_DECLARE_CLASS2(native,text,TextField)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace screens{


class ScoreCardScreen_obj : public ::com::minigloop::ui::Screen_obj{
	public:
		typedef ::com::minigloop::ui::Screen_obj super;
		typedef ScoreCardScreen_obj OBJ_;
		ScoreCardScreen_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< ScoreCardScreen_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ScoreCardScreen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ScoreCardScreen"); }

		virtual Void destroy( );

		virtual Void update( int dt);

		virtual Void onClick( ::native::events::MouseEvent e);
		Dynamic onClick_dyn();

		virtual Void onMove( ::native::events::MouseEvent e);
		Dynamic onMove_dyn();

		::native::display::Bitmap _tw; /* REM */ 
		::native::display::Bitmap _fb; /* REM */ 
		::native::display::Bitmap _regresar; /* REM */ 
		::native::display::Bitmap _volver; /* REM */ 
		Float _mouseY; /* REM */ 
		Float _mouseX; /* REM */ 
		::native::display::Sprite _box_1; /* REM */ 
		::native::text::TextField _message; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens

#endif /* INCLUDED_com_funbox_bcp_minigame2_screens_ScoreCardScreen */ 
