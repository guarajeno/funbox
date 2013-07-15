#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NInterval
#define INCLUDED_com_funbox_bcp_minigame2_util_NInterval

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,NInterval)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace util{


class NInterval_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NInterval_obj OBJ_;
		NInterval_obj();
		Void __construct(Dynamic callbackFunc,int timeLimit);

	public:
		static hx::ObjectPtr< NInterval_obj > __new(Dynamic callbackFunc,int timeLimit);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NInterval_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NInterval"); }

		virtual Void update( int dt);
		Dynamic update_dyn();

		int mTimeCounter; /* REM */ 
		int mTimeLimit; /* REM */ 
		Dynamic mCallbackFunc; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util

#endif /* INCLUDED_com_funbox_bcp_minigame2_util_NInterval */ 
