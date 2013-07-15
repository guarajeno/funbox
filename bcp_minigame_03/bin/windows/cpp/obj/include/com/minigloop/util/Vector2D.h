#ifndef INCLUDED_com_minigloop_util_Vector2D
#define INCLUDED_com_minigloop_util_Vector2D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,util,Vector2D)
namespace com{
namespace minigloop{
namespace util{


class Vector2D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector2D_obj OBJ_;
		Vector2D_obj();
		Void __construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y);

	public:
		static hx::ObjectPtr< Vector2D_obj > __new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vector2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector2D"); }

		Float y; /* REM */ 
		Float x; /* REM */ 
};

} // end namespace com
} // end namespace minigloop
} // end namespace util

#endif /* INCLUDED_com_minigloop_util_Vector2D */ 
