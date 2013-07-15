#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_ScoreCardScreen
#include <com/funbox/bcp/minigame2/screens/ScoreCardScreen.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_Screen
#include <com/minigloop/ui/Screen.h>
#endif
#ifndef INCLUDED_com_minigloop_util_AssetsLoader
#include <com/minigloop/util/AssetsLoader.h>
#endif
#ifndef INCLUDED_com_minigloop_util_SoundManager
#include <com/minigloop/util/SoundManager.h>
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
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace screens{

Void ScoreCardScreen_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("ScoreCardScreen::new","com/funbox/bcp/minigame2/screens/ScoreCardScreen.hx",38);
{
	HX_STACK_LINE(39)
	super::__construct(canvas);
	HX_STACK_LINE(41)
	::native::text::TextFormat tf = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tf,"tf");
	HX_STACK_LINE(42)
	tf->size = (int)16;
	HX_STACK_LINE(43)
	tf->color = (int)16777215;
	HX_STACK_LINE(44)
	tf->italic = true;
	HX_STACK_LINE(45)
	tf->bold = true;
	HX_STACK_LINE(46)
	tf->font = HX_CSTRING("Arial");
	HX_STACK_LINE(48)
	this->_canvas->addChild(::com::minigloop::util::AssetsLoader_obj::getAsset(HX_CSTRING("scorecard")));
	HX_STACK_LINE(50)
	this->_message = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(51)
	this->_message->setTextFormat(tf,null(),null());
	HX_STACK_LINE(52)
	this->_message->set_text(((HX_CSTRING("Hiciste ") + ::com::funbox::bcp::minigame2::Global_obj::totalPoints) + HX_CSTRING(" puntos mientras practicabas para prevenir este fraude.")));
	HX_STACK_LINE(53)
	this->_message->set_width((int)800);
	HX_STACK_LINE(54)
	this->_message->set_height((int)400);
	HX_STACK_LINE(55)
	this->_message->set_multiline(true);
	HX_STACK_LINE(56)
	this->_message->set_x((int)55);
	HX_STACK_LINE(57)
	this->_message->set_y((int)200);
	HX_STACK_LINE(58)
	this->_message->setTextFormat(tf,null(),null());
	HX_STACK_LINE(59)
	this->_canvas->addChild(this->_message);
	HX_STACK_LINE(61)
	::com::minigloop::util::SoundManager_obj::play(HX_CSTRING("scorecard"),null());
	HX_STACK_LINE(83)
	this->_volver = ::com::minigloop::util::AssetsLoader_obj::getAsset(HX_CSTRING("volver"));
	HX_STACK_LINE(84)
	this->_volver->set_x((int)325);
	HX_STACK_LINE(85)
	this->_volver->set_y((int)341);
	HX_STACK_LINE(86)
	this->_volver->set_visible(false);
	HX_STACK_LINE(88)
	this->_regresar = ::com::minigloop::util::AssetsLoader_obj::getAsset(HX_CSTRING("regresar"));
	HX_STACK_LINE(89)
	this->_regresar->set_x((int)165);
	HX_STACK_LINE(90)
	this->_regresar->set_y((int)342);
	HX_STACK_LINE(91)
	this->_regresar->set_visible(false);
	HX_STACK_LINE(93)
	this->_fb = ::com::minigloop::util::AssetsLoader_obj::getAsset(HX_CSTRING("facebook"));
	HX_STACK_LINE(94)
	this->_fb->set_x((int)280);
	HX_STACK_LINE(95)
	this->_fb->set_y((int)290);
	HX_STACK_LINE(96)
	this->_fb->set_visible(false);
	HX_STACK_LINE(98)
	this->_tw = ::com::minigloop::util::AssetsLoader_obj::getAsset(HX_CSTRING("twitter"));
	HX_STACK_LINE(99)
	this->_tw->set_x((int)320);
	HX_STACK_LINE(100)
	this->_tw->set_y((int)290);
	HX_STACK_LINE(103)
	this->_canvas->addChild(this->_volver);
	HX_STACK_LINE(104)
	this->_canvas->addChild(this->_regresar);
	HX_STACK_LINE(105)
	this->_canvas->addChild(this->_fb);
	HX_STACK_LINE(106)
	this->_canvas->addChild(this->_tw);
	HX_STACK_LINE(108)
	this->_canvas->addEventListener(::native::events::MouseEvent_obj::CLICK,this->onClick_dyn(),null(),null(),null());
	HX_STACK_LINE(109)
	this->_canvas->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->onMove_dyn(),null(),null(),null());
}
;
	return null();
}

ScoreCardScreen_obj::~ScoreCardScreen_obj() { }

