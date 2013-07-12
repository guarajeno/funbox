#ifndef INCLUDED_com_funbox_bcp_minigame2_util_AlphaTweener
#define INCLUDED_com_funbox_bcp_minigame2_util_AlphaTweener

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,AlphaTweener)
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace util{


class AlphaTweener_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AlphaTweener_obj OBJ_;
		AlphaTweener_obj();
		Void __construct(::native::display::Bitmap bitmap,Float _dt,Dynamic __callback);

	public:
		static hx::ObjectPtr< AlphaTweener_obj > __new(::native::display::Bitmap bitmap,Float _dt,Dynamic __callback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AlphaTweener_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AlphaTweener"); }

		virtual Void update( int dt);
		Dynamic update_dyn();

		bool _isPaused; /* REM */ 
		Float _value; /* REM */ 
		Float _dt; /* REM */ 
		Float _t; /* REM */ 
		Dynamic _callback; /* REM */ 
		::native::display::Bitmap _obj; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util

#endif /* INCLUDED_com_funbox_bcp_minigame2_util_AlphaTweener */ 
