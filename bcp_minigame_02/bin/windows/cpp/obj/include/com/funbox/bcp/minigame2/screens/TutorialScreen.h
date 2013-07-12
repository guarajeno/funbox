#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_TutorialScreen
#define INCLUDED_com_funbox_bcp_minigame2_screens_TutorialScreen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/minigloop/ui/Screen.h>
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,EffectManager)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,TutorialScreen)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,NInterval)
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


class TutorialScreen_obj : public ::com::minigloop::ui::Screen_obj{
	public:
		typedef ::com::minigloop::ui::Screen_obj super;
		typedef TutorialScreen_obj OBJ_;
		TutorialScreen_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< TutorialScreen_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TutorialScreen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TutorialScreen"); }

		virtual Void destroy( );

		virtual Void update( int dt);

		virtual Void onGoGame( );
		Dynamic onGoGame_dyn();

		virtual Void onFinishWait( );
		Dynamic onFinishWait_dyn();

		::native::display::Sprite mCanvasMouse; /* REM */ 
		::native::display::Sprite mCanvasEffect; /* REM */ 
		::native::display::Sprite mCanvasTutorial; /* REM */ 
		::com::funbox::bcp::minigame2::engine::effectManager::EffectManager mEffectManager; /* REM */ 
		Float mMoneyInitX; /* REM */ 
		Float mBagInitX; /* REM */ 
		::com::funbox::bcp::minigame2::util::NInterval mInterval; /* REM */ 
		int mCurrentState; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mTutorialTicketMoneySprite; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mTutorialBagMoneySprite; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mTutorialHandSprite; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mTutorialSprite; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mBGMaskSprite; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mBGSprite; /* REM */ 
		static int STATE_SHOW_TUTORIAL; /* REM */ 
		static int STATE_WAIT; /* REM */ 
		static int STATE_DISAPPEAR_TUTORIAL; /* REM */ 
		static int STATE_NOTHING; /* REM */ 
		static int STATE_MOUSE_LEFT; /* REM */ 
		static int STATE_MOUSE_RIGHT; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens

#endif /* INCLUDED_com_funbox_bcp_minigame2_screens_TutorialScreen */ 
