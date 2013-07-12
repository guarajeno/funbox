#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType
#include <com/funbox/bcp/minigame2/type/EnumTouchObjectType.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace type{

Void EnumTouchObjectType_obj::__construct()
{
	return null();
}

EnumTouchObjectType_obj::~EnumTouchObjectType_obj() { }

Dynamic EnumTouchObjectType_obj::__CreateEmpty() { return  new EnumTouchObjectType_obj; }
hx::ObjectPtr< EnumTouchObjectType_obj > EnumTouchObjectType_obj::__new()
{  hx::ObjectPtr< EnumTouchObjectType_obj > result = new EnumTouchObjectType_obj();
	result->__construct();
	return result;}

Dynamic EnumTouchObjectType_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EnumTouchObjectType_obj > result = new EnumTouchObjectType_obj();
	result->__construct();
	return result;}

int EnumTouchObjectType_obj::PLAYER;

int EnumTouchObjectType_obj::MONEY;

int EnumTouchObjectType_obj::COIN;

int EnumTouchObjectType_obj::BOT_COLLECTOR;


EnumTouchObjectType_obj::EnumTouchObjectType_obj()
{
}

void EnumTouchObjectType_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EnumTouchObjectType);
	HX_MARK_END_CLASS();
}

void EnumTouchObjectType_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic EnumTouchObjectType_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"COIN") ) { return COIN; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"MONEY") ) { return MONEY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PLAYER") ) { return PLAYER; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"BOT_COLLECTOR") ) { return BOT_COLLECTOR; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EnumTouchObjectType_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"COIN") ) { COIN=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"MONEY") ) { MONEY=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PLAYER") ) { PLAYER=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"BOT_COLLECTOR") ) { BOT_COLLECTOR=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EnumTouchObjectType_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PLAYER"),
	HX_CSTRING("MONEY"),
	HX_CSTRING("COIN"),
	HX_CSTRING("BOT_COLLECTOR"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EnumTouchObjectType_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EnumTouchObjectType_obj::PLAYER,"PLAYER");
	HX_MARK_MEMBER_NAME(EnumTouchObjectType_obj::MONEY,"MONEY");
	HX_MARK_MEMBER_NAME(EnumTouchObjectType_obj::COIN,"COIN");
	HX_MARK_MEMBER_NAME(EnumTouchObjectType_obj::BOT_COLLECTOR,"BOT_COLLECTOR");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EnumTouchObjectType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EnumTouchObjectType_obj::PLAYER,"PLAYER");
	HX_VISIT_MEMBER_NAME(EnumTouchObjectType_obj::MONEY,"MONEY");
	HX_VISIT_MEMBER_NAME(EnumTouchObjectType_obj::COIN,"COIN");
	HX_VISIT_MEMBER_NAME(EnumTouchObjectType_obj::BOT_COLLECTOR,"BOT_COLLECTOR");
};

Class EnumTouchObjectType_obj::__mClass;

void EnumTouchObjectType_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.type.EnumTouchObjectType"), hx::TCanCast< EnumTouchObjectType_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EnumTouchObjectType_obj::__boot()
{
	PLAYER= (int)0;
	MONEY= (int)1;
	COIN= (int)2;
	BOT_COLLECTOR= (int)3;
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace type
