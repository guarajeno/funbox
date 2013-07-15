#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#include <com/funbox/bcp/minigame2/MiniGame2.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_VerticalTouchEngine
#include <com/funbox/bcp/minigame2/engine/VerticalTouchEngine.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameHud
#include <com/funbox/bcp/minigame2/screens/GameHud.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_ScoreCardScreen
#include <com/funbox/bcp/minigame2/screens/ScoreCardScreen.h>
#endif
#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_Screen
#include <com/minigloop/ui/Screen.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_ScreenManager
#include <com/minigloop/ui/ScreenManager.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
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
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{

Void MiniGame2_obj::__construct(::native::display::Sprite canvas,::com::funbox::bcp::minigame2::screens::GameHud gameHud)
{
HX_STACK_PUSH("MiniGame2::new","com/funbox/bcp/minigame2/MiniGame2.hx",44);
{
	HX_STACK_LINE(45)
	super::__construct(canvas);
	HX_STACK_LINE(47)
	::com::funbox::bcp::minigame2::Global_obj::minigame = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(49)
	this->mGameHud = gameHud;
	HX_STACK_LINE(51)
	this->mLevelTime = (int)30100;
	HX_STACK_LINE(52)
	this->mMousePressed = false;
	HX_STACK_LINE(55)
	this->mGhostGameMask = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(56)
	this->mGhostGameMask->get_graphics()->beginFill((int)16777215,(int)0);
	HX_STACK_LINE(57)
	this->mGhostGameMask->get_graphics()->drawRect((int)0,(int)0,(int)2000,(int)2000);
	HX_STACK_LINE(58)
	this->mGhostGameMask->get_graphics()->endFill();
	HX_STACK_LINE(60)
	this->mGhostGameMask->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->onMouseHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(61)
	this->mGhostGameMask->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(62)
	this->mGhostGameMask->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onMouseHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(63)
	this->mGhostGameMask->addEventListener(::native::events::MouseEvent_obj::MOUSE_OUT,this->onMouseHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(64)
	this->mGhostGameMask->addEventListener(::native::events::MouseEvent_obj::ROLL_OUT,this->onMouseHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(67)
	this->mGameCanvas = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(68)
	this->_canvas->addChild(this->mGameCanvas);
	HX_STACK_LINE(70)
	this->mVTEngine = ::com::funbox::bcp::minigame2::engine::VerticalTouchEngine_obj::__new(hx::ObjectPtr<OBJ_>(this),this->mGameCanvas);
	HX_STACK_LINE(73)
	::com::funbox::bcp::minigame2::Global_obj::stage->addChild(this->mGhostGameMask);
}
;
	return null();
}

MiniGame2_obj::~MiniGame2_obj() { }

Dynamic MiniGame2_obj::__CreateEmpty() { return  new MiniGame2_obj; }
hx::ObjectPtr< MiniGame2_obj > MiniGame2_obj::__new(::native::display::Sprite canvas,::com::funbox::bcp::minigame2::screens::GameHud gameHud)
{  hx::ObjectPtr< MiniGame2_obj > result = new MiniGame2_obj();
	result->__construct(canvas,gameHud);
	return result;}

Dynamic MiniGame2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MiniGame2_obj > result = new MiniGame2_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void MiniGame2_obj::destroy( ){
{
		HX_STACK_PUSH("MiniGame2::destroy","com/funbox/bcp/minigame2/MiniGame2.hx",116);
		HX_STACK_THIS(this);
		HX_STACK_LINE(117)
		this->mVTEngine->free();
		HX_STACK_LINE(118)
		this->mVTEngine = null();
		HX_STACK_LINE(120)
		::com::funbox::bcp::minigame2::Global_obj::stage->removeChild(this->mGhostGameMask);
		HX_STACK_LINE(121)
		this->mGhostGameMask = null();
		HX_STACK_LINE(123)
		this->_canvas->removeChild(this->mGameCanvas);
		HX_STACK_LINE(124)
		this->mGameCanvas = null();
		HX_STACK_LINE(127)
		this->super::destroy();
		HX_STACK_LINE(127)
		return null();
	}
return null();
}


Void MiniGame2_obj::update( int dt){
{
		HX_STACK_PUSH("MiniGame2::update","com/funbox/bcp/minigame2/MiniGame2.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(100)
		this->mVTEngine->update(dt);
		HX_STACK_LINE(102)
		hx::SubEq(this->mLevelTime,dt);
		HX_STACK_LINE(104)
		if (((this->mLevelTime <= (int)0))){
			HX_STACK_LINE(105)
			this->mLevelTime = (int)0;
			HX_STACK_LINE(106)
			this->mGameHud->SetTime(this->mLevelTime);
			HX_STACK_LINE(108)
			::com::funbox::bcp::minigame2::Global_obj::totalPoints = this->mGameHud->GetScore();
			HX_STACK_LINE(109)
			::com::minigloop::ui::ScreenManager_obj::getInstance()->gotoScreen(hx::ClassOf< ::com::funbox::bcp::minigame2::screens::ScoreCardScreen >());
		}
		else{
			HX_STACK_LINE(111)
			this->mGameHud->SetTime(this->mLevelTime);
		}
		HX_STACK_LINE(104)
		return null();
	}
return null();
}


Void MiniGame2_obj::onMouseHandler( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("MiniGame2::onMouseHandler","com/funbox/bcp/minigame2/MiniGame2.hx",76);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(76)
		::String _switch_1 = (e->get_type());
		if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_MOVE)){
		}
		else if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_DOWN)){
			HX_STACK_LINE(88)
			this->mMousePressed = true;
		}
		else if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_UP)){
			HX_STACK_LINE(90)
			this->mMousePressed = false;
		}
		else if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_OUT)){
			HX_STACK_LINE(92)
			this->mMousePressed = false;
		}
		else if (  ( _switch_1==::native::events::MouseEvent_obj::ROLL_OUT)){
			HX_STACK_LINE(94)
			this->mMousePressed = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MiniGame2_obj,onMouseHandler,(void))

