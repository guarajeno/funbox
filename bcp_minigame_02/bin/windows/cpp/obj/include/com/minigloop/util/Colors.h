#ifndef INCLUDED_com_minigloop_util_Colors
#define INCLUDED_com_minigloop_util_Colors

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,util,Colors)
namespace com{
namespace minigloop{
namespace util{


class Colors_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Colors_obj OBJ_;
		Colors_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Colors_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Colors_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Colors"); }

		static int bg; /* REM */ 
		static int fps; /* REM */ 
		static int ms; /* REM */ 
		static int mem; /* REM */ 
		static int memmax; /* REM */ 
		static ::String bgCSS; /* REM */ 
		static ::String fpsCSS; /* REM */ 
		static ::String msCSS; /* REM */ 
		static ::String memCSS; /* REM */ 
		static ::String memmaxCSS; /* REM */ 
};

} // end namespace com
} // end namespace minigloop
} // end namespace util

#endif /* INCLUDED_com_minigloop_util_Colors */ 
