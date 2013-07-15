#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
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
#ifndef INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType
#include <com/funbox/bcp/minigame2/type/EnumTouchObjectType.h>
#endif
#ifndef INCLUDED_com_minigloop_display_AtlasSprite
#include <com/minigloop/display/AtlasSprite.h>
#endif
#ifndef INCLUDED_com_minigloop_display_VisualObject
#include <com/minigloop/display/VisualObject.h>
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
namespace enemy{

Void BotCollector_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas)
{
HX_STACK_PUSH("BotCollector::new","com/funbox/bcp/minigame2/entities/enemy/BotCollector.hx",19);
{
	HX_STACK_LINE(20)
	super::__construct(clipName,aniData,canvas,(int)0,(int)0,::com::minigloop::util::Vector2D_obj::__new(null(),null()));
	HX_STACK_LINE(22)
	this->setObjectType(::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::BOT_COLLECTOR);
	HX_STACK_LINE(24)
	this->mX = (((int(::com::funbox::bcp::minigame2::Global_obj::StageWidth) >> int((int)1))) - (Float(this->getWidth()) / Float((int)2)));
	HX_STACK_LINE(25)
	this->mY = ((::com::funbox::bcp::minigame2::Global_obj::StageHeight - this->getHeight()) - ::com::funbox::bcp::minigame2::Global_obj::ScreenOffsetHeight);
	HX_STACK_LINE(27)
	this->mEntities = Array_obj< ::com::funbox::bcp::minigame2::entities::TouchObject >::__new();
	HX_STACK_LINE(29)
	this->mSpeed->x = 0.2;
	HX_STACK_LINE(30)
	this->mCanFall = false;
	HX_STACK_LINE(32)
	this->setOffsetX((Float(this->getWidth()) / Float((int)2)));
	HX_STACK_LINE(33)
	this->setOffsetY((Float(this->getHeight()) / Float((int)2)));
	HX_STACK_LINE(35)
	this->mAnimationBitmap->gotoAndStop((int)0);
}
;
	return null();
}

BotCollector_obj::~BotCollector_obj() { }

Dynamic BotCollector_obj::__CreateEmpty() { return  new BotCollector_obj; }
hx::ObjectPtr< BotCollector_obj > BotCollector_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas)
{  hx::ObjectPtr< BotCollector_obj > result = new BotCollector_obj();
	result->__construct(clipName,aniData,canvas);
	return result;}

