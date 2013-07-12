#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_input_Mouse
#include <com/minigloop/input/Mouse.h>
#endif
#ifndef INCLUDED_com_minigloop_util_Vector2D
#include <com/minigloop/util/Vector2D.h>
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
namespace minigloop{
namespace input{

Void Mouse_obj::__construct()
{
HX_STACK_PUSH("Mouse::new","com/minigloop/input/Mouse.hx",24);
{
}
;
	return null();
}

Mouse_obj::~Mouse_obj() { }

Dynamic Mouse_obj::__CreateEmpty() { return  new Mouse_obj; }
hx::ObjectPtr< Mouse_obj > Mouse_obj::__new()
{  hx::ObjectPtr< Mouse_obj > result = new Mouse_obj();
	result->__construct();
	return result;}

Dynamic Mouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mouse_obj > result = new Mouse_obj();
	result->__construct();
	return result;}

::native::display::Stage Mouse_obj::_stage;

::com::minigloop::util::Vector2D Mouse_obj::position;

::com::minigloop::util::Vector2D Mouse_obj::lastPosition;

Void Mouse_obj::init( ::native::display::Stage stage){
{
		HX_STACK_PUSH("Mouse::init","com/minigloop/input/Mouse.hx",29);
		HX_STACK_ARG(stage,"stage");
		HX_STACK_LINE(30)
		::com::minigloop::input::Mouse_obj::_stage = stage;
		HX_STACK_LINE(31)
		::com::minigloop::input::Mouse_obj::_stage->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,::com::minigloop::input::Mouse_obj::onMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(32)
		::com::minigloop::input::Mouse_obj::_stage->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,::com::minigloop::input::Mouse_obj::onMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(34)
		::com::minigloop::input::Mouse_obj::position = ::com::minigloop::util::Vector2D_obj::__new((int)0,(int)0);
		HX_STACK_LINE(35)
		::com::minigloop::input::Mouse_obj::lastPosition = ::com::minigloop::util::Vector2D_obj::__new((int)0,(int)0);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mouse_obj,init,(void))

Void Mouse_obj::onMouseMove( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Mouse::onMouseMove","com/minigloop/input/Mouse.hx",39);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(40)
		::com::minigloop::input::Mouse_obj::lastPosition->x = ::com::minigloop::input::Mouse_obj::position->x;
		HX_STACK_LINE(41)
		::com::minigloop::input::Mouse_obj::lastPosition->y = ::com::minigloop::input::Mouse_obj::position->y;
		HX_STACK_LINE(43)
		::com::minigloop::input::Mouse_obj::position->x = e->localX;
		HX_STACK_LINE(44)
		::com::minigloop::input::Mouse_obj::position->y = e->localY;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mouse_obj,onMouseMove,(void))


Mouse_obj::Mouse_obj()
{
}

void Mouse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mouse);
	HX_MARK_END_CLASS();
}

void Mouse_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Mouse_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_stage") ) { return _stage; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { return onMouseMove_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"lastPosition") ) { return lastPosition; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mouse_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_stage") ) { _stage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::com::minigloop::util::Vector2D >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"lastPosition") ) { lastPosition=inValue.Cast< ::com::minigloop::util::Vector2D >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mouse_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_stage"),
	HX_CSTRING("position"),
	HX_CSTRING("lastPosition"),
	HX_CSTRING("init"),
	HX_CSTRING("onMouseMove"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mouse_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Mouse_obj::_stage,"_stage");
	HX_MARK_MEMBER_NAME(Mouse_obj::position,"position");
	HX_MARK_MEMBER_NAME(Mouse_obj::lastPosition,"lastPosition");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mouse_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Mouse_obj::_stage,"_stage");
	HX_VISIT_MEMBER_NAME(Mouse_obj::position,"position");
	HX_VISIT_MEMBER_NAME(Mouse_obj::lastPosition,"lastPosition");
};

Class Mouse_obj::__mClass;

void Mouse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.input.Mouse"), hx::TCanCast< Mouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Mouse_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace input
