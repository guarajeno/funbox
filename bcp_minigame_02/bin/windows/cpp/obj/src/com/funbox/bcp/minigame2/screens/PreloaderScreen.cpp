#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_PreloaderScreen
#include <com/funbox/bcp/minigame2/screens/PreloaderScreen.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_screens_TutorialScreen
#include <com/funbox/bcp/minigame2/screens/TutorialScreen.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_Screen
#include <com/minigloop/ui/Screen.h>
#endif
#ifndef INCLUDED_com_minigloop_ui_ScreenManager
#include <com/minigloop/ui/ScreenManager.h>
#endif
#ifndef INCLUDED_com_minigloop_util_AssetsLoader
#include <com/minigloop/util/AssetsLoader.h>
#endif
#ifndef INCLUDED_com_minigloop_util_DataLoader
#include <com/minigloop/util/DataLoader.h>
#endif
#ifndef INCLUDED_com_minigloop_util_SoundManager
#include <com/minigloop/util/SoundManager.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
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

Void PreloaderScreen_obj::__construct(::native::display::Sprite canvas)
{
HX_STACK_PUSH("PreloaderScreen::new","com/funbox/bcp/minigame2/screens/PreloaderScreen.hx",22);
{
	HX_STACK_LINE(23)
	super::__construct(canvas);
	HX_STACK_LINE(25)
	::com::funbox::bcp::minigame2::Global_obj::stage = canvas->get_stage();
	HX_STACK_LINE(26)
	::com::funbox::bcp::minigame2::Global_obj::StageWidth = canvas->get_stage()->get_stageWidth();
	HX_STACK_LINE(27)
	::com::funbox::bcp::minigame2::Global_obj::StageHeight = (canvas->get_stage()->get_stageHeight() - (int)160);
	HX_STACK_LINE(29)
	::com::minigloop::util::DataLoader_obj::init();
	HX_STACK_LINE(30)
	::com::minigloop::util::AssetsLoader_obj::init();
	HX_STACK_LINE(31)
	::com::minigloop::util::SoundManager_obj::init();
	HX_STACK_LINE(34)
	::com::minigloop::util::SoundManager_obj::addSound(HX_CSTRING("sound/bgm_juego_2.mp3"),HX_CSTRING("bgm_juego_2"));
	HX_STACK_LINE(35)
	::com::minigloop::util::SoundManager_obj::addSound(HX_CSTRING("sound/fx_dinero.mp3"),HX_CSTRING("fx_dinero"));
	HX_STACK_LINE(36)
	::com::minigloop::util::SoundManager_obj::addSound(HX_CSTRING("sound/scorecard.mp3"),HX_CSTRING("scorecard"));
	HX_STACK_LINE(40)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/scorecard/btn_volver.png"),HX_CSTRING("volver"));
	HX_STACK_LINE(41)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/scorecard/btn_regresar.png"),HX_CSTRING("regresar"));
	HX_STACK_LINE(42)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/scorecard/gui_scorecard_twitter_over.png"),HX_CSTRING("twitter"));
	HX_STACK_LINE(43)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/scorecard/gui_scorecard_face_over.png"),HX_CSTRING("facebook"));
	HX_STACK_LINE(44)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/scorecard/minigame1_scorecard.png"),HX_CSTRING("scorecard"));
	HX_STACK_LINE(48)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/hud/spMinigame02_background_score.png"),HX_CSTRING("spMinigame02_background_score"));
	HX_STACK_LINE(52)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_text.png"),HX_CSTRING("spMinigame02_tutorial_text"));
	HX_STACK_LINE(54)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_bag_money.png"),HX_CSTRING("spMinigame02_tutorial_bag_money"));
	HX_STACK_LINE(56)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_mouseHand.png"),HX_CSTRING("spMinigame02_tutorial_mouseHand"));
	HX_STACK_LINE(58)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/spMinigame02_tutorial_ticket_money.png"),HX_CSTRING("spMinigame02_tutorial_ticket_money"));
	HX_STACK_LINE(62)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/check_secure/spMinigame02_tutorial_check_secure.png"),HX_CSTRING("spMinigame02_tutorial_check_secure"));
	HX_STACK_LINE(64)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/interfaces/tutorial/check_secure/spMinigame02_tutorial_check_secure.json"),HX_CSTRING("spMinigame02_tutorial_check_secure"));
	HX_STACK_LINE(68)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/score_effect/spMinigame02_tutorial_score_100.png"),HX_CSTRING("spMinigame02_tutorial_score_100"));
	HX_STACK_LINE(70)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/tutorial/score_effect/spMinigame02_tutorial_score_500.png"),HX_CSTRING("spMinigame02_tutorial_score_500"));
	HX_STACK_LINE(74)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/spMinigame02_bg.jpg"),HX_CSTRING("spMinigame02_bg"));
	HX_STACK_LINE(76)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/spMinigame02_background_mask.png"),HX_CSTRING("spMinigame02_background_mask"));
	HX_STACK_LINE(80)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/score_effect/spMinigame02_score_100.png"),HX_CSTRING("spMinigame02_score_100"));
	HX_STACK_LINE(82)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/score_effect/spMinigame02_score_500.png"),HX_CSTRING("spMinigame02_score_500"));
	HX_STACK_LINE(84)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/score_effect/spMinigame02_score_1000.png"),HX_CSTRING("spMinigame02_score_1000"));
	HX_STACK_LINE(88)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/check_secure/spMinigame02_check_secure.png"),HX_CSTRING("spMinigame02_check_secure"));
	HX_STACK_LINE(90)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/check_secure/spMinigame02_check_secure.json"),HX_CSTRING("spMinigame02_check_secure"));
	HX_STACK_LINE(94)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/bag_money/spMinigame02_ani_bag_money.png"),HX_CSTRING("spMinigame02_ani_bag_money"));
	HX_STACK_LINE(96)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/bag_money/spMinigame02_ani_bag_money.json"),HX_CSTRING("spMinigame02_ani_bag_money"));
	HX_STACK_LINE(100)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/ticket_money/spMinigame02_ani_ticket_money.png"),HX_CSTRING("spMinigame02_ani_ticket_money"));
	HX_STACK_LINE(102)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/ticket_money/spMinigame02_ani_ticket_money.json"),HX_CSTRING("spMinigame02_ani_ticket_money"));
	HX_STACK_LINE(106)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/bot_collector/spMinigame02_ani_bot_collector.png"),HX_CSTRING("spMinigame02_ani_bot_collector"));
	HX_STACK_LINE(108)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/bot_collector/spMinigame02_ani_bot_collector.json"),HX_CSTRING("spMinigame02_ani_bot_collector"));
	HX_STACK_LINE(112)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/effect_puff/spMinigame02_ani_effect_puff.png"),HX_CSTRING("spMinigame02_ani_effect_puff"));
	HX_STACK_LINE(114)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/effect_puff/spMinigame02_ani_effect_puff.json"),HX_CSTRING("spMinigame02_ani_effect_puff"));
	HX_STACK_LINE(118)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/mouse_mask/spMinigame02_mouseHand_click.png"),HX_CSTRING("spMinigame02_mouseHand_click"));
	HX_STACK_LINE(120)
	::com::minigloop::util::DataLoader_obj::addData(HX_CSTRING("images/minigame02/mouse_mask/spMinigame02_mouseHand_click.json"),HX_CSTRING("spMinigame02_mouseHand_click"));
	HX_STACK_LINE(124)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_01.png"),HX_CSTRING("spMinigame02_gui_text_01"));
	HX_STACK_LINE(126)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_02.png"),HX_CSTRING("spMinigame02_gui_text_02"));
	HX_STACK_LINE(128)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_03.png"),HX_CSTRING("spMinigame02_gui_text_03"));
	HX_STACK_LINE(130)
	::com::minigloop::util::AssetsLoader_obj::addAsset(HX_CSTRING("images/minigame02/interfaces/popup_start_sequence/spMinigame02_gui_text_start.png"),HX_CSTRING("spMinigame02_gui_text_start"));
	HX_STACK_LINE(133)
	::com::minigloop::util::AssetsLoader_obj::load(this->onAssetsLoaded_dyn());
	HX_STACK_LINE(134)
	::com::minigloop::util::DataLoader_obj::load(this->onDataLoaded_dyn());
	HX_STACK_LINE(135)
	::com::minigloop::util::SoundManager_obj::load(this->onSoundsLoaded_dyn());
}
;
	return null();
}

