#include <hxcpp.h>

#ifndef INCLUDED_com_minigloop_util_DataLoader
#include <com/minigloop/util/DataLoader.h>
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

Void DataLoader_obj::__construct()
{
HX_STACK_PUSH("DataLoader::new","com/minigloop/util/DataLoader.hx",23);
{
}
;
	return null();
}

DataLoader_obj::~DataLoader_obj() { }

Dynamic DataLoader_obj::__CreateEmpty() { return  new DataLoader_obj; }
hx::ObjectPtr< DataLoader_obj > DataLoader_obj::__new()
{  hx::ObjectPtr< DataLoader_obj > result = new DataLoader_obj();
	result->__construct();
	return result;}

Dynamic DataLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DataLoader_obj > result = new DataLoader_obj();
	result->__construct();
	return result;}

::native::net::URLLoader DataLoader_obj::_loader;

Array< ::String > DataLoader_obj::_urls;

Array< ::String > DataLoader_obj::_ids;

Array< ::native::net::URLLoader > DataLoader_obj::_loaders;

int DataLoader_obj::_index;

Dynamic DataLoader_obj::_callback;

Void DataLoader_obj::init( ){
{
		HX_STACK_PUSH("DataLoader::init","com/minigloop/util/DataLoader.hx",28);
		HX_STACK_LINE(29)
		::com::minigloop::util::DataLoader_obj::_urls = Array_obj< ::String >::__new();
		HX_STACK_LINE(30)
		::com::minigloop::util::DataLoader_obj::_ids = Array_obj< ::String >::__new();
		HX_STACK_LINE(31)
		::com::minigloop::util::DataLoader_obj::_loaders = Array_obj< ::native::net::URLLoader >::__new();
		HX_STACK_LINE(33)
		::com::minigloop::util::DataLoader_obj::_index = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(DataLoader_obj,init,(void))

Void DataLoader_obj::addData( ::String url,::String id){
{
		HX_STACK_PUSH("DataLoader::addData","com/minigloop/util/DataLoader.hx",37);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(id,"id");
		HX_STACK_LINE(38)
		::com::minigloop::util::DataLoader_obj::_urls->push(url);
		HX_STACK_LINE(39)
		::com::minigloop::util::DataLoader_obj::_ids->push(id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DataLoader_obj,addData,(void))

Void DataLoader_obj::load( Dynamic __callback){
{
		HX_STACK_PUSH("DataLoader::load","com/minigloop/util/DataLoader.hx",43);
		HX_STACK_ARG(__callback,"__callback");
		HX_STACK_LINE(44)
		::com::minigloop::util::DataLoader_obj::_callback = __callback;
		HX_STACK_LINE(45)
		::com::minigloop::util::DataLoader_obj::loadData(null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DataLoader_obj,load,(void))

Void DataLoader_obj::loadData( ::native::events::Event e){
{
		HX_STACK_PUSH("DataLoader::loadData","com/minigloop/util/DataLoader.hx",49);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(49)
		if (((::com::minigloop::util::DataLoader_obj::_index < ::com::minigloop::util::DataLoader_obj::_urls->length))){
			HX_STACK_LINE(52)
			::native::net::URLRequest request = ::native::net::URLRequest_obj::__new(::com::minigloop::util::DataLoader_obj::_urls->__get(::com::minigloop::util::DataLoader_obj::_index));		HX_STACK_VAR(request,"request");
			HX_STACK_LINE(53)
			::com::minigloop::util::DataLoader_obj::_loader = ::native::net::URLLoader_obj::__new(null());
			HX_STACK_LINE(54)
			::com::minigloop::util::DataLoader_obj::_loader->load(request);
			HX_STACK_LINE(55)
			::com::minigloop::util::DataLoader_obj::_loader->addEventListener(::native::events::Event_obj::COMPLETE,::com::minigloop::util::DataLoader_obj::loadData_dyn(),null(),null(),null());
			HX_STACK_LINE(57)
			::com::minigloop::util::DataLoader_obj::_loaders->push(::com::minigloop::util::DataLoader_obj::_loader);
			HX_STACK_LINE(58)
			(::com::minigloop::util::DataLoader_obj::_index)++;
		}
		else{
			HX_STACK_LINE(61)
			::com::minigloop::util::DataLoader_obj::_callback();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DataLoader_obj,loadData,(void))

::String DataLoader_obj::getData( ::String id){
	HX_STACK_PUSH("DataLoader::getData","com/minigloop/util/DataLoader.hx",67);
	HX_STACK_ARG(id,"id");
	HX_STACK_LINE(68)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(70)
	{
		HX_STACK_LINE(70)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::com::minigloop::util::DataLoader_obj::_urls->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(70)
		while(((_g1 < _g))){
			HX_STACK_LINE(70)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(72)
			if (((::com::minigloop::util::DataLoader_obj::_ids->__get(i1) == id))){
				HX_STACK_LINE(73)
				return ::com::minigloop::util::DataLoader_obj::_loaders->__get(i1)->data;
			}
		}
	}
	HX_STACK_LINE(78)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DataLoader_obj,getData,return )


DataLoader_obj::DataLoader_obj()
{
}

void DataLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DataLoader);
	HX_MARK_END_CLASS();
}

void DataLoader_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic DataLoader_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"addData") ) { return addData_dyn(); }
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_loaders") ) { return _loaders; }
		if (HX_FIELD_EQ(inName,"loadData") ) { return loadData_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_callback") ) { return _callback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DataLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_loader") ) { _loader=inValue.Cast< ::native::net::URLLoader >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_loaders") ) { _loaders=inValue.Cast< Array< ::native::net::URLLoader > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_callback") ) { _callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DataLoader_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("addData"),
	HX_CSTRING("load"),
	HX_CSTRING("loadData"),
	HX_CSTRING("getData"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DataLoader_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DataLoader_obj::_loader,"_loader");
	HX_MARK_MEMBER_NAME(DataLoader_obj::_urls,"_urls");
	HX_MARK_MEMBER_NAME(DataLoader_obj::_ids,"_ids");
	HX_MARK_MEMBER_NAME(DataLoader_obj::_loaders,"_loaders");
	HX_MARK_MEMBER_NAME(DataLoader_obj::_index,"_index");
	HX_MARK_MEMBER_NAME(DataLoader_obj::_callback,"_callback");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DataLoader_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DataLoader_obj::_loader,"_loader");
	HX_VISIT_MEMBER_NAME(DataLoader_obj::_urls,"_urls");
	HX_VISIT_MEMBER_NAME(DataLoader_obj::_ids,"_ids");
	HX_VISIT_MEMBER_NAME(DataLoader_obj::_loaders,"_loaders");
	HX_VISIT_MEMBER_NAME(DataLoader_obj::_index,"_index");
	HX_VISIT_MEMBER_NAME(DataLoader_obj::_callback,"_callback");
};

Class DataLoader_obj::__mClass;

void DataLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.util.DataLoader"), hx::TCanCast< DataLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DataLoader_obj::__boot()
{
}

} // end namespace com
} // end namespace minigloop
} // end namespace util
