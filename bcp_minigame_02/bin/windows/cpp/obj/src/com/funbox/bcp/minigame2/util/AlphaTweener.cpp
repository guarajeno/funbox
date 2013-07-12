#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_AlphaTweener
#include <com/funbox/bcp/minigame2/util/AlphaTweener.h>
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

Void AlphaTweener_obj::__construct(::native::display::Bitmap bitmap,Float _dt,Dynamic __callback)
{
HX_STACK_PUSH("AlphaTweener::new","com/funbox/bcp/minigame2/util/AlphaTweener.hx",9);
{
	HX_STACK_LINE(16)
	this->_value = (int)0;
	HX_STACK_LINE(14)
	this->_t = (int)0;
	HX_STACK_LINE(22)
	this->_obj = bitmap;
	HX_STACK_LINE(23)
	this->_callback = __callback;
	HX_STACK_LINE(24)
	this->_dt = _dt;
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

AlphaTweener_obj::~AlphaTweener_obj() { }

Dynamic AlphaTweener_obj::__CreateEmpty() { return  new AlphaTweener_obj; }
hx::ObjectPtr< AlphaTweener_obj > AlphaTweener_obj::__new(::native::display::Bitmap bitmap,Float _dt,Dynamic __callback)
{  hx::ObjectPtr< AlphaTweener_obj > result = new AlphaTweener_obj();
	result->__construct(bitmap,_dt,__callback);
	return result;}

Dynamic AlphaTweener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AlphaTweener_obj > result = new AlphaTweener_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void AlphaTweener_obj::update( int dt){
{
		HX_STACK_PUSH("AlphaTweener::update","com/funbox/bcp/minigame2/util/AlphaTweener.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(35)
		if ((this->_isPaused)){
			HX_STACK_LINE(35)
			return null();
		}
		HX_STACK_LINE(37)
		this->_obj->set_alpha(this->_value);
		HX_STACK_LINE(39)
		this->_value = ::Math_obj::sin(this->_t);
		HX_STACK_LINE(40)
		hx::AddEq(this->_t,this->_dt);
		HX_STACK_LINE(42)
		if (((this->_t >= (int)3))){
			HX_STACK_LINE(44)
			this->_obj->set_alpha((int)0);
			HX_STACK_LINE(45)
			this->_isPaused = true;
			HX_STACK_LINE(46)
			if (((this->_callback != null()))){
				HX_STACK_LINE(46)
				this->_callback();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AlphaTweener_obj,update,(void))


AlphaTweener_obj::AlphaTweener_obj()
{
}

void AlphaTweener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AlphaTweener);
	HX_MARK_MEMBER_NAME(_isPaused,"_isPaused");
	HX_MARK_MEMBER_NAME(_value,"_value");
	HX_MARK_MEMBER_NAME(_dt,"_dt");
	HX_MARK_MEMBER_NAME(_t,"_t");
	HX_MARK_MEMBER_NAME(_callback,"_callback");
	HX_MARK_MEMBER_NAME(_obj,"_obj");
	HX_MARK_END_CLASS();
}

void AlphaTweener_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_isPaused,"_isPaused");
	HX_VISIT_MEMBER_NAME(_value,"_value");
	HX_VISIT_MEMBER_NAME(_dt,"_dt");
	HX_VISIT_MEMBER_NAME(_t,"_t");
	HX_VISIT_MEMBER_NAME(_callback,"_callback");
	HX_VISIT_MEMBER_NAME(_obj,"_obj");
}

Dynamic AlphaTweener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_t") ) { return _t; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_dt") ) { return _dt; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_obj") ) { return _obj; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"_value") ) { return _value; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_isPaused") ) { return _isPaused; }
		if (HX_FIELD_EQ(inName,"_callback") ) { return _callback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AlphaTweener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_t") ) { _t=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_dt") ) { _dt=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_obj") ) { _obj=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { _value=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_isPaused") ) { _isPaused=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_callback") ) { _callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AlphaTweener_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_isPaused"));
	outFields->push(HX_CSTRING("_value"));
	outFields->push(HX_CSTRING("_dt"));
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
	HX_CSTRING("_value"),
	HX_CSTRING("_dt"),
	HX_CSTRING("_t"),
	HX_CSTRING("_callback"),
	HX_CSTRING("_obj"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AlphaTweener_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AlphaTweener_obj::__mClass,"__mClass");
};

Class AlphaTweener_obj::__mClass;

void AlphaTweener_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.util.AlphaTweener"), hx::TCanCast< AlphaTweener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AlphaTweener_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util
