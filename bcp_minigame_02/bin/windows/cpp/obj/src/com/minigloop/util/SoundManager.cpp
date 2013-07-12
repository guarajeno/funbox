#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_util_SoundManager
#include <com/minigloop/util/SoundManager.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_native_events_ErrorEvent
#include <native/events/ErrorEvent.h>
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
#ifndef INCLUDED_native_events_TextEvent
#include <native/events/TextEvent.h>
#endif
#ifndef INCLUDED_native_media_Sound
#include <native/media/Sound.h>
#endif
#ifndef INCLUDED_native_media_SoundChannel
#include <native/media/SoundChannel.h>
#endif
#ifndef INCLUDED_native_media_SoundLoaderContext
#include <native/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_native_media_SoundTransform
#include <native/media/SoundTransform.h>
#endif
#ifndef INCLUDED_native_net_URLRequest
#include <native/net/URLRequest.h>
#endif
namespace com{
namespace minigloop{
namespace util{

Void SoundManager_obj::__construct()
{
HX_STACK_PUSH("SoundManager::new","com/minigloop/util/SoundManager.hx",31);
{
}
;
	return null();
}

SoundManager_obj::~SoundManager_obj() { }

Dynamic SoundManager_obj::__CreateEmpty() { return  new SoundManager_obj; }
hx::ObjectPtr< SoundManager_obj > SoundManager_obj::__new()
{  hx::ObjectPtr< SoundManager_obj > result = new SoundManager_obj();
	result->__construct();
	return result;}

Dynamic SoundManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundManager_obj > result = new SoundManager_obj();
	result->__construct();
	return result;}

::native::media::Sound SoundManager_obj::_sound;

Array< ::String > SoundManager_obj::_urls;

Array< ::String > SoundManager_obj::_ids;

Array< ::native::media::Sound > SoundManager_obj::_sounds;

Array< ::native::media::SoundChannel > SoundManager_obj::_channels;

int SoundManager_obj::_index;

Dynamic SoundManager_obj::_callback;

::native::media::SoundChannel SoundManager_obj::_channel;

Void SoundManager_obj::init( ){
{
		HX_STACK_PUSH("SoundManager::init","com/minigloop/util/SoundManager.hx",36);
		HX_STACK_LINE(37)
		::com::minigloop::util::SoundManager_obj::_urls = Array_obj< ::String >::__new();
		HX_STACK_LINE(38)
		::com::minigloop::util::SoundManager_obj::_ids = Array_obj< ::String >::__new();
		HX_STACK_LINE(39)
		::com::minigloop::util::SoundManager_obj::_sounds = Array_obj< ::native::media::Sound >::__new();
		HX_STACK_LINE(40)
		::com::minigloop::util::SoundManager_obj::_channels = Array_obj< ::native::media::SoundChannel >::__new();
		HX_STACK_LINE(42)
		::com::minigloop::util::SoundManager_obj::_index = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,init,(void))

Void SoundManager_obj::addSound( ::String url,::String id){
{
		HX_STACK_PUSH("SoundManager::addSound","com/minigloop/util/SoundManager.hx",46);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(id,"id");
		HX_STACK_LINE(47)
		::com::minigloop::util::SoundManager_obj::_urls->push(url);
		HX_STACK_LINE(48)
		::com::minigloop::util::SoundManager_obj::_ids->push(id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(SoundManager_obj,addSound,(void))

Void SoundManager_obj::load( Dynamic __callback){
{
		HX_STACK_PUSH("SoundManager::load","com/minigloop/util/SoundManager.hx",52);
		HX_STACK_ARG(__callback,"__callback");
		HX_STACK_LINE(53)
		::com::minigloop::util::SoundManager_obj::_callback = __callback;
		HX_STACK_LINE(57)
		::com::minigloop::util::SoundManager_obj::loadSound(null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,load,(void))

Void SoundManager_obj::loadSound( ::native::events::Event e){
{
		HX_STACK_PUSH("SoundManager::loadSound","com/minigloop/util/SoundManager.hx",61);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(61)
		if (((::com::minigloop::util::SoundManager_obj::_index < ::com::minigloop::util::SoundManager_obj::_urls->length))){
			HX_STACK_LINE(64)
			::native::net::URLRequest request = ::native::net::URLRequest_obj::__new(::com::minigloop::util::SoundManager_obj::_urls->__get(::com::minigloop::util::SoundManager_obj::_index));		HX_STACK_VAR(request,"request");
			HX_STACK_LINE(65)
			::com::minigloop::util::SoundManager_obj::_sound = ::native::media::Sound_obj::__new(null(),null(),null());
			HX_STACK_LINE(67)
			::com::minigloop::util::SoundManager_obj::_sound->load(request,null(),null());
			HX_STACK_LINE(68)
			::com::minigloop::util::SoundManager_obj::_sound->addEventListener(::native::events::Event_obj::COMPLETE,::com::minigloop::util::SoundManager_obj::loadSound_dyn(),null(),null(),null());
			HX_STACK_LINE(69)
			::com::minigloop::util::SoundManager_obj::_sound->addEventListener(::native::events::ErrorEvent_obj::ERROR,::com::minigloop::util::SoundManager_obj::onError_dyn(),null(),null(),null());
			HX_STACK_LINE(71)
			::com::minigloop::util::SoundManager_obj::_sounds->push(::com::minigloop::util::SoundManager_obj::_sound);
			HX_STACK_LINE(74)
			::haxe::Log_obj::trace(((HX_CSTRING("sound loaded: [") + ::com::minigloop::util::SoundManager_obj::_ids->__get(::com::minigloop::util::SoundManager_obj::_index)) + HX_CSTRING("]")),hx::SourceInfo(HX_CSTRING("SoundManager.hx"),74,HX_CSTRING("com.minigloop.util.SoundManager"),HX_CSTRING("loadSound")));
			HX_STACK_LINE(76)
			(::com::minigloop::util::SoundManager_obj::_index)++;
		}
		else{
			HX_STACK_LINE(79)
			::com::minigloop::util::SoundManager_obj::_callback();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,loadSound,(void))

Void SoundManager_obj::onError( ::native::events::ErrorEvent e){
{
		HX_STACK_PUSH("SoundManager::onError","com/minigloop/util/SoundManager.hx",85);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(85)
		::haxe::Log_obj::trace((HX_CSTRING("Error loading sound: ") + ::com::minigloop::util::SoundManager_obj::_urls->__get(::com::minigloop::util::SoundManager_obj::_index)),hx::SourceInfo(HX_CSTRING("SoundManager.hx"),86,HX_CSTRING("com.minigloop.util.SoundManager"),HX_CSTRING("onError")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,onError,(void))

::native::media::Sound SoundManager_obj::getSound( ::String id){
	HX_STACK_PUSH("SoundManager::getSound","com/minigloop/util/SoundManager.hx",90);
	HX_STACK_ARG(id,"id");
	HX_STACK_LINE(91)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(93)
	{
		HX_STACK_LINE(93)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::com::minigloop::util::SoundManager_obj::_urls->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(93)
		while(((_g1 < _g))){
			HX_STACK_LINE(93)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(95)
			if (((::com::minigloop::util::SoundManager_obj::_ids->__get(i1) == id))){
				HX_STACK_LINE(96)
				return ::com::minigloop::util::SoundManager_obj::_sounds->__get(i1);
			}
		}
	}
	HX_STACK_LINE(101)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,getSound,return )

int SoundManager_obj::getChannelId( ::String id){
	HX_STACK_PUSH("SoundManager::getChannelId","com/minigloop/util/SoundManager.hx",105);
	HX_STACK_ARG(id,"id");
	HX_STACK_LINE(106)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(108)
	{
		HX_STACK_LINE(108)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::com::minigloop::util::SoundManager_obj::_urls->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(108)
		while(((_g1 < _g))){
			HX_STACK_LINE(108)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(110)
			if (((::com::minigloop::util::SoundManager_obj::_ids->__get(i1) == id))){
				HX_STACK_LINE(111)
				return i1;
			}
		}
	}
	HX_STACK_LINE(116)
	return (int)-1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,getChannelId,return )

Void SoundManager_obj::play( ::String id,hx::Null< bool >  __o_loop){
bool loop = __o_loop.Default(false);
	HX_STACK_PUSH("SoundManager::play","com/minigloop/util/SoundManager.hx",120);
	HX_STACK_ARG(id,"id");
	HX_STACK_ARG(loop,"loop");
{
		HX_STACK_LINE(121)
		::native::media::SoundChannel channel = ::com::minigloop::util::SoundManager_obj::getSound(id)->play((int)0,(  ((loop)) ? int((int)9999) : int((int)0) ),null());		HX_STACK_VAR(channel,"channel");
		HX_STACK_LINE(122)
		::com::minigloop::util::SoundManager_obj::_channels->push(channel);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(SoundManager_obj,play,(void))

Void SoundManager_obj::stopAll( ){
{
		HX_STACK_PUSH("SoundManager::stopAll","com/minigloop/util/SoundManager.hx",126);
		HX_STACK_LINE(127)
		::haxe::Log_obj::trace(HX_CSTRING("stop all"),hx::SourceInfo(HX_CSTRING("SoundManager.hx"),127,HX_CSTRING("com.minigloop.util.SoundManager"),HX_CSTRING("stopAll")));
		HX_STACK_LINE(128)
		::haxe::Log_obj::trace(::com::minigloop::util::SoundManager_obj::_channels->length,hx::SourceInfo(HX_CSTRING("SoundManager.hx"),128,HX_CSTRING("com.minigloop.util.SoundManager"),HX_CSTRING("stopAll")));
		HX_STACK_LINE(129)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(130)
		{
			HX_STACK_LINE(130)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = (::com::minigloop::util::SoundManager_obj::_sounds->length - (int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(130)
			while(((_g1 < _g))){
				HX_STACK_LINE(130)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(132)
				if (((::com::minigloop::util::SoundManager_obj::_channels->__get(i1) != null()))){
					HX_STACK_LINE(132)
					::com::minigloop::util::SoundManager_obj::_channels->__get(i1)->stop();
				}
				HX_STACK_LINE(135)
				::com::minigloop::util::SoundManager_obj::_channels[i1] = null();
			}
		}
		HX_STACK_LINE(138)
		::com::minigloop::util::SoundManager_obj::_channels = Array_obj< ::native::media::SoundChannel >::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,stopAll,(void))


SoundManager_obj::SoundManager_obj()
{
}

void SoundManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundManager);
	HX_MARK_END_CLASS();
}

void SoundManager_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic SoundManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_ids") ) { return _ids; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_urls") ) { return _urls; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_sound") ) { return _sound; }
		if (HX_FIELD_EQ(inName,"_index") ) { return _index; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sounds") ) { return _sounds; }
		if (HX_FIELD_EQ(inName,"onError") ) { return onError_dyn(); }
		if (HX_FIELD_EQ(inName,"stopAll") ) { return stopAll_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_channel") ) { return _channel; }
		if (HX_FIELD_EQ(inName,"addSound") ) { return addSound_dyn(); }
		if (HX_FIELD_EQ(inName,"getSound") ) { return getSound_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_channels") ) { return _channels; }
		if (HX_FIELD_EQ(inName,"_callback") ) { return _callback; }
		if (HX_FIELD_EQ(inName,"loadSound") ) { return loadSound_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getChannelId") ) { return getChannelId_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SoundManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_ids") ) { _ids=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_urls") ) { _urls=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_sound") ) { _sound=inValue.Cast< ::native::media::Sound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_index") ) { _index=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sounds") ) { _sounds=inValue.Cast< Array< ::native::media::Sound > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_channel") ) { _channel=inValue.Cast< ::native::media::SoundChannel >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_channels") ) { _channels=inValue.Cast< Array< ::native::media::SoundChannel > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_callback") ) { _callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SoundManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_sound"),
	HX_CSTRING("_urls"),
	HX_CSTRING("_ids"),
	HX_CSTRING("_sounds"),
	HX_CSTRING("_channels"),
	HX_CSTRING("_index"),
	HX_CSTRING("_callback"),
	HX_CSTRING("_channel"),
	HX_CSTRING("init"),
	HX_CSTRING("addSound"),
	HX_CSTRING("load"),
	HX_CSTRING("loadSound"),
	HX_CSTRING("onError"),
	HX_CSTRING("getSound"),
	HX_CSTRING("getChannelId"),
	HX_CSTRING("play"),
	HX_CSTRING("stopAll"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_sound,"_sound");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_urls,"_urls");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_ids,"_ids");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_sounds,"_sounds");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_channels,"_channels");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_index,"_index");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_callback,"_callback");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_channel,"_channel");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_sound,"_sound");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_urls,"_urls");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_ids,"_ids");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_sounds,"_sounds");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_channels,"_channels");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_index,"_index");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_callback,"_callback");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_channel,"_channel");
};

Class SoundManager_obj::__mClass;

void SoundManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.util.SoundManager"), hx::TCanCast< SoundManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SoundManager_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace util
