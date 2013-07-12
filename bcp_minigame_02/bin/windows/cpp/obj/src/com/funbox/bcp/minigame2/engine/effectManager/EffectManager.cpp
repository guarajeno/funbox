#include <hxcpp.h>

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
namespace effectManager{

Void EffectManager_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("EffectManager::new","com/funbox/bcp/minigame2/engine/effectManager/EffectManager.hx",14);
{
	HX_STACK_LINE(15)
	this->mCanvas = canvas;
	HX_STACK_LINE(17)
	this->mEffectsRepo = Array_obj< ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect >::__new();
}
;
	return null();
}

EffectManager_obj::~EffectManager_obj() { }

Dynamic EffectManager_obj::__CreateEmpty() { return  new EffectManager_obj; }
hx::ObjectPtr< EffectManager_obj > EffectManager_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< EffectManager_obj > result = new EffectManager_obj();
	result->__construct(canvas);
	return result;}

Dynamic EffectManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EffectManager_obj > result = new EffectManager_obj();
	result->__construct(inArgs[0]);
	return result;}

Void EffectManager_obj::free( ){
{
		HX_STACK_PUSH("EffectManager::free","com/funbox/bcp/minigame2/engine/effectManager/EffectManager.hx",71);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EffectManager_obj,free,(void))

Void EffectManager_obj::update( int dt){
{
		HX_STACK_PUSH("EffectManager::update","com/funbox/bcp/minigame2/engine/effectManager/EffectManager.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(48)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(49)
		int length = (this->mEffectsRepo->length - (int)1);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(51)
		while(((i <= length))){
			HX_STACK_LINE(52)
			::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect sObj = this->mEffectsRepo->__get(i);		HX_STACK_VAR(sObj,"sObj");
			HX_STACK_LINE(54)
			if (((sObj != null()))){
				HX_STACK_LINE(54)
				if ((!(sObj->isDead))){
					HX_STACK_LINE(55)
					sObj->update(dt);
				}
				else{
					HX_STACK_LINE(59)
					sObj->free();
					HX_STACK_LINE(60)
					sObj = null();
					HX_STACK_LINE(62)
					this->mEffectsRepo->splice(i,(int)1);
					HX_STACK_LINE(63)
					(length)--;
				}
			}
			HX_STACK_LINE(67)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EffectManager_obj,update,(void))

::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect EffectManager_obj::createSpriteAndTextEffect( ::String clipName,::String aniData,::String clipNameOther,::String aniDataOther,::com::minigloop::util::Vector2D pos1,::com::minigloop::util::Vector2D pos2){
	HX_STACK_PUSH("EffectManager::createSpriteAndTextEffect","com/funbox/bcp/minigame2/engine/effectManager/EffectManager.hx",33);
	HX_STACK_THIS(this);
	HX_STACK_ARG(clipName,"clipName");
	HX_STACK_ARG(aniData,"aniData");
	HX_STACK_ARG(clipNameOther,"clipNameOther");
	HX_STACK_ARG(aniDataOther,"aniDataOther");
	HX_STACK_ARG(pos1,"pos1");
	HX_STACK_ARG(pos2,"pos2");
	HX_STACK_LINE(35)
	::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect touchObj = null();		HX_STACK_VAR(touchObj,"touchObj");
	HX_STACK_LINE(37)
	touchObj = ::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect_obj::__new(clipName,aniData,clipNameOther,aniDataOther,this->mCanvas,pos1,pos2);
	HX_STACK_LINE(40)
	if (((touchObj != null()))){
		HX_STACK_LINE(40)
		this->mEffectsRepo->push(touchObj);
	}
	HX_STACK_LINE(44)
	return touchObj;
}


HX_DEFINE_DYNAMIC_FUNC6(EffectManager_obj,createSpriteAndTextEffect,return )

::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect EffectManager_obj::createEffect( Float x,Float y,::String clipName,::String aniData){
	HX_STACK_PUSH("EffectManager::createEffect","com/funbox/bcp/minigame2/engine/effectManager/EffectManager.hx",20);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(clipName,"clipName");
	HX_STACK_ARG(aniData,"aniData");
	HX_STACK_LINE(21)
	::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect touchObj = null();		HX_STACK_VAR(touchObj,"touchObj");
	HX_STACK_LINE(23)
	touchObj = ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect_obj::__new(clipName,aniData,this->mCanvas,x,y);
	HX_STACK_LINE(25)
	if (((touchObj != null()))){
		HX_STACK_LINE(25)
		this->mEffectsRepo->push(touchObj);
	}
	HX_STACK_LINE(29)
	return touchObj;
}


HX_DEFINE_DYNAMIC_FUNC4(EffectManager_obj,createEffect,return )


EffectManager_obj::EffectManager_obj()
{
}

void EffectManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EffectManager);
	HX_MARK_MEMBER_NAME(mEffectsRepo,"mEffectsRepo");
	HX_MARK_MEMBER_NAME(mCanvas,"mCanvas");
	HX_MARK_END_CLASS();
}

void EffectManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mEffectsRepo,"mEffectsRepo");
	HX_VISIT_MEMBER_NAME(mCanvas,"mCanvas");
}

Dynamic EffectManager_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 12:
		if (HX_FIELD_EQ(inName,"createEffect") ) { return createEffect_dyn(); }
		if (HX_FIELD_EQ(inName,"mEffectsRepo") ) { return mEffectsRepo; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"createSpriteAndTextEffect") ) { return createSpriteAndTextEffect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EffectManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mCanvas") ) { mCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mEffectsRepo") ) { mEffectsRepo=inValue.Cast< Array< ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EffectManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mEffectsRepo"));
	outFields->push(HX_CSTRING("mCanvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("createSpriteAndTextEffect"),
	HX_CSTRING("createEffect"),
	HX_CSTRING("mEffectsRepo"),
	HX_CSTRING("mCanvas"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EffectManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EffectManager_obj::__mClass,"__mClass");
};

Class EffectManager_obj::__mClass;

void EffectManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.engine.effectManager.EffectManager"), hx::TCanCast< EffectManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EffectManager_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
} // end namespace effectManager
