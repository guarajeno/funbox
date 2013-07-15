#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController
#define INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,EntitiesController)
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
namespace engine{


class EntitiesController_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EntitiesController_obj OBJ_;
		EntitiesController_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< EntitiesController_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EntitiesController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EntitiesController"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual Void removeEntitie( ::com::funbox::bcp::minigame2::entities::TouchObject obj);
		Dynamic removeEntitie_dyn();

		virtual ::com::funbox::bcp::minigame2::entities::TouchObject createEntitie( Float x,Float y,::com::minigloop::util::Vector2D speed,int type);
		Dynamic createEntitie_dyn();

		Array< ::com::funbox::bcp::minigame2::entities::TouchObject > mEntities; /* REM */ 
		::native::display::Sprite mCanvas; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine

#endif /* INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController */ 
