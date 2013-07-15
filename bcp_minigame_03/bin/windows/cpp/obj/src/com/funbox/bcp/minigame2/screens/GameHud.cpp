#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameHud
#include <com/funbox/bcp/minigame2/screens/GameHud.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NUtils
#include <com/funbox/bcp/minigame2/util/NUtils.h>
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
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace screens{

Void GameHud_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("GameHud::new","com/funbox/bcp/minigame2/screens/GameHud.hx",38);
{
	HX_STACK_LINE(39)
	this->mCanvas = canvas;
	HX_STACK_LINE(41)
	this->mPuntajeSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_background_score"),null(),this->mCanvas,(int)5,(int)5);
	HX_STACK_LINE(45)
	this->mTextFormat = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(46)
	this->mTextFormat->color = (int)-1;
	HX_STACK_LINE(47)
	this->mTextFormat->size = (int)15;
	HX_STACK_LINE(48)
	this->mTextFormat->bold = true;
	HX_STACK_LINE(49)
	this->mTextFormat->font = HX_CSTRING("calibri");
	HX_STACK_LINE(51)
	this->mTF_Score = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(52)
	this->mTF_Score->setTextFormat(this->mTextFormat,null(),null());
	HX_STACK_LINE(53)
	this->mTF_Score->set_defaultTextFormat(this->mTextFormat);
	HX_STACK_LINE(54)
	this->mTF_Score->set_text(HX_CSTRING("0000000"));
	HX_STACK_LINE(55)
	this->mTF_Score->set_x((int)76);
	HX_STACK_LINE(56)
	this->mTF_Score->set_y((int)6);
	HX_STACK_LINE(57)
	this->mTF_Score->set_width((int)180);
	HX_STACK_LINE(58)
	this->mTF_Score->set_mouseEnabled(false);
	HX_STACK_LINE(60)
	this->mTF_Score->set_selectable(false);
	HX_STACK_LINE(62)
	this->mTF_Time = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(63)
	this->mTF_Time->setTextFormat(this->mTextFormat,null(),null());
	HX_STACK_LINE(64)
	this->mTF_Time->set_defaultTextFormat(this->mTextFormat);
	HX_STACK_LINE(65)
	this->mTF_Time->set_text(HX_CSTRING("00:00"));
	HX_STACK_LINE(66)
	this->mTF_Time->set_x((int)215);
	HX_STACK_LINE(67)
	this->mTF_Time->set_y((int)6);
	HX_STACK_LINE(68)
	this->mTF_Time->set_width((int)180);
	HX_STACK_LINE(69)
	this->mTF_Time->set_mouseEnabled(false);
	HX_STACK_LINE(71)
	this->mTF_Time->set_selectable(false);
	HX_STACK_LINE(73)
	this->mCanvas->addChild(this->mTF_Score);
	HX_STACK_LINE(74)
	this->mCanvas->addChild(this->mTF_Time);
	HX_STACK_LINE(77)
	this->SetScore((int)0);
	HX_STACK_LINE(78)
	this->SetTime((int)0);
}
;
	return null();
}

GameHud_obj::~GameHud_obj() { }

Dynamic GameHud_obj::__CreateEmpty() { return  new GameHud_obj; }
hx::ObjectPtr< GameHud_obj > GameHud_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< GameHud_obj > result = new GameHud_obj();
	result->__construct(canvas);
	return result;}

Dynamic GameHud_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameHud_obj > result = new GameHud_obj();
	result->__construct(inArgs[0]);
	return result;}

Void GameHud_obj::free( ){
{
		HX_STACK_PUSH("GameHud::free","com/funbox/bcp/minigame2/screens/GameHud.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_LINE(86)
		this->mPuntajeSprite->free();
		HX_STACK_LINE(87)
		this->mPuntajeSprite = null();
		HX_STACK_LINE(89)
		this->mCanvas->removeChild(this->mTF_Score);
		HX_STACK_LINE(90)
		this->mCanvas->removeChild(this->mTF_Time);
		HX_STACK_LINE(92)
		this->mTF_Score = null();
		HX_STACK_LINE(93)
		this->mTF_Time = null();
		HX_STACK_LINE(94)
		this->mCanvas = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameHud_obj,free,(void))

Void GameHud_obj::update( int dt){
{
		HX_STACK_PUSH("GameHud::update","com/funbox/bcp/minigame2/screens/GameHud.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(81)
		this->mPuntajeSprite->update(dt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHud_obj,update,(void))

Void GameHud_obj::SetTime( int value){
{
		HX_STACK_PUSH("GameHud::SetTime","com/funbox/bcp/minigame2/screens/GameHud.hx",33);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(34)
		this->mTime = value;
		HX_STACK_LINE(35)
		this->mTF_Time->set_text(::com::funbox::bcp::minigame2::util::NUtils_obj::parseMillisecondsInClockFormat(this->mTime));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHud_obj,SetTime,(void))

int GameHud_obj::GetTime( ){
	HX_STACK_PUSH("GameHud::GetTime","com/funbox/bcp/minigame2/screens/GameHud.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_LINE(32)
	return this->mTime;
}


HX_DEFINE_DYNAMIC_FUNC0(GameHud_obj,GetTime,return )

Void GameHud_obj::SetScore( int value){
{
		HX_STACK_PUSH("GameHud::SetScore","com/funbox/bcp/minigame2/screens/GameHud.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(28)
		this->mScore = value;
		HX_STACK_LINE(29)
		this->mTF_Score->set_text(::com::funbox::bcp::minigame2::util::NUtils_obj::getDigitsByValue(this->mScore,(int)7));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHud_obj,SetScore,(void))

int GameHud_obj::GetScore( ){
	HX_STACK_PUSH("GameHud::GetScore","com/funbox/bcp/minigame2/screens/GameHud.hx",26);
	HX_STACK_THIS(this);
	HX_STACK_LINE(26)
	return this->mScore;
}


HX_DEFINE_DYNAMIC_FUNC0(GameHud_obj,GetScore,return )


GameHud_obj::GameHud_obj()
{
}

void GameHud_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameHud);
	HX_MARK_MEMBER_NAME(mTF_Time,"mTF_Time");
	HX_MARK_MEMBER_NAME(mTF_Score,"mTF_Score");
	HX_MARK_MEMBER_NAME(mTextFormat,"mTextFormat");
	HX_MARK_MEMBER_NAME(mTime,"mTime");
	HX_MARK_MEMBER_NAME(mScore,"mScore");
	HX_MARK_MEMBER_NAME(mPuntajeSprite,"mPuntajeSprite");
	HX_MARK_MEMBER_NAME(mCanvas,"mCanvas");
	HX_MARK_END_CLASS();
}

void GameHud_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mTF_Time,"mTF_Time");
	HX_VISIT_MEMBER_NAME(mTF_Score,"mTF_Score");
	HX_VISIT_MEMBER_NAME(mTextFormat,"mTextFormat");
	HX_VISIT_MEMBER_NAME(mTime,"mTime");
	HX_VISIT_MEMBER_NAME(mScore,"mScore");
	HX_VISIT_MEMBER_NAME(mPuntajeSprite,"mPuntajeSprite");
	HX_VISIT_MEMBER_NAME(mCanvas,"mCanvas");
}

Dynamic GameHud_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mTime") ) { return mTime; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"mScore") ) { return mScore; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SetTime") ) { return SetTime_dyn(); }
		if (HX_FIELD_EQ(inName,"GetTime") ) { return GetTime_dyn(); }
		if (HX_FIELD_EQ(inName,"mCanvas") ) { return mCanvas; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SetScore") ) { return SetScore_dyn(); }
		if (HX_FIELD_EQ(inName,"GetScore") ) { return GetScore_dyn(); }
		if (HX_FIELD_EQ(inName,"mTF_Time") ) { return mTF_Time; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mTF_Score") ) { return mTF_Score; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mTextFormat") ) { return mTextFormat; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mPuntajeSprite") ) { return mPuntajeSprite; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameHud_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mTime") ) { mTime=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mScore") ) { mScore=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mCanvas") ) { mCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mTF_Time") ) { mTF_Time=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mTF_Score") ) { mTF_Score=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mTextFormat") ) { mTextFormat=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mPuntajeSprite") ) { mPuntajeSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameHud_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mTF_Time"));
	outFields->push(HX_CSTRING("mTF_Score"));
	outFields->push(HX_CSTRING("mTextFormat"));
	outFields->push(HX_CSTRING("mTime"));
	outFields->push(HX_CSTRING("mScore"));
	outFields->push(HX_CSTRING("mPuntajeSprite"));
	outFields->push(HX_CSTRING("mCanvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("SetTime"),
	HX_CSTRING("GetTime"),
	HX_CSTRING("SetScore"),
	HX_CSTRING("GetScore"),
	HX_CSTRING("mTF_Time"),
	HX_CSTRING("mTF_Score"),
	HX_CSTRING("mTextFormat"),
	HX_CSTRING("mTime"),
	HX_CSTRING("mScore"),
	HX_CSTRING("mPuntajeSprite"),
	HX_CSTRING("mCanvas"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameHud_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameHud_obj::__mClass,"__mClass");
};

Class GameHud_obj::__mClass;

void GameHud_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.screens.GameHud"), hx::TCanCast< GameHud_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GameHud_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens
