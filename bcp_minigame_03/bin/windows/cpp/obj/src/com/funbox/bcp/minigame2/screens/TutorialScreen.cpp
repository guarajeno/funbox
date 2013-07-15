#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_BaseEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/BaseEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_EffectManager
#include <com/funbox/bcp/minigame2/engine/effectManager/EffectManager.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_effectManager_SpriteAndTextEffect
#include <com/funbox/bcp/minigame2/engine/effectManager/SpriteAndTextEffect.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_GameScreen
#include <com/funbox/bcp/minigame2/screens/GameScreen.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_TutorialScreen
#include <com/funbox/bcp/minigame2/screens/TutorialScreen.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NInterval
#include <com/funbox/bcp/minigame2/util/NInterval.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_Screen
#include <com/minigloop/ui/Screen.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_ScreenManager
#include <com/minigloop/ui/ScreenManager.h>
#endif
#ifndef INCLUDED_com_minigloop_util_Vector2D
#include <com/minigloop/util/Vector2D.h>
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
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace screens{

Void TutorialScreen_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("TutorialScreen::new","com/funbox/bcp/minigame2/screens/TutorialScreen.hx",56);
{
	HX_STACK_LINE(57)
	super::__construct(canvas);
	HX_STACK_LINE(59)
	this->mCanvasTutorial = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(60)
	this->mCanvasEffect = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(61)
	this->mCanvasMouse = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(63)
	this->_canvas->addChild(this->mCanvasTutorial);
	HX_STACK_LINE(64)
	this->_canvas->addChild(this->mCanvasEffect);
	HX_STACK_LINE(65)
	this->_canvas->addChild(this->mCanvasMouse);
	HX_STACK_LINE(67)
	this->mEffectManager = ::com::funbox::bcp::minigame2::engine::effectManager::EffectManager_obj::__new(this->mCanvasEffect);
	HX_STACK_LINE(69)
	this->mBGSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_bg"),null(),this->mCanvasTutorial,(int)0,(int)0);
	HX_STACK_LINE(70)
	this->mBGMaskSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_background_mask"),null(),this->mCanvasTutorial,(int)0,(int)0);
	HX_STACK_LINE(71)
	this->mTutorialSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_tutorial_text"),null(),this->mCanvasTutorial,(int)0,(int)0);
	HX_STACK_LINE(73)
	this->mTutorialBagMoneySprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_tutorial_bag_money"),null(),this->mCanvasTutorial,(int)0,(int)0);
	HX_STACK_LINE(74)
	this->mTutorialTicketMoneySprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_tutorial_ticket_money"),null(),this->mCanvasTutorial,(int)0,(int)0);
	HX_STACK_LINE(75)
	this->mTutorialHandSprite = ::com::funbox::bcp::minigame2::entities::BaseActor_obj::__new(HX_CSTRING("spMinigame02_tutorial_mouseHand"),null(),this->mCanvasMouse,(int)0,(int)0);
	HX_STACK_LINE(77)
	this->mTutorialBagMoneySprite->setX((((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialHandSprite->getWidth()) / Float((int)2))) - (int)100));
	HX_STACK_LINE(78)
	this->mTutorialBagMoneySprite->setY(((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialHandSprite->getHeight()) / Float((int)2))));
	HX_STACK_LINE(80)
	this->mTutorialTicketMoneySprite->setX((((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialTicketMoneySprite->getWidth()) / Float((int)2))) + (int)100));
	HX_STACK_LINE(81)
	this->mTutorialTicketMoneySprite->setY(((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialTicketMoneySprite->getHeight()) / Float((int)2))));
	HX_STACK_LINE(83)
	this->mTutorialSprite->setX(((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialSprite->getWidth()) / Float((int)2))));
	HX_STACK_LINE(84)
	this->mTutorialSprite->setY((((Float(::com::funbox::bcp::minigame2::Global_obj::StageHeight) / Float((int)2)) - (Float(this->mTutorialSprite->getHeight()) / Float((int)2))) - (int)20));
	HX_STACK_LINE(86)
	this->mTutorialHandSprite->setX(((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialHandSprite->getWidth()) / Float((int)2))));
	HX_STACK_LINE(87)
	this->mTutorialHandSprite->setY((((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialHandSprite->getHeight()) / Float((int)2))) + (int)20));
	HX_STACK_LINE(89)
	this->mTutorialSprite->setAlpha(0.0);
	HX_STACK_LINE(91)
	this->mBagInitX = (((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialHandSprite->getWidth()) / Float((int)2))) - (int)100);
	HX_STACK_LINE(92)
	this->mMoneyInitX = (((Float(::com::funbox::bcp::minigame2::Global_obj::StageWidth) / Float((int)2)) - (Float(this->mTutorialTicketMoneySprite->getWidth()) / Float((int)2))) + (int)100);
	HX_STACK_LINE(94)
	this->mCurrentState = ::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_SHOW_TUTORIAL;
}
;
	return null();
}

