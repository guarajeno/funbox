#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#define INCLUDED_com_funbox_bcp_minigame2_Global

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,funbox,bcp,minigame2,Global)
HX_DECLARE_CLASS4(com,funbox,bcp,minigame2,MiniGame2)
HX_DECLARE_CLASS2(com,minigloop,Game)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Stage)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{


class Global_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Global_obj OBJ_;
		Global_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Global_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Global_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Global"); }

		static int minPlayerSpeed; /* REM */ 
		static int maxPlayerSpeed; /* REM */ 
		static int enemyFrequency; /* REM */ 
		static int ScreenOffsetWidth; /* REM */ 
		static int ScreenOffsetHeight; /* REM */ 
		static ::com::funbox::bcp::minigame2::MiniGame2 minigame; /* REM */ 
		static ::native::display::Stage stage; /* REM */ 
		static int StageWidth; /* REM */ 
		static int StageHeight; /* REM */ 
		static int totalPoints; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2

#endif /* INCLUDED_com_funbox_bcp_minigame2_Global */ 
