#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NMath
#include <com/funbox/bcp/minigame2/util/NMath.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NUtils
#include <com/funbox/bcp/minigame2/util/NUtils.h>
#endif
#ifndef INCLUDED_com_minigloop_util_AssetsLoader
#include <com/minigloop/util/AssetsLoader.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_BlendMode
#include <native/display/BlendMode.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_PixelSnapping
#include <native/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace util{

Void NUtils_obj::__construct()
{
HX_STACK_PUSH("NUtils::new","com/funbox/bcp/minigame2/util/NUtils.hx",13);
{
}
;
	return null();
}

NUtils_obj::~NUtils_obj() { }

Dynamic NUtils_obj::__CreateEmpty() { return  new NUtils_obj; }
hx::ObjectPtr< NUtils_obj > NUtils_obj::__new()
{  hx::ObjectPtr< NUtils_obj > result = new NUtils_obj();
	result->__construct();
	return result;}

Dynamic NUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NUtils_obj > result = new NUtils_obj();
	result->__construct();
	return result;}

::native::display::Bitmap NUtils_obj::getAsset( ::String assetName){
	HX_STACK_PUSH("NUtils::getAsset","com/funbox/bcp/minigame2/util/NUtils.hx",17);
	HX_STACK_ARG(assetName,"assetName");
	HX_STACK_LINE(18)
	::native::display::Bitmap b = ::com::minigloop::util::AssetsLoader_obj::getAsset(assetName);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(19)
	::native::display::BitmapData bd = b->bitmapData->clone();		HX_STACK_VAR(bd,"bd");
	HX_STACK_LINE(20)
	bd->draw(b,null(),null(),null(),null(),null());
	HX_STACK_LINE(21)
	return ::native::display::Bitmap_obj::__new(bd,null(),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NUtils_obj,getAsset,return )

int NUtils_obj::getValueFromProbabilityChart( int numOptions,int numProbabilitys){
	HX_STACK_PUSH("NUtils::getValueFromProbabilityChart","com/funbox/bcp/minigame2/util/NUtils.hx",24);
	HX_STACK_ARG(numOptions,"numOptions");
	HX_STACK_ARG(numProbabilitys,"numProbabilitys");
	HX_STACK_LINE(25)
	numProbabilitys = (  (((numProbabilitys <= numOptions))) ? int((numOptions + (int)1)) : int(numProbabilitys) );
	HX_STACK_LINE(27)
	int choosenOption = (int)0;		HX_STACK_VAR(choosenOption,"choosenOption");
	HX_STACK_LINE(28)
	Array< int > probabilityChart = Array_obj< int >::__new();		HX_STACK_VAR(probabilityChart,"probabilityChart");
	HX_STACK_LINE(29)
	int optionCounter = (int)0;		HX_STACK_VAR(optionCounter,"optionCounter");
	HX_STACK_LINE(31)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(33)
	while(((i < numProbabilitys))){
		HX_STACK_LINE(34)
		probabilityChart->push(optionCounter);
		HX_STACK_LINE(35)
		(optionCounter)++;
		HX_STACK_LINE(36)
		if (((optionCounter >= numOptions))){
			HX_STACK_LINE(36)
			optionCounter = (int)0;
		}
		HX_STACK_LINE(38)
		(i)++;
	}
	HX_STACK_LINE(41)
	choosenOption = probabilityChart->__get(::Std_obj::_int(::com::funbox::bcp::minigame2::util::NMath_obj::random((int)0,(numProbabilitys - (int)1))));
	HX_STACK_LINE(43)
	return choosenOption;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NUtils_obj,getValueFromProbabilityChart,return )

::String NUtils_obj::parseMillisecondsInClockFormat( int milliseconds){
	HX_STACK_PUSH("NUtils::parseMillisecondsInClockFormat","com/funbox/bcp/minigame2/util/NUtils.hx",46);
	HX_STACK_ARG(milliseconds,"milliseconds");
	HX_STACK_LINE(47)
	Float minutes = (Float((Float(milliseconds) / Float(1000.0))) / Float(60.0));		HX_STACK_VAR(minutes,"minutes");
	HX_STACK_LINE(48)
	int minutesFloor = ::Math_obj::floor(minutes);		HX_STACK_VAR(minutesFloor,"minutesFloor");
	HX_STACK_LINE(49)
	Float secondsRaw = (minutes - minutesFloor);		HX_STACK_VAR(secondsRaw,"secondsRaw");
	HX_STACK_LINE(50)
	int seconds = ::Std_obj::_int((secondsRaw * (int)60));		HX_STACK_VAR(seconds,"seconds");
	HX_STACK_LINE(51)
	::String clockFormat = ((::com::funbox::bcp::minigame2::util::NUtils_obj::getDigitsByValue(minutesFloor,(int)2) + HX_CSTRING(":")) + ::com::funbox::bcp::minigame2::util::NUtils_obj::getDigitsByValue(seconds,(int)2));		HX_STACK_VAR(clockFormat,"clockFormat");
	HX_STACK_LINE(53)
	return clockFormat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NUtils_obj,parseMillisecondsInClockFormat,return )

::String NUtils_obj::getDigitsByValue( int value,int num_digits){
	HX_STACK_PUSH("NUtils::getDigitsByValue","com/funbox/bcp/minigame2/util/NUtils.hx",56);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(num_digits,"num_digits");
	HX_STACK_LINE(57)
	::String s = ::Std_obj::string(value);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(58)
	int offset = (num_digits - s.length);		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(60)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(62)
	while(((i < offset))){
		HX_STACK_LINE(63)
		s = (HX_CSTRING("0") + s);
		HX_STACK_LINE(64)
		(i)++;
	}
	HX_STACK_LINE(67)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NUtils_obj,getDigitsByValue,return )


NUtils_obj::NUtils_obj()
{
}

void NUtils_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NUtils);
	HX_MARK_END_CLASS();
}

void NUtils_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic NUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"getAsset") ) { return getAsset_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getDigitsByValue") ) { return getDigitsByValue_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getValueFromProbabilityChart") ) { return getValueFromProbabilityChart_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"parseMillisecondsInClockFormat") ) { return parseMillisecondsInClockFormat_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getAsset"),
	HX_CSTRING("getValueFromProbabilityChart"),
	HX_CSTRING("parseMillisecondsInClockFormat"),
	HX_CSTRING("getDigitsByValue"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NUtils_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NUtils_obj::__mClass,"__mClass");
};

Class NUtils_obj::__mClass;

void NUtils_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.util.NUtils"), hx::TCanCast< NUtils_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NUtils_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util
