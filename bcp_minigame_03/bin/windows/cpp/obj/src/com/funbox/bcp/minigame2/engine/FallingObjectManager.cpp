#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_Global
#include <com/funbox/bcp/minigame2/Global.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_EntitiesController
#include <com/funbox/bcp/minigame2/engine/EntitiesController.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_FallingObjectManager
#include <com/funbox/bcp/minigame2/engine/FallingObjectManager.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_BaseActor
#include <com/funbox/bcp/minigame2/entities/BaseActor.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_entities_TouchObject
#include <com/funbox/bcp/minigame2/entities/TouchObject.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType
#include <com/funbox/bcp/minigame2/type/EnumTouchObjectType.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NInterval
#include <com/funbox/bcp/minigame2/util/NInterval.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NMath
#include <com/funbox/bcp/minigame2/util/NMath.h>
#endif
#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NUtils
#include <com/funbox/bcp/minigame2/util/NUtils.h>
#endif
#ifndef INCLUDED_com_minigloop_util_Vector2D
#include <com/minigloop/util/Vector2D.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace engine{

Void FallingObjectManager_obj::__construct(::com::funbox::bcp::minigame2::engine::EntitiesController entitiesController)
{
HX_STACK_PUSH("FallingObjectManager::new","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",24);
{
	HX_STACK_LINE(25)
	this->mEntitiesController = entitiesController;
	HX_STACK_LINE(26)
	this->mStarted = false;
	HX_STACK_LINE(28)
	this->mTouchObjectsToChoose = Array_obj< int >::__new();
	HX_STACK_LINE(30)
	this->mTouchObjectsToChoose->push(::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::COIN);
	HX_STACK_LINE(31)
	this->mTouchObjectsToChoose->push(::com::funbox::bcp::minigame2::type::EnumTouchObjectType_obj::MONEY);
	HX_STACK_LINE(33)
	this->mIntervalCreation_1 = ::com::funbox::bcp::minigame2::util::NInterval_obj::__new(this->onFinishThenCreate_1_dyn(),(int)950);
	HX_STACK_LINE(34)
	this->mIntervalCreation_2 = ::com::funbox::bcp::minigame2::util::NInterval_obj::__new(this->onFinishThenCreate_2_dyn(),(int)1500);
}
;
	return null();
}

FallingObjectManager_obj::~FallingObjectManager_obj() { }

Dynamic FallingObjectManager_obj::__CreateEmpty() { return  new FallingObjectManager_obj; }
hx::ObjectPtr< FallingObjectManager_obj > FallingObjectManager_obj::__new(::com::funbox::bcp::minigame2::engine::EntitiesController entitiesController)
{  hx::ObjectPtr< FallingObjectManager_obj > result = new FallingObjectManager_obj();
	result->__construct(entitiesController);
	return result;}

