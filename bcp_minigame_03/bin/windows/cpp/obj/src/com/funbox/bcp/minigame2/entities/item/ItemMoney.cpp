#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemMoney
#include <com/funbox/bcp/minigame2/entities/item/ItemMoney.h>
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
namespace item{

Void ItemMoney_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed)
{
HX_STACK_PUSH("ItemMoney::new","com/funbox/bcp/minigame2/entities/item/ItemMoney.hx",12);
{
	HX_STACK_LINE(13)
	super::__construct(clipName,aniData,canvas,x,y,speed);
	HX_STACK_LINE(15)
	this->setObjectType(::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::MONEY);
	HX_STACK_LINE(17)
	this->setOffsetX((Float(this->getWidth()) / Float((int)2)));
	HX_STACK_LINE(18)
	this->setOffsetY((Float(this->getHeight()) / Float((int)2)));
	HX_STACK_LINE(20)
	this->mAcceleration = (int)0;
}
;
	return null();
}

ItemMoney_obj::~ItemMoney_obj() { }

Dynamic ItemMoney_obj::__CreateEmpty() { return  new ItemMoney_obj; }
hx::ObjectPtr< ItemMoney_obj > ItemMoney_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed)
{  hx::ObjectPtr< ItemMoney_obj > result = new ItemMoney_obj();
	result->__construct(clipName,aniData,canvas,x,y,speed);
	return result;}

Dynamic ItemMoney_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ItemMoney_obj > result = new ItemMoney_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void ItemMoney_obj::update( int dt){
{
		HX_STACK_PUSH("ItemMoney::update","com/funbox/bcp/minigame2/entities/item/ItemMoney.hx",23);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(24)
		if ((!(this->mStaticImage))){
			HX_STACK_LINE(24)
			if (((bool((this->mAnimationBitmap->getCurrentIndex() == (int)12)) && bool(!(this->mCanFall))))){
				HX_STACK_LINE(26)
				this->mAnimationBitmap->gotoAndStop((int)12);
				HX_STACK_LINE(27)
				this->mPauseAnimation = true;
			}
		}
		HX_STACK_LINE(31)
		if ((this->mCanFall)){
			HX_STACK_LINE(32)
			hx::AddEq(this->mX,(::Math_obj::cos(this->mAcceleration) * (int)2));
			HX_STACK_LINE(33)
			hx::AddEq(this->mAcceleration,0.1);
		}
		HX_STACK_LINE(36)
		this->super::update(dt);
	}
return null();
}



ItemMoney_obj::ItemMoney_obj()
{
}

void ItemMoney_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ItemMoney);
	HX_MARK_MEMBER_NAME(mAcceleration,"mAcceleration");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ItemMoney_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mAcceleration,"mAcceleration");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ItemMoney_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mAcceleration") ) { return mAcceleration; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ItemMoney_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"mAcceleration") ) { mAcceleration=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ItemMoney_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mAcceleration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("mAcceleration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ItemMoney_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ItemMoney_obj::__mClass,"__mClass");
};

Class ItemMoney_obj::__mClass;

void ItemMoney_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.entities.item.ItemMoney"), hx::TCanCast< ItemMoney_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ItemMoney_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace item
