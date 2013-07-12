#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NMath
#include <com/funbox/bcp/minigame2/util/NMath.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace util{

Void NMath_obj::__construct()
{
HX_STACK_PUSH("NMath::new","com/funbox/bcp/minigame2/util/NMath.hx",9);
{
}
;
	return null();
}

NMath_obj::~NMath_obj() { }

Dynamic NMath_obj::__CreateEmpty() { return  new NMath_obj; }
hx::ObjectPtr< NMath_obj > NMath_obj::__new()
{  hx::ObjectPtr< NMath_obj > result = new NMath_obj();
	result->__construct();
	return result;}

Dynamic NMath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NMath_obj > result = new NMath_obj();
	result->__construct();
	return result;}

Float NMath_obj::random( Float min,Float max){
	HX_STACK_PUSH("NMath::random","com/funbox/bcp/minigame2/util/NMath.hx",13);
	HX_STACK_ARG(min,"min");
	HX_STACK_ARG(max,"max");
	HX_STACK_LINE(13)
	return ((::Math_obj::random() * ((max - min))) + min);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NMath_obj,random,return )


NMath_obj::NMath_obj()
{
}

void NMath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NMath);
	HX_MARK_END_CLASS();
}

void NMath_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic NMath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NMath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NMath_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("random"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NMath_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NMath_obj::__mClass,"__mClass");
};

Class NMath_obj::__mClass;

void NMath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.util.NMath"), hx::TCanCast< NMath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NMath_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util