::com::funbox::bcp::minigame2::screens::GameHud MiniGame2_obj::getGameHud( ){
	HX_STACK_PUSH("MiniGame2::getGameHud","com/funbox/bcp/minigame2/MiniGame2.hx",42);
	HX_STACK_THIS(this);
	HX_STACK_LINE(42)
	return this->mGameHud;
}


HX_DEFINE_DYNAMIC_FUNC0(MiniGame2_obj,getGameHud,return )

::com::funbox::bcp::minigame2::engine::VerticalTouchEngine MiniGame2_obj::getVTEngine( ){
	HX_STACK_PUSH("MiniGame2::getVTEngine","com/funbox/bcp/minigame2/MiniGame2.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_LINE(41)
	return this->mVTEngine;
}


HX_DEFINE_DYNAMIC_FUNC0(MiniGame2_obj,getVTEngine,return )

bool MiniGame2_obj::isMousePressed( ){
	HX_STACK_PUSH("MiniGame2::isMousePressed","com/funbox/bcp/minigame2/MiniGame2.hx",39);
	HX_STACK_THIS(this);
	HX_STACK_LINE(39)
	return this->mMousePressed;
}


HX_DEFINE_DYNAMIC_FUNC0(MiniGame2_obj,isMousePressed,return )

Float MiniGame2_obj::getMouseY( ){
	HX_STACK_PUSH("MiniGame2::getMouseY","com/funbox/bcp/minigame2/MiniGame2.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_LINE(38)
	return this->mMouseY;
}


HX_DEFINE_DYNAMIC_FUNC0(MiniGame2_obj,getMouseY,return )

Float MiniGame2_obj::getMouseX( ){
	HX_STACK_PUSH("MiniGame2::getMouseX","com/funbox/bcp/minigame2/MiniGame2.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_LINE(37)
	return this->mMouseX;
}


HX_DEFINE_DYNAMIC_FUNC0(MiniGame2_obj,getMouseX,return )


MiniGame2_obj::MiniGame2_obj()
{
}

void MiniGame2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MiniGame2);
	HX_MARK_MEMBER_NAME(mLevelTime,"mLevelTime");
	HX_MARK_MEMBER_NAME(mMousePressed,"mMousePressed");
	HX_MARK_MEMBER_NAME(mMouseY,"mMouseY");
	HX_MARK_MEMBER_NAME(mMouseX,"mMouseX");
	HX_MARK_MEMBER_NAME(mVTEngine,"mVTEngine");
	HX_MARK_MEMBER_NAME(mGameHud,"mGameHud");
	HX_MARK_MEMBER_NAME(mGameCanvas,"mGameCanvas");
	HX_MARK_MEMBER_NAME(mGhostGameMask,"mGhostGameMask");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MiniGame2_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mLevelTime,"mLevelTime");
	HX_VISIT_MEMBER_NAME(mMousePressed,"mMousePressed");
	HX_VISIT_MEMBER_NAME(mMouseY,"mMouseY");
	HX_VISIT_MEMBER_NAME(mMouseX,"mMouseX");
	HX_VISIT_MEMBER_NAME(mVTEngine,"mVTEngine");
	HX_VISIT_MEMBER_NAME(mGameHud,"mGameHud");
	HX_VISIT_MEMBER_NAME(mGameCanvas,"mGameCanvas");
	HX_VISIT_MEMBER_NAME(mGhostGameMask,"mGhostGameMask");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MiniGame2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"mMouseY") ) { return mMouseY; }
		if (HX_FIELD_EQ(inName,"mMouseX") ) { return mMouseX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mGameHud") ) { return mGameHud; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getMouseY") ) { return getMouseY_dyn(); }
		if (HX_FIELD_EQ(inName,"getMouseX") ) { return getMouseX_dyn(); }
		if (HX_FIELD_EQ(inName,"mVTEngine") ) { return mVTEngine; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getGameHud") ) { return getGameHud_dyn(); }
		if (HX_FIELD_EQ(inName,"mLevelTime") ) { return mLevelTime; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getVTEngine") ) { return getVTEngine_dyn(); }
		if (HX_FIELD_EQ(inName,"mGameCanvas") ) { return mGameCanvas; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mMousePressed") ) { return mMousePressed; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onMouseHandler") ) { return onMouseHandler_dyn(); }
		if (HX_FIELD_EQ(inName,"isMousePressed") ) { return isMousePressed_dyn(); }
		if (HX_FIELD_EQ(inName,"mGhostGameMask") ) { return mGhostGameMask; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MiniGame2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mMouseY") ) { mMouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mMouseX") ) { mMouseX=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mGameHud") ) { mGameHud=inValue.Cast< ::com::funbox::bcp::minigame2::screens::GameHud >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mVTEngine") ) { mVTEngine=inValue.Cast< ::com::funbox::bcp::minigame2::engine::VerticalTouchEngine >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mLevelTime") ) { mLevelTime=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mGameCanvas") ) { mGameCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mMousePressed") ) { mMousePressed=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mGhostGameMask") ) { mGhostGameMask=inValue.Cast< ::native::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MiniGame2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mLevelTime"));
	outFields->push(HX_CSTRING("mMousePressed"));
	outFields->push(HX_CSTRING("mMouseY"));
	outFields->push(HX_CSTRING("mMouseX"));
	outFields->push(HX_CSTRING("mVTEngine"));
	outFields->push(HX_CSTRING("mGameHud"));
	outFields->push(HX_CSTRING("mGameCanvas"));
	outFields->push(HX_CSTRING("mGhostGameMask"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("onMouseHandler"),
	HX_CSTRING("getGameHud"),
	HX_CSTRING("getVTEngine"),
	HX_CSTRING("isMousePressed"),
	HX_CSTRING("getMouseY"),
	HX_CSTRING("getMouseX"),
	HX_CSTRING("mLevelTime"),
	HX_CSTRING("mMousePressed"),
	HX_CSTRING("mMouseY"),
	HX_CSTRING("mMouseX"),
	HX_CSTRING("mVTEngine"),
	HX_CSTRING("mGameHud"),
	HX_CSTRING("mGameCanvas"),
	HX_CSTRING("mGhostGameMask"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MiniGame2_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MiniGame2_obj::__mClass,"__mClass");
};

Class MiniGame2_obj::__mClass;

void MiniGame2_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.MiniGame2"), hx::TCanCast< MiniGame2_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MiniGame2_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
