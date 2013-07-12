#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController
#include <com/funbox/bcp/minigame2/engine/EntitiesController.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemCoin
#include <com/funbox/bcp/minigame2/entities/item/ItemCoin.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemMoney
#include <com/funbox/bcp/minigame2/entities/item/ItemMoney.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType
#include <com/funbox/bcp/minigame2/type/EnumTouchObjectType.h>
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
namespace engine{

Void EntitiesController_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("EntitiesController::new","com/funbox/bcp/minigame2/engine/EntitiesController.hx",16);
{
	HX_STACK_LINE(17)
	this->mCanvas = canvas;
	HX_STACK_LINE(19)
	this->mEntities = Array_obj< ::com::funbox::bcp::minigame2::entities::TouchObject >::__new();
}
;
	return null();
}

EntitiesController_obj::~EntitiesController_obj() { }

Dynamic EntitiesController_obj::__CreateEmpty() { return  new EntitiesController_obj; }
hx::ObjectPtr< EntitiesController_obj > EntitiesController_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< EntitiesController_obj > result = new EntitiesController_obj();
	result->__construct(canvas);
	return result;}

Dynamic EntitiesController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EntitiesController_obj > result = new EntitiesController_obj();
	result->__construct(inArgs[0]);
	return result;}

Void EntitiesController_obj::free( ){
{
		HX_STACK_PUSH("EntitiesController::free","com/funbox/bcp/minigame2/engine/EntitiesController.hx",69);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EntitiesController_obj,free,(void))

Void EntitiesController_obj::update( int dt){
{
		HX_STACK_PUSH("EntitiesController::update","com/funbox/bcp/minigame2/engine/EntitiesController.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(46)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(47)
		int length = (this->mEntities->length - (int)1);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(49)
		while(((i <= length))){
			HX_STACK_LINE(50)
			::com::funbox::bcp::minigame2::entities::TouchObject sObj = this->mEntities->__get(i);		HX_STACK_VAR(sObj,"sObj");
			HX_STACK_LINE(52)
			if (((sObj != null()))){
				HX_STACK_LINE(52)
				if ((!(sObj->isDead))){
					HX_STACK_LINE(53)
					sObj->update(dt);
				}
				else{
					HX_STACK_LINE(57)
					sObj->free();
					HX_STACK_LINE(58)
					sObj = null();
					HX_STACK_LINE(60)
					this->mEntities->splice(i,(int)1);
					HX_STACK_LINE(61)
					(length)--;
				}
			}
			HX_STACK_LINE(65)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EntitiesController_obj,update,(void))

Void EntitiesController_obj::removeEntitie( ::com::funbox::bcp::minigame2::entities::TouchObject obj){
{
		HX_STACK_PUSH("EntitiesController::removeEntitie","com/funbox/bcp/minigame2/engine/EntitiesController.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_ARG(obj,"obj");
		HX_STACK_LINE(41)
		this->mEntities->remove(obj);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EntitiesController_obj,removeEntitie,(void))

::com::funbox::bcp::minigame2::entities::TouchObject EntitiesController_obj::createEntitie( Float x,Float y,::com::minigloop::util::Vector2D speed,int type){
	HX_STACK_PUSH("EntitiesController::createEntitie","com/funbox/bcp/minigame2/engine/EntitiesController.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(speed,"speed");
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(23)
	::com::funbox::bcp::minigame2::entities::TouchObject touchObj = null();		HX_STACK_VAR(touchObj,"touchObj");
	HX_STACK_LINE(25)
	int _switch_1 = (type);
	if (  ( _switch_1==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::MONEY)){
		HX_STACK_LINE(26)
		touchObj = ::com::funbox::bcp::minigame2::entities::item::ItemMoney_obj::__new(HX_CSTRING("spMinigame02_ani_ticket_money"),HX_CSTRING("spMinigame02_ani_ticket_money"),this->mCanvas,x,y,speed);
	}
	else if (  ( _switch_1==::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::COIN)){
		HX_STACK_LINE(29)
		touchObj = ::com::funbox::bcp::minigame2::entities::item::ItemCoin_obj::__new(HX_CSTRING("spMinigame02_ani_bag_money"),HX_CSTRING("spMinigame02_ani_bag_money"),this->mCanvas,x,y,speed);
	}
	HX_STACK_LINE(34)
	if (((touchObj != null()))){
		HX_STACK_LINE(34)
		this->mEntities->push(touchObj);
	}
	HX_STACK_LINE(38)
	return touchObj;
}


HX_DEFINE_DYNAMIC_FUNC4(EntitiesController_obj,createEntitie,return )


EntitiesController_obj::EntitiesController_obj()
{
}

void EntitiesController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EntitiesController);
	HX_MARK_MEMBER_NAME(mEntities,"mEntities");
	HX_MARK_MEMBER_NAME(mCanvas,"mCanvas");
	HX_MARK_END_CLASS();
}

void EntitiesController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mEntities,"mEntities");
	HX_VISIT_MEMBER_NAME(mCanvas,"mCanvas");
}

Dynamic EntitiesController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mCanvas") ) { return mCanvas; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mEntities") ) { return mEntities; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"removeEntitie") ) { return removeEntitie_dyn(); }
		if (HX_FIELD_EQ(inName,"createEntitie") ) { return createEntitie_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EntitiesController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mCanvas") ) { mCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mEntities") ) { mEntities=inValue.Cast< Array< ::com::funbox::bcp::minigame2::entities::TouchObject > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EntitiesController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mEntities"));
	outFields->push(HX_CSTRING("mCanvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("removeEntitie"),
	HX_CSTRING("createEntitie"),
	HX_CSTRING("mEntities"),
	HX_CSTRING("mCanvas"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EntitiesController_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EntitiesController_obj::__mClass,"__mClass");
};

Class EntitiesController_obj::__mClass;

void EntitiesController_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.engine.EntitiesController"), hx::TCanCast< EntitiesController_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EntitiesController_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
