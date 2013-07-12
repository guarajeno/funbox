#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#define INCLUDED_com_funbox_bcp_minigame2_MiniGame2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/minigloop/Game.h>
HX_DECLARE_CLASS4(com,funbox,bcp,minigame2,MiniGame2)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,VerticalTouchEngine)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,GameHud)
HX_DECLARE_CLASS2(com,minigloop,Game)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,MouseEvent)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{


class MiniGame2_obj : public ::com::minigloop::Game_obj{
	public:
		typedef ::com::minigloop::Game_obj super;
		typedef MiniGame2_obj OBJ_;
		MiniGame2_obj();
		Void __construct(::native::display::Sprite canvas,::com::funbox::bcp::minigame2::screens::GameHud gameHud);

	public:
		static hx::ObjectPtr< MiniGame2_obj > __new(::native::display::Sprite canvas,::com::funbox::bcp::minigame2::screens::GameHud gameHud);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MiniGame2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MiniGame2"); }

		virtual Void destroy( );

		virtual Void update( int dt);

		virtual Void onMouseHandler( ::native::events::MouseEvent e);
		Dynamic onMouseHandler_dyn();

		virtual ::com::funbox::bcp::minigame2::screens::GameHud getGameHud( );
		Dynamic getGameHud_dyn();

		virtual ::com::funbox::bcp::minigame2::engine::VerticalTouchEngine getVTEngine( );
		Dynamic getVTEngine_dyn();

		virtual bool isMousePressed( );
		Dynamic isMousePressed_dyn();

		virtual Float getMouseY( );
		Dynamic getMouseY_dyn();

		virtual Float getMouseX( );
		Dynamic getMouseX_dyn();

		int mLevelTime; /* REM */ 
		bool mMousePressed; /* REM */ 
		Float mMouseY; /* REM */ 
		Float mMouseX; /* REM */ 
		::com::funbox::bcp::minigame2::engine::VerticalTouchEngine mVTEngine; /* REM */ 
		::com::funbox::bcp::minigame2::screens::GameHud mGameHud; /* REM */ 
		::native::display::Sprite mGameCanvas; /* REM */ 
		::native::display::Sprite mGhostGameMask; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2

#endif /* INCLUDED_com_funbox_bcp_minigame2_MiniGame2 */ 
