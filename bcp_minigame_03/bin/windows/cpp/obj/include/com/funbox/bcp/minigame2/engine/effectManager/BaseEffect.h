#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect
#define INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,BaseEffect)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
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
namespace effectManager{


class BaseEffect_obj : public ::com::funbox::bcp::minigame2::entities::BaseActor_obj{
	public:
		typedef ::com::funbox::bcp::minigame2::entities::BaseActor_obj super;
		typedef BaseEffect_obj OBJ_;
		BaseEffect_obj();
		Void __construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y);

	public:
		static hx::ObjectPtr< BaseEffect_obj > __new(::String clipName,::String aniData,::native::display::Sprite canvas,Float x,Float y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BaseEffect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BaseEffect"); }

		virtual Void update( int dt);

		virtual Void SetDelayTimeToStart( int time);
		Dynamic SetDelayTimeToStart_dyn();

		virtual Void DieWithAlpha( bool value);
		Dynamic DieWithAlpha_dyn();

		Float mAlphaFactor; /* REM */ 
		bool mDieWithAlpha; /* REM */ 
		int mDelayToStart; /* REM */ 
		bool isDead; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
} // end namespace effectManager

#endif /* INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect */ 
