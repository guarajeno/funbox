#ifndef INCLUDED_com_minigloop_display_VisualObject
#define INCLUDED_com_minigloop_display_VisualObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,minigloop,display,VisualObject)
HX_DECLARE_CLASS3(com,minigloop,util,Vector2D)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace minigloop{
namespace display{


class VisualObject_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef VisualObject_obj OBJ_;
		VisualObject_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< VisualObject_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VisualObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VisualObject"); }

		virtual Void update( int dt);
		Dynamic update_dyn();

		::com::minigloop::util::Vector2D position; /* REM */ 
		::native::display::Sprite _canvas; /* REM */ 
};

} // end namespace com
} // end namespace minigloop
} // end namespace display

#endif /* INCLUDED_com_minigloop_display_VisualObject */ 
