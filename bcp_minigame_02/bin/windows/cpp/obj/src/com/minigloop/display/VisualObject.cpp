#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_display_VisualObject
#include <com/minigloop/display/VisualObject.h>
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
namespace display{

Void VisualObject_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("VisualObject::new","com/minigloop/display/VisualObject.hx",17);
{
	HX_STACK_LINE(18)
	this->_canvas = canvas;
	HX_STACK_LINE(20)
	this->position = ::com::minigloop::util::Vector2D_obj::__new((int)0,(int)0);
}
;
	return null();
}

VisualObject_obj::~VisualObject_obj() { }

Dynamic VisualObject_obj::__CreateEmpty() { return  new VisualObject_obj; }
hx::ObjectPtr< VisualObject_obj > VisualObject_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< VisualObject_obj > result = new VisualObject_obj();
	result->__construct(canvas);
	return result;}

Dynamic VisualObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VisualObject_obj > result = new VisualObject_obj();
	result->__construct(inArgs[0]);
	return result;}

Void VisualObject_obj::update( int dt){
{
		HX_STACK_PUSH("VisualObject::update","com/minigloop/display/VisualObject.hx",24);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(VisualObject_obj,update,(void))


VisualObject_obj::VisualObject_obj()
{
}

void VisualObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VisualObject);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(_canvas,"_canvas");
	HX_MARK_END_CLASS();
}

void VisualObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(_canvas,"_canvas");
}

Dynamic VisualObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { return _canvas; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VisualObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { _canvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::com::minigloop::util::Vector2D >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VisualObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("_canvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("position"),
	HX_CSTRING("_canvas"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VisualObject_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VisualObject_obj::__mClass,"__mClass");
};

Class VisualObject_obj::__mClass;

void VisualObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.display.VisualObject"), hx::TCanCast< VisualObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VisualObject_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace display
