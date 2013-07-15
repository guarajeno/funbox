#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#define INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,TouchObject)
HX_DECLARE_CLASS3(com,minigloop,util,Vector2D)
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
namespace entities{


class TouchObject_obj : public ::com::funbox::bcp::minigame2::entities::BaseActor_obj{
	public:
		typedef ::com::funbox::bcp::minigame2::entities::BaseActor_obj super;
		typedef TouchObject_obj OBJ_;
		TouchObject_obj();
		Void __construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed);

	public:
		static hx::ObjectPtr< TouchObject_obj > __new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchObject"); }

		virtual Void free( );

		virtual Void update( int dt);

		virtual Void makePuffEffect( );
		Dynamic makePuffEffect_dyn();

		virtual Void setObjectType( int value);
		Dynamic setObjectType_dyn();

		virtual Void setSpeed( ::com::minigloop::util::Vector2D speed);
		Dynamic setSpeed_dyn();

		virtual bool getCanFall( );
		Dynamic getCanFall_dyn();

		virtual int type( );
		Dynamic type_dyn();

		::com::minigloop::util::Vector2D mSpeed; /* REM */ 
		int mAppHeight; /* REM */ 
		int mAppWidth; /* REM */ 
		int mType; /* REM */ 
		bool mAreTouchableItems; /* REM */ 
		bool mCanFall; /* REM */ 
		bool isDead; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities

#endif /* INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject */ 
