#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameScreen
#define INCLUDED_com_funbox_bcp_minigame2_screens_GameScreen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/minigloop/ui/Screen.h>
HX_DECLARE_CLASS4(com,funbox,bcp,minigame2,MiniGame2)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,GameHud)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,GameScreen)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,GameTransitionPopupScreen)
HX_DECLARE_CLASS2(com,minigloop,Game)
HX_DECLARE_CLASS3(com,minigloop,ui,Screen)
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


class GameScreen_obj : public ::com::minigloop::ui::Screen_obj{
	public:
		typedef ::com::minigloop::ui::Screen_obj super;
		typedef GameScreen_obj OBJ_;
		GameScreen_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< GameScreen_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameScreen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameScreen"); }

		virtual Void destroy( );

		virtual Void update( int dt);

		virtual Void onFinishTransition( );
		Dynamic onFinishTransition_dyn();

		bool mPausedGame; /* REM */ 
		::native::display::Sprite mFrontCanvas; /* REM */ 
		::native::display::Sprite mHudCanvas; /* REM */ 
		::native::display::Sprite mGameCanvas; /* REM */ 
		::com::funbox::bcp::minigame2::screens::GameTransitionPopupScreen _gameTransition; /* REM */ 
		::com::funbox::bcp::minigame2::screens::GameHud _gameHud; /* REM */ 
		::com::funbox::bcp::minigame2::MiniGame2 _game; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens

#endif /* INCLUDED_com_funbox_bcp_minigame2_screens_GameScreen */ 
