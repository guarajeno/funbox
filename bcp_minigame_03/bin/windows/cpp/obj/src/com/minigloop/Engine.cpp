#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_Engine
#include <com/minigloop/Engine.h>
#endif
#ifndef INCLUDED_com_minigloop_input_Mouse
#include <com/minigloop/input/Mouse.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_Screen
#include <com/minigloop/ui/Screen.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_ScreenManager
#include <com/minigloop/ui/ScreenManager.h>
#endif
#ifndef INCLUDED_native_Lib
#include <native/Lib.h>
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
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
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
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace minigloop{

Void Engine_obj::__construct(::native::display::Stage stage,::Class gameClass)
{
HX_STACK_PUSH("Engine::new","com/minigloop/Engine.hx",34);
{
	HX_STACK_LINE(35)
	this->_stage = stage;
	HX_STACK_LINE(36)
	this->_gameClass = gameClass;
	HX_STACK_LINE(37)
	this->init();
}
;
	return null();
}

Engine_obj::~Engine_obj() { }

Dynamic Engine_obj::__CreateEmpty() { return  new Engine_obj; }
hx::ObjectPtr< Engine_obj > Engine_obj::__new(::native::display::Stage stage,::Class gameClass)
{  hx::ObjectPtr< Engine_obj > result = new Engine_obj();
	result->__construct(stage,gameClass);
	return result;}

Dynamic Engine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Engine_obj > result = new Engine_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Engine_obj::update( int dt){
{
		HX_STACK_PUSH("Engine::update","com/minigloop/Engine.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(71)
		::com::minigloop::ui::ScreenManager_obj::getInstance()->update(dt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Engine_obj,update,(void))

Void Engine_obj::loop( ::native::events::Event e){
{
		HX_STACK_PUSH("Engine::loop","com/minigloop/Engine.hx",62);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(63)
		this->_now = ::native::Lib_obj::getTimer();
		HX_STACK_LINE(64)
		this->_dt = (this->_now - this->_last);
		HX_STACK_LINE(65)
		this->_last = this->_now;
		HX_STACK_LINE(67)
		this->update(this->_dt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Engine_obj,loop,(void))

Void Engine_obj::init( ){
{
		HX_STACK_PUSH("Engine::init","com/minigloop/Engine.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		this->_last = this->_now = ::native::Lib_obj::getTimer();
		HX_STACK_LINE(43)
		this->_stage = ::nme::Lib_obj::get_current()->get_stage();
		HX_STACK_LINE(45)
		this->_bufferCanvas = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(46)
		this->_statsCanvas = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(48)
		this->_stage->addChild(this->_bufferCanvas);
		HX_STACK_LINE(49)
		this->_stage->addChild(this->_statsCanvas);
		HX_STACK_LINE(53)
		::com::minigloop::input::Mouse_obj::init(this->_stage);
		HX_STACK_LINE(55)
		::com::minigloop::ui::ScreenManager_obj::getInstance()->init(this->_bufferCanvas);
		HX_STACK_LINE(56)
		::com::minigloop::ui::ScreenManager_obj::getInstance()->gotoScreen(this->_gameClass);
		HX_STACK_LINE(58)
		this->_stage->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->loop_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,init,(void))


Engine_obj::Engine_obj()
{
}

void Engine_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Engine);
	HX_MARK_MEMBER_NAME(_gameClass,"_gameClass");
	HX_MARK_MEMBER_NAME(_stage,"_stage");
	HX_MARK_MEMBER_NAME(_statsCanvas,"_statsCanvas");
	HX_MARK_MEMBER_NAME(_bufferCanvas,"_bufferCanvas");
	HX_MARK_MEMBER_NAME(_dt,"_dt");
	HX_MARK_MEMBER_NAME(_last,"_last");
	HX_MARK_MEMBER_NAME(_now,"_now");
	HX_MARK_END_CLASS();
}

void Engine_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_gameClass,"_gameClass");
	HX_VISIT_MEMBER_NAME(_stage,"_stage");
	HX_VISIT_MEMBER_NAME(_statsCanvas,"_statsCanvas");
	HX_VISIT_MEMBER_NAME(_bufferCanvas,"_bufferCanvas");
	HX_VISIT_MEMBER_NAME(_dt,"_dt");
	HX_VISIT_MEMBER_NAME(_last,"_last");
	HX_VISIT_MEMBER_NAME(_now,"_now");
}

Dynamic Engine_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_dt") ) { return _dt; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { return loop_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"_now") ) { return _now; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { return _last; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_stage") ) { return _stage; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_gameClass") ) { return _gameClass; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_statsCanvas") ) { return _statsCanvas; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bufferCanvas") ) { return _bufferCanvas; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Engine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_dt") ) { _dt=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_now") ) { _now=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { _last=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_stage") ) { _stage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_gameClass") ) { _gameClass=inValue.Cast< ::Class >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_statsCanvas") ) { _statsCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bufferCanvas") ) { _bufferCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Engine_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_gameClass"));
	outFields->push(HX_CSTRING("_stage"));
	outFields->push(HX_CSTRING("_statsCanvas"));
	outFields->push(HX_CSTRING("_bufferCanvas"));
	outFields->push(HX_CSTRING("_dt"));
	outFields->push(HX_CSTRING("_last"));
	outFields->push(HX_CSTRING("_now"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("loop"),
	HX_CSTRING("init"),
	HX_CSTRING("_gameClass"),
	HX_CSTRING("_stage"),
	HX_CSTRING("_statsCanvas"),
	HX_CSTRING("_bufferCanvas"),
	HX_CSTRING("_dt"),
	HX_CSTRING("_last"),
	HX_CSTRING("_now"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Engine_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Engine_obj::__mClass,"__mClass");
};

Class Engine_obj::__mClass;

void Engine_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.Engine"), hx::TCanCast< Engine_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Engine_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
