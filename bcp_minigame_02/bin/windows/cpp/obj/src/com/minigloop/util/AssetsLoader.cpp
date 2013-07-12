#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_util_AssetsLoader
#include <com/minigloop/util/AssetsLoader.h>
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
#ifndef INCLUDED_native_display_Loader
#include <native/display/Loader.h>
#endif
#ifndef INCLUDED_native_display_LoaderInfo
#include <native/display/LoaderInfo.h>
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
#ifndef INCLUDED_native_net_URLLoader
#include <native/net/URLLoader.h>
#endif
#ifndef INCLUDED_native_net_URLRequest
#include <native/net/URLRequest.h>
#endif
namespace com{
namespace minigloop{
namespace util{

Void AssetsLoader_obj::__construct()
{
HX_STACK_PUSH("AssetsLoader::new","com/minigloop/util/AssetsLoader.hx",21);
{
}
;
	return null();
}

AssetsLoader_obj::~AssetsLoader_obj() { }

Dynamic AssetsLoader_obj::__CreateEmpty() { return  new AssetsLoader_obj; }
hx::ObjectPtr< AssetsLoader_obj > AssetsLoader_obj::__new()
{  hx::ObjectPtr< AssetsLoader_obj > result = new AssetsLoader_obj();
	result->__construct();
	return result;}

Dynamic AssetsLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AssetsLoader_obj > result = new AssetsLoader_obj();
	result->__construct();
	return result;}

::native::display::Loader AssetsLoader_obj::_loader;

Array< ::String > AssetsLoader_obj::_urls;

Array< ::String > AssetsLoader_obj::_ids;

Array< ::native::display::Loader > AssetsLoader_obj::_loaders;

int AssetsLoader_obj::_index;

Dynamic AssetsLoader_obj::_callback;

Void AssetsLoader_obj::init( ){
{
		HX_STACK_PUSH("AssetsLoader::init","com/minigloop/util/AssetsLoader.hx",26);
		HX_STACK_LINE(27)
		::com::minigloop::util::AssetsLoader_obj::_urls = Array_obj< ::String >::__new();
		HX_STACK_LINE(28)
		::com::minigloop::util::AssetsLoader_obj::_ids = Array_obj< ::String >::__new();
		HX_STACK_LINE(29)
		::com::minigloop::util::AssetsLoader_obj::_loaders = Array_obj< ::native::display::Loader >::__new();
		HX_STACK_LINE(31)
		::com::minigloop::util::AssetsLoader_obj::_index = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AssetsLoader_obj,init,(void))

Void AssetsLoader_obj::addAsset( ::String url,::String id){
{
		HX_STACK_PUSH("AssetsLoader::addAsset","com/minigloop/util/AssetsLoader.hx",35);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(id,"id");
		HX_STACK_LINE(36)
		::com::minigloop::util::AssetsLoader_obj::_urls->push(url);
		HX_STACK_LINE(37)
		::com::minigloop::util::AssetsLoader_obj::_ids->push(id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(AssetsLoader_obj,addAsset,(void))

Void AssetsLoader_obj::load( Dynamic __callback){
{
		HX_STACK_PUSH("AssetsLoader::load","com/minigloop/util/AssetsLoader.hx",41);
		HX_STACK_ARG(__callback,"__callback");
		HX_STACK_LINE(42)
		::com::minigloop::util::AssetsLoader_obj::_callback = __callback;
		HX_STACK_LINE(43)
		::com::minigloop::util::AssetsLoader_obj::loadAsset(null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AssetsLoader_obj,load,(void))

Void AssetsLoader_obj::loadAsset( ::native::events::Event e){
{
		HX_STACK_PUSH("AssetsLoader::loadAsset","com/minigloop/util/AssetsLoader.hx",47);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(47)
		if (((::com::minigloop::util::AssetsLoader_obj::_index < ::com::minigloop::util::AssetsLoader_obj::_urls->length))){
			HX_STACK_LINE(50)
			::native::net::URLRequest request = ::native::net::URLRequest_obj::__new(::com::minigloop::util::AssetsLoader_obj::_urls->__get(::com::minigloop::util::AssetsLoader_obj::_index));		HX_STACK_VAR(request,"request");
			HX_STACK_LINE(51)
			::com::minigloop::util::AssetsLoader_obj::_loader = ::native::display::Loader_obj::__new();
			HX_STACK_LINE(52)
			::com::minigloop::util::AssetsLoader_obj::_loader->load(request);
			HX_STACK_LINE(53)
			::com::minigloop::util::AssetsLoader_obj::_loader->contentLoaderInfo->addEventListener(::native::events::Event_obj::COMPLETE,::com::minigloop::util::AssetsLoader_obj::loadAsset_dyn(),null(),null(),null());
			HX_STACK_LINE(55)
			::com::minigloop::util::AssetsLoader_obj::_loaders->push(::com::minigloop::util::AssetsLoader_obj::_loader);
			HX_STACK_LINE(56)
			(::com::minigloop::util::AssetsLoader_obj::_index)++;
		}
		else{
			HX_STACK_LINE(59)
			::com::minigloop::util::AssetsLoader_obj::_callback();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AssetsLoader_obj,loadAsset,(void))

::native::display::Bitmap AssetsLoader_obj::getAsset( ::String id){
	HX_STACK_PUSH("AssetsLoader::getAsset","com/minigloop/util/AssetsLoader.hx",65);
	HX_STACK_ARG(id,"id");
	HX_STACK_LINE(66)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(68)
	{
		HX_STACK_LINE(68)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::com::minigloop::util::AssetsLoader_obj::_urls->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		while(((_g1 < _g))){
			HX_STACK_LINE(68)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(70)
			if (((::com::minigloop::util::AssetsLoader_obj::_ids->__get(i1) == id))){
				HX_STACK_LINE(71)
				return hx::TCast< native::display::Bitmap >::cast(::com::minigloop::util::AssetsLoader_obj::_loaders->__get(i1)->content);
			}
		}
	}
	HX_STACK_LINE(76)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AssetsLoader_obj,getAsset,return )


AssetsLoader_obj::AssetsLoader_obj()
{
}

void AssetsLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AssetsLoader);
	HX_MARK_END_CLASS();
}

void AssetsLoader_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic AssetsLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_ids") ) { return _ids; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_urls") ) { return _urls; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_index") ) { return _index; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_loader") ) { return _loader; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_loaders") ) { return _loaders; }
		if (HX_FIELD_EQ(inName,"addAsset") ) { return addAsset_dyn(); }
		if (HX_FIELD_EQ(inName,"getAsset") ) { return getAsset_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_callback") ) { return _callback; }
		if (HX_FIELD_EQ(inName,"loadAsset") ) { return loadAsset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AssetsLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_ids") ) { _ids=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_urls") ) { _urls=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_index") ) { _index=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_loader") ) { _loader=inValue.Cast< ::native::display::Loader >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_loaders") ) { _loaders=inValue.Cast< Array< ::native::display::Loader > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_callback") ) { _callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AssetsLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_loader"),
	HX_CSTRING("_urls"),
	HX_CSTRING("_ids"),
	HX_CSTRING("_loaders"),
	HX_CSTRING("_index"),
	HX_CSTRING("_callback"),
	HX_CSTRING("init"),
	HX_CSTRING("addAsset"),
	HX_CSTRING("load"),
	HX_CSTRING("loadAsset"),
	HX_CSTRING("getAsset"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::_loader,"_loader");
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::_urls,"_urls");
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::_ids,"_ids");
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::_loaders,"_loaders");
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::_index,"_index");
	HX_MARK_MEMBER_NAME(AssetsLoader_obj::_callback,"_callback");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::_loader,"_loader");
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::_urls,"_urls");
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::_ids,"_ids");
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::_loaders,"_loaders");
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::_index,"_index");
	HX_VISIT_MEMBER_NAME(AssetsLoader_obj::_callback,"_callback");
};

Class AssetsLoader_obj::__mClass;

void AssetsLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.util.AssetsLoader"), hx::TCanCast< AssetsLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AssetsLoader_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace util