PreloaderScreen_obj::~PreloaderScreen_obj() { }

Dynamic PreloaderScreen_obj::__CreateEmpty() { return  new PreloaderScreen_obj; }
hx::ObjectPtr< PreloaderScreen_obj > PreloaderScreen_obj::__new(::native::display::Sprite canvas)
{  hx::ObjectPtr< PreloaderScreen_obj > result = new PreloaderScreen_obj();
	result->__construct(canvas);
	return result;}

Dynamic PreloaderScreen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PreloaderScreen_obj > result = new PreloaderScreen_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PreloaderScreen_obj::update( int dt){
{
		HX_STACK_PUSH("PreloaderScreen::update","com/funbox/bcp/minigame2/screens/PreloaderScreen.hx",157);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(158)
		if (((bool((bool(this->_isAssetsDownloaded) && bool(this->_isDataDownloaded))) && bool(this->_isSoundsDownloaded)))){
			HX_STACK_LINE(159)
			::com::minigloop::ui::ScreenManager_obj::getInstance()->gotoScreen(hx::ClassOf< ::com::funbox::bcp::minigame2::screens::TutorialScreen >());
		}
		HX_STACK_LINE(162)
		this->super::update(dt);
		HX_STACK_LINE(162)
		return null();
	}
return null();
}


