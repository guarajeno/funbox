#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#include <com/funbox/bcp/minigame2/MiniGame2.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController
#include <com/funbox/bcp/minigame2/engine/EntitiesController.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_FallingObjectManager
#include <com/funbox/bcp/minigame2/engine/FallingObjectManager.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_VerticalTouchEngine
#include <com/funbox/bcp/minigame2/engine/VerticalTouchEngine.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_EffectManager
#include <com/funbox/bcp/minigame2/engine/effectManager/EffectManager.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_enemy_BotCollector
#include <com/funbox/bcp/minigame2/entities/enemy/BotCollector.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_player_GamePlayer
#include <com/funbox/bcp/minigame2/entities/player/GamePlayer.h>
#endif
#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace engine{

Void VerticalTouchEngine_obj::__construct(::com::funbox::bcp::minigame2::MiniGame2 miniGameRef,::native::display::Sprite gameCanvas)
{
HX_STACK_PUSH("VerticalTouchEngine::new","com/funbox/bcp/minigame2/engine/VerticalTouchEngine.hx",41);
{
	HX_STACK_LINE(42)
	this->mGameCanvas = gameCanvas;
	HX_STACK_LINE(43)
	this->mMinigameRef = miniGameRef;
	HX_STACK_LINE(45)
	this->mEntitiesCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(46)
	this->mPlayerCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(47)
	this->mBotCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(48)
	this->mEffectCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(49)
	this->mBGCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(51)
	this->mGameCanvas->addChild(this->mBGCanvas);
	HX_STACK_LINE(52)
	this->mGameCanvas->addChild(this->mEntitiesCanvas);
	HX_STACK_LINE(53)
	this->mGameCanvas->addChild(this->mBotCanvas);
	HX_STACK_LINE(54)
	this->mGameCanvas->addChild(this->mPlayerCanvas);
	HX_STACK_LINE(55)
	this->mGameCanvas->addChild(this->mEffectCanvas);
	HX_STACK_LINE(57)
	this->mEffectManager = ::com::funbox::bcp::minigame2::engine::effectManager::EffectManager_obj::__new(this->mEffectCanvas);
	HX_STACK_LINE(59)
	this->mEntitiesController = ::com::funbox::bcp::minigame2::engine::EntitiesController_obj::__new(this->mEntitiesCanvas);
	HX_STACK_LINE(60)
	this->mFallingObjectManager = ::com::funbox::bcp::minigame2::engine::FallingObjectManager_obj::__new(this->mEntitiesController);
	HX_STACK_LINE(62)
	this->mPlayer = ::com::funbox::bcp::minigame2::entities::player::GamePlayer_obj::__new(HX_CSTRING("spMinigame02_mouseHand_click"),HX_CSTRING("spMinigame02_mouseHand_click"),this->mPlayerCanvas,(int)2,(int)24);
	HX_STACK_LINE(65)
	this->mBotCollector = ::com::funbox::bcp::minigame2::entities::enemy::BotCollector_obj::__new(HX_CSTRING("spMinigame02_ani_bot_collector"),HX_CSTRING("spMinigame02_ani_bot_collector"),this->mBotCanvas);
	HX_STACK_LINE(68)
	this->mBGSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_bg"),null(),this->mBGCanvas,(int)0,(int)0);
	HX_STACK_LINE(69)
	this->mBGMaskSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_background_mask"),null(),this->mGameCanvas,(int)0,(int)0);
	HX_STACK_LINE(71)
	this->mFallingObjectManager->start();
}
;
	return null();
}

VerticalTouchEngine_obj::~VerticalTouchEngine_obj() { }

Dynamic VerticalTouchEngine_obj::__CreateEmpty() { return  new VerticalTouchEngine_obj; }
hx::ObjectPtr< VerticalTouchEngine_obj > VerticalTouchEngine_obj::__new(::com::funbox::bcp::minigame2::MiniGame2 miniGameRef,::native::display::Sprite gameCanvas)
{  hx::ObjectPtr< VerticalTouchEngine_obj > result = new VerticalTouchEngine_obj();
	result->__construct(miniGameRef,gameCanvas);
	return result;}