TutorialScreen_obj::~TutorialScreen_obj() { }

Dynamic TutorialScreen_obj::__CreateEmpty() { return  new TutorialScreen_obj; }
hx::ObjectPtr< TutorialScreen_obj > TutorialScreen_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< TutorialScreen_obj > result = new TutorialScreen_obj();
	result->__construct(canvas);
	return result;}

Dynamic TutorialScreen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TutorialScreen_obj > result = new TutorialScreen_obj();
	result->__construct(inArgs[0]);
	return result;}

Void TutorialScreen_obj::destroy( ){
{
		HX_STACK_PUSH("TutorialScreen::destroy","com/funbox/bcp/minigame2/screens/TutorialScreen.hx",184);
		HX_STACK_THIS(this);
		HX_STACK_LINE(185)
		this->mTutorialHandSprite->free();
		HX_STACK_LINE(187)
		if (((this->mTutorialBagMoneySprite != null()))){
			HX_STACK_LINE(187)
			this->mTutorialBagMoneySprite->free();
		}
		HX_STACK_LINE(191)
		if (((this->mTutorialTicketMoneySprite != null()))){
			HX_STACK_LINE(191)
			this->mTutorialTicketMoneySprite->free();
		}
		HX_STACK_LINE(195)
		this->mBGSprite->free();
		HX_STACK_LINE(196)
		this->mBGMaskSprite->free();
		HX_STACK_LINE(197)
		this->mTutorialSprite->free();
		HX_STACK_LINE(198)
		this->mEffectManager->free();
		HX_STACK_LINE(200)
		this->_canvas->removeChild(this->mCanvasEffect);
		HX_STACK_LINE(201)
		this->_canvas->removeChild(this->mCanvasTutorial);
		HX_STACK_LINE(203)
		this->mTutorialHandSprite = null();
		HX_STACK_LINE(204)
		this->mTutorialBagMoneySprite = null();
		HX_STACK_LINE(205)
		this->mTutorialTicketMoneySprite = null();
		HX_STACK_LINE(207)
		this->mEffectManager = null();
		HX_STACK_LINE(208)
		this->mBGSprite = null();
		HX_STACK_LINE(209)
		this->mBGMaskSprite = null();
		HX_STACK_LINE(210)
		this->mTutorialSprite = null();
		HX_STACK_LINE(211)
		this->mInterval = null();
		HX_STACK_LINE(213)
		this->super::destroy();
		HX_STACK_LINE(213)
		return null();
	}
return null();
}


