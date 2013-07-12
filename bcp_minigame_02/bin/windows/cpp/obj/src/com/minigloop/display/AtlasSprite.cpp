#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_display_AtlasSprite
#include <com/minigloop/display/AtlasSprite.h>
#endif
#ifndef INCLUDED_com_minigloop_display_VisualObject
#include <com/minigloop/display/VisualObject.h>
#endif
#ifndef INCLUDED_com_minigloop_util_AssetsLoader
#include <com/minigloop/util/AssetsLoader.h>
#endif
#ifndef INCLUDED_com_minigloop_util_DataLoader
#include <com/minigloop/util/DataLoader.h>
#endif
#ifndef INCLUDED_com_minigloop_util_Vector2D
#include <com/minigloop/util/Vector2D.h>
#endif
#ifndef INCLUDED_haxe_Json
#include <haxe/Json.h>
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
#ifndef INCLUDED_native_display_PixelSnapping
#include <native/display/PixelSnapping.h>
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
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace com{
namespace minigloop{
namespace display{

Void AtlasSprite_obj::__construct(::native::display::Sprite canvas,::String imgId,::String atlasId,::String __o_align)
{
HX_STACK_PUSH("AtlasSprite::new","com/minigloop/display/AtlasSprite.hx",58);
::String align = __o_align.Default(HX_CSTRING("center"));
{
	HX_STACK_LINE(59)
	super::__construct(canvas);
	HX_STACK_LINE(61)
	this->_scaleX = (int)1;
	HX_STACK_LINE(62)
	this->_scaleY = (int)1;
	HX_STACK_LINE(64)
	this->mCanPlay = true;
	HX_STACK_LINE(66)
	this->_container = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(67)
	this->_canvas->addChild(this->_container);
	HX_STACK_LINE(69)
	this->_currentIndex = (int)0;
	HX_STACK_LINE(70)
	this->_frames = Array_obj< ::native::display::Bitmap >::__new();
	HX_STACK_LINE(72)
	Dynamic obj = ::haxe::Json_obj::parse(::com::minigloop::util::DataLoader_obj::getData(atlasId));		HX_STACK_VAR(obj,"obj");
	HX_STACK_LINE(74)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(75)
	{
		HX_STACK_LINE(75)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = obj->__Field(HX_CSTRING("frames"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(75)
		while(((_g1 < _g))){
			HX_STACK_LINE(75)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(76)
			Dynamic frame = obj->__Field(HX_CSTRING("frames"),true)->__GetItem(i1);		HX_STACK_VAR(frame,"frame");
			HX_STACK_LINE(77)
			this->_sourceWidth = frame->__Field(HX_CSTRING("spriteSourceSize"),true)->__Field(HX_CSTRING("w"),true);
			HX_STACK_LINE(78)
			this->_sourceHeight = frame->__Field(HX_CSTRING("spriteSourceSize"),true)->__Field(HX_CSTRING("h"),true);
			HX_STACK_LINE(80)
			::native::display::BitmapData src = ::com::minigloop::util::AssetsLoader_obj::getAsset(imgId)->bitmapData;		HX_STACK_VAR(src,"src");
			HX_STACK_LINE(81)
			::native::display::BitmapData bmd = ::native::display::BitmapData_obj::__new(frame->__Field(HX_CSTRING("sourceSize"),true)->__Field(HX_CSTRING("w"),true),frame->__Field(HX_CSTRING("sourceSize"),true)->__Field(HX_CSTRING("h"),true),true,(int)0,null());		HX_STACK_VAR(bmd,"bmd");
			HX_STACK_LINE(82)
			bmd->copyPixels(src,::native::geom::Rectangle_obj::__new(frame->__Field(HX_CSTRING("frame"),true)->__Field(HX_CSTRING("x"),true),frame->__Field(HX_CSTRING("frame"),true)->__Field(HX_CSTRING("y"),true),frame->__Field(HX_CSTRING("frame"),true)->__Field(HX_CSTRING("w"),true),frame->__Field(HX_CSTRING("frame"),true)->__Field(HX_CSTRING("h"),true)),::native::geom::Point_obj::__new(frame->__Field(HX_CSTRING("spriteSourceSize"),true)->__Field(HX_CSTRING("x"),true),frame->__Field(HX_CSTRING("spriteSourceSize"),true)->__Field(HX_CSTRING("y"),true)),null(),null(),null());
			HX_STACK_LINE(84)
			::native::display::Bitmap bm = ::native::display::Bitmap_obj::__new(bmd,null(),null());		HX_STACK_VAR(bm,"bm");
			HX_STACK_LINE(85)
			this->_frames->push(bm);
		}
	}
	HX_STACK_LINE(88)
	::String _switch_1 = (align);
	if (  ( _switch_1==HX_CSTRING("center"))){
		HX_STACK_LINE(92)
		this->_offsetX = (Float(-(this->_sourceWidth)) / Float((int)2));
		HX_STACK_LINE(93)
		this->_offsetY = (Float(-(this->_sourceHeight)) / Float((int)2));
	}
}
;
	return null();
}

AtlasSprite_obj::~AtlasSprite_obj() { }

Dynamic AtlasSprite_obj::__CreateEmpty() { return  new AtlasSprite_obj; }
hx::ObjectPtr< AtlasSprite_obj > AtlasSprite_obj::__new(::native::display::Sprite canvas,::String imgId,::String atlasId,::String __o_align)
{  hx::ObjectPtr< AtlasSprite_obj > result = new AtlasSprite_obj();
	result->__construct(canvas,imgId,atlasId,__o_align);
	return result;}

Dynamic AtlasSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AtlasSprite_obj > result = new AtlasSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void AtlasSprite_obj::destroy( ){
{
		HX_STACK_PUSH("AtlasSprite::destroy","com/minigloop/display/AtlasSprite.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_LINE(155)
		this->_canvas->removeChild(this->_container);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,destroy,(void))

Void AtlasSprite_obj::update( int dt){
{
		HX_STACK_PUSH("AtlasSprite::update","com/minigloop/display/AtlasSprite.hx",134);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(135)
		if ((this->mCanPlay)){
			HX_STACK_LINE(136)
			if (((this->_container->get_numChildren() > (int)0))){
				HX_STACK_LINE(136)
				this->_container->removeChildAt((int)0);
			}
			HX_STACK_LINE(140)
			this->_container->addChild(this->_frames->__get(this->_currentIndex));
			HX_STACK_LINE(141)
			this->_frames->__get(this->_currentIndex)->set_scaleX(this->_scaleX);
			HX_STACK_LINE(143)
			(this->_currentIndex)++;
			HX_STACK_LINE(145)
			if (((this->_currentIndex == this->_frames->length))){
				HX_STACK_LINE(145)
				this->_currentIndex = (int)0;
			}
		}
		HX_STACK_LINE(150)
		this->_container->set_x((this->position->x + this->_offsetX));
		HX_STACK_LINE(151)
		this->_container->set_y((this->position->y + this->_offsetY));
	}
return null();
}


Void AtlasSprite_obj::stop( ){
{
		HX_STACK_PUSH("AtlasSprite::stop","com/minigloop/display/AtlasSprite.hx",130);
		HX_STACK_THIS(this);
		HX_STACK_LINE(130)
		this->mCanPlay = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,stop,(void))

Void AtlasSprite_obj::gotoAndStop( int frame){
{
		HX_STACK_PUSH("AtlasSprite::gotoAndStop","com/minigloop/display/AtlasSprite.hx",114);
		HX_STACK_THIS(this);
		HX_STACK_ARG(frame,"frame");
		HX_STACK_LINE(115)
		if (((this->_container->get_numChildren() > (int)0))){
			HX_STACK_LINE(115)
			this->_container->removeChildAt((int)0);
		}
		HX_STACK_LINE(119)
		this->_container->addChild(this->_frames->__get(frame));
		HX_STACK_LINE(120)
		this->_frames->__get(frame)->set_scaleX(this->_scaleX);
		HX_STACK_LINE(121)
		this->_frames->__get(frame)->set_alpha(this->mAlpha);
		HX_STACK_LINE(123)
		this->_container->set_x((this->position->x + this->_offsetX));
		HX_STACK_LINE(124)
		this->_container->set_y((this->position->y + this->_offsetY));
		HX_STACK_LINE(126)
		this->_currentIndex = frame;
		HX_STACK_LINE(127)
		this->mCanPlay = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AtlasSprite_obj,gotoAndStop,(void))

Void AtlasSprite_obj::gotoAndPlay( int frame){
{
		HX_STACK_PUSH("AtlasSprite::gotoAndPlay","com/minigloop/display/AtlasSprite.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_ARG(frame,"frame");
		HX_STACK_LINE(99)
		if (((this->_container->get_numChildren() > (int)0))){
			HX_STACK_LINE(99)
			this->_container->removeChildAt((int)0);
		}
		HX_STACK_LINE(103)
		this->_container->addChild(this->_frames->__get(frame));
		HX_STACK_LINE(104)
		this->_frames->__get(frame)->set_scaleX(this->_scaleX);
		HX_STACK_LINE(105)
		this->_frames->__get(frame)->set_alpha(this->mAlpha);
		HX_STACK_LINE(107)
		this->_container->set_x((this->position->x + this->_offsetX));
		HX_STACK_LINE(108)
		this->_container->set_y((this->position->y + this->_offsetY));
		HX_STACK_LINE(110)
		this->_currentIndex = frame;
		HX_STACK_LINE(111)
		this->mCanPlay = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AtlasSprite_obj,gotoAndPlay,(void))

Void AtlasSprite_obj::setScaleY( Float value){
{
		HX_STACK_PUSH("AtlasSprite::setScaleY","com/minigloop/display/AtlasSprite.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(55)
		this->_scaleY = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AtlasSprite_obj,setScaleY,(void))

Void AtlasSprite_obj::setScaleX( Float value){
{
		HX_STACK_PUSH("AtlasSprite::setScaleX","com/minigloop/display/AtlasSprite.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(54)
		this->_scaleX = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AtlasSprite_obj,setScaleX,(void))

int AtlasSprite_obj::getLength( ){
	HX_STACK_PUSH("AtlasSprite::getLength","com/minigloop/display/AtlasSprite.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_LINE(52)
	return this->_frames->length;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,getLength,return )

int AtlasSprite_obj::getCurrentIndex( ){
	HX_STACK_PUSH("AtlasSprite::getCurrentIndex","com/minigloop/display/AtlasSprite.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_LINE(51)
	return this->_currentIndex;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,getCurrentIndex,return )

Float AtlasSprite_obj::getScaleY( ){
	HX_STACK_PUSH("AtlasSprite::getScaleY","com/minigloop/display/AtlasSprite.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_LINE(49)
	return this->_scaleY;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,getScaleY,return )

Float AtlasSprite_obj::getScaleX( ){
	HX_STACK_PUSH("AtlasSprite::getScaleX","com/minigloop/display/AtlasSprite.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_LINE(48)
	return this->_scaleX;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,getScaleX,return )

Float AtlasSprite_obj::currentHeight( ){
	HX_STACK_PUSH("AtlasSprite::currentHeight","com/minigloop/display/AtlasSprite.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_LINE(46)
	return this->_frames->__get(this->_currentIndex)->get_height();
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,currentHeight,return )

Float AtlasSprite_obj::currentWidth( ){
	HX_STACK_PUSH("AtlasSprite::currentWidth","com/minigloop/display/AtlasSprite.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_LINE(45)
	return this->_frames->__get(this->_currentIndex)->get_width();
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,currentWidth,return )

bool AtlasSprite_obj::playing( ){
	HX_STACK_PUSH("AtlasSprite::playing","com/minigloop/display/AtlasSprite.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_LINE(43)
	return this->mCanPlay;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,playing,return )

::native::display::Bitmap AtlasSprite_obj::currentFrame( ){
	HX_STACK_PUSH("AtlasSprite::currentFrame","com/minigloop/display/AtlasSprite.hx",42);
	HX_STACK_THIS(this);
	HX_STACK_LINE(42)
	return this->_frames->__get(this->_currentIndex);
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,currentFrame,return )

Void AtlasSprite_obj::setAlpha( Float value){
{
		HX_STACK_PUSH("AtlasSprite::setAlpha","com/minigloop/display/AtlasSprite.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(38)
		this->mAlpha = value;
		HX_STACK_LINE(39)
		this->_container->set_alpha(this->mAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AtlasSprite_obj,setAlpha,(void))

Float AtlasSprite_obj::getAlpha( ){
	HX_STACK_PUSH("AtlasSprite::getAlpha","com/minigloop/display/AtlasSprite.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_LINE(36)
	return this->mAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasSprite_obj,getAlpha,return )


AtlasSprite_obj::AtlasSprite_obj()
{
}

void AtlasSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AtlasSprite);
	HX_MARK_MEMBER_NAME(mCanPlay,"mCanPlay");
	HX_MARK_MEMBER_NAME(_scaleY,"_scaleY");
	HX_MARK_MEMBER_NAME(_scaleX,"_scaleX");
	HX_MARK_MEMBER_NAME(mAlpha,"mAlpha");
	HX_MARK_MEMBER_NAME(_offsetY,"_offsetY");
	HX_MARK_MEMBER_NAME(_offsetX,"_offsetX");
	HX_MARK_MEMBER_NAME(_sourceHeight,"_sourceHeight");
	HX_MARK_MEMBER_NAME(_sourceWidth,"_sourceWidth");
	HX_MARK_MEMBER_NAME(_currentIndex,"_currentIndex");
	HX_MARK_MEMBER_NAME(_frames,"_frames");
	HX_MARK_MEMBER_NAME(_container,"_container");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AtlasSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mCanPlay,"mCanPlay");
	HX_VISIT_MEMBER_NAME(_scaleY,"_scaleY");
	HX_VISIT_MEMBER_NAME(_scaleX,"_scaleX");
	HX_VISIT_MEMBER_NAME(mAlpha,"mAlpha");
	HX_VISIT_MEMBER_NAME(_offsetY,"_offsetY");
	HX_VISIT_MEMBER_NAME(_offsetX,"_offsetX");
	HX_VISIT_MEMBER_NAME(_sourceHeight,"_sourceHeight");
	HX_VISIT_MEMBER_NAME(_sourceWidth,"_sourceWidth");
	HX_VISIT_MEMBER_NAME(_currentIndex,"_currentIndex");
	HX_VISIT_MEMBER_NAME(_frames,"_frames");
	HX_VISIT_MEMBER_NAME(_container,"_container");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic AtlasSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"mAlpha") ) { return mAlpha; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"playing") ) { return playing_dyn(); }
		if (HX_FIELD_EQ(inName,"_scaleY") ) { return _scaleY; }
		if (HX_FIELD_EQ(inName,"_scaleX") ) { return _scaleX; }
		if (HX_FIELD_EQ(inName,"_frames") ) { return _frames; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setAlpha") ) { return setAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getAlpha") ) { return getAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"mCanPlay") ) { return mCanPlay; }
		if (HX_FIELD_EQ(inName,"_offsetY") ) { return _offsetY; }
		if (HX_FIELD_EQ(inName,"_offsetX") ) { return _offsetX; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setScaleY") ) { return setScaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"setScaleX") ) { return setScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		if (HX_FIELD_EQ(inName,"getScaleY") ) { return getScaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"getScaleX") ) { return getScaleX_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_container") ) { return _container; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"gotoAndStop") ) { return gotoAndStop_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoAndPlay") ) { return gotoAndPlay_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentWidth") ) { return currentWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"currentFrame") ) { return currentFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"_sourceWidth") ) { return _sourceWidth; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentHeight") ) { return currentHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"_sourceHeight") ) { return _sourceHeight; }
		if (HX_FIELD_EQ(inName,"_currentIndex") ) { return _currentIndex; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getCurrentIndex") ) { return getCurrentIndex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AtlasSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"mAlpha") ) { mAlpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_scaleY") ) { _scaleY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_scaleX") ) { _scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_frames") ) { _frames=inValue.Cast< Array< ::native::display::Bitmap > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mCanPlay") ) { mCanPlay=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_offsetY") ) { _offsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_offsetX") ) { _offsetX=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_container") ) { _container=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_sourceWidth") ) { _sourceWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_sourceHeight") ) { _sourceHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_currentIndex") ) { _currentIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AtlasSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mCanPlay"));
	outFields->push(HX_CSTRING("_scaleY"));
	outFields->push(HX_CSTRING("_scaleX"));
	outFields->push(HX_CSTRING("mAlpha"));
	outFields->push(HX_CSTRING("_offsetY"));
	outFields->push(HX_CSTRING("_offsetX"));
	outFields->push(HX_CSTRING("_sourceHeight"));
	outFields->push(HX_CSTRING("_sourceWidth"));
	outFields->push(HX_CSTRING("_currentIndex"));
	outFields->push(HX_CSTRING("_frames"));
	outFields->push(HX_CSTRING("_container"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("stop"),
	HX_CSTRING("gotoAndStop"),
	HX_CSTRING("gotoAndPlay"),
	HX_CSTRING("setScaleY"),
	HX_CSTRING("setScaleX"),
	HX_CSTRING("getLength"),
	HX_CSTRING("getCurrentIndex"),
	HX_CSTRING("getScaleY"),
	HX_CSTRING("getScaleX"),
	HX_CSTRING("currentHeight"),
	HX_CSTRING("currentWidth"),
	HX_CSTRING("playing"),
	HX_CSTRING("currentFrame"),
	HX_CSTRING("setAlpha"),
	HX_CSTRING("getAlpha"),
	HX_CSTRING("mCanPlay"),
	HX_CSTRING("_scaleY"),
	HX_CSTRING("_scaleX"),
	HX_CSTRING("mAlpha"),
	HX_CSTRING("_offsetY"),
	HX_CSTRING("_offsetX"),
	HX_CSTRING("_sourceHeight"),
	HX_CSTRING("_sourceWidth"),
	HX_CSTRING("_currentIndex"),
	HX_CSTRING("_frames"),
	HX_CSTRING("_container"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AtlasSprite_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AtlasSprite_obj::__mClass,"__mClass");
};

Class AtlasSprite_obj::__mClass;

void AtlasSprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.display.AtlasSprite"), hx::TCanCast< AtlasSprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AtlasSprite_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace display