Void PreloaderScreen_obj::onDataLoaded( ){
{
		HX_STACK_PUSH("PreloaderScreen::onDataLoaded","com/funbox/bcp/minigame2/screens/PreloaderScreen.hx",151);
		HX_STACK_THIS(this);
		HX_STACK_LINE(152)
		this->_isDataDownloaded = true;
		HX_STACK_LINE(153)
		::haxe::Log_obj::trace(HX_CSTRING("DATA LOADED"),hx::SourceInfo(HX_CSTRING("PreloaderScreen.hx"),153,HX_CSTRING("com.funbox.bcp.minigame2.screens.PreloaderScreen"),HX_CSTRING("onDataLoaded")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PreloaderScreen_obj,onDataLoaded,(void))

Void PreloaderScreen_obj::onAssetsLoaded( ){
{
		HX_STACK_PUSH("PreloaderScreen::onAssetsLoaded","com/funbox/bcp/minigame2/screens/PreloaderScreen.hx",145);
		HX_STACK_THIS(this);
		HX_STACK_LINE(146)
		this->_isAssetsDownloaded = true;
		HX_STACK_LINE(147)
		::haxe::Log_obj::trace(HX_CSTRING("ASSETS LOADED"),hx::SourceInfo(HX_CSTRING("PreloaderScreen.hx"),147,HX_CSTRING("com.funbox.bcp.minigame2.screens.PreloaderScreen"),HX_CSTRING("onAssetsLoaded")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PreloaderScreen_obj,onAssetsLoaded,(void))

Void PreloaderScreen_obj::onSoundsLoaded( ){
{
		HX_STACK_PUSH("PreloaderScreen::onSoundsLoaded","com/funbox/bcp/minigame2/screens/PreloaderScreen.hx",139);
		HX_STACK_THIS(this);
		HX_STACK_LINE(140)
		this->_isSoundsDownloaded = true;
		HX_STACK_LINE(141)
		::haxe::Log_obj::trace(HX_CSTRING("SOUNDS LOADED"),hx::SourceInfo(HX_CSTRING("PreloaderScreen.hx"),141,HX_CSTRING("com.funbox.bcp.minigame2.screens.PreloaderScreen"),HX_CSTRING("onSoundsLoaded")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PreloaderScreen_obj,onSoundsLoaded,(void))


PreloaderScreen_obj::PreloaderScreen_obj()
{
}

void PreloaderScreen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PreloaderScreen);
	HX_MARK_MEMBER_NAME(_isSoundsDownloaded,"_isSoundsDownloaded");
	HX_MARK_MEMBER_NAME(_isDataDownloaded,"_isDataDownloaded");
	HX_MARK_MEMBER_NAME(_isAssetsDownloaded,"_isAssetsDownloaded");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PreloaderScreen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_isSoundsDownloaded,"_isSoundsDownloaded");
	HX_VISIT_MEMBER_NAME(_isDataDownloaded,"_isDataDownloaded");
	HX_VISIT_MEMBER_NAME(_isAssetsDownloaded,"_isAssetsDownloaded");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic PreloaderScreen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onDataLoaded") ) { return onDataLoaded_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onAssetsLoaded") ) { return onAssetsLoaded_dyn(); }
		if (HX_FIELD_EQ(inName,"onSoundsLoaded") ) { return onSoundsLoaded_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_isDataDownloaded") ) { return _isDataDownloaded; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_isSoundsDownloaded") ) { return _isSoundsDownloaded; }
		if (HX_FIELD_EQ(inName,"_isAssetsDownloaded") ) { return _isAssetsDownloaded; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PreloaderScreen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"_isDataDownloaded") ) { _isDataDownloaded=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_isSoundsDownloaded") ) { _isSoundsDownloaded=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isAssetsDownloaded") ) { _isAssetsDownloaded=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PreloaderScreen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_isSoundsDownloaded"));
	outFields->push(HX_CSTRING("_isDataDownloaded"));
	outFields->push(HX_CSTRING("_isAssetsDownloaded"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("onDataLoaded"),
	HX_CSTRING("onAssetsLoaded"),
	HX_CSTRING("onSoundsLoaded"),
	HX_CSTRING("_isSoundsDownloaded"),
	HX_CSTRING("_isDataDownloaded"),
	HX_CSTRING("_isAssetsDownloaded"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PreloaderScreen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PreloaderScreen_obj::__mClass,"__mClass");
};

Class PreloaderScreen_obj::__mClass;

void PreloaderScreen_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.screens.PreloaderScreen"), hx::TCanCast< PreloaderScreen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PreloaderScreen_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace screens
