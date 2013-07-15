#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_util_Vector2D
#include <com/minigloop/util/Vector2D.h>
#endif
namespace com{
namespace minigloop{
namespace util{

Void Vector2D_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y)
{
HX_STACK_PUSH("Vector2D::new","com/minigloop/util/Vector2D.hx",14);
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
{
	HX_STACK_LINE(15)
	this->x = x;
	HX_STACK_LINE(16)
	this->y = y;
}
;
	return null();
}

Vector2D_obj::~Vector2D_obj() { }

Dynamic Vector2D_obj::__CreateEmpty() { return  new Vector2D_obj; }
hx::ObjectPtr< Vector2D_obj > Vector2D_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y)
{  hx::ObjectPtr< Vector2D_obj > result = new Vector2D_obj();
	result->__construct(__o_x,__o_y);
	return result;}

Dynamic Vector2D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector2D_obj > result = new Vector2D_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


Vector2D_obj::Vector2D_obj()
{
}

void Vector2D_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector2D);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Vector2D_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Vector2D_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector2D_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector2D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector2D_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector2D_obj::__mClass,"__mClass");
};

Class Vector2D_obj::__mClass;

void Vector2D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.util.Vector2D"), hx::TCanCast< Vector2D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Vector2D_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace util
