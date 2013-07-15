#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_enemy_BotCollector
#define INCLUDED_com_funbox_bcp_minigame2_entities_enemy_BotCollector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,TouchObject)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,entities,enemy,BotCollector)
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
namespace enemy{


class BotCollector_obj : public ::com::funbox::bcp::minigame2::entities::TouchObject_obj{
	public:
		typedef ::com::funbox::bcp::minigame2::entities::TouchObject_obj super;
		typedef BotCollector_obj OBJ_;
		BotCollector_obj();
		Void __construct(::String clipName,::String aniData,::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< BotCollector_obj > __new(::String clipName,::String aniData,::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BotCollector_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BotCollector"); }

		virtual Void update( int dt);

		virtual Void addObjectInGround( ::com::funbox::bcp::minigame2::entities::TouchObject touchableObject);
		Dynamic addObjectInGround_dyn();

		::com::funbox::bcp::minigame2::entities::TouchObject mTouchObjectToCatch; /* REM */ 
		Array< ::com::funbox::bcp::minigame2::entities::TouchObject > mEntities; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace enemy

#endif /* INCLUDED_com_funbox_bcp_minigame2_entities_enemy_BotCollector */ 
