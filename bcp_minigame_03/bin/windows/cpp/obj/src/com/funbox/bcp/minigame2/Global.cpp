#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#include <com/funbox/bcp/minigame2/MiniGame2.h>
#endif
#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
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

Void Global_obj::__construct()
{
HX_STACK_PUSH("Global::new","com/funbox/bcp/minigame2/Global.hx",25);
{
}
;
	return null();
}

Global_obj::~Global_obj() { }

Dynamic Global_obj::__CreateEmpty() { return  new Global_obj; }
hx::ObjectPtr< Global_obj > Global_obj::__new()
{  hx::ObjectPtr< Global_obj > result = new Global_obj();
	result->__construct();
	return result;}

Dynamic Global_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Global_obj > result = new Global_obj();
	result->__construct();
	return result;}

int Global_obj::minPlayerSpeed;

int Global_obj::maxPlayerSpeed;

int Global_obj::enemyFrequency;

int Global_obj::ScreenOffsetWidth;

int Global_obj::ScreenOffsetHeight;

::com::funbox::bcp::minigame2::MiniGame2 Global_obj::minigame;

::native::display::Stage Global_obj::stage;

int Global_obj::StageWidth;

int Global_obj::StageHeight;

int Global_obj::totalPoints;


Global_obj::Global_obj()
{
}

void Global_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Global);
	HX_MARK_END_CLASS();
}

void Global_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Global_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { return stage; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"minigame") ) { return minigame; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"StageWidth") ) { return StageWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"StageHeight") ) { return StageHeight; }
		if (HX_FIELD_EQ(inName,"totalPoints") ) { return totalPoints; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"minPlayerSpeed") ) { return minPlayerSpeed; }
		if (HX_FIELD_EQ(inName,"maxPlayerSpeed") ) { return maxPlayerSpeed; }
		if (HX_FIELD_EQ(inName,"enemyFrequency") ) { return enemyFrequency; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"ScreenOffsetWidth") ) { return ScreenOffsetWidth; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"ScreenOffsetHeight") ) { return ScreenOffsetHeight; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Global_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"minigame") ) { minigame=inValue.Cast< ::com::funbox::bcp::minigame2::MiniGame2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"StageWidth") ) { StageWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"StageHeight") ) { StageHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"totalPoints") ) { totalPoints=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"minPlayerSpeed") ) { minPlayerSpeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxPlayerSpeed") ) { maxPlayerSpeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enemyFrequency") ) { enemyFrequency=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"ScreenOffsetWidth") ) { ScreenOffsetWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"ScreenOffsetHeight") ) { ScreenOffsetHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Global_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("minPlayerSpeed"),
	HX_CSTRING("maxPlayerSpeed"),
	HX_CSTRING("enemyFrequency"),
	HX_CSTRING("ScreenOffsetWidth"),
	HX_CSTRING("ScreenOffsetHeight"),
	HX_CSTRING("minigame"),
	HX_CSTRING("stage"),
	HX_CSTRING("StageWidth"),
	HX_CSTRING("StageHeight"),
	HX_CSTRING("totalPoints"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Global_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Global_obj::minPlayerSpeed,"minPlayerSpeed");
	HX_MARK_MEMBER_NAME(Global_obj::maxPlayerSpeed,"maxPlayerSpeed");
	HX_MARK_MEMBER_NAME(Global_obj::enemyFrequency,"enemyFrequency");
	HX_MARK_MEMBER_NAME(Global_obj::ScreenOffsetWidth,"ScreenOffsetWidth");
	HX_MARK_MEMBER_NAME(Global_obj::ScreenOffsetHeight,"ScreenOffsetHeight");
	HX_MARK_MEMBER_NAME(Global_obj::minigame,"minigame");
	HX_MARK_MEMBER_NAME(Global_obj::stage,"stage");
	HX_MARK_MEMBER_NAME(Global_obj::StageWidth,"StageWidth");
	HX_MARK_MEMBER_NAME(Global_obj::StageHeight,"StageHeight");
	HX_MARK_MEMBER_NAME(Global_obj::totalPoints,"totalPoints");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Global_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Global_obj::minPlayerSpeed,"minPlayerSpeed");
	HX_VISIT_MEMBER_NAME(Global_obj::maxPlayerSpeed,"maxPlayerSpeed");
	HX_VISIT_MEMBER_NAME(Global_obj::enemyFrequency,"enemyFrequency");
	HX_VISIT_MEMBER_NAME(Global_obj::ScreenOffsetWidth,"ScreenOffsetWidth");
	HX_VISIT_MEMBER_NAME(Global_obj::ScreenOffsetHeight,"ScreenOffsetHeight");
	HX_VISIT_MEMBER_NAME(Global_obj::minigame,"minigame");
	HX_VISIT_MEMBER_NAME(Global_obj::stage,"stage");
	HX_VISIT_MEMBER_NAME(Global_obj::StageWidth,"StageWidth");
	HX_VISIT_MEMBER_NAME(Global_obj::StageHeight,"StageHeight");
	HX_VISIT_MEMBER_NAME(Global_obj::totalPoints,"totalPoints");
};

Class Global_obj::__mClass;

void Global_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.Global"), hx::TCanCast< Global_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Global_obj::__boot()
{
	minPlayerSpeed= (int)10;
	maxPlayerSpeed= (int)15;
	enemyFrequency= (int)1000;
	ScreenOffsetWidth= (int)50;
	ScreenOffsetHeight= (int)15;
	minigame= null();
	stage= null();
	StageWidth= (int)0;
	StageHeight= (int)0;
	totalPoints= (int)0;
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
