#include <hxcpp.h>

#ifndef INCLUDED_com_funbox_bcp_minigame2_util_NInterval
#include <com/funbox/bcp/minigame2/util/NInterval.h>
#endif
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace util{

Void NInterval_obj::__construct(Dynamic callbackFunc,int timeLimit)
{
HX_STACK_PUSH("NInterval::new","com/funbox/bcp/minigame2/util/NInterval.hx",13);
{
	HX_STACK_LINE(14)
	this->mCallbackFunc = callbackFunc;
	HX_STACK_LINE(15)
	this->mTimeLimit = timeLimit;
}
;
	return null();
}

NInterval_obj::~NInterval_obj() { }

Dynamic NInterval_obj::__CreateEmpty() { return  new NInterval_obj; }
hx::ObjectPtr< NInterval_obj > NInterval_obj::__new(Dynamic callbackFunc,int timeLimit)
{  hx::ObjectPtr< NInterval_obj > result = new NInterval_obj();
	result->__construct(callbackFunc,timeLimit);
	return result;}

Dynamic NInterval_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NInterval_obj > result = new NInterval_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void NInterval_obj::update( int dt){
{
		HX_STACK_PUSH("NInterval::update","com/funbox/bcp/minigame2/util/NInterval.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(18)
		if ((((this->mTimeCounter + dt) > this->mTimeLimit))){
			HX_STACK_LINE(20)
			this->mTimeCounter = (int)0;
			HX_STACK_LINE(22)
			if (((this->mCallbackFunc != null()))){
				HX_STACK_LINE(23)
				this->mCallbackFunc();
				HX_STACK_LINE(24)
				this->mCallbackFunc = null();
			}
		}
		else{
			HX_STACK_LINE(27)
			hx::AddEq(this->mTimeCounter,dt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NInterval_obj,update,(void))


NInterval_obj::NInterval_obj()
{
}

void NInterval_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NInterval);
	HX_MARK_MEMBER_NAME(mTimeCounter,"mTimeCounter");
	HX_MARK_MEMBER_NAME(mTimeLimit,"mTimeLimit");
	HX_MARK_MEMBER_NAME(mCallbackFunc,"mCallbackFunc");
	HX_MARK_END_CLASS();
}

void NInterval_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mTimeCounter,"mTimeCounter");
	HX_VISIT_MEMBER_NAME(mTimeLimit,"mTimeLimit");
	HX_VISIT_MEMBER_NAME(mCallbackFunc,"mCallbackFunc");
}

Dynamic NInterval_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mTimeLimit") ) { return mTimeLimit; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mTimeCounter") ) { return mTimeCounter; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mCallbackFunc") ) { return mCallbackFunc; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NInterval_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"mTimeLimit") ) { mTimeLimit=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mTimeCounter") ) { mTimeCounter=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mCallbackFunc") ) { mCallbackFunc=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NInterval_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mTimeCounter"));
	outFields->push(HX_CSTRING("mTimeLimit"));
	outFields->push(HX_CSTRING("mCallbackFunc"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("mTimeCounter"),
	HX_CSTRING("mTimeLimit"),
	HX_CSTRING("mCallbackFunc"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NInterval_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NInterval_obj::__mClass,"__mClass");
};

Class NInterval_obj::__mClass;

void NInterval_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.funbox.bcp.minigame2.util.NInterval"), hx::TCanCast< NInterval_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NInterval_obj::__boot()
{
}

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace util
