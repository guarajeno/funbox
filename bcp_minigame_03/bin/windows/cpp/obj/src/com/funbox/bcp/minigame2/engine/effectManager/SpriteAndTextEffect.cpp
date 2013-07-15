#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_SpriteAndTextEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/SpriteAndTextEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NUtils
#include <com/funbox/bcp/minigame2/util/NUtils.h>
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
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
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

Void SpriteAndTextEffect_obj::__construct(::String clipName,::String aniData,::String clipNameOther,::String aniDataOther,::native::display::Sprite canvas,::com::minigloop::util::Vector2D pos1,::com::minigloop::util::Vector2D pos2)
{
HX_STACK_PUSH("SpriteAndTextEffect::new","com/funbox/bcp/minigame2/engine/effectManager/SpriteAndTextEffect.hx",23);
{
	HX_STACK_LINE(24)
	super::__construct(clipName,aniData,canvas,pos1->x,pos1->y);
	HX_STACK_LINE(26)
	this->mOtherX = pos2->x;
	HX_STACK_LINE(27)
	this->mOtherY = pos2->y;
	HX_STACK_LINE(29)
	this->mClipContainer = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(30)
	this->mCanvas->addChild(this->mClipContainer);
	HX_STACK_LINE(32)
	if (((bool((clipNameOther != null())) && bool((aniDataOther != null()))))){
		HX_STACK_LINE(33)
		this->mAnimationBitmapOther = ::com::minigloop::display::AtlasSprite_obj::__new(this->mClipContainer,clipNameOther,aniDataOther,null());
		HX_STACK_LINE(34)
		this->mAnimationBitmapOther->position->x = (this->mX + this->mOtherX);
		HX_STACK_LINE(35)
		this->mAnimationBitmapOther->position->y = (this->mY + this->mOtherY);
	}
	else{
		HX_STACK_LINE(38)
		this->mBitmapOther = ::com::funbox::bcp::minigame2::util::NUtils_obj::getAsset(clipNameOther);
		HX_STACK_LINE(39)
		this->mBitmapOther->set_x((this->mX + this->mOtherX));
		HX_STACK_LINE(40)
		this->mBitmapOther->set_y((this->mY + this->mOtherY));
		HX_STACK_LINE(42)
		this->mClipContainer->addChild(this->mBitmapOther);
	}
}
;
	return null();
}

SpriteAndTextEffect_obj::~SpriteAndTextEffect_obj() { }

Dynamic SpriteAndTextEffect_obj::__CreateEmpty() { return  new SpriteAndTextEffect_obj; }
hx::ObjectPtr< SpriteAndTextEffect_obj > SpriteAndTextEffect_obj::__new(::String clipName,::String aniData,::String clipNameOther,::String aniDataOther,::native::display::Sprite canvas,::com::minigloop::util::Vector2D pos1,::com::minigloop::util::Vector2D pos2)
{  hx::ObjectPtr< SpriteAndTextEffect_obj > result = new SpriteAndTextEffect_obj();
	result->__construct(clipName,aniData,clipNameOther,aniDataOther,canvas,pos1,pos2);
	return result;}

Dynamic SpriteAndTextEffect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpriteAndTextEffect_obj > result = new SpriteAndTextEffect_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void SpriteAndTextEffect_obj::free( ){
{
		HX_STACK_PUSH("SpriteAndTextEffect::free","com/funbox/bcp/minigame2/engine/effectManager/SpriteAndTextEffect.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_LINE(86)
		if (((this->mBitmapOther != null()))){
			HX_STACK_LINE(87)
			this->mClipContainer->removeChild(this->mBitmapOther);
			HX_STACK_LINE(88)
			this->mBitmapOther->bitmapData->dispose();
		}
		HX_STACK_LINE(91)
		if (((this->mAnimationBitmapOther != null()))){
			HX_STACK_LINE(92)
			this->mAnimationBitmapOther->destroy();
			HX_STACK_LINE(93)
			this->mAnimationBitmapOther = null();
		}
		HX_STACK_LINE(96)
		this->super::free();
	}
return null();
}


Void SpriteAndTextEffect_obj::update( int dt){
{
		HX_STACK_PUSH("SpriteAndTextEffect::update","com/funbox/bcp/minigame2/engine/effectManager/SpriteAndTextEffect.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(47)
		if ((!(this->mPauseAnimation))){
			HX_STACK_LINE(48)
			if (((this->mAnimationBitmapOther != null()))){
				HX_STACK_LINE(49)
				this->mAnimationBitmapOther->position->x = (this->mX + this->mOtherX);
				HX_STACK_LINE(50)
				this->mAnimationBitmapOther->position->y = (this->mY + this->mOtherY);
				HX_STACK_LINE(51)
				this->mAnimationBitmapOther->update(dt);
			}
			HX_STACK_LINE(54)
			if (((this->mBitmapOther != null()))){
				HX_STACK_LINE(55)
				this->mBitmapOther->set_x((this->mX + this->mOtherX));
				HX_STACK_LINE(56)
				this->mBitmapOther->set_y((this->mY + this->mOtherY));
			}
		}
		HX_STACK_LINE(60)
		if (((this->mAnimationBitmapOther != null()))){
			HX_STACK_LINE(64)
			{
				HX_STACK_LINE(64)
				::native::display::Sprite _g = this->mClipContainer;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(64)
				_g->set_alpha((_g->get_alpha() - this->mAlphaFactor));
			}
			HX_STACK_LINE(66)
			if (((this->mClipContainer->get_alpha() <= (int)0))){
				HX_STACK_LINE(67)
				this->mClipContainer->set_alpha((int)0);
				HX_STACK_LINE(68)
				this->isDead = true;
			}
		}
		HX_STACK_LINE(73)
		if (((this->mBitmapOther != null()))){
			HX_STACK_LINE(74)
			{
				HX_STACK_LINE(74)
				::native::display::Sprite _g = this->mClipContainer;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(74)
				_g->set_alpha((_g->get_alpha() - this->mAlphaFactor));
			}
			HX_STACK_LINE(76)
			if (((this->mClipContainer->get_alpha() <= (int)0))){
				HX_STACK_LINE(77)
				this->mClipContainer->set_alpha((int)0);
				HX_STACK_LINE(78)
				this->isDead = true;
			}
		}
		HX_STACK_LINE(82)
		this->super::update(dt);
	}
return null();
}



SpriteAndTextEffect_obj::SpriteAndTextEffect_obj()
{
}

void SpriteAndTextEffect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpriteAndTextEffect);
	HX_MARK_MEMBER_NAME(mClipContainer,"mClipContainer");
	HX_MARK_MEMBER_NAME(mOtherY,"mOtherY");
	HX_MARK_MEMBER_NAME(mOtherX,"mOtherX");
	HX_MARK_MEMBER_NAME(mAnimationBitmapOther,"mAnimationBitmapOther");
	HX_MARK_MEMBER_NAME(mBitmapOther,"mBitmapOther");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SpriteAndTextEffect_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mClipContainer,"mClipContainer");
	HX_VISIT_MEMBER_NAME(mOtherY,"mOtherY");
	HX_VISIT_MEMBER_NAME(mOtherX,"mOtherX");
	HX_VISIT_MEMBER_NAME(mAnimationBitmapOther,"mAnimationBitmapOther");
	HX_VISIT_MEMBER_NAME(mBitmapOther,"mBitmapOther");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SpriteAndTextEffect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mOtherY") ) { return mOtherY; }
		if (HX_FIELD_EQ(inName,"mOtherX") ) { return mOtherX; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mBitmapOther") ) { return mBitmapOther; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mClipContainer") ) { return mClipContainer; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mAnimationBitmapOther") ) { return mAnimationBitmapOther; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SpriteAndTextEffect_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mOtherY") ) { mOtherY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mOtherX") ) { mOtherX=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mBitmapOther") ) { mBitmapOther=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mClipContainer") ) { mClipContainer=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mAnimationBitmapOther") ) { mAnimationBitmapOther=inValue.Cast< ::com::minigloop::display::AtlasSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SpriteAndTextEffect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mClipContainer"));
	outFields->push(HX_CSTRING("mOtherY"));
	outFields->push(HX_CSTRING("mOtherX"));
	outFields->push(HX_CSTRING("mAnimationBitmapOther"));
	outFields->push(HX_CSTRING("mBitmapOther"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("mClipContainer"),
	HX_CSTRING("mOtherY"),
	HX_CSTRING("mOtherX"),
	HX_CSTRING("mAnimationBitmapOther"),
	HX_CSTRING("mBitmapOther"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpriteAndTextEffect_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpriteAndTextEffect_obj::__mClass,"__mClass");
};

Class SpriteAndTextEffect_obj::__mClass;

void SpriteAndTextEffect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.engine.effectManager.SpriteAndTextEffect"), hx::TCanCast< SpriteAndTextEffect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SpriteAndTextEffect_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
} // end namespace effectManager
