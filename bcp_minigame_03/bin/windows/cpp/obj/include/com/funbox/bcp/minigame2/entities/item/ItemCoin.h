#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemCoin
#define INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemCoin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,TouchObject)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,entities,item,ItemCoin)
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
namespace item{


class ItemCoin_obj : public ::com::funbox::bcp::minigame2::entities::TouchObject_obj{
	public:
		typedef ::com::funbox::bcp::minigame2::entities::TouchObject_obj super;
		typedef ItemCoin_obj OBJ_;
		ItemCoin_obj();
		Void __construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed);

	public:
		static hx::ObjectPtr< ItemCoin_obj > __new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y,::com::minigloop::util::Vector2D speed);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ItemCoin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ItemCoin"); }

		virtual Void update( int dt);

};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace item

#endif /* INCLUDED_com_funbox_bcp_minigame2_entities_item_ItemCoin */ 