Void TutorialScreen_obj::update( int dt){
{
		HX_STACK_PUSH("TutorialScreen::update","com/funbox/bcp/minigame2/screens/TutorialScreen.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(107)
		this->mBGSprite->update(dt);
		HX_STACK_LINE(108)
		this->mBGMaskSprite->update(dt);
		HX_STACK_LINE(109)
		this->mTutorialSprite->update(dt);
		HX_STACK_LINE(110)
		this->mEffectManager->update(dt);
		HX_STACK_LINE(112)
		if (((this->mTutorialHandSprite != null()))){
			HX_STACK_LINE(112)
			this->mTutorialHandSprite->update(dt);
		}
		HX_STACK_LINE(113)
		if (((this->mTutorialBagMoneySprite != null()))){
			HX_STACK_LINE(113)
			this->mTutorialBagMoneySprite->update(dt);
		}
		HX_STACK_LINE(114)
		if (((this->mTutorialTicketMoneySprite != null()))){
			HX_STACK_LINE(114)
			this->mTutorialTicketMoneySprite->update(dt);
		}
		HX_STACK_LINE(116)
		int _switch_1 = (this->mCurrentState);
		if (  ( _switch_1==::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_SHOW_TUTORIAL)){
			HX_STACK_LINE(117)
			if (((this->mTutorialSprite->getAlpha() >= 1.0))){
				HX_STACK_LINE(119)
				this->mTutorialSprite->setAlpha(1.0);
				HX_STACK_LINE(121)
				this->mCurrentState = ::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_MOUSE_LEFT;
			}
			else{
				HX_STACK_LINE(123)
				this->mTutorialSprite->setAlpha((this->mTutorialSprite->getAlpha() + (0.0008 * dt)));
			}
		}
		else if (  ( _switch_1==::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_MOUSE_LEFT)){
			HX_STACK_LINE(127)
			Float nx1 = (this->mTutorialHandSprite->getX() - (0.15 * dt));		HX_STACK_VAR(nx1,"nx1");
			HX_STACK_LINE(128)
			this->mTutorialHandSprite->setX(nx1);
			HX_STACK_LINE(130)
			if (((nx1 <= this->mBagInitX))){
				HX_STACK_LINE(131)
				this->mCurrentState = ::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_MOUSE_RIGHT;
				HX_STACK_LINE(133)
				::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect effect = this->mEffectManager->createSpriteAndTextEffect(HX_CSTRING("spMinigame02_tutorial_check_secure"),HX_CSTRING("spMinigame02_tutorial_check_secure"),HX_CSTRING("spMinigame02_tutorial_score_500"),null(),::com::minigloop::util::Vector2D_obj::__new((this->mBagInitX + (int)20),(this->mTutorialTicketMoneySprite->getY() + (int)7)),::com::minigloop::util::Vector2D_obj::__new((int)-20,(int)-43));		HX_STACK_VAR(effect,"effect");
				HX_STACK_LINE(138)
				effect->DieWithAlpha(true);
				HX_STACK_LINE(140)
				this->mEffectManager->createEffect((this->mBagInitX + (int)8),(this->mTutorialTicketMoneySprite->getY() + (int)8),HX_CSTRING("spMinigame02_ani_effect_puff"),HX_CSTRING("spMinigame02_ani_effect_puff"));
				HX_STACK_LINE(143)
				this->mTutorialBagMoneySprite->free();
				HX_STACK_LINE(144)
				this->mTutorialBagMoneySprite = null();
			}
		}
		else if (  ( _switch_1==::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_MOUSE_RIGHT)){
			HX_STACK_LINE(147)
			Float nx2 = (this->mTutorialHandSprite->getX() + (0.15 * dt));		HX_STACK_VAR(nx2,"nx2");
			HX_STACK_LINE(148)
			this->mTutorialHandSprite->setX(nx2);
			HX_STACK_LINE(150)
			if (((nx2 >= this->mMoneyInitX))){
				HX_STACK_LINE(151)
				this->mCurrentState = ::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_WAIT;
				HX_STACK_LINE(152)
				this->mInterval = ::com::funbox::bcp::minigame2::util::NInterval_obj::__new(this->onFinishWait_dyn(),(int)400);
				HX_STACK_LINE(154)
				::com::funbox::bcp::minigame2::engine::effectManager::SpriteAndTextEffect effect2 = this->mEffectManager->createSpriteAndTextEffect(HX_CSTRING("spMinigame02_tutorial_check_secure"),HX_CSTRING("spMinigame02_tutorial_check_secure"),HX_CSTRING("spMinigame02_tutorial_score_100"),null(),::com::minigloop::util::Vector2D_obj::__new((this->mMoneyInitX + (int)8),(this->mTutorialTicketMoneySprite->getY() + (int)7)),::com::minigloop::util::Vector2D_obj::__new((int)-20,(int)-43));		HX_STACK_VAR(effect2,"effect2");
				HX_STACK_LINE(159)
				effect2->DieWithAlpha(true);
				HX_STACK_LINE(161)
				this->mEffectManager->createEffect((this->mMoneyInitX + (int)8),(this->mTutorialTicketMoneySprite->getY() + (int)8),HX_CSTRING("spMinigame02_ani_effect_puff"),HX_CSTRING("spMinigame02_ani_effect_puff"));
				HX_STACK_LINE(164)
				this->mTutorialTicketMoneySprite->free();
				HX_STACK_LINE(165)
				this->mTutorialTicketMoneySprite = null();
			}
		}
		else if (  ( _switch_1==::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_WAIT)){
			HX_STACK_LINE(167)
			if (((this->mInterval != null()))){
				HX_STACK_LINE(168)
				this->mInterval->update(dt);
			}
		}
		else if (  ( _switch_1==::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_DISAPPEAR_TUTORIAL)){
			HX_STACK_LINE(171)
			if (((this->mTutorialSprite->getAlpha() <= 0.0))){
				HX_STACK_LINE(173)
				this->mTutorialSprite->setAlpha(0.0);
				HX_STACK_LINE(175)
				this->onGoGame();
				HX_STACK_LINE(176)
				this->mCurrentState = ::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_NOTHING;
			}
			else{
				HX_STACK_LINE(178)
				this->mTutorialSprite->setAlpha((this->mTutorialSprite->getAlpha() - (0.0005 * dt)));
			}
		}
	}
return null();
}


Void TutorialScreen_obj::onGoGame( ){
{
		HX_STACK_PUSH("TutorialScreen::onGoGame","com/funbox/bcp/minigame2/screens/TutorialScreen.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_LINE(102)
		::com::minigloop::ui::ScreenManager_obj::getInstance()->gotoScreen(hx::ClassOf< ::com::funbox::bcp::minigame2::screens::GameScreen >());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TutorialScreen_obj,onGoGame,(void))

Void TutorialScreen_obj::onFinishWait( ){
{
		HX_STACK_PUSH("TutorialScreen::onFinishWait","com/funbox/bcp/minigame2/screens/TutorialScreen.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_LINE(98)
		this->mInterval = null();
		HX_STACK_LINE(99)
		this->mCurrentState = ::com::funbox::bcp::minigame2::screens::TutorialScreen_obj::STATE_DISAPPEAR_TUTORIAL;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TutorialScreen_obj,onFinishWait,(void))

int TutorialScreen_obj::STATE_SHOW_TUTORIAL;

int TutorialScreen_obj::STATE_WAIT;

int TutorialScreen_obj::STATE_DISAPPEAR_TUTORIAL;

int TutorialScreen_obj::STATE_NOTHING;

int TutorialScreen_obj::STATE_MOUSE_LEFT;

int TutorialScreen_obj::STATE_MOUSE_RIGHT;


TutorialScreen_obj::TutorialScreen_obj()
{
}

void TutorialScreen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TutorialScreen);
	HX_MARK_MEMBER_NAME(mCanvasMouse,"mCanvasMouse");
	HX_MARK_MEMBER_NAME(mCanvasEffect,"mCanvasEffect");
	HX_MARK_MEMBER_NAME(mCanvasTutorial,"mCanvasTutorial");
	HX_MARK_MEMBER_NAME(mEffectManager,"mEffectManager");
	HX_MARK_MEMBER_NAME(mMoneyInitX,"mMoneyInitX");
	HX_MARK_MEMBER_NAME(mBagInitX,"mBagInitX");
	HX_MARK_MEMBER_NAME(mInterval,"mInterval");
	HX_MARK_MEMBER_NAME(mCurrentState,"mCurrentState");
	HX_MARK_MEMBER_NAME(mTutorialTicketMoneySprite,"mTutorialTicketMoneySprite");
	HX_MARK_MEMBER_NAME(mTutorialBagMoneySprite,"mTutorialBagMoneySprite");
	HX_MARK_MEMBER_NAME(mTutorialHandSprite,"mTutorialHandSprite");
	HX_MARK_MEMBER_NAME(mTutorialSprite,"mTutorialSprite");
	HX_MARK_MEMBER_NAME(mBGMaskSprite,"mBGMaskSprite");
	HX_MARK_MEMBER_NAME(mBGSprite,"mBGSprite");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TutorialScreen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mCanvasMouse,"mCanvasMouse");
	HX_VISIT_MEMBER_NAME(mCanvasEffect,"mCanvasEffect");
	HX_VISIT_MEMBER_NAME(mCanvasTutorial,"mCanvasTutorial");
	HX_VISIT_MEMBER_NAME(mEffectManager,"mEffectManager");
	HX_VISIT_MEMBER_NAME(mMoneyInitX,"mMoneyInitX");
	HX_VISIT_MEMBER_NAME(mBagInitX,"mBagInitX");
	HX_VISIT_MEMBER_NAME(mInterval,"mInterval");
	HX_VISIT_MEMBER_NAME(mCurrentState,"mCurrentState");
	HX_VISIT_MEMBER_NAME(mTutorialTicketMoneySprite,"mTutorialTicketMoneySprite");
	HX_VISIT_MEMBER_NAME(mTutorialBagMoneySprite,"mTutorialBagMoneySprite");
	HX_VISIT_MEMBER_NAME(mTutorialHandSprite,"mTutorialHandSprite");
	HX_VISIT_MEMBER_NAME(mTutorialSprite,"mTutorialSprite");
	HX_VISIT_MEMBER_NAME(mBGMaskSprite,"mBGMaskSprite");
	HX_VISIT_MEMBER_NAME(mBGSprite,"mBGSprite");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TutorialScreen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onGoGame") ) { return onGoGame_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mBagInitX") ) { return mBagInitX; }
		if (HX_FIELD_EQ(inName,"mInterval") ) { return mInterval; }
		if (HX_FIELD_EQ(inName,"mBGSprite") ) { return mBGSprite; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"STATE_WAIT") ) { return STATE_WAIT; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mMoneyInitX") ) { return mMoneyInitX; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onFinishWait") ) { return onFinishWait_dyn(); }
		if (HX_FIELD_EQ(inName,"mCanvasMouse") ) { return mCanvasMouse; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"STATE_NOTHING") ) { return STATE_NOTHING; }
		if (HX_FIELD_EQ(inName,"mCanvasEffect") ) { return mCanvasEffect; }
		if (HX_FIELD_EQ(inName,"mCurrentState") ) { return mCurrentState; }
		if (HX_FIELD_EQ(inName,"mBGMaskSprite") ) { return mBGMaskSprite; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mEffectManager") ) { return mEffectManager; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"mCanvasTutorial") ) { return mCanvasTutorial; }
		if (HX_FIELD_EQ(inName,"mTutorialSprite") ) { return mTutorialSprite; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"STATE_MOUSE_LEFT") ) { return STATE_MOUSE_LEFT; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"STATE_MOUSE_RIGHT") ) { return STATE_MOUSE_RIGHT; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"STATE_SHOW_TUTORIAL") ) { return STATE_SHOW_TUTORIAL; }
		if (HX_FIELD_EQ(inName,"mTutorialHandSprite") ) { return mTutorialHandSprite; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"mTutorialBagMoneySprite") ) { return mTutorialBagMoneySprite; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"STATE_DISAPPEAR_TUTORIAL") ) { return STATE_DISAPPEAR_TUTORIAL; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"mTutorialTicketMoneySprite") ) { return mTutorialTicketMoneySprite; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TutorialScreen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"mBagInitX") ) { mBagInitX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mInterval") ) { mInterval=inValue.Cast< ::com::funbox::bcp::minigame2::util::NInterval >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mBGSprite") ) { mBGSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"STATE_WAIT") ) { STATE_WAIT=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mMoneyInitX") ) { mMoneyInitX=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mCanvasMouse") ) { mCanvasMouse=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"STATE_NOTHING") ) { STATE_NOTHING=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mCanvasEffect") ) { mCanvasEffect=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mCurrentState") ) { mCurrentState=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mBGMaskSprite") ) { mBGMaskSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mEffectManager") ) { mEffectManager=inValue.Cast< ::com::funbox::bcp::minigame2::engine::effectManager::EffectManager >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"mCanvasTutorial") ) { mCanvasTutorial=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mTutorialSprite") ) { mTutorialSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"STATE_MOUSE_LEFT") ) { STATE_MOUSE_LEFT=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"STATE_MOUSE_RIGHT") ) { STATE_MOUSE_RIGHT=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"STATE_SHOW_TUTORIAL") ) { STATE_SHOW_TUTORIAL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mTutorialHandSprite") ) { mTutorialHandSprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"mTutorialBagMoneySprite") ) { mTutorialBagMoneySprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"STATE_DISAPPEAR_TUTORIAL") ) { STATE_DISAPPEAR_TUTORIAL=inValue.Cast< int >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"mTutorialTicketMoneySprite") ) { mTutorialTicketMoneySprite=inValue.Cast< ::com::funbox::bcp::minigame2::entities::BaseActor >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TutorialScreen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mCanvasMouse"));
	outFields->push(HX_CSTRING("mCanvasEffect"));
	outFields->push(HX_CSTRING("mCanvasTutorial"));
	outFields->push(HX_CSTRING("mEffectManager"));
	outFields->push(HX_CSTRING("mMoneyInitX"));
	outFields->push(HX_CSTRING("mBagInitX"));
	outFields->push(HX_CSTRING("mInterval"));
	outFields->push(HX_CSTRING("mCurrentState"));
	outFields->push(HX_CSTRING("mTutorialTicketMoneySprite"));
	outFields->push(HX_CSTRING("mTutorialBagMoneySprite"));
	outFields->push(HX_CSTRING("mTutorialHandSprite"));
	outFields->push(HX_CSTRING("mTutorialSprite"));
	outFields->push(HX_CSTRING("mBGMaskSprite"));
	outFields->push(HX_CSTRING("mBGSprite"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("STATE_SHOW_TUTORIAL"),
	HX_CSTRING("STATE_WAIT"),
	HX_CSTRING("STATE_DISAPPEAR_TUTORIAL"),
	HX_CSTRING("STATE_NOTHING"),
	HX_CSTRING("STATE_MOUSE_LEFT"),
	HX_CSTRING("STATE_MOUSE_RIGHT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("onGoGame"),
	HX_CSTRING("onFinishWait"),
	HX_CSTRING("mCanvasMouse"),
	HX_CSTRING("mCanvasEffect"),
	HX_CSTRING("mCanvasTutorial"),
	HX_CSTRING("mEffectManager"),
	HX_CSTRING("mMoneyInitX"),
	HX_CSTRING("mBagInitX"),
	HX_CSTRING("mInterval"),
	HX_CSTRING("mCurrentState"),
	HX_CSTRING("mTutorialTicketMoneySprite"),
	HX_CSTRING("mTutorialBagMoneySprite"),
	HX_CSTRING("mTutorialHandSprite"),
	HX_CSTRING("mTutorialSprite"),
	HX_CSTRING("mBGMaskSprite"),
	HX_CSTRING("mBGSprite"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::STATE_SHOW_TUTORIAL,"STATE_SHOW_TUTORIAL");
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::STATE_WAIT,"STATE_WAIT");
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::STATE_DISAPPEAR_TUTORIAL,"STATE_DISAPPEAR_TUTORIAL");
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::STATE_NOTHING,"STATE_NOTHING");
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::STATE_MOUSE_LEFT,"STATE_MOUSE_LEFT");
	HX_MARK_MEMBER_NAME(TutorialScreen_obj::STATE_MOUSE_RIGHT,"STATE_MOUSE_RIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::STATE_SHOW_TUTORIAL,"STATE_SHOW_TUTORIAL");
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::STATE_WAIT,"STATE_WAIT");
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::STATE_DISAPPEAR_TUTORIAL,"STATE_DISAPPEAR_TUTORIAL");
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::STATE_NOTHING,"STATE_NOTHING");
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::STATE_MOUSE_LEFT,"STATE_MOUSE_LEFT");
	HX_VISIT_MEMBER_NAME(TutorialScreen_obj::STATE_MOUSE_RIGHT,"STATE_MOUSE_RIGHT");
};

Class TutorialScreen_obj::__mClass;

void TutorialScreen_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.screens.TutorialScreen"), hx::TCanCast< TutorialScreen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TutorialScreen_obj::__boot()
{
	STATE_SHOW_TUTORIAL= (int)0;
	STATE_WAIT= (int)1;
	STATE_DISAPPEAR_TUTORIAL= (int)2;
	STATE_NOTHING= (int)3;
	STATE_MOUSE_LEFT= (int)4;
	STATE_MOUSE_RIGHT= (int)5;
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens
