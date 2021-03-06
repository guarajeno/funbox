#include <hxcpp.h>

#ifndef INCLUDED_native_display_GradientType
#include <native/display/GradientType.h>
#endif
namespace native{
namespace display{

::native::display::GradientType GradientType_obj::LINEAR;

::native::display::GradientType GradientType_obj::RADIAL;

HX_DEFINE_CREATE_ENUM(GradientType_obj)

int GradientType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("LINEAR")) return 1;
	if (inName==HX_CSTRING("RADIAL")) return 0;
	return super::__FindIndex(inName);
}

int GradientType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("LINEAR")) return 0;
	if (inName==HX_CSTRING("RADIAL")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GradientType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("LINEAR")) return LINEAR;
	if (inName==HX_CSTRING("RADIAL")) return RADIAL;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("RADIAL"),
	HX_CSTRING("LINEAR"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GradientType_obj::LINEAR,"LINEAR");
	HX_MARK_MEMBER_NAME(GradientType_obj::RADIAL,"RADIAL");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GradientType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GradientType_obj::LINEAR,"LINEAR");
	HX_VISIT_MEMBER_NAME(GradientType_obj::RADIAL,"RADIAL");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientType_obj::__mClass;

Dynamic __Create_GradientType_obj() { return new GradientType_obj; }

void GradientType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.display.GradientType"), hx::TCanCast< GradientType_obj >,sStaticFields,sMemberFields,
	&__Create_GradientType_obj, &__Create,
	&super::__SGetClass(), &CreateGradientType_obj, sMarkStatics, sVisitStatic);
}

void GradientType_obj::__boot()
{
Static(LINEAR) = hx::CreateEnum< GradientType_obj >(HX_CSTRING("LINEAR"),1);
Static(RADIAL) = hx::CreateEnum< GradientType_obj >(HX_CSTRING("RADIAL"),0);
}


} // end namespace native
} // end namespace display
