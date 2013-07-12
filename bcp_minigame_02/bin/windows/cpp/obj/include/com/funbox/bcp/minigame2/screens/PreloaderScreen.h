#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_PreloaderScreen
#define INCLUDED_com_funbox_bcp_minigame2_screens_PreloaderScreen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/minigloop/ui/Screen.h>
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,PreloaderScreen)
HX_DECLARE_CLASS3(com,minigloop,ui,Screen)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace screens{


class PreloaderScreen_obj : public ::com::minigloop::ui::Screen_obj{
	public:
		typedef ::com::minigloop::ui::Screen_obj super;
		typedef PreloaderScreen_obj OBJ_;
		PreloaderScreen_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< PreloaderScreen_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PreloaderScreen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PreloaderScreen"); }

		virtual Void update( int dt);

		virtual Void onDataLoaded( );
		Dynamic onDataLoaded_dyn();

		virtual Void onAssetsLoaded( );
		Dynamic onAssetsLoaded_dyn();

		virtual Void onSoundsLoaded( );
		Dynamic onSoundsLoaded_dyn();

		bool _isSoundsDownloaded; /* REM */ 
		bool _isDataDownloaded; /* REM */ 
		bool _isAssetsDownloaded; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens

#endif /* INCLUDED_com_funbox_bcp_minigame2_screens_PreloaderScreen */ 
