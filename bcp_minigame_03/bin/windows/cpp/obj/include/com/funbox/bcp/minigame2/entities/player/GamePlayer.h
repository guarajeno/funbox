#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_player_GamePlayer
#define INCLUDED_com_funbox_bcp_minigame2_entities_player_GamePlayer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,entities,player,GamePlayer)
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
namespace player{


class GamePlayer_obj : public ::com::funbox::bcp::minigame2::entities::BaseActor_obj{
	public:
		typedef ::com::funbox::bcp::minigame2::entities::BaseActor_obj super;
		typedef GamePlayer_obj OBJ_;
		GamePlayer_obj();
		Void __construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float offsetX,Float offsetY);

	public:
		static hx::ObjectPtr< GamePlayer_obj > __new(::String clipName,::String aniData,::native::display::Sprite canvas,Float offsetX,Float offsetY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GamePlayer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GamePlayer"); }

		virtual Void free( );

		virtual Void update( int dt);

};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace player

#endif /* INCLUDED_com_funbox_bcp_minigame2_entities_player_GamePlayer */ 
