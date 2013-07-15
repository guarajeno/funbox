#include <hxcpp.h>

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
namespace entities{

Void BaseActor_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y)
{
HX_STACK_PUSH("BaseActor::new","com/funbox/bcp/minigame2/entities/BaseActor.hx",77);
{
	HX_STACK_LINE(78)
	this->mX = x;
	HX_STACK_LINE(79)
	this->mY = y;
	HX_STACK_LINE(80)
	this->mCanvas = canvas;
	HX_STACK_LINE(82)
	this->mOffsetX = (int)0;
	HX_STACK_LINE(83)
	this->mOffsetY = (int)0;
	HX_STACK_LINE(84)
	this->mFlipOffsetX = (int)0;
	HX_STACK_LINE(86)
	this->mFlip = false;
	HX_STACK_LINE(87)
	this->mStaticImage = true;
	HX_STACK_LINE(88)
	this->mPauseAnimation = false;
	HX_STACK_LINE(90)
	if (((bool((clipName != null())) && bool((aniData == null()))))){
		HX_STACK_LINE(91)
		this->mStaticImage = true;
		HX_STACK_LINE(93)
		this->mBitmap = ::com::funbox::bcp::minigame2::util::NUtils_obj::getAsset(clipName);
		HX_STACK_LINE(94)
		this->mBitmap->set_x(-(this->mBitmap->get_width()));
		HX_STACK_LINE(95)
		this->mBitmap->set_y(-(this->mBitmap->get_height()));
		HX_STACK_LINE(97)
		this->mWidth = this->mBitmap->get_width();
		HX_STACK_LINE(98)
		this->mHeight = this->mBitmap->get_height();
		HX_STACK_LINE(100)
		this->mCanvas->addChild(this->mBitmap);
	}
	else{
		HX_STACK_LINE(103)
		this->mStaticImage = false;
		HX_STACK_LINE(105)
		this->mAnimationBitmap = ::com::minigloop::display::AtlasSprite_obj::__new(this->mCanvas,clipName,aniData,null());
		HX_STACK_LINE(106)
		this->mAnimationBitmap->position->x = -(this->mAnimationBitmap->currentWidth());
		HX_STACK_LINE(107)
		this->mAnimationBitmap->position->y = -(this->mAnimationBitmap->currentHeight());
		HX_STACK_LINE(109)
		this->mWidth = this->mAnimationBitmap->currentWidth();
		HX_STACK_LINE(110)
		this->mHeight = this->mAnimationBitmap->currentHeight();
	}
	HX_STACK_LINE(113)
	this->setAlpha(1.0);
}
;
	return null();
}

BaseActor_obj::~BaseActor_obj() { }

Dynamic BaseActor_obj::__CreateEmpty() { return  new BaseActor_obj; }
hx::ObjectPtr< BaseActor_obj > BaseActor_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y)
{  hx::ObjectPtr< BaseActor_obj > result = new BaseActor_obj();
	result->__construct(clipName,aniData,canvas,x,y);
	return result;}

