#ifndef INCLUDED_com_minigloop_util_SoundManager
#define INCLUDED_com_minigloop_util_SoundManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,util,SoundManager)
HX_DECLARE_CLASS2(native,events,ErrorEvent)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,TextEvent)
HX_DECLARE_CLASS2(native,media,Sound)
HX_DECLARE_CLASS2(native,media,SoundChannel)
namespace com{
namespace minigloop{
namespace util{


class SoundManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SoundManager_obj OBJ_;
		SoundManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SoundManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundManager"); }

		static ::native::media::Sound _sound; /* REM */ 
		static Array< ::String > _urls; /* REM */ 
		static Array< ::String > _ids; /* REM */ 
		static Array< ::native::media::Sound > _sounds; /* REM */ 
		static Array< ::native::media::SoundChannel > _channels; /* REM */ 
		static int _index; /* REM */ 
		static Dynamic _callback; /* REM */ 
		static ::native::media::SoundChannel _channel; /* REM */ 
		static Void init( );
		static Dynamic init_dyn();

		static Void addSound( ::String url,::String id);
		static Dynamic addSound_dyn();

		static Void load( Dynamic __callback);
		static Dynamic load_dyn();

		static Void loadSound( ::native::events::Event e);
		static Dynamic loadSound_dyn();

		static Void onError( ::native::events::ErrorEvent e);
		static Dynamic onError_dyn();

		static ::native::media::Sound getSound( ::String id);
		static Dynamic getSound_dyn();

		static int getChannelId( ::String id);
		static Dynamic getChannelId_dyn();

		static Void play( ::String id,hx::Null< bool >  loop);
		static Dynamic play_dyn();

		static Void stopAll( );
		static Dynamic stopAll_dyn();

};

} // end namespace com
} // end namespace minigloop
} // end namespace util

#endif /* INCLUDED_com_minigloop_util_SoundManager */ 