Dynamic ScoreCardScreen_obj::__CreateEmpty() { return  new ScoreCardScreen_obj; }
hx::ObjectPtr< ScoreCardScreen_obj > ScoreCardScreen_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< ScoreCardScreen_obj > result = new ScoreCardScreen_obj();
	result->__construct(canvas);
	return result;}

Dynamic ScoreCardScreen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScoreCardScreen_obj > result = new ScoreCardScreen_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ScoreCardScreen_obj::destroy( ){
{
		HX_STACK_PUSH("ScoreCardScreen::destroy","com/funbox/bcp/minigame2/screens/ScoreCardScreen.hx",257);
		HX_STACK_THIS(this);
		HX_STACK_LINE(257)
		while(((this->_canvas->get_numChildren() > (int)0))){
			HX_STACK_LINE(259)
			this->_canvas->removeChildAt((int)0);
		}
	}
return null();
}


Void ScoreCardScreen_obj::update( int dt){
{
		HX_STACK_PUSH("ScoreCardScreen::update","com/funbox/bcp/minigame2/screens/ScoreCardScreen.hx",252);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
	}
return null();
}


Void ScoreCardScreen_obj::onClick( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("ScoreCardScreen::onClick","com/funbox/bcp/minigame2/screens/ScoreCardScreen.hx",172);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScoreCardScreen_obj,onClick,(void))

Void ScoreCardScreen_obj::onMove( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("ScoreCardScreen::onMove","com/funbox/bcp/minigame2/screens/ScoreCardScreen.hx",113);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScoreCardScreen_obj,onMove,(void))


ScoreCardScreen_obj::ScoreCardScreen_obj()
{
}

void ScoreCardScreen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScoreCardScreen);
	HX_MARK_MEMBER_NAME(_tw,"_tw");
	HX_MARK_MEMBER_NAME(_fb,"_fb");
	HX_MARK_MEMBER_NAME(_regresar,"_regresar");
	HX_MARK_MEMBER_NAME(_volver,"_volver");
	HX_MARK_MEMBER_NAME(_mouseY,"_mouseY");
	HX_MARK_MEMBER_NAME(_mouseX,"_mouseX");
	HX_MARK_MEMBER_NAME(_box_1,"_box_1");
	HX_MARK_MEMBER_NAME(_message,"_message");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ScoreCardScreen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_tw,"_tw");
	HX_VISIT_MEMBER_NAME(_fb,"_fb");
	HX_VISIT_MEMBER_NAME(_regresar,"_regresar");
	HX_VISIT_MEMBER_NAME(_volver,"_volver");
	HX_VISIT_MEMBER_NAME(_mouseY,"_mouseY");
	HX_VISIT_MEMBER_NAME(_mouseX,"_mouseX");
	HX_VISIT_MEMBER_NAME(_box_1,"_box_1");
	HX_VISIT_MEMBER_NAME(_message,"_message");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ScoreCardScreen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_tw") ) { return _tw; }
		if (HX_FIELD_EQ(inName,"_fb") ) { return _fb; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"onMove") ) { return onMove_dyn(); }
		if (HX_FIELD_EQ(inName,"_box_1") ) { return _box_1; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick_dyn(); }
		if (HX_FIELD_EQ(inName,"_volver") ) { return _volver; }
		if (HX_FIELD_EQ(inName,"_mouseY") ) { return _mouseY; }
		if (HX_FIELD_EQ(inName,"_mouseX") ) { return _mouseX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_message") ) { return _message; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_regresar") ) { return _regresar; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ScoreCardScreen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_tw") ) { _tw=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fb") ) { _fb=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_box_1") ) { _box_1=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_volver") ) { _volver=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mouseY") ) { _mouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mouseX") ) { _mouseX=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_message") ) { _message=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_regresar") ) { _regresar=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScoreCardScreen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_tw"));
	outFields->push(HX_CSTRING("_fb"));
	outFields->push(HX_CSTRING("_regresar"));
	outFields->push(HX_CSTRING("_volver"));
	outFields->push(HX_CSTRING("_mouseY"));
	outFields->push(HX_CSTRING("_mouseX"));
	outFields->push(HX_CSTRING("_box_1"));
	outFields->push(HX_CSTRING("_message"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("onClick"),
	HX_CSTRING("onMove"),
	HX_CSTRING("_tw"),
	HX_CSTRING("_fb"),
	HX_CSTRING("_regresar"),
	HX_CSTRING("_volver"),
	HX_CSTRING("_mouseY"),
	HX_CSTRING("_mouseX"),
	HX_CSTRING("_box_1"),
	HX_CSTRING("_message"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScoreCardScreen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScoreCardScreen_obj::__mClass,"__mClass");
};

Class ScoreCardScreen_obj::__mClass;

void ScoreCardScreen_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.screens.ScoreCardScreen"), hx::TCanCast< ScoreCardScreen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ScoreCardScreen_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens
