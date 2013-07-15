#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_minigloop_display_AtlasSprite
#include <com/minigloop/display/AtlasSprite.h>
#endif
#ifndef INCLUDED_com_minigloop_display_VisualObject
#include <com/minigloop/display/VisualObject.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
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

Void BaseEffect_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y)
{
HX_STACK_PUSH("BaseEffect::new","com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.hx",19);
{
	HX_STACK_LINE(20)
	super::__construct(clipName,aniData,canvas,x,y);
	HX_STACK_LINE(22)
	this->isDead = false;
	HX_STACK_LINE(23)
	this->mDelayToStart = (int)0;
	HX_STACK_LINE(24)
	this->mAlphaFactor = 0.06;
	HX_STACK_LINE(25)
	this->mDieWithAlpha = false;
}
;
	return null();
}

BaseEffect_obj::~BaseEffect_obj() { }

Dynamic BaseEffect_obj::__CreateEmpty() { return  new BaseEffect_obj; }
hx::ObjectPtr< BaseEffect_obj > BaseEffect_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y)
{  hx::ObjectPtr< BaseEffect_obj > result = new BaseEffect_obj();
	result->__construct(clipName,aniData,canvas,x,y);
	return result;}

Dynamic BaseEffect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseEffect_obj > result = new BaseEffect_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void BaseEffect_obj::update( int dt){
{
		HX_STACK_PUSH("BaseEffect::update","com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(38)
		if (((this->mDelayToStart < (int)0))){
			HX_STACK_LINE(39)
			this->mDelayToStart = (int)0;
			HX_STACK_LINE(40)
			this->mPauseAnimation = false;
		}
		HX_STACK_LINE(43)
		if ((!(this->mDieWithAlpha))){
			HX_STACK_LINE(43)
			if ((!(this->mStaticImage))){
				HX_STACK_LINE(44)
				if (((this->mAnimationBitmap->getCurrentIndex() == (this->mAnimationBitmap->getLength() - (int)1)))){
					HX_STACK_LINE(45)
					this->isDead = true;
				}
			}
		}
		else{
			HX_STACK_LINE(50)
			if ((!(this->mStaticImage))){
				HX_STACK_LINE(55)
				this->mAnimationBitmap->setAlpha((this->mAnimationBitmap->getAlpha() - this->mAlphaFactor));
				HX_STACK_LINE(57)
				if (((this->mAnimationBitmap->getAlpha() <= (int)0))){
					HX_STACK_LINE(58)
					this->mAnimationBitmap->setAlpha((int)0);
					HX_STACK_LINE(59)
					this->isDead = true;
				}
			}
			else{
				HX_STACK_LINE(63)
				if (((this->mBitmap != null()))){
					HX_STACK_LINE(65)
					{
						HX_STACK_LINE(65)
						::native::display::Bitmap _g = this->mBitmap;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(65)
						_g->set_alpha((_g->get_alpha() - this->mAlphaFactor));
					}
					HX_STACK_LINE(67)
					if (((this->mBitmap->get_alpha() <= (int)0))){
						HX_STACK_LINE(68)
						this->mBitmap->set_alpha((int)0);
						HX_STACK_LINE(69)
						this->isDead = true;
					}
				}
			}
		}
		HX_STACK_LINE(75)
		if ((!(this->isDead))){
			HX_STACK_LINE(75)
			this->super::update(dt);
		}
	}
return null();
}


Void BaseEffect_obj::SetDelayTimeToStart( int time){
{
		HX_STACK_PUSH("BaseEffect::SetDelayTimeToStart","com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
		HX_STACK_LINE(33)
		this->mDelayToStart = time;
		HX_STACK_LINE(34)
		this->mPauseAnimation = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseEffect_obj,SetDelayTimeToStart,(void))

Void BaseEffect_obj::DieWithAlpha( bool value){
{
		HX_STACK_PUSH("BaseEffect::DieWithAlpha","com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.hx",28);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(28)
		this->mDieWithAlpha = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseEffect_obj,DieWithAlpha,(void))


BaseEffect_obj::BaseEffect_obj()
{
}

void BaseEffect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseEffect);
	HX_MARK_MEMBER_NAME(mAlphaFactor,"mAlphaFactor");
	HX_MARK_MEMBER_NAME(mDieWithAlpha,"mDieWithAlpha");
	HX_MARK_MEMBER_NAME(mDelayToStart,"mDelayToStart");
	HX_MARK_MEMBER_NAME(isDead,"isDead");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BaseEffect_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mAlphaFactor,"mAlphaFactor");
	HX_VISIT_MEMBER_NAME(mDieWithAlpha,"mDieWithAlpha");
	HX_VISIT_MEMBER_NAME(mDelayToStart,"mDelayToStart");
	HX_VISIT_MEMBER_NAME(isDead,"isDead");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BaseEffect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"isDead") ) { return isDead; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"DieWithAlpha") ) { return DieWithAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"mAlphaFactor") ) { return mAlphaFactor; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mDieWithAlpha") ) { return mDieWithAlpha; }
		if (HX_FIELD_EQ(inName,"mDelayToStart") ) { return mDelayToStart; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"SetDelayTimeToStart") ) { return SetDelayTimeToStart_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseEffect_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"isDead") ) { isDead=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mAlphaFactor") ) { mAlphaFactor=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mDieWithAlpha") ) { mDieWithAlpha=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mDelayToStart") ) { mDelayToStart=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseEffect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mAlphaFactor"));
	outFields->push(HX_CSTRING("mDieWithAlpha"));
	outFields->push(HX_CSTRING("mDelayToStart"));
	outFields->push(HX_CSTRING("isDead"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("SetDelayTimeToStart"),
	HX_CSTRING("DieWithAlpha"),
	HX_CSTRING("mAlphaFactor"),
	HX_CSTRING("mDieWithAlpha"),
	HX_CSTRING("mDelayToStart"),
	HX_CSTRING("isDead"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseEffect_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseEffect_obj::__mClass,"__mClass");
};

Class BaseEffect_obj::__mClass;

void BaseEffect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.engine.effectManager.BaseEffect"), hx::TCanCast< BaseEffect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BaseEffect_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
} // end namespace effectManager