Dynamic BaseActor_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseActor_obj > result = new BaseActor_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void BaseActor_obj::free( ){
{
		HX_STACK_PUSH("BaseActor::free","com/funbox/bcp/minigame2/entities/BaseActor.hx",149);
		HX_STACK_THIS(this);
		HX_STACK_LINE(150)
		if ((this->mStaticImage)){
			HX_STACK_LINE(151)
			this->mCanvas->removeChild(this->mBitmap);
			HX_STACK_LINE(152)
			this->mBitmap->bitmapData->dispose();
		}
		else{
			HX_STACK_LINE(155)
			this->mAnimationBitmap->destroy();
			HX_STACK_LINE(156)
			this->mAnimationBitmap = null();
		}
		HX_STACK_LINE(159)
		this->mBitmap = null();
		HX_STACK_LINE(160)
		this->mCanvas = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,free,(void))

Void BaseActor_obj::update( int dt){
{
		HX_STACK_PUSH("BaseActor::update","com/funbox/bcp/minigame2/entities/BaseActor.hx",134);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(134)
		if ((this->mStaticImage)){
			HX_STACK_LINE(136)
			this->mBitmap->set_x(((this->mX + this->mOffsetX) + this->mFlipOffsetX));
			HX_STACK_LINE(137)
			this->mBitmap->set_y((this->mY + this->mOffsetY));
		}
		else{
			HX_STACK_LINE(140)
			this->mAnimationBitmap->position->x = ((this->mX + this->mOffsetX) + this->mFlipOffsetX);
			HX_STACK_LINE(141)
			this->mAnimationBitmap->position->y = (this->mY + this->mOffsetY);
			HX_STACK_LINE(143)
			if ((!(this->mPauseAnimation))){
				HX_STACK_LINE(143)
				this->mAnimationBitmap->update(dt);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,update,(void))

bool BaseActor_obj::hitTestPoint( int x,int y){
	HX_STACK_PUSH("BaseActor::hitTestPoint","com/funbox/bcp/minigame2/entities/BaseActor.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(128)
	if (((bool((bool((bool((x > this->mX)) && bool((x < (this->mX + this->mWidth))))) && bool((y > this->mY)))) && bool((y < (this->mY + this->mHeight)))))){
		HX_STACK_LINE(128)
		return true;
	}
	HX_STACK_LINE(131)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(BaseActor_obj,hitTestPoint,return )

bool BaseActor_obj::hitTest( ::com::funbox::bcp::minigame2::entities::BaseActor actor){
	HX_STACK_PUSH("BaseActor::hitTest","com/funbox/bcp/minigame2/entities/BaseActor.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_ARG(actor,"actor");
	HX_STACK_LINE(117)
	Float secondOBjX = actor->getX();		HX_STACK_VAR(secondOBjX,"secondOBjX");
	HX_STACK_LINE(118)
	Float secondOBjY = actor->getY();		HX_STACK_VAR(secondOBjY,"secondOBjY");
	HX_STACK_LINE(120)
	if (((bool((bool((bool(((this->mX + this->mWidth) >= secondOBjX)) && bool(((secondOBjX + actor->getWidth()) >= this->mX)))) && bool(((this->mY + this->mHeight) >= secondOBjY)))) && bool(((secondOBjY + actor->getHeight()) >= this->mY))))){
		HX_STACK_LINE(121)
		return true;
	}
	HX_STACK_LINE(124)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,hitTest,return )

Void BaseActor_obj::setFlip( bool value){
{
		HX_STACK_PUSH("BaseActor::setFlip","com/funbox/bcp/minigame2/entities/BaseActor.hx",64);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(65)
		this->mFlip = value;
		HX_STACK_LINE(67)
		if ((this->mStaticImage)){
			HX_STACK_LINE(67)
			this->mBitmap->set_scaleX((  ((this->mFlip)) ? int((int)-1) : int((int)1) ));
		}
		else{
			HX_STACK_LINE(70)
			this->mAnimationBitmap->setScaleX((  ((this->mFlip)) ? int((int)-1) : int((int)1) ));
		}
		HX_STACK_LINE(74)
		this->mFlipOffsetX = (  ((this->mFlip)) ? Float(this->mWidth) : Float((int)0) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,setFlip,(void))

bool BaseActor_obj::getFlip( ){
	HX_STACK_PUSH("BaseActor::getFlip","com/funbox/bcp/minigame2/entities/BaseActor.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_LINE(62)
	return this->mFlip;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getFlip,return )

Void BaseActor_obj::setOffsetY( Float value){
{
		HX_STACK_PUSH("BaseActor::setOffsetY","com/funbox/bcp/minigame2/entities/BaseActor.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(60)
		this->mOffsetY = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,setOffsetY,(void))

Float BaseActor_obj::getOffsetY( ){
	HX_STACK_PUSH("BaseActor::getOffsetY","com/funbox/bcp/minigame2/entities/BaseActor.hx",59);
	HX_STACK_THIS(this);
	HX_STACK_LINE(59)
	return this->mOffsetY;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getOffsetY,return )

Void BaseActor_obj::setOffsetX( Float value){
{
		HX_STACK_PUSH("BaseActor::setOffsetX","com/funbox/bcp/minigame2/entities/BaseActor.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(57)
		this->mOffsetX = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,setOffsetX,(void))

Float BaseActor_obj::getOffsetX( ){
	HX_STACK_PUSH("BaseActor::getOffsetX","com/funbox/bcp/minigame2/entities/BaseActor.hx",56);
	HX_STACK_THIS(this);
	HX_STACK_LINE(56)
	return this->mOffsetX;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getOffsetX,return )

Void BaseActor_obj::setAlpha( Float value){
{
		HX_STACK_PUSH("BaseActor::setAlpha","com/funbox/bcp/minigame2/entities/BaseActor.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(46)
		this->mAlpha = value;
		HX_STACK_LINE(48)
		if ((this->mStaticImage)){
			HX_STACK_LINE(48)
			this->mBitmap->set_alpha(this->mAlpha);
		}
		else{
			HX_STACK_LINE(51)
			this->mAnimationBitmap->setAlpha(this->mAlpha);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,setAlpha,(void))

Float BaseActor_obj::getAlpha( ){
	HX_STACK_PUSH("BaseActor::getAlpha","com/funbox/bcp/minigame2/entities/BaseActor.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_LINE(44)
	return this->mAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getAlpha,return )

Void BaseActor_obj::setY( Float value){
{
		HX_STACK_PUSH("BaseActor::setY","com/funbox/bcp/minigame2/entities/BaseActor.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(42)
		this->mY = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,setY,(void))

Float BaseActor_obj::getY( ){
	HX_STACK_PUSH("BaseActor::getY","com/funbox/bcp/minigame2/entities/BaseActor.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_LINE(41)
	return this->mY;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getY,return )

Void BaseActor_obj::setX( Float value){
{
		HX_STACK_PUSH("BaseActor::setX","com/funbox/bcp/minigame2/entities/BaseActor.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(39)
		this->mX = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseActor_obj,setX,(void))

Float BaseActor_obj::getX( ){
	HX_STACK_PUSH("BaseActor::getX","com/funbox/bcp/minigame2/entities/BaseActor.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_LINE(38)
	return this->mX;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getX,return )

Float BaseActor_obj::getHeight( ){
	HX_STACK_PUSH("BaseActor::getHeight","com/funbox/bcp/minigame2/entities/BaseActor.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_LINE(36)
	return this->mHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getHeight,return )

Float BaseActor_obj::getWidth( ){
	HX_STACK_PUSH("BaseActor::getWidth","com/funbox/bcp/minigame2/entities/BaseActor.hx",35);
	HX_STACK_THIS(this);
	HX_STACK_LINE(35)
	return this->mWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseActor_obj,getWidth,return )


BaseActor_obj::BaseActor_obj()
{
}

void BaseActor_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseActor);
	HX_MARK_MEMBER_NAME(mPauseAnimation,"mPauseAnimation");
	HX_MARK_MEMBER_NAME(mStaticImage,"mStaticImage");
	HX_MARK_MEMBER_NAME(mFlip,"mFlip");
	HX_MARK_MEMBER_NAME(mAnimationBitmap,"mAnimationBitmap");
	HX_MARK_MEMBER_NAME(mBitmap,"mBitmap");
	HX_MARK_MEMBER_NAME(mCanvas,"mCanvas");
	HX_MARK_MEMBER_NAME(mAlpha,"mAlpha");
	HX_MARK_MEMBER_NAME(mHeight,"mHeight");
	HX_MARK_MEMBER_NAME(mWidth,"mWidth");
	HX_MARK_MEMBER_NAME(mFlipOffsetX,"mFlipOffsetX");
	HX_MARK_MEMBER_NAME(mOffsetY,"mOffsetY");
	HX_MARK_MEMBER_NAME(mOffsetX,"mOffsetX");
	HX_MARK_MEMBER_NAME(mY,"mY");
	HX_MARK_MEMBER_NAME(mX,"mX");
	HX_MARK_END_CLASS();
}

void BaseActor_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mPauseAnimation,"mPauseAnimation");
	HX_VISIT_MEMBER_NAME(mStaticImage,"mStaticImage");
	HX_VISIT_MEMBER_NAME(mFlip,"mFlip");
	HX_VISIT_MEMBER_NAME(mAnimationBitmap,"mAnimationBitmap");
	HX_VISIT_MEMBER_NAME(mBitmap,"mBitmap");
	HX_VISIT_MEMBER_NAME(mCanvas,"mCanvas");
	HX_VISIT_MEMBER_NAME(mAlpha,"mAlpha");
	HX_VISIT_MEMBER_NAME(mHeight,"mHeight");
	HX_VISIT_MEMBER_NAME(mWidth,"mWidth");
	HX_VISIT_MEMBER_NAME(mFlipOffsetX,"mFlipOffsetX");
	HX_VISIT_MEMBER_NAME(mOffsetY,"mOffsetY");
	HX_VISIT_MEMBER_NAME(mOffsetX,"mOffsetX");
	HX_VISIT_MEMBER_NAME(mY,"mY");
	HX_VISIT_MEMBER_NAME(mX,"mX");
}

Dynamic BaseActor_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"mY") ) { return mY; }
		if (HX_FIELD_EQ(inName,"mX") ) { return mX; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		if (HX_FIELD_EQ(inName,"setY") ) { return setY_dyn(); }
		if (HX_FIELD_EQ(inName,"getY") ) { return getY_dyn(); }
		if (HX_FIELD_EQ(inName,"setX") ) { return setX_dyn(); }
		if (HX_FIELD_EQ(inName,"getX") ) { return getX_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mFlip") ) { return mFlip; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"mAlpha") ) { return mAlpha; }
		if (HX_FIELD_EQ(inName,"mWidth") ) { return mWidth; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hitTest") ) { return hitTest_dyn(); }
		if (HX_FIELD_EQ(inName,"setFlip") ) { return setFlip_dyn(); }
		if (HX_FIELD_EQ(inName,"getFlip") ) { return getFlip_dyn(); }
		if (HX_FIELD_EQ(inName,"mBitmap") ) { return mBitmap; }
		if (HX_FIELD_EQ(inName,"mCanvas") ) { return mCanvas; }
		if (HX_FIELD_EQ(inName,"mHeight") ) { return mHeight; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setAlpha") ) { return setAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getAlpha") ) { return getAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getWidth") ) { return getWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"mOffsetY") ) { return mOffsetY; }
		if (HX_FIELD_EQ(inName,"mOffsetX") ) { return mOffsetX; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getHeight") ) { return getHeight_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setOffsetY") ) { return setOffsetY_dyn(); }
		if (HX_FIELD_EQ(inName,"getOffsetY") ) { return getOffsetY_dyn(); }
		if (HX_FIELD_EQ(inName,"setOffsetX") ) { return setOffsetX_dyn(); }
		if (HX_FIELD_EQ(inName,"getOffsetX") ) { return getOffsetX_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hitTestPoint") ) { return hitTestPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"mStaticImage") ) { return mStaticImage; }
		if (HX_FIELD_EQ(inName,"mFlipOffsetX") ) { return mFlipOffsetX; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"mPauseAnimation") ) { return mPauseAnimation; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"mAnimationBitmap") ) { return mAnimationBitmap; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseActor_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"mY") ) { mY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mX") ) { mX=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mFlip") ) { mFlip=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mAlpha") ) { mAlpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mWidth") ) { mWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mBitmap") ) { mBitmap=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mCanvas") ) { mCanvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mHeight") ) { mHeight=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mOffsetY") ) { mOffsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mOffsetX") ) { mOffsetX=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mStaticImage") ) { mStaticImage=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mFlipOffsetX") ) { mFlipOffsetX=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"mPauseAnimation") ) { mPauseAnimation=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"mAnimationBitmap") ) { mAnimationBitmap=inValue.Cast< ::com::minigloop::display::AtlasSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseActor_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mPauseAnimation"));
	outFields->push(HX_CSTRING("mStaticImage"));
	outFields->push(HX_CSTRING("mFlip"));
	outFields->push(HX_CSTRING("mAnimationBitmap"));
	outFields->push(HX_CSTRING("mBitmap"));
	outFields->push(HX_CSTRING("mCanvas"));
	outFields->push(HX_CSTRING("mAlpha"));
	outFields->push(HX_CSTRING("mHeight"));
	outFields->push(HX_CSTRING("mWidth"));
	outFields->push(HX_CSTRING("mFlipOffsetX"));
	outFields->push(HX_CSTRING("mOffsetY"));
	outFields->push(HX_CSTRING("mOffsetX"));
	outFields->push(HX_CSTRING("mY"));
	outFields->push(HX_CSTRING("mX"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("hitTestPoint"),
	HX_CSTRING("hitTest"),
	HX_CSTRING("setFlip"),
	HX_CSTRING("getFlip"),
	HX_CSTRING("setOffsetY"),
	HX_CSTRING("getOffsetY"),
	HX_CSTRING("setOffsetX"),
	HX_CSTRING("getOffsetX"),
	HX_CSTRING("setAlpha"),
	HX_CSTRING("getAlpha"),
	HX_CSTRING("setY"),
	HX_CSTRING("getY"),
	HX_CSTRING("setX"),
	HX_CSTRING("getX"),
	HX_CSTRING("getHeight"),
	HX_CSTRING("getWidth"),
	HX_CSTRING("mPauseAnimation"),
	HX_CSTRING("mStaticImage"),
	HX_CSTRING("mFlip"),
	HX_CSTRING("mAnimationBitmap"),
	HX_CSTRING("mBitmap"),
	HX_CSTRING("mCanvas"),
	HX_CSTRING("mAlpha"),
	HX_CSTRING("mHeight"),
	HX_CSTRING("mWidth"),
	HX_CSTRING("mFlipOffsetX"),
	HX_CSTRING("mOffsetY"),
	HX_CSTRING("mOffsetX"),
	HX_CSTRING("mY"),
	HX_CSTRING("mX"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseActor_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseActor_obj::__mClass,"__mClass");
};

Class BaseActor_obj::__mClass;

void BaseActor_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.entities.BaseActor"), hx::TCanCast< BaseActor_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BaseActor_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
