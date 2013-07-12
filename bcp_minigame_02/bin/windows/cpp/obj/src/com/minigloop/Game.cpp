#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
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
namespace minigloop{

Void Game_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("Game::new","com/minigloop/Game.hx",16);
{
	HX_STACK_LINE(17)
	this->_canvas = canvas;
	HX_STACK_LINE(18)
	this->_isPaused = false;
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hx::ObjectPtr< Game_obj > Game_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct(canvas);
	return result;}

Dynamic Game_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Game_obj::destroy( ){
{
		HX_STACK_PUSH("Game::destroy","com/minigloop/Game.hx",32);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,destroy,(void))

Void Game_obj::setPause( bool val){
{
		HX_STACK_PUSH("Game::setPause","com/minigloop/Game.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_ARG(val,"val");
		HX_STACK_LINE(27)
		this->_isPaused = val;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,setPause,(void))

Void Game_obj::update( int dt){
{
		HX_STACK_PUSH("Game::update","com/minigloop/Game.hx",22);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,update,(void))


Game_obj::Game_obj()
{
}

void Game_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Game);
	HX_MARK_MEMBER_NAME(_canvas,"_canvas");
	HX_MARK_MEMBER_NAME(_isPaused,"_isPaused");
	HX_MARK_END_CLASS();
}

void Game_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_canvas,"_canvas");
	HX_VISIT_MEMBER_NAME(_isPaused,"_isPaused");
}

Dynamic Game_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"_canvas") ) { return _canvas; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setPause") ) { return setPause_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_isPaused") ) { return _isPaused; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Game_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { _canvas=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_isPaused") ) { _isPaused=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Game_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_canvas"));
	outFields->push(HX_CSTRING("_isPaused"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("setPause"),
	HX_CSTRING("update"),
	HX_CSTRING("_canvas"),
	HX_CSTRING("_isPaused"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Game_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Game_obj::__mClass,"__mClass");
};

Class Game_obj::__mClass;

void Game_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.Game"), hx::TCanCast< Game_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Game_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