Dynamic VerticalTouchEngine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VerticalTouchEngine_obj > result = new VerticalTouchEngine_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void VerticalTouchEngine_obj::free( ){
{
		HX_STACK_PUSH("VerticalTouchEngine::free","com/funbox/bcp/minigame2/engine/VerticalTouchEngine.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_LINE(86)
		this->mEntitiesController->free();
		HX_STACK_LINE(87)
		this->mFallingObjectManager->free();
		HX_STACK_LINE(88)
		this->mBotCollector->free();
		HX_STACK_LINE(89)
		this->mEffectManager->free();
		HX_STACK_LINE(90)
		this->mBGSprite->free();
		HX_STACK_LINE(91)
		this->mBGMaskSprite->free();
		HX_STACK_LINE(92)
		this->mPlayer->free();
		HX_STACK_LINE(94)
		this->mBGSprite = null();
		HX_STACK_LINE(95)
		this->mBotCollector = null();
		HX_STACK_LINE(96)
		this->mEntitiesController = null();
		HX_STACK_LINE(97)
		this->mFallingObjectManager = null();
		HX_STACK_LINE(98)
		this->mEffectManager = null();
		HX_STACK_LINE(99)
		this->mBGMaskSprite = null();
		HX_STACK_LINE(100)
		this->mPlayer = null();
		HX_STACK_LINE(102)
		this->mGameCanvas->removeChild(this->mBGCanvas);
		HX_STACK_LINE(103)
		this->mGameCanvas->removeChild(this->mEntitiesCanvas);
		HX_STACK_LINE(104)
		this->mGameCanvas->removeChild(this->mBotCanvas);
		HX_STACK_LINE(105)
		this->mGameCanvas->removeChild(this->mPlayerCanvas);
		HX_STACK_LINE(106)
		this->mGameCanvas->removeChild(this->mEffectCanvas);
		HX_STACK_LINE(108)
		this->mBGCanvas = null();
		HX_STACK_LINE(109)
		this->mEntitiesCanvas = null();
		HX_STACK_LINE(110)
		this->mBotCanvas = null();
		HX_STACK_LINE(111)
		this->mPlayerCanvas = null();
		HX_STACK_LINE(112)
		this->mEffectCanvas = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(VerticalTouchEngine_obj,free,(void))

Void VerticalTouchEngine_obj::update( int dt){
{
		HX_STACK_PUSH("VerticalTouchEngine::update","com/funbox/bcp/minigame2/engine/VerticalTouchEngine.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(75)
		this->mPlayer->update(dt);
		HX_STACK_LINE(77)
		this->mEntitiesController->update(dt);
		HX_STACK_LINE(78)
		this->mFallingObjectManager->update(dt);
		HX_STACK_LINE(79)
		this->mBotCollector->update(dt);
		HX_STACK_LINE(80)
		this->mEffectManager->update(dt);
		HX_STACK_LINE(81)
		this->mBGSprite->update(dt);
		HX_STACK_LINE(82)
		this->mBGMaskSprite->update(dt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(VerticalTouchEngine_obj,update,(void))

::com::funbox::bcp::minigame2::engine::EntitiesController VerticalTouchEngine_obj::getEntitiesController( ){
	HX_STACK_PUSH("VerticalTouchEngine::getEntitiesController","com/funbox/bcp/minigame2/engine/VerticalTouchEngine.hx",39);
	HX_STACK_THIS(this);
	HX_STACK_LINE(39)
	return this->mEntitiesController;
}


HX_DEFINE_DYNAMIC_FUNC0(VerticalTouchEngine_obj,getEntitiesController,return )

::com::funbox::bcp::minigame2::engine::effectManager::EffectManager VerticalTouchEngine_obj::getEffectManager( ){
	HX_STACK_PUSH("VerticalTouchEngine::getEffectManager","com/funbox/bcp/minigame2/engine/VerticalTouchEngine.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_LINE(38)
	return this->mEffectManager;
}


HX_DEFINE_DYNAMIC_FUNC0(VerticalTouchEngine_obj,getEffectManager,return )

::com::funbox::bcp::minigame2::entities::enemy::BotCollector VerticalTouchEngine_obj::getBotCollector( ){
	HX_STACK_PUSH("VerticalTouchEngine::getBotCollector","com/funbox/bcp/minigame2/engine/VerticalTouchEngine.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_LINE(37)
	return this->mBotCollector;
}


HX_DEFINE_DYNAMIC_FUNC0(VerticalTouchEngine_obj,getBotCollector,return )


VerticalTouchEngine_obj::VerticalTouchEngine_obj()
{
}

void VerticalTouchEngine_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VerticalTouchEngine);
	HX_MARK_MEMBER_NAME(mMinigameRef,"mMinigameRef");
	HX_MARK_MEMBER_NAME(mEffectManager,"mEffectManager");
	HX_MARK_MEMBER_NAME(mFallingObjectManager,"mFallingObjectManager");
	HX_MARK_MEMBER_NAME(mEntitiesController,"mEntitiesController");
	HX_MARK_MEMBER_NAME(mBotCollector,"mBotCollector");
	HX_MARK_MEMBER_NAME(mPlayer,"mPlayer");
	HX_MARK_MEMBER_NAME(mBGMaskSprite,"mBGMaskSprite");
	HX_MARK_MEMBER_NAME(mBGSprite,"mBGSprite");
	HX_MARK_MEMBER_NAME(mBGCanvas,"mBGCanvas");
	HX_MARK_MEMBER_NAME(mEffectCanvas,"mEffectCanvas");
	HX_MARK_MEMBER_NAME(mBotCanvas,"mBotCanvas");
	HX_MARK_MEMBER_NAME(mPlayerCanvas,"mPlayerCanvas");
	HX_MARK_MEMBER_NAME(mEntitiesCanvas,"mEntitiesCanvas");
	HX_MARK_MEMBER_NAME(mGameCanvas,"mGameCanvas");
	HX_MARK_END_CLASS();
}

void VerticalTouchEngine_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mMinigameRef,"mMinigameRef");
	HX_VISIT_MEMBER_NAME(mEffectManager,"mEffectManager");
	HX_VISIT_MEMBER_NAME(mFallingObjectManager,"mFallingObjectManager");
	HX_VISIT_MEMBER_NAME(mEntitiesController,"mEntitiesController");
	HX_VISIT_MEMBER_NAME(mBotCollector,"mBotCollector");
	HX_VISIT_MEMBER_NAME(mPlayer,"mPlayer");
	HX_VISIT_MEMBER_NAME(mBGMaskSprite,"mBGMaskSprite");
	HX_VISIT_MEMBER_NAME(mBGSprite,"mBGSprite");
	HX_VISIT_MEMBER_NAME(mBGCanvas,"mBGCanvas");
	HX_VISIT_MEMBER_NAME(mEffectCanvas,"mEffectCanvas");
	HX_VISIT_MEMBER_NAME(mBotCanvas,"mBotCanvas");
	HX_VISIT_MEMBER_NAME(mPlayerCanvas,"mPlayerCanvas");
	HX_VISIT_MEMBER_NAME(mEntitiesCanvas,"mEntitiesCanvas");
	HX_VISIT_MEMBER_NAME(mGameCanvas,"mGameCanvas");
}

Dynamic VerticalTouchEngine_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mPlayer") ) { return mPlayer; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mBGSprite") ) { return mBGSprite; }
		if (HX_FIELD_EQ(inName,"mBGCanvas") ) { return mBGCanvas; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mBotCanvas") ) { return mBotCanvas; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mGameCanvas") ) { return mGameCanvas; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mMinigameRef") ) { return mMinigameRef; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mBotCollector") ) { return mBotCollector; }
		if (HX_FIELD_EQ(inName,"mBGMaskSprite") ) { return mBGMaskSprite; }
		if (HX_FIELD_EQ(inName,"mEffectCanvas") ) { return mEffectCanvas; }
		if (HX_FIELD_EQ(inName,"mPlayerCanvas") ) { return mPlayerCanvas; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mEffectManager") ) { return mEffectManager; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getBotCollector") ) { return getBotCollector_dyn(); }
		if (HX_FIELD_EQ(inName,"mEntitiesCanvas") ) { return mEntitiesCanvas; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getEffectManager") ) { return getEffectManager_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mEntitiesController") ) { return mEntitiesController; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getEntitiesController") ) { return getEntitiesController_dyn(); }
		if (HX_FIELD_EQ(inName,"mFallingObjectManager") ) { return mFallingObjectManager; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VerticalTouchEngine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mPlayer") ) { mPlayer=inValue.Cast< ::com::funbox::bcp::minigame2::entities::player::GamePlayer >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mBGSprite") ) { mBGSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mBGCanvas") ) { mBGCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mBotCanvas") ) { mBotCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mGameCanvas") ) { mGameCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mMinigameRef") ) { mMinigameRef=inValue.Cast< ::com::funbox::bcp::minigame2::MiniGame2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mBotCollector") ) { mBotCollector=inValue.Cast< ::com::funbox::bcp::minigame2::entities::enemy::BotCollector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mBGMaskSprite") ) { mBGMaskSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mEffectCanvas") ) { mEffectCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mPlayerCanvas") ) { mPlayerCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mEffectManager") ) { mEffectManager=inValue.Cast< ::com::funbox::bcp::minigame2::engine::effectManager::EffectManager >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"mEntitiesCanvas") ) { mEntitiesCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mEntitiesController") ) { mEntitiesController=inValue.Cast< ::com::funbox::bcp::minigame2::engine::EntitiesController >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mFallingObjectManager") ) { mFallingObjectManager=inValue.Cast< ::com::funbox::bcp::minigame2::engine::FallingObjectManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VerticalTouchEngine_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mMinigameRef"));
	outFields->push(HX_CSTRING("mEffectManager"));
	outFields->push(HX_CSTRING("mFallingObjectManager"));
	outFields->push(HX_CSTRING("mEntitiesController"));
	outFields->push(HX_CSTRING("mBotCollector"));
	outFields->push(HX_CSTRING("mPlayer"));
	outFields->push(HX_CSTRING("mBGMaskSprite"));
	outFields->push(HX_CSTRING("mBGSprite"));
	outFields->push(HX_CSTRING("mBGCanvas"));
	outFields->push(HX_CSTRING("mEffectCanvas"));
	outFields->push(HX_CSTRING("mBotCanvas"));
	outFields->push(HX_CSTRING("mPlayerCanvas"));
	outFields->push(HX_CSTRING("mEntitiesCanvas"));
	outFields->push(HX_CSTRING("mGameCanvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("getEntitiesController"),
	HX_CSTRING("getEffectManager"),
	HX_CSTRING("getBotCollector"),
	HX_CSTRING("mMinigameRef"),
	HX_CSTRING("mEffectManager"),
	HX_CSTRING("mFallingObjectManager"),
	HX_CSTRING("mEntitiesController"),
	HX_CSTRING("mBotCollector"),
	HX_CSTRING("mPlayer"),
	HX_CSTRING("mBGMaskSprite"),
	HX_CSTRING("mBGSprite"),
	HX_CSTRING("mBGCanvas"),
	HX_CSTRING("mEffectCanvas"),
	HX_CSTRING("mBotCanvas"),
	HX_CSTRING("mPlayerCanvas"),
	HX_CSTRING("mEntitiesCanvas"),
	HX_CSTRING("mGameCanvas"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VerticalTouchEngine_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VerticalTouchEngine_obj::__mClass,"__mClass");
};

Class VerticalTouchEngine_obj::__mClass;

void VerticalTouchEngine_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.engine.VerticalTouchEngine"), hx::TCanCast< VerticalTouchEngine_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VerticalTouchEngine_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
