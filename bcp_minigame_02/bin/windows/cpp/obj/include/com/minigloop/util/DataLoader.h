#ifndef INCLUDED_com_minigloop_util_DataLoader
#define INCLUDED_com_minigloop_util_DataLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,util,DataLoader)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,net,URLLoader)
namespace com{
namespace minigloop{
namespace util{


class DataLoader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DataLoader_obj OBJ_;
		DataLoader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DataLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DataLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DataLoader"); }

		static ::native::net::URLLoader _loader; /* REM */ 
		static Array< ::String > _urls; /* REM */ 
		static Array< ::String > _ids; /* REM */ 
		static Array< ::native::net::URLLoader > _loaders; /* REM */ 
		static int _index; /* REM */ 
		static Dynamic _callback; /* REM */ 
		static Void init( );
		static Dynamic init_dyn();

		static Void addData( ::String url,::String id);
		static Dynamic addData_dyn();

		static Void load( Dynamic __callback);
		static Dynamic load_dyn();

		static Void loadData( ::native::events::Event e);
		static Dynamic loadData_dyn();

		static ::String getData( ::String id);
		static Dynamic getData_dyn();

};

} // end namespace com
} // end namespace minigloop
} // end namespace util

#endif /* INCLUDED_com_minigloop_util_DataLoader */ 
