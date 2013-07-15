#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#include <com/funbox/bcp/minigame2/MiniGame2.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameHud
#include <com/funbox/bcp/minigame2/screens/GameHud.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameScreen
#include <com/funbox/bcp/minigame2/screens/GameScreen.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameTransitionPopupScreen
#include <com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.h>
#endif
#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_Screen
#include <com/minigloop/ui/Screen.h>
#endif
#ifndef INCLUDED_com_minigloop_util_SoundManager
#include <com/minigloop/util/SoundManager.h>
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
namespace screens{

Void GameScreen_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("GameScreen::new","com/funbox/bcp/minigame2/screens/GameScreen.hx",29);
{
	HX_STACK_LINE(30)
	super::__construct(canvas);
	HX_STACK_LINE(32)
	this->mGameCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(33)
	this->mHudCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(34)
	this->mFrontCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(36)
	this->_canvas->addChild(this->mGameCanvas);
	HX_STACK_LINE(37)
	this->_canvas->addChild(this->mHudCanvas);
	HX_STACK_LINE(38)
	this->_canvas->addChild(this->mFrontCanvas);
	HX_STACK_LINE(40)
	this->_gameHud = ::com::funbox::bcp::minigame2::screens::GameHud_obj::__new(this->mHudCanvas);
	HX_STACK_LINE(41)
	this->_game = ::com::funbox::bcp::minigame2::MiniGame2_obj::__new(this->mGameCanvas,this->_gameHud);
	HX_STACK_LINE(43)
	this->_gameTransition = ::com::funbox::bcp::minigame2::screens::GameTransitionPopupScreen_obj::__new(this->mFrontCanvas,this->onFinishTransition_dyn());
	HX_STACK_LINE(45)
	this->mPausedGame = true;
	HX_STACK_LINE(48)
	this->_gameHud->update((int)33);
	HX_STACK_LINE(49)
	this->_game->update((int)33);
}
;
	return null();
}

GameScreen_obj::~GameScreen_obj() { }

Dynamic GameScreen_obj::__CreateEmpty() { return  new GameScreen_obj; }
hx::ObjectPtr< GameScreen_obj > GameScreen_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< GameScreen_obj > result = new GameScreen_obj();
	result->__construct(canvas);
	return result;}

Dynamic GameScreen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameScreen_obj > result = new GameScreen_obj();
	result->__construct(inArgs[0]);
	return result;}

Void GameScreen_obj::destroy( ){
{
		HX_STACK_PUSH("GameScreen::destroy","com/funbox/bcp/minigame2/screens/GameScreen.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_LINE(71)
		if (((this->_gameTransition != null()))){
			HX_STACK_LINE(71)
			this->_gameTransition->free();
		}
		HX_STACK_LINE(75)
		this->_game->destroy();
		HX_STACK_LINE(76)
		this->_game = null();
		HX_STACK_LINE(78)
		this->_gameHud->free();
		HX_STACK_LINE(79)
		this->_gameHud = null();
		HX_STACK_LINE(81)
		this->_canvas->removeChild(this->mGameCanvas);
		HX_STACK_LINE(82)
		this->_canvas->removeChild(this->mHudCanvas);
		HX_STACK_LINE(84)
		this->mGameCanvas = null();
		HX_STACK_LINE(85)
		this->mHudCanvas = null();
		HX_STACK_LINE(87)
		this->super::destroy();
		HX_STACK_LINE(87)
		return null();
	}
return null();
}


Void GameScreen_obj::update( int dt){
{
		HX_STACK_PUSH("GameScreen::update","com/funbox/bcp/minigame2/screens/GameScreen.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(62)
		if (((this->_gameTransition != null()))){
			HX_STACK_LINE(62)
			this->_gameTransition->update(dt);
		}
		HX_STACK_LINE(64)
		if ((!(this->mPausedGame))){
			HX_STACK_LINE(65)
			this->_gameHud->update(dt);
			HX_STACK_LINE(66)
			this->_game->update(dt);
		}
		HX_STACK_LINE(64)
		return null();
	}
return null();
}


Void GameScreen_obj::onFinishTransition( ){
{
		HX_STACK_PUSH("GameScreen::onFinishTransition","com/funbox/bcp/minigame2/screens/GameScreen.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_LINE(53)
		::com::minigloop::util::SoundManager_obj::play(HX_CSTRING("bgm_juego_2"),true);
		HX_STACK_LINE(55)
		this->_gameTransition->free();
		HX_STACK_LINE(56)
		this->_gameTransition = null();
		HX_STACK_LINE(58)
		this->mPausedGame = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameScreen_obj,onFinishTransition,(void))


GameScreen_obj::GameScreen_obj()
{
}

void GameScreen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameScreen);
	HX_MARK_MEMBER_NAME(mPausedGame,"mPausedGame");
	HX_MARK_MEMBER_NAME(mFrontCanvas,"mFrontCanvas");
	HX_MARK_MEMBER_NAME(mHudCanvas,"mHudCanvas");
	HX_MARK_MEMBER_NAME(mGameCanvas,"mGameCanvas");
	HX_MARK_MEMBER_NAME(_gameTransition,"_gameTransition");
	HX_MARK_MEMBER_NAME(_gameHud,"_gameHud");
	HX_MARK_MEMBER_NAME(_game,"_game");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameScreen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mPausedGame,"mPausedGame");
	HX_VISIT_MEMBER_NAME(mFrontCanvas,"mFrontCanvas");
	HX_VISIT_MEMBER_NAME(mHudCanvas,"mHudCanvas");
	HX_VISIT_MEMBER_NAME(mGameCanvas,"mGameCanvas");
	HX_VISIT_MEMBER_NAME(_gameTransition,"_gameTransition");
	HX_VISIT_MEMBER_NAME(_gameHud,"_gameHud");
	HX_VISIT_MEMBER_NAME(_game,"_game");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GameScreen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_game") ) { return _game; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gameHud") ) { return _gameHud; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mHudCanvas") ) { return mHudCanvas; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mPausedGame") ) { return mPausedGame; }
		if (HX_FIELD_EQ(inName,"mGameCanvas") ) { return mGameCanvas; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mFrontCanvas") ) { return mFrontCanvas; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_gameTransition") ) { return _gameTransition; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onFinishTransition") ) { return onFinishTransition_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameScreen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_game") ) { _game=inValue.Cast< ::com::funbox::bcp::minigame2::MiniGame2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gameHud") ) { _gameHud=inValue.Cast< ::com::funbox::bcp::minigame2::screens::GameHud >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mHudCanvas") ) { mHudCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mPausedGame") ) { mPausedGame=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mGameCanvas") ) { mGameCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mFrontCanvas") ) { mFrontCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_gameTransition") ) { _gameTransition=inValue.Cast< ::com::funbox::bcp::minigame2::screens::GameTransitionPopupScreen >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameScreen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mPausedGame"));
	outFields->push(HX_CSTRING("mFrontCanvas"));
	outFields->push(HX_CSTRING("mHudCanvas"));
	outFields->push(HX_CSTRING("mGameCanvas"));
	outFields->push(HX_CSTRING("_gameTransition"));
	outFields->push(HX_CSTRING("_gameHud"));
	outFields->push(HX_CSTRING("_game"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("onFinishTransition"),
	HX_CSTRING("mPausedGame"),
	HX_CSTRING("mFrontCanvas"),
	HX_CSTRING("mHudCanvas"),
	HX_CSTRING("mGameCanvas"),
	HX_CSTRING("_gameTransition"),
	HX_CSTRING("_gameHud"),
	HX_CSTRING("_game"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameScreen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameScreen_obj::__mClass,"__mClass");
};

Class GameScreen_obj::__mClass;

void GameScreen_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.screens.GameScreen"), hx::TCanCast< GameScreen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GameScreen_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens
