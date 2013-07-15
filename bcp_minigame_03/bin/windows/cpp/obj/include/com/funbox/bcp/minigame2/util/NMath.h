#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NMath
#define INCLUDED_com_funbox_bcp_minigame2_util_NMath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,NMath)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace util{


class NMath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NMath_obj OBJ_;
		NMath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NMath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NMath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NMath"); }

		static Float random( Float min,Float max);
		static Dynamic random_dyn();

};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util

#endif /* INCLUDED_com_funbox_bcp_minigame2_util_NMath */ 
