#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_EffectManager
#define INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_EffectManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,BaseEffect)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,EffectManager)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,SpriteAndTextEffect)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
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
namespace effectManager{


class EffectManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EffectManager_obj OBJ_;
		EffectManager_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< EffectManager_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EffectManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EffectManager"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual ::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect createSpriteAndTextEffect( ::String clipName,::String aniData,::String clipNameOther,::String aniDataOther,::com::minigloop::util::Vector2D pos1,::com::minigloop::util::Vector2D pos2);
		Dynamic createSpriteAndTextEffect_dyn();

		virtual ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect createEffect( Float x,Float y,::String clipName,::String aniData);
		Dynamic createEffect_dyn();

		Array< ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect > mEffectsRepo; /* REM */ 
		::native::display::Sprite mCanvas; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
} // end namespace effectManager

#endif /* INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_EffectManager */ 
