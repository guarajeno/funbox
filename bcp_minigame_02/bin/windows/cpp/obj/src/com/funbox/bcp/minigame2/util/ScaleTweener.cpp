#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
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
namespace util{

Void ScaleTweener_obj::__construct(::native::display::Bitmap bitmap,Dynamic __callback)
{
HX_STACK_PUSH("ScaleTweener::new","com/funbox/bcp/minigame2/util/ScaleTweener.hx",9);
{
	HX_STACK_LINE(17)
	this->_factor = 0.025;
	HX_STACK_LINE(15)
	this->_value = (int)0;
	HX_STACK_LINE(14)
	this->_t = (int)0;
	HX_STACK_LINE(23)
	this->_obj = bitmap;
	HX_STACK_LINE(24)
	this->_callback = __callback;
	HX_STACK_LINE(26)
	this->_t = (int)0;
	HX_STACK_LINE(27)
	this->_value = (int)0;
	HX_STACK_LINE(28)
	this->_isPaused = false;
	HX_STACK_LINE(30)
	this->update((int)0);
}
;
	return null();
}

ScaleTweener_obj::~ScaleTweener_obj() { }

Dynamic ScaleTweener_obj::__CreateEmpty() { return  new ScaleTweener_obj; }
hx::ObjectPtr< ScaleTweener_obj > ScaleTweener_obj::__new(::native::display::Bitmap bitmap,Dynamic __callback)
{  hx::ObjectPtr< ScaleTweener_obj > result = new ScaleTweener_obj();
	result->__construct(bitmap,__callback);
	return result;}

Dynamic ScaleTweener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScaleTweener_obj > result = new ScaleTweener_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void ScaleTweener_obj::update( int dt){
{
		HX_STACK_PUSH("ScaleTweener::update","com/funbox/bcp/minigame2/util/ScaleTweener.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(35)
		if ((this->_isPaused)){
			HX_STACK_LINE(35)
			return null();
		}
		HX_STACK_LINE(37)
		this->_obj->set_scaleX(this->_value);
		HX_STACK_LINE(38)
		this->_obj->set_scaleY(this->_value);
		HX_STACK_LINE(40)
		this->_value = ::Math_obj::sin(this->_t);
		HX_STACK_LINE(41)
		hx::AddEq(this->_t,this->_factor);
		HX_STACK_LINE(43)
		if (((this->_t == (int)1))){
			HX_STACK_LINE(43)
			this->_t = 0.99;
		}
		HX_STACK_LINE(45)
		if (((this->_t >= (int)3))){
			HX_STACK_LINE(47)
			this->_obj->set_scaleX((int)0);
			HX_STACK_LINE(48)
			this->_isPaused = true;
			HX_STACK_LINE(49)
			this->_callback();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScaleTweener_obj,update,(void))


ScaleTweener_obj::ScaleTweener_obj()
{
}

void ScaleTweener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScaleTweener);
	HX_MARK_MEMBER_NAME(_isPaused,"_isPaused");
	HX_MARK_MEMBER_NAME(_factor,"_factor");
	HX_MARK_MEMBER_NAME(_value,"_value");
	HX_MARK_MEMBER_NAME(_t,"_t");
	HX_MARK_MEMBER_NAME(_callback,"_callback");
	HX_MARK_MEMBER_NAME(_obj,"_obj");
	HX_MARK_END_CLASS();
}

void ScaleTweener_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_isPaused,"_isPaused");
	HX_VISIT_MEMBER_NAME(_factor,"_factor");
	HX_VISIT_MEMBER_NAME(_value,"_value");
	HX_VISIT_MEMBER_NAME(_t,"_t");
	HX_VISIT_MEMBER_NAME(_callback,"_callback");
	HX_VISIT_MEMBER_NAME(_obj,"_obj");
}

Dynamic ScaleTweener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_t") ) { return _t; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_obj") ) { return _obj; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_value") ) { return _value; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_factor") ) { return _factor; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_isPaused") ) { return _isPaused; }
		if (HX_FIELD_EQ(inName,"_callback") ) { return _callback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ScaleTweener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_t") ) { _t=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_obj") ) { _obj=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { _value=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_factor") ) { _factor=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_isPaused") ) { _isPaused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_callback") ) { _callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScaleTweener_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_isPaused"));
	outFields->push(HX_CSTRING("_factor"));
	outFields->push(HX_CSTRING("_value"));
	outFields->push(HX_CSTRING("_t"));
	outFields->push(HX_CSTRING("_callback"));
	outFields->push(HX_CSTRING("_obj"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("_isPaused"),
	HX_CSTRING("_factor"),
	HX_CSTRING("_value"),
	HX_CSTRING("_t"),
	HX_CSTRING("_callback"),
	HX_CSTRING("_obj"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScaleTweener_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScaleTweener_obj::__mClass,"__mClass");
};

Class ScaleTweener_obj::__mClass;

void ScaleTweener_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.util.ScaleTweener"), hx::TCanCast< ScaleTweener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ScaleTweener_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util
