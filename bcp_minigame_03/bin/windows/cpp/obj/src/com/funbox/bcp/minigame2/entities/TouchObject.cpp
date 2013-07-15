#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#include <com/funbox/bcp/minigame2/MiniGame2.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController
#include <com/funbox/bcp/minigame2/engine/EntitiesController.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_VerticalTouchEngine
#include <com/funbox/bcp/minigame2/engine/VerticalTouchEngine.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_EffectManager
#include <com/funbox/bcp/minigame2/engine/effectManager/EffectManager.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_SpriteAndTextEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/SpriteAndTextEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_enemy_BotCollector
#include <com/funbox/bcp/minigame2/entities/enemy/BotCollector.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameHud
#include <com/funbox/bcp/minigame2/screens/GameHud.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType
#include <com/funbox/bcp/minigame2/type/EnumTouchObjectType.h>
#endif
#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
#endif
#ifndef INCLUDED_com_minigloop_util_SoundManager
#include <com/minigloop/util/SoundManager.h>
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
namespace funbox{
namespace bcp{
namespace minigame2{
namespace entities{

Void TouchObject_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed)
{
HX_STACK_PUSH("TouchObject::new","com/funbox/bcp/minigame2/entities/TouchObject.hx",30);
{
	HX_STACK_LINE(31)
	super::__construct(clipName,aniData,canvas,x,y);
	HX_STACK_LINE(33)
	this->isDead = false;
	HX_STACK_LINE(34)
	this->mCanFall = true;
	HX_STACK_LINE(35)
	this->mAreTouchableItems = false;
	HX_STACK_LINE(37)
	this->mAppWidth = ::Std_obj::_int(::com::funbox::bcp::minigame2::Global_obj::StageWidth);
	HX_STACK_LINE(38)
	this->mAppHeight = ::Std_obj::_int(::com::funbox::bcp::minigame2::Global_obj::StageHeight);
	HX_STACK_LINE(40)
	this->setSpeed(speed);
}
;
	return null();
}

TouchObject_obj::~TouchObject_obj() { }

Dynamic TouchObject_obj::__CreateEmpty() { return  new TouchObject_obj; }
hx::ObjectPtr< TouchObject_obj > TouchObject_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed)
{  hx::ObjectPtr< TouchObject_obj > result = new TouchObject_obj();
	result->__construct(clipName,aniData,canvas,x,y,speed);
	return result;}

Dynamic TouchObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchObject_obj > result = new TouchObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void TouchObject_obj::free( ){
{
		HX_STACK_PUSH("TouchObject::free","com/funbox/bcp/minigame2/entities/TouchObject.hx",127);
		HX_STACK_THIS(this);
		HX_STACK_LINE(128)
		this->mSpeed = null();
		HX_STACK_LINE(130)
		this->super::free();
	}
return null();
}


Void TouchObject_obj::update( int dt){
{
		HX_STACK_PUSH("TouchObject::update","com/funbox/bcp/minigame2/entities/TouchObject.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(83)
		if (((bool(::com::funbox::bcp::minigame2::Global_obj::minigame->isMousePressed()) && bool(this->mCanFall)))){
			HX_STACK_LINE(84)
			int mouseX = ::Std_obj::_int(::com::funbox::bcp::minigame2::Global_obj::minigame->getMouseX());		HX_STACK_VAR(mouseX,"mouseX");
			HX_STACK_LINE(85)
			int mouseY = ::Std_obj::_int(::com::funbox::bcp::minigame2::Global_obj::minigame->getMouseY());		HX_STACK_VAR(mouseY,"mouseY");
			HX_STACK_LINE(87)
			if ((this->hitTestPoint(mouseX,mouseY))){
				HX_STACK_LINE(88)
				this->isDead = true;
				HX_STACK_LINE(89)
				this->makePuffEffect();
				HX_STACK_LINE(91)
				int score_earned = (int)0;		HX_STACK_VAR(score_earned,"score_earned");
				HX_STACK_LINE(93)
				int _switch_1 = (this->mType);
				if (  ( _switch_1==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::COIN)){
					HX_STACK_LINE(94)
					score_earned = (int)500;
				}
				else if (  ( _switch_1==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::MONEY)){
					HX_STACK_LINE(96)
					score_earned = (int)100;
				}
				HX_STACK_LINE(100)
				::com::minigloop::util::SoundManager_obj::play(HX_CSTRING("fx_dinero"),null());
				HX_STACK_LINE(102)
				int newScore = ::com::funbox::bcp::minigame2::Global_obj::minigame->getGameHud()->GetScore();		HX_STACK_VAR(newScore,"newScore");
				HX_STACK_LINE(103)
				hx::AddEq(newScore,score_earned);
				HX_STACK_LINE(104)
				::com::funbox::bcp::minigame2::Global_obj::minigame->getGameHud()->SetScore(newScore);
			}
		}
		HX_STACK_LINE(108)
		if ((this->mAreTouchableItems)){
			HX_STACK_LINE(108)
			if ((this->mCanFall)){
				HX_STACK_LINE(110)
				hx::AddEq(this->mX,(this->mSpeed->x * dt));
				HX_STACK_LINE(111)
				hx::AddEq(this->mY,(this->mSpeed->y * dt));
				HX_STACK_LINE(113)
				if (((this->mY > ((this->mAppHeight - this->getHeight()) - ::com::funbox::bcp::minigame2::Global_obj::ScreenOffsetHeight)))){
					HX_STACK_LINE(114)
					this->mCanFall = false;
					HX_STACK_LINE(115)
					this->mY = ((this->mAppHeight - this->getHeight()) - ::com::funbox::bcp::minigame2::Global_obj::ScreenOffsetHeight);
					HX_STACK_LINE(117)
					::com::funbox::bcp::minigame2::entities::enemy::BotCollector bot = ::com::funbox::bcp::minigame2::Global_obj::minigame->getVTEngine()->getBotCollector();		HX_STACK_VAR(bot,"bot");
					HX_STACK_LINE(118)
					bot->addObjectInGround(hx::ObjectPtr<OBJ_>(this));
					HX_STACK_LINE(119)
					::com::funbox::bcp::minigame2::Global_obj::minigame->getVTEngine()->getEntitiesController()->removeEntitie(hx::ObjectPtr<OBJ_>(this));
				}
			}
		}
		HX_STACK_LINE(124)
		this->super::update(dt);
	}
return null();
}


Void TouchObject_obj::makePuffEffect( ){
{
		HX_STACK_PUSH("TouchObject::makePuffEffect","com/funbox/bcp/minigame2/entities/TouchObject.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_LINE(62)
		if ((this->mCanFall)){
			HX_STACK_LINE(63)
			::String clipScoreName = HX_CSTRING("");		HX_STACK_VAR(clipScoreName,"clipScoreName");
			HX_STACK_LINE(65)
			int _switch_2 = (this->mType);
			if (  ( _switch_2==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::COIN)){
				HX_STACK_LINE(66)
				clipScoreName = HX_CSTRING("spMinigame02_score_500");
			}
			else if (  ( _switch_2==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::MONEY)){
				HX_STACK_LINE(68)
				clipScoreName = HX_CSTRING("spMinigame02_score_100");
			}
			HX_STACK_LINE(72)
			::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect effect = ::com::funbox::bcp::minigame2::Global_obj::minigame->getVTEngine()->getEffectManager()->createSpriteAndTextEffect(HX_CSTRING("spMinigame02_check_secure"),HX_CSTRING("spMinigame02_check_secure"),clipScoreName,null(),::com::minigloop::util::Vector2D_obj::__new((this->mX + (Float(this->getWidth()) / Float((int)2))),(this->mY + (Float(this->getHeight()) / Float((int)2)))),::com::minigloop::util::Vector2D_obj::__new((int)-20,(int)-43));		HX_STACK_VAR(effect,"effect");
			HX_STACK_LINE(75)
			effect->DieWithAlpha(true);
		}
		HX_STACK_LINE(78)
		::com::funbox::bcp::minigame2::Global_obj::minigame->getVTEngine()->getEffectManager()->createEffect((this->mX + (Float(this->getWidth()) / Float((int)2))),(this->mY + (Float(this->getHeight()) / Float((int)2))),HX_CSTRING("spMinigame02_ani_effect_puff"),HX_CSTRING("spMinigame02_ani_effect_puff"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TouchObject_obj,makePuffEffect,(void))

Void TouchObject_obj::setObjectType( int value){
{
		HX_STACK_PUSH("TouchObject::setObjectType","com/funbox/bcp/minigame2/entities/TouchObject.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(48)
		this->mType = value;
		HX_STACK_LINE(50)
		int _switch_3 = (value);
		if (  ( _switch_3==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::PLAYER)){
			HX_STACK_LINE(52)
			this->mCanFall = false;
			HX_STACK_LINE(53)
			this->mAreTouchableItems = false;
		}
		else if (  ( _switch_3==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::COIN)){
			HX_STACK_LINE(54)
			this->mAreTouchableItems = true;
		}
		else if (  ( _switch_3==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::MONEY)){
			HX_STACK_LINE(56)
			this->mAreTouchableItems = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchObject_obj,setObjectType,(void))

Void TouchObject_obj::setSpeed( ::com::minigloop::util::Vector2D speed){
{
		HX_STACK_PUSH("TouchObject::setSpeed","com/funbox/bcp/minigame2/entities/TouchObject.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(speed,"speed");
		HX_STACK_LINE(43)
		this->mSpeed = speed;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchObject_obj,setSpeed,(void))

bool TouchObject_obj::getCanFall( ){
	HX_STACK_PUSH("TouchObject::getCanFall","com/funbox/bcp/minigame2/entities/TouchObject.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_LINE(28)
	return this->mCanFall;
}


HX_DEFINE_DYNAMIC_FUNC0(TouchObject_obj,getCanFall,return )

int TouchObject_obj::type( ){
	HX_STACK_PUSH("TouchObject::type","com/funbox/bcp/minigame2/entities/TouchObject.hx",27);
	HX_STACK_THIS(this);
	HX_STACK_LINE(27)
	return this->mType;
}


HX_DEFINE_DYNAMIC_FUNC0(TouchObject_obj,type,return )


TouchObject_obj::TouchObject_obj()
{
}

void TouchObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchObject);
	HX_MARK_MEMBER_NAME(mSpeed,"mSpeed");
	HX_MARK_MEMBER_NAME(mAppHeight,"mAppHeight");
	HX_MARK_MEMBER_NAME(mAppWidth,"mAppWidth");
	HX_MARK_MEMBER_NAME(mType,"mType");
	HX_MARK_MEMBER_NAME(mAreTouchableItems,"mAreTouchableItems");
	HX_MARK_MEMBER_NAME(mCanFall,"mCanFall");
	HX_MARK_MEMBER_NAME(isDead,"isDead");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TouchObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mSpeed,"mSpeed");
	HX_VISIT_MEMBER_NAME(mAppHeight,"mAppHeight");
	HX_VISIT_MEMBER_NAME(mAppWidth,"mAppWidth");
	HX_VISIT_MEMBER_NAME(mType,"mType");
	HX_VISIT_MEMBER_NAME(mAreTouchableItems,"mAreTouchableItems");
	HX_VISIT_MEMBER_NAME(mCanFall,"mCanFall");
	HX_VISIT_MEMBER_NAME(isDead,"isDead");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TouchObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		if (HX_FIELD_EQ(inName,"type") ) { return type_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mType") ) { return mType; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"mSpeed") ) { return mSpeed; }
		if (HX_FIELD_EQ(inName,"isDead") ) { return isDead; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setSpeed") ) { return setSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"mCanFall") ) { return mCanFall; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mAppWidth") ) { return mAppWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getCanFall") ) { return getCanFall_dyn(); }
		if (HX_FIELD_EQ(inName,"mAppHeight") ) { return mAppHeight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setObjectType") ) { return setObjectType_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"makePuffEffect") ) { return makePuffEffect_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"mAreTouchableItems") ) { return mAreTouchableItems; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mType") ) { mType=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mSpeed") ) { mSpeed=inValue.Cast< ::com::minigloop::util::Vector2D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isDead") ) { isDead=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mCanFall") ) { mCanFall=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mAppWidth") ) { mAppWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mAppHeight") ) { mAppHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"mAreTouchableItems") ) { mAreTouchableItems=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mSpeed"));
	outFields->push(HX_CSTRING("mAppHeight"));
	outFields->push(HX_CSTRING("mAppWidth"));
	outFields->push(HX_CSTRING("mType"));
	outFields->push(HX_CSTRING("mAreTouchableItems"));
	outFields->push(HX_CSTRING("mCanFall"));
	outFields->push(HX_CSTRING("isDead"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("makePuffEffect"),
	HX_CSTRING("setObjectType"),
	HX_CSTRING("setSpeed"),
	HX_CSTRING("getCanFall"),
	HX_CSTRING("type"),
	HX_CSTRING("mSpeed"),
	HX_CSTRING("mAppHeight"),
	HX_CSTRING("mAppWidth"),
	HX_CSTRING("mType"),
	HX_CSTRING("mAreTouchableItems"),
	HX_CSTRING("mCanFall"),
	HX_CSTRING("isDead"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchObject_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchObject_obj::__mClass,"__mClass");
};

Class TouchObject_obj::__mClass;

void TouchObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.entities.TouchObject"), hx::TCanCast< TouchObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TouchObject_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