Dynamic BotCollector_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BotCollector_obj > result = new BotCollector_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void BotCollector_obj::update( int dt){
{
		HX_STACK_PUSH("BotCollector::update","com/funbox/bcp/minigame2/entities/enemy/BotCollector.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(43)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(44)
		int length = (this->mEntities->length - (int)1);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(46)
		while(((i <= length))){
			HX_STACK_LINE(47)
			::com::funbox::bcp::minigame2::entities::TouchObject sObj = this->mEntities->__get(i);		HX_STACK_VAR(sObj,"sObj");
			HX_STACK_LINE(49)
			if (((sObj != null()))){
				HX_STACK_LINE(49)
				if ((!(sObj->isDead))){
					HX_STACK_LINE(51)
					sObj->update(dt);
					HX_STACK_LINE(53)
					if ((!(sObj->getCanFall()))){
						HX_STACK_LINE(53)
						if ((sObj->hitTest(hx::ObjectPtr<OBJ_>(this)))){
							HX_STACK_LINE(55)
							if (((this->mTouchObjectToCatch == sObj))){
								HX_STACK_LINE(55)
								this->mTouchObjectToCatch = null();
							}
							HX_STACK_LINE(59)
							sObj->makePuffEffect();
							HX_STACK_LINE(60)
							sObj->free();
							HX_STACK_LINE(61)
							sObj = null();
							HX_STACK_LINE(63)
							this->mEntities->splice(i,(int)1);
							HX_STACK_LINE(64)
							(length)--;
						}
						else{
							HX_STACK_LINE(66)
							if (((this->mTouchObjectToCatch == null()))){
								HX_STACK_LINE(66)
								this->mTouchObjectToCatch = sObj;
							}
						}
					}
				}
				else{
					HX_STACK_LINE(72)
					sObj->free();
					HX_STACK_LINE(73)
					sObj = null();
					HX_STACK_LINE(75)
					this->mEntities->splice(i,(int)1);
					HX_STACK_LINE(76)
					(length)--;
				}
			}
			HX_STACK_LINE(80)
			(i)++;
		}
		HX_STACK_LINE(83)
		if (((this->mTouchObjectToCatch != null()))){
			HX_STACK_LINE(84)
			Float tx = this->mTouchObjectToCatch->getX();		HX_STACK_VAR(tx,"tx");
			HX_STACK_LINE(85)
			Float ty = this->mTouchObjectToCatch->getY();		HX_STACK_VAR(ty,"ty");
			HX_STACK_LINE(87)
			bool dir = ((this->mX + (Float(this->getWidth()) / Float((int)2))) > (tx + (Float(this->mTouchObjectToCatch->getWidth()) / Float((int)2))));		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(89)
			if ((dir)){
				HX_STACK_LINE(90)
				hx::SubEq(this->mX,(this->mSpeed->x * dt));
				HX_STACK_LINE(91)
				this->setFlip(true);
			}
			else{
				HX_STACK_LINE(94)
				hx::AddEq(this->mX,(this->mSpeed->x * dt));
				HX_STACK_LINE(95)
				this->setFlip(false);
			}
			HX_STACK_LINE(98)
			if ((!(this->mAnimationBitmap->playing()))){
				HX_STACK_LINE(98)
				this->mAnimationBitmap->gotoAndPlay((int)0);
			}
		}
		else{
			HX_STACK_LINE(102)
			if ((this->mAnimationBitmap->playing())){
				HX_STACK_LINE(103)
				this->mAnimationBitmap->gotoAndStop((int)0);
			}
		}
		HX_STACK_LINE(108)
		this->super::update(dt);
	}
return null();
}


Void BotCollector_obj::addObjectInGround( ::com::funbox::bcp::minigame2::entities::TouchObject touchableObject){
{
		HX_STACK_PUSH("BotCollector::addObjectInGround","com/funbox/bcp/minigame2/entities/enemy/BotCollector.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touchableObject,"touchableObject");
		HX_STACK_LINE(38)
		this->mEntities->push(touchableObject);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BotCollector_obj,addObjectInGround,(void))


BotCollector_obj::BotCollector_obj()
{
}

void BotCollector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BotCollector);
	HX_MARK_MEMBER_NAME(mTouchObjectToCatch,"mTouchObjectToCatch");
	HX_MARK_MEMBER_NAME(mEntities,"mEntities");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BotCollector_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mTouchObjectToCatch,"mTouchObjectToCatch");
	HX_VISIT_MEMBER_NAME(mEntities,"mEntities");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BotCollector_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mEntities") ) { return mEntities; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"addObjectInGround") ) { return addObjectInGround_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mTouchObjectToCatch") ) { return mTouchObjectToCatch; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BotCollector_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"mEntities") ) { mEntities=inValue.Cast< Array< ::com::funbox::bcp::minigame2::entities::TouchObject > >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mTouchObjectToCatch") ) { mTouchObjectToCatch=inValue.Cast< ::com::funbox::bcp::minigame2::entities::TouchObject >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BotCollector_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mTouchObjectToCatch"));
	outFields->push(HX_CSTRING("mEntities"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("addObjectInGround"),
	HX_CSTRING("mTouchObjectToCatch"),
	HX_CSTRING("mEntities"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BotCollector_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BotCollector_obj::__mClass,"__mClass");
};

Class BotCollector_obj::__mClass;

void BotCollector_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.entities.enemy.BotCollector"), hx::TCanCast< BotCollector_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BotCollector_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace enemy
