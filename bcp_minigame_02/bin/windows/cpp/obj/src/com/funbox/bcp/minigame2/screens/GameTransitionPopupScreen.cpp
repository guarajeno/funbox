#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameTransitionPopupScreen
#include <com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NUtils
#include <com/funbox/bcp/minigame2/util/NUtils.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_ScaleTweener
#include <com/funbox/bcp/minigame2/util/ScaleTweener.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
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

Void GameTransitionPopupScreen_obj::__construct(::native::display::Sprite canvas,Dynamic onCallbackFunction)
{
HX_STACK_PUSH("GameTransitionPopupScreen::new","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",28);
{
	HX_STACK_LINE(29)
	this->mCanvas = canvas;
	HX_STACK_LINE(30)
	this->mOnCallbackFunction = onCallbackFunction;
	HX_STACK_LINE(32)
	this->_img_1 = ::com::funbox::bcp::minigame2::util::NUtils_obj::getAsset(HX_CSTRING("spMinigame02_gui_text_03"));
	HX_STACK_LINE(33)
	this->_img_2 = ::com::funbox::bcp::minigame2::util::NUtils_obj::getAsset(HX_CSTRING("spMinigame02_gui_text_02"));
	HX_STACK_LINE(34)
	this->_img_3 = ::com::funbox::bcp::minigame2::util::NUtils_obj::getAsset(HX_CSTRING("spMinigame02_gui_text_01"));
	HX_STACK_LINE(35)
	this->_start = ::com::funbox::bcp::minigame2::util::NUtils_obj::getAsset(HX_CSTRING("spMinigame02_gui_text_start"));
	HX_STACK_LINE(37)
	this->_img_1->set_x((int)310);
	HX_STACK_LINE(38)
	this->_img_1->set_y((int)220);
	HX_STACK_LINE(39)
	this->_img_1->set_scaleX((int)0);
	HX_STACK_LINE(41)
	this->_img_2->set_x((int)310);
	HX_STACK_LINE(42)
	this->_img_2->set_y((int)220);
	HX_STACK_LINE(43)
	this->_img_2->set_scaleX((int)0);
	HX_STACK_LINE(45)
	this->_img_3->set_x((int)310);
	HX_STACK_LINE(46)
	this->_img_3->set_y((int)220);
	HX_STACK_LINE(47)
	this->_img_3->set_scaleX((int)0);
	HX_STACK_LINE(49)
	this->_start->set_x((int)180);
	HX_STACK_LINE(50)
	this->_start->set_y((int)220);
	HX_STACK_LINE(51)
	this->_start->set_scaleX((int)0);
	HX_STACK_LINE(53)
	this->mCanvas->addChild(this->_img_1);
	HX_STACK_LINE(54)
	this->mCanvas->addChild(this->_img_2);
	HX_STACK_LINE(55)
	this->mCanvas->addChild(this->_img_3);
	HX_STACK_LINE(56)
	this->mCanvas->addChild(this->_start);
	HX_STACK_LINE(58)
	this->_state = HX_CSTRING("tweening");
	HX_STACK_LINE(60)
	this->_scaleTweener = ::com::funbox::bcp::minigame2::util::ScaleTweener_obj::__new(this->_img_1,this->tween2_dyn());
	HX_STACK_LINE(61)
	this->_scaleTweener->_factor = 0.1;
}
;
	return null();
}

GameTransitionPopupScreen_obj::~GameTransitionPopupScreen_obj() { }

Dynamic GameTransitionPopupScreen_obj::__CreateEmpty() { return  new GameTransitionPopupScreen_obj; }
hx::ObjectPtr< GameTransitionPopupScreen_obj > GameTransitionPopupScreen_obj::__new(::native::display::Sprite canvas,Dynamic onCallbackFunction)
{  hx::ObjectPtr< GameTransitionPopupScreen_obj > result = new GameTransitionPopupScreen_obj();
	result->__construct(canvas,onCallbackFunction);
	return result;}

Dynamic GameTransitionPopupScreen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameTransitionPopupScreen_obj > result = new GameTransitionPopupScreen_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void GameTransitionPopupScreen_obj::free( ){
{
		HX_STACK_PUSH("GameTransitionPopupScreen::free","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_LINE(101)
		this->_scaleTweener = null();
		HX_STACK_LINE(103)
		this->mCanvas->removeChild(this->_img_1);
		HX_STACK_LINE(104)
		this->mCanvas->removeChild(this->_img_2);
		HX_STACK_LINE(105)
		this->mCanvas->removeChild(this->_img_3);
		HX_STACK_LINE(106)
		this->mCanvas->removeChild(this->_start);
		HX_STACK_LINE(108)
		this->_img_1 = null();
		HX_STACK_LINE(109)
		this->_img_2 = null();
		HX_STACK_LINE(110)
		this->_img_3 = null();
		HX_STACK_LINE(111)
		this->_start = null();
		HX_STACK_LINE(113)
		this->mCanvas = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameTransitionPopupScreen_obj,free,(void))

Void GameTransitionPopupScreen_obj::update( int dt){
{
		HX_STACK_PUSH("GameTransitionPopupScreen::update","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(87)
		::String _switch_1 = (this->_state);
		if (  ( _switch_1==HX_CSTRING("tweening"))){
			HX_STACK_LINE(89)
			this->_scaleTweener->update(dt);
		}
		else if (  ( _switch_1==HX_CSTRING("init_game"))){
			HX_STACK_LINE(92)
			if (((this->mOnCallbackFunction != null()))){
				HX_STACK_LINE(93)
				this->mOnCallbackFunction();
				HX_STACK_LINE(94)
				this->mOnCallbackFunction = null();
			}
			HX_STACK_LINE(96)
			this->_state = HX_CSTRING("");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameTransitionPopupScreen_obj,update,(void))

Void GameTransitionPopupScreen_obj::endTweens( ){
{
		HX_STACK_PUSH("GameTransitionPopupScreen::endTweens","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",83);
		HX_STACK_THIS(this);
		HX_STACK_LINE(83)
		this->_state = HX_CSTRING("init_game");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameTransitionPopupScreen_obj,endTweens,(void))

Void GameTransitionPopupScreen_obj::tweenStart( ){
{
		HX_STACK_PUSH("GameTransitionPopupScreen::tweenStart","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_LINE(78)
		this->_scaleTweener = ::com::funbox::bcp::minigame2::util::ScaleTweener_obj::__new(this->_start,this->endTweens_dyn());
		HX_STACK_LINE(79)
		this->_scaleTweener->_factor = 0.1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameTransitionPopupScreen_obj,tweenStart,(void))

Void GameTransitionPopupScreen_obj::tween3( ){
{
		HX_STACK_PUSH("GameTransitionPopupScreen::tween3","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_LINE(72)
		this->_scaleTweener = ::com::funbox::bcp::minigame2::util::ScaleTweener_obj::__new(this->_img_3,this->tweenStart_dyn());
		HX_STACK_LINE(73)
		this->_scaleTweener->_factor = 0.1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameTransitionPopupScreen_obj,tween3,(void))

Void GameTransitionPopupScreen_obj::tween2( ){
{
		HX_STACK_PUSH("GameTransitionPopupScreen::tween2","com/funbox/bcp/minigame2/screens/GameTransitionPopupScreen.hx",65);
		HX_STACK_THIS(this);
		HX_STACK_LINE(66)
		this->_scaleTweener = ::com::funbox::bcp::minigame2::util::ScaleTweener_obj::__new(this->_img_2,this->tween3_dyn());
		HX_STACK_LINE(67)
		this->_scaleTweener->_factor = 0.1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameTransitionPopupScreen_obj,tween2,(void))


GameTransitionPopupScreen_obj::GameTransitionPopupScreen_obj()
{
}

void GameTransitionPopupScreen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameTransitionPopupScreen);
	HX_MARK_MEMBER_NAME(mOnCallbackFunction,"mOnCallbackFunction");
	HX_MARK_MEMBER_NAME(_scaleTweener,"_scaleTweener");
	HX_MARK_MEMBER_NAME(_state,"_state");
	HX_MARK_MEMBER_NAME(mCanvas,"mCanvas");
	HX_MARK_MEMBER_NAME(_start,"_start");
	HX_MARK_MEMBER_NAME(_img_3,"_img_3");
	HX_MARK_MEMBER_NAME(_img_2,"_img_2");
	HX_MARK_MEMBER_NAME(_img_1,"_img_1");
	HX_MARK_END_CLASS();
}

void GameTransitionPopupScreen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mOnCallbackFunction,"mOnCallbackFunction");
	HX_VISIT_MEMBER_NAME(_scaleTweener,"_scaleTweener");
	HX_VISIT_MEMBER_NAME(_state,"_state");
	HX_VISIT_MEMBER_NAME(mCanvas,"mCanvas");
	HX_VISIT_MEMBER_NAME(_start,"_start");
	HX_VISIT_MEMBER_NAME(_img_3,"_img_3");
	HX_VISIT_MEMBER_NAME(_img_2,"_img_2");
	HX_VISIT_MEMBER_NAME(_img_1,"_img_1");
}

Dynamic GameTransitionPopupScreen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"tween3") ) { return tween3_dyn(); }
		if (HX_FIELD_EQ(inName,"tween2") ) { return tween2_dyn(); }
		if (HX_FIELD_EQ(inName,"_state") ) { return _state; }
		if (HX_FIELD_EQ(inName,"_start") ) { return _start; }
		if (HX_FIELD_EQ(inName,"_img_3") ) { return _img_3; }
		if (HX_FIELD_EQ(inName,"_img_2") ) { return _img_2; }
		if (HX_FIELD_EQ(inName,"_img_1") ) { return _img_1; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mCanvas") ) { return mCanvas; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"endTweens") ) { return endTweens_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tweenStart") ) { return tweenStart_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_scaleTweener") ) { return _scaleTweener; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mOnCallbackFunction") ) { return mOnCallbackFunction; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameTransitionPopupScreen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_state") ) { _state=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_start") ) { _start=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_img_3") ) { _img_3=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_img_2") ) { _img_2=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_img_1") ) { _img_1=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mCanvas") ) { mCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_scaleTweener") ) { _scaleTweener=inValue.Cast< ::com::funbox::bcp::minigame2::util::ScaleTweener >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mOnCallbackFunction") ) { mOnCallbackFunction=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameTransitionPopupScreen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mOnCallbackFunction"));
	outFields->push(HX_CSTRING("_scaleTweener"));
	outFields->push(HX_CSTRING("_state"));
	outFields->push(HX_CSTRING("mCanvas"));
	outFields->push(HX_CSTRING("_start"));
	outFields->push(HX_CSTRING("_img_3"));
	outFields->push(HX_CSTRING("_img_2"));
	outFields->push(HX_CSTRING("_img_1"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("endTweens"),
	HX_CSTRING("tweenStart"),
	HX_CSTRING("tween3"),
	HX_CSTRING("tween2"),
	HX_CSTRING("mOnCallbackFunction"),
	HX_CSTRING("_scaleTweener"),
	HX_CSTRING("_state"),
	HX_CSTRING("mCanvas"),
	HX_CSTRING("_start"),
	HX_CSTRING("_img_3"),
	HX_CSTRING("_img_2"),
	HX_CSTRING("_img_1"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameTransitionPopupScreen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameTransitionPopupScreen_obj::__mClass,"__mClass");
};

Class GameTransitionPopupScreen_obj::__mClass;

void GameTransitionPopupScreen_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.screens.GameTransitionPopupScreen"), hx::TCanCast< GameTransitionPopupScreen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GameTransitionPopupScreen_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens
