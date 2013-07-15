#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_MiniGame2
#include <com/funbox/bcp/minigame2/MiniGame2.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_player_GamePlayer
#include <com/funbox/bcp/minigame2/entities/player/GamePlayer.h>
#endif
#ifndef INCLUDED_com_minigloop_Game
#include <com/minigloop/Game.h>
#endif
#ifndef INCLUDED_com_minigloop_display_AtlasSprite
#include <com/minigloop/display/AtlasSprite.h>
#endif
#ifndef INCLUDED_com_minigloop_display_VisualObject
#include <com/minigloop/display/VisualObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_ui_Mouse
#include <native/ui/Mouse.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace entities{
namespace player{

Void GamePlayer_obj::__construct(::String clipName,::String aniData,::native::display::Sprite canvas,Float offsetX,Float offsetY)
{
HX_STACK_PUSH("GamePlayer::new","com/funbox/bcp/minigame2/entities/player/GamePlayer.hx",11);
{
	HX_STACK_LINE(12)
	super::__construct(clipName,aniData,canvas,(int)0,(int)0);
	HX_STACK_LINE(14)
	this->mOffsetX = offsetX;
	HX_STACK_LINE(15)
	this->mOffsetY = offsetY;
	HX_STACK_LINE(17)
	this->mAnimationBitmap->gotoAndStop((int)0);
	HX_STACK_LINE(19)
	::native::ui::Mouse_obj::hide();
}
;
	return null();
}

GamePlayer_obj::~GamePlayer_obj() { }

Dynamic GamePlayer_obj::__CreateEmpty() { return  new GamePlayer_obj; }
hx::ObjectPtr< GamePlayer_obj > GamePlayer_obj::__new(::String clipName,::String aniData,::native::display::Sprite canvas,Float offsetX,Float offsetY)
{  hx::ObjectPtr< GamePlayer_obj > result = new GamePlayer_obj();
	result->__construct(clipName,aniData,canvas,offsetX,offsetY);
	return result;}

Dynamic GamePlayer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GamePlayer_obj > result = new GamePlayer_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void GamePlayer_obj::free( ){
{
		HX_STACK_PUSH("GamePlayer::free","com/funbox/bcp/minigame2/entities/player/GamePlayer.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_LINE(38)
		::native::ui::Mouse_obj::show();
		HX_STACK_LINE(40)
		this->super::free();
	}
return null();
}


Void GamePlayer_obj::update( int dt){
{
		HX_STACK_PUSH("GamePlayer::update","com/funbox/bcp/minigame2/entities/player/GamePlayer.hx",22);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(23)
		this->mX = ::com::funbox::bcp::minigame2::Global_obj::minigame->getMouseX();
		HX_STACK_LINE(24)
		this->mY = ::com::funbox::bcp::minigame2::Global_obj::minigame->getMouseY();
		HX_STACK_LINE(26)
		if (((bool(::com::funbox::bcp::minigame2::Global_obj::minigame->isMousePressed()) && bool((this->mAnimationBitmap->getCurrentIndex() == (int)0))))){
			HX_STACK_LINE(26)
			this->mAnimationBitmap->gotoAndPlay((int)0);
		}
		HX_STACK_LINE(30)
		if (((this->mAnimationBitmap->getCurrentIndex() == (this->mAnimationBitmap->getLength() - (int)1)))){
			HX_STACK_LINE(30)
			this->mAnimationBitmap->gotoAndStop((int)0);
		}
		HX_STACK_LINE(34)
		this->super::update(dt);
	}
return null();
}



GamePlayer_obj::GamePlayer_obj()
{
}

void GamePlayer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GamePlayer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GamePlayer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GamePlayer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GamePlayer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GamePlayer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GamePlayer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GamePlayer_obj::__mClass,"__mClass");
};

Class GamePlayer_obj::__mClass;

void GamePlayer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.entities.player.GamePlayer"), hx::TCanCast< GamePlayer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GamePlayer_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace entities
} // end namespace player
