#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NUtils
#define INCLUDED_com_funbox_bcp_minigame2_util_NUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,NUtils)
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


class NUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NUtils_obj OBJ_;
		NUtils_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NUtils"); }

		static ::native::display::Bitmap getAsset( ::String assetName);
		static Dynamic getAsset_dyn();

		static int getValueFromProbabilityChart( int numOptions,int numProbabilitys);
		static Dynamic getValueFromProbabilityChart_dyn();

		static ::String parseMillisecondsInClockFormat( int milliseconds);
		static Dynamic parseMillisecondsInClockFormat_dyn();

		static ::String getDigitsByValue( int value,int num_digits);
		static Dynamic getDigitsByValue_dyn();

};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util

#endif /* INCLUDED_com_funbox_bcp_minigame2_util_NUtils */ 
