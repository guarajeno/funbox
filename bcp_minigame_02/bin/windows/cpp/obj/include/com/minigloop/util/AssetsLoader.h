#ifndef INCLUDED_com_minigloop_util_AssetsLoader
#define INCLUDED_com_minigloop_util_AssetsLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,util,AssetsLoader)
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Loader)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace minigloop{
namespace util{


class AssetsLoader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AssetsLoader_obj OBJ_;
		AssetsLoader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AssetsLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AssetsLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AssetsLoader"); }

		static ::native::display::Loader _loader; /* REM */ 
		static Array< ::String > _urls; /* REM */ 
		static Array< ::String > _ids; /* REM */ 
		static Array< ::native::display::Loader > _loaders; /* REM */ 
		static int _index; /* REM */ 
		static Dynamic _callback; /* REM */ 
		static Void init( );
		static Dynamic init_dyn();

		static Void addAsset( ::String url,::String id);
		static Dynamic addAsset_dyn();

		static Void load( Dynamic __callback);
		static Dynamic load_dyn();

		static Void loadAsset( ::native::events::Event e);
		static Dynamic loadAsset_dyn();

		static ::native::display::Bitmap getAsset( ::String id);
		static Dynamic getAsset_dyn();

};

} // end namespace com
} // end namespace minigloop
} // end namespace util

#endif /* INCLUDED_com_minigloop_util_AssetsLoader */ 
