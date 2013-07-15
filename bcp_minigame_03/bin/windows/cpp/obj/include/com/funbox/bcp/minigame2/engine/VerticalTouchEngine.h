#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_VerticalTouchEngine
#define INCLUDED_com_funbox_bcp_minigame2_engine_VerticalTouchEngine

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,funbox,bcp,minigame2,MiniGame2)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,EntitiesController)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,FallingObjectManager)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,VerticalTouchEngine)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,EffectManager)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,TouchObject)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,entities,enemy,BotCollector)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,entities,player,GamePlayer)
HX_DECLARE_CLASS2(com,minigloop,Game)
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
namespace engine{


class VerticalTouchEngine_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef VerticalTouchEngine_obj OBJ_;
		VerticalTouchEngine_obj();
		Void __construct(::com::funbox::bcp::minigame2::MiniGame2 miniGameRef,::native::display::Sprite gameCanvas);

	public:
		static hx::ObjectPtr< VerticalTouchEngine_obj > __new(::com::funbox::bcp::minigame2::MiniGame2 miniGameRef,::native::display::Sprite gameCanvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VerticalTouchEngine_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VerticalTouchEngine"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual ::com::funbox::bcp::minigame2::engine::EntitiesController getEntitiesController( );
		Dynamic getEntitiesController_dyn();

		virtual ::com::funbox::bcp::minigame2::engine::effectManager::EffectManager getEffectManager( );
		Dynamic getEffectManager_dyn();

		virtual ::com::funbox::bcp::minigame2::entities::enemy::BotCollector getBotCollector( );
		Dynamic getBotCollector_dyn();

		::com::funbox::bcp::minigame2::MiniGame2 mMinigameRef; /* REM */ 
		::com::funbox::bcp::minigame2::engine::effectManager::EffectManager mEffectManager; /* REM */ 
		::com::funbox::bcp::minigame2::engine::FallingObjectManager mFallingObjectManager; /* REM */ 
		::com::funbox::bcp::minigame2::engine::EntitiesController mEntitiesController; /* REM */ 
		::com::funbox::bcp::minigame2::entities::enemy::BotCollector mBotCollector; /* REM */ 
		::com::funbox::bcp::minigame2::entities::player::GamePlayer mPlayer; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mBGMaskSprite; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mBGSprite; /* REM */ 
		::native::display::Sprite mBGCanvas; /* REM */ 
		::native::display::Sprite mEffectCanvas; /* REM */ 
		::native::display::Sprite mBotCanvas; /* REM */ 
		::native::display::Sprite mPlayerCanvas; /* REM */ 
		::native::display::Sprite mEntitiesCanvas; /* REM */ 
		::native::display::Sprite mGameCanvas; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine

#endif /* INCLUDED_com_funbox_bcp_minigame2_engine_VerticalTouchEngine */ 
