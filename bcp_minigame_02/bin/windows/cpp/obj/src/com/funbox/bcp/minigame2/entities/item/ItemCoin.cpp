#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemCoin
#include <com/funbox/bcp/minigame2/entities/item/ItemCoin.h>
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

Void ItemCoin_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed)
{
HX_STACK_PUSH("ItemCoin::new","com/funbox/bcp/minigame2/entities/item/ItemCoin.hx",10);
{
	HX_STACK_LINE(11)
	super::__construct(clipName,aniData,canvas,x,y,speed);
	HX_STACK_LINE(13)
	this->setObjectType(::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::COIN);
	HX_STACK_LINE(15)
	this->setOffsetX((Float(this->getWidth()) / Float((int)2)));
	HX_STACK_LINE(16)
	this->setOffsetY((Float(this->getHeight()) / Float((int)2)));
}
;
	return null();
}

ItemCoin_obj::~ItemCoin_obj() { }

Dynamic ItemCoin_obj::__CreateEmpty() { return  new ItemCoin_obj; }
hx::ObjectPtr< ItemCoin_obj > ItemCoin_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed)
{  hx::ObjectPtr< ItemCoin_obj > result = new ItemCoin_obj();
	result->__construct(clipName,aniData,canvas,x,y,speed);
	return result;}

Dynamic ItemCoin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ItemCoin_obj > result = new ItemCoin_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void ItemCoin_obj::update( int dt){
{
		HX_STACK_PUSH("ItemCoin::update","com/funbox/bcp/minigame2/entities/item/ItemCoin.hx",19);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(20)
		if ((!(this->mStaticImage))){
			HX_STACK_LINE(20)
			if (((bool((this->mAnimationBitmap->getCurrentIndex() == (int)0)) && bool(!(this->mCanFall))))){
				HX_STACK_LINE(22)
				this->mAnimationBitmap->gotoAndStop((int)0);
				HX_STACK_LINE(24)
				this->mPauseAnimation = true;
			}
		}
		HX_STACK_LINE(28)
		this->super::update(dt);
	}
return null();
}



ItemCoin_obj::ItemCoin_obj()
{
}

void ItemCoin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ItemCoin);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ItemCoin_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ItemCoin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ItemCoin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ItemCoin_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ItemCoin_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ItemCoin_obj::__mClass,"__mClass");
};

Class ItemCoin_obj::__mClass;

void ItemCoin_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.entities.item.ItemCoin"), hx::TCanCast< ItemCoin_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ItemCoin_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace item
