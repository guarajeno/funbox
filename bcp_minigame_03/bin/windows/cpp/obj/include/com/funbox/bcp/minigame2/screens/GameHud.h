#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameHud
#define INCLUDED_com_funbox_bcp_minigame2_screens_GameHud

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,entities,BaseActor)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,screens,GameHud)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,text,TextField)
HX_DECLARE_CLASS2(native,text,TextFormat)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace screens{


class GameHud_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GameHud_obj OBJ_;
		GameHud_obj();
		Void __construct(::native::display::Sprite canvas);

	public:
		static hx::ObjectPtr< GameHud_obj > __new(::native::display::Sprite canvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameHud_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameHud"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual Void SetTime( int value);
		Dynamic SetTime_dyn();

		virtual int GetTime( );
		Dynamic GetTime_dyn();

		virtual Void SetScore( int value);
		Dynamic SetScore_dyn();

		virtual int GetScore( );
		Dynamic GetScore_dyn();

		::native::text::TextField mTF_Time; /* REM */ 
		::native::text::TextField mTF_Score; /* REM */ 
		::native::text::TextFormat mTextFormat; /* REM */ 
		int mTime; /* REM */ 
		int mScore; /* REM */ 
		::com::funbox::bcp::minigame2::entities::BaseActor mPuntajeSprite; /* REM */ 
		::native::display::Sprite mCanvas; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens

#endif /* INCLUDED_com_funbox_bcp_minigame2_screens_GameHud */ 