Dynamic FallingObjectManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FallingObjectManager_obj > result = new FallingObjectManager_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FallingObjectManager_obj::free( ){
{
		HX_STACK_PUSH("FallingObjectManager::free","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",72);
		HX_STACK_THIS(this);
		HX_STACK_LINE(73)
		this->mTouchObjectsToChoose = null();
		HX_STACK_LINE(74)
		this->mEntitiesController = null();
		HX_STACK_LINE(76)
		if (((this->mIntervalCreation_1 != null()))){
			HX_STACK_LINE(76)
			this->mIntervalCreation_1 = null();
		}
		HX_STACK_LINE(77)
		if (((this->mIntervalCreation_2 != null()))){
			HX_STACK_LINE(77)
			this->mIntervalCreation_2 = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FallingObjectManager_obj,free,(void))

Void FallingObjectManager_obj::update( int dt){
{
		HX_STACK_PUSH("FallingObjectManager::update","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",65);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(65)
		if ((this->mStarted)){
			HX_STACK_LINE(67)
			if (((this->mIntervalCreation_1 != null()))){
				HX_STACK_LINE(67)
				this->mIntervalCreation_1->update(dt);
			}
			HX_STACK_LINE(68)
			if (((this->mIntervalCreation_2 != null()))){
				HX_STACK_LINE(68)
				this->mIntervalCreation_2->update(dt);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FallingObjectManager_obj,update,(void))

Void FallingObjectManager_obj::onCreateEntitie( ){
{
		HX_STACK_PUSH("FallingObjectManager::onCreateEntitie","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_LINE(54)
		Float x = ::com::funbox::bcp::minigame2::util::NMath_obj::random((int)30,(int)610);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(55)
		Float y = (int)-80;		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(56)
		::com::minigloop::util::Vector2D speed = ::com::minigloop::util::Vector2D_obj::__new((int)0,::com::funbox::bcp::minigame2::util::NMath_obj::random(0.05,0.4));		HX_STACK_VAR(speed,"speed");
		HX_STACK_LINE(57)
		int typeToChoose = this->mTouchObjectsToChoose->__get(::com::funbox::bcp::minigame2::util::NUtils_obj::getValueFromProbabilityChart(this->mTouchObjectsToChoose->length,(int)10));		HX_STACK_VAR(typeToChoose,"typeToChoose");
		HX_STACK_LINE(59)
		::com::funbox::bcp::minigame2::entities::TouchObject tObj = this->mEntitiesController->createEntitie((int)0,(int)0,speed,typeToChoose);		HX_STACK_VAR(tObj,"tObj");
		HX_STACK_LINE(60)
		tObj->setX(::com::funbox::bcp::minigame2::util::NMath_obj::random((tObj->getWidth() + ::com::funbox::bcp::minigame2::Global_obj::ScreenOffsetWidth),((::com::funbox::bcp::minigame2::Global_obj::StageWidth - tObj->getWidth()) - ::com::funbox::bcp::minigame2::Global_obj::ScreenOffsetWidth)));
		HX_STACK_LINE(62)
		tObj->setY(-(tObj->getHeight()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FallingObjectManager_obj,onCreateEntitie,(void))

Void FallingObjectManager_obj::start( ){
{
		HX_STACK_PUSH("FallingObjectManager::start","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(49)
		this->mStarted = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FallingObjectManager_obj,start,(void))

Void FallingObjectManager_obj::onFinishThenCreate_2( ){
{
		HX_STACK_PUSH("FallingObjectManager::onFinishThenCreate_2","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_LINE(44)
		this->onCreateEntitie();
		HX_STACK_LINE(46)
		this->mIntervalCreation_2 = ::com::funbox::bcp::minigame2::util::NInterval_obj::__new(this->onFinishThenCreate_2_dyn(),(int)1500);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FallingObjectManager_obj,onFinishThenCreate_2,(void))

Void FallingObjectManager_obj::onFinishThenCreate_1( ){
{
		HX_STACK_PUSH("FallingObjectManager::onFinishThenCreate_1","com/funbox/bcp/minigame2/engine/FallingObjectManager.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_LINE(38)
		this->onCreateEntitie();
		HX_STACK_LINE(40)
		this->mIntervalCreation_1 = ::com::funbox::bcp::minigame2::util::NInterval_obj::__new(this->onFinishThenCreate_1_dyn(),(int)950);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FallingObjectManager_obj,onFinishThenCreate_1,(void))


FallingObjectManager_obj::FallingObjectManager_obj()
{
}

void FallingObjectManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FallingObjectManager);
	HX_MARK_MEMBER_NAME(mTouchObjectsToChoose,"mTouchObjectsToChoose");
	HX_MARK_MEMBER_NAME(mStarted,"mStarted");
	HX_MARK_MEMBER_NAME(mIntervalCreation_2,"mIntervalCreation_2");
	HX_MARK_MEMBER_NAME(mIntervalCreation_1,"mIntervalCreation_1");
	HX_MARK_MEMBER_NAME(mEntitiesController,"mEntitiesController");
	HX_MARK_END_CLASS();
}

void FallingObjectManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mTouchObjectsToChoose,"mTouchObjectsToChoose");
	HX_VISIT_MEMBER_NAME(mStarted,"mStarted");
	HX_VISIT_MEMBER_NAME(mIntervalCreation_2,"mIntervalCreation_2");
	HX_VISIT_MEMBER_NAME(mIntervalCreation_1,"mIntervalCreation_1");
	HX_VISIT_MEMBER_NAME(mEntitiesController,"mEntitiesController");
}

Dynamic FallingObjectManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mStarted") ) { return mStarted; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onCreateEntitie") ) { return onCreateEntitie_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mIntervalCreation_2") ) { return mIntervalCreation_2; }
		if (HX_FIELD_EQ(inName,"mIntervalCreation_1") ) { return mIntervalCreation_1; }
		if (HX_FIELD_EQ(inName,"mEntitiesController") ) { return mEntitiesController; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"onFinishThenCreate_2") ) { return onFinishThenCreate_2_dyn(); }
		if (HX_FIELD_EQ(inName,"onFinishThenCreate_1") ) { return onFinishThenCreate_1_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mTouchObjectsToChoose") ) { return mTouchObjectsToChoose; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FallingObjectManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mStarted") ) { mStarted=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mIntervalCreation_2") ) { mIntervalCreation_2=inValue.Cast< ::com::funbox::bcp::minigame2::util::NInterval >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mIntervalCreation_1") ) { mIntervalCreation_1=inValue.Cast< ::com::funbox::bcp::minigame2::util::NInterval >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mEntitiesController") ) { mEntitiesController=inValue.Cast< ::com::funbox::bcp::minigame2::engine::EntitiesController >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mTouchObjectsToChoose") ) { mTouchObjectsToChoose=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FallingObjectManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mTouchObjectsToChoose"));
	outFields->push(HX_CSTRING("mStarted"));
	outFields->push(HX_CSTRING("mIntervalCreation_2"));
	outFields->push(HX_CSTRING("mIntervalCreation_1"));
	outFields->push(HX_CSTRING("mEntitiesController"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("onCreateEntitie"),
	HX_CSTRING("start"),
	HX_CSTRING("onFinishThenCreate_2"),
	HX_CSTRING("onFinishThenCreate_1"),
	HX_CSTRING("mTouchObjectsToChoose"),
	HX_CSTRING("mStarted"),
	HX_CSTRING("mIntervalCreation_2"),
	HX_CSTRING("mIntervalCreation_1"),
	HX_CSTRING("mEntitiesController"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FallingObjectManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FallingObjectManager_obj::__mClass,"__mClass");
};

Class FallingObjectManager_obj::__mClass;

void FallingObjectManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.engine.FallingObjectManager"), hx::TCanCast< FallingObjectManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FallingObjectManager_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine
