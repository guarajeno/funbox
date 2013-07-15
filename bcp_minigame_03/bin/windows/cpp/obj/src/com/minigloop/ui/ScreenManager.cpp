#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
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
namespace minigloop{
namespace ui{

Void ScreenManager_obj::__construct()
{
HX_STACK_PUSH("ScreenManager::new","com/minigloop/ui/ScreenManager.hx",16);
{
}
;
	return null();
}

ScreenManager_obj::~ScreenManager_obj() { }

Dynamic ScreenManager_obj::__CreateEmpty() { return  new ScreenManager_obj; }
hx::ObjectPtr< ScreenManager_obj > ScreenManager_obj::__new()
{  hx::ObjectPtr< ScreenManager_obj > result = new ScreenManager_obj();
	result->__construct();
	return result;}

Dynamic ScreenManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScreenManager_obj > result = new ScreenManager_obj();
	result->__construct();
	return result;}

Void ScreenManager_obj::update( int dt){
{
		HX_STACK_PUSH("ScreenManager::update","com/minigloop/ui/ScreenManager.hx",36);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(36)
		if (((::com::minigloop::ui::ScreenManager_obj::_currentScreen != null()))){
			HX_STACK_LINE(38)
			::com::minigloop::ui::ScreenManager_obj::_currentScreen->update(dt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScreenManager_obj,update,(void))

Void ScreenManager_obj::gotoScreen( ::Class screenClass){
{
		HX_STACK_PUSH("ScreenManager::gotoScreen","com/minigloop/ui/ScreenManager.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_ARG(screenClass,"screenClass");
		HX_STACK_LINE(27)
		if (((::com::minigloop::ui::ScreenManager_obj::_currentScreen != null()))){
			HX_STACK_LINE(28)
			::com::minigloop::ui::ScreenManager_obj::_currentScreen->destroy();
		}
		HX_STACK_LINE(32)
		::com::minigloop::ui::ScreenManager_obj::_currentScreen = ::Type_obj::createInstance(screenClass,Dynamic( Array_obj<Dynamic>::__new().Add(::com::minigloop::ui::ScreenManager_obj::_canvas)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScreenManager_obj,gotoScreen,(void))

Void ScreenManager_obj::init( ::native::display::Sprite canvas){
{
		HX_STACK_PUSH("ScreenManager::init","com/minigloop/ui/ScreenManager.hx",20);
		HX_STACK_THIS(this);
		HX_STACK_ARG(canvas,"canvas");
		HX_STACK_LINE(21)
		::com::minigloop::ui::ScreenManager_obj::_canvas = canvas;
		HX_STACK_LINE(22)
		::com::minigloop::ui::ScreenManager_obj::_currentScreen = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScreenManager_obj,init,(void))

::com::minigloop::ui::ScreenManager ScreenManager_obj::instance;

::com::minigloop::ui::Screen ScreenManager_obj::_currentScreen;

::native::display::Sprite ScreenManager_obj::_canvas;

::com::minigloop::ui::ScreenManager ScreenManager_obj::getInstance( ){
	HX_STACK_PUSH("ScreenManager::getInstance","com/minigloop/ui/ScreenManager.hx",44);
	HX_STACK_LINE(45)
	if (((::com::minigloop::ui::ScreenManager_obj::instance == null()))){
		HX_STACK_LINE(46)
		::com::minigloop::ui::ScreenManager_obj::instance = ::com::minigloop::ui::ScreenManager_obj::__new();
	}
	HX_STACK_LINE(50)
	return ::com::minigloop::ui::ScreenManager_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ScreenManager_obj,getInstance,return )


ScreenManager_obj::ScreenManager_obj()
{
}

void ScreenManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScreenManager);
	HX_MARK_END_CLASS();
}

void ScreenManager_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic ScreenManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { return _canvas; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return inCallProp ? getInstance() : instance; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gotoScreen") ) { return gotoScreen_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_currentScreen") ) { return _currentScreen; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ScreenManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { _canvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::com::minigloop::ui::ScreenManager >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_currentScreen") ) { _currentScreen=inValue.Cast< ::com::minigloop::ui::Screen >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScreenManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("_currentScreen"),
	HX_CSTRING("_canvas"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("gotoScreen"),
	HX_CSTRING("init"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScreenManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ScreenManager_obj::instance,"instance");
	HX_MARK_MEMBER_NAME(ScreenManager_obj::_currentScreen,"_currentScreen");
	HX_MARK_MEMBER_NAME(ScreenManager_obj::_canvas,"_canvas");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScreenManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ScreenManager_obj::instance,"instance");
	HX_VISIT_MEMBER_NAME(ScreenManager_obj::_currentScreen,"_currentScreen");
	HX_VISIT_MEMBER_NAME(ScreenManager_obj::_canvas,"_canvas");
};

Class ScreenManager_obj::__mClass;

void ScreenManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.ui.ScreenManager"), hx::TCanCast< ScreenManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ScreenManager_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace ui
