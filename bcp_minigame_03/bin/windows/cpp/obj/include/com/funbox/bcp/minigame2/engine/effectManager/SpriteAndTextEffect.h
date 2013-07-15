#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_SpriteAndTextEffect
#define INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_SpriteAndTextEffect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.h>
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,BaseEffect)
HX_DECLARE_CLASS6(com,funbox,bcp,minigame2,engine,effectManager,SpriteAndTextEffect)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS3(com,minigloop,display,AtlasSprite)
HX_DECLARE_CLASS3(com,minigloop,display,VisualObject)
HX_DECLARE_CLASS3(com,minigloop,util,Vector2D)
HX_DECLARE_CLASS2(native,display,Bitmap)
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


class SpriteAndTextEffect_obj : public ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect_obj{
	public:
		typedef ::com::funbox::bcp::minigame2::engine::effectManager::BaseEffect_obj super;
		typedef SpriteAndTextEffect_obj OBJ_;
		SpriteAndTextEffect_obj();
		Void __construct(::String clipName,::String aniData,::String clipNameOther,::String aniDataOther,::native::display::Sprite canvas,::com::minigloop::util::Vector2D pos1,::com::minigloop::util::Vector2D pos2);

	public:
		static hx::ObjectPtr< SpriteAndTextEffect_obj > __new(::String clipName,::String aniData,::String clipNameOther,::String aniDataOther,::native::display::Sprite canvas,::com::minigloop::util::Vector2D pos1,::com::minigloop::util::Vector2D pos2);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SpriteAndTextEffect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SpriteAndTextEffect"); }

		virtual Void free( );

		virtual Void update( int dt);

		::native::display::Sprite mClipContainer; /* REM */ 
		Float mOtherY; /* REM */ 
		Float mOtherX; /* REM */ 
		::com::minigloop::display::AtlasSprite mAnimationBitmapOther; /* REM */ 
		::native::display::Bitmap mBitmapOther; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
} // end namespace effectManager

#endif /* INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_SpriteAndTextEffect */ 
