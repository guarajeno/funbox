#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_minigloop_util_Stats
#include <com/minigloop/util/Stats.h>
#endif
#ifndef INCLUDED_native_Lib
#include <native/Lib.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_native_system_System
#include <native/system/System.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace minigloop{
namespace util{

Void Stats_obj::__construct(hx::Null< bool >  __o_alignRight,hx::Null< bool >  __o_fastUpdate)
{
HX_STACK_PUSH("Stats::new","com/minigloop/util/Stats.hx",70);
bool alignRight = __o_alignRight.Default(true);
bool fastUpdate = __o_fastUpdate.Default(false);
{
	HX_STACK_LINE(71)
	super::__construct();
	HX_STACK_LINE(72)
	this->alignRight = alignRight;
	HX_STACK_LINE(73)
	this->fastUpdate = fastUpdate;
	HX_STACK_LINE(74)
	this->htmlText = HX_CSTRING("");
	HX_STACK_LINE(75)
	this->mem_max = (int)0;
	HX_STACK_LINE(76)
	this->fps = (int)0;
	HX_STACK_LINE(78)
	this->text = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(79)
	this->text->set_defaultTextFormat(::native::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)9,null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),(int)-2));
	HX_STACK_LINE(80)
	this->text->set_multiline(true);
	HX_STACK_LINE(81)
	this->text->set_width((int)70);
	HX_STACK_LINE(82)
	this->text->set_height((int)50);
	HX_STACK_LINE(83)
	this->text->set_selectable(false);
	HX_STACK_LINE(84)
	this->text->set_mouseEnabled(false);
	HX_STACK_LINE(86)
	this->rectangle = ::native::geom::Rectangle_obj::__new((int)69,(int)0,(int)1,(int)50);
	HX_STACK_LINE(88)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->init_dyn(),false,(int)0,true);
	HX_STACK_LINE(89)
	this->addEventListener(::native::events::Event_obj::REMOVED_FROM_STAGE,this->destroy_dyn(),false,(int)0,true);
}
;
	return null();
}

Stats_obj::~Stats_obj() { }

Dynamic Stats_obj::__CreateEmpty() { return  new Stats_obj; }
hx::ObjectPtr< Stats_obj > Stats_obj::__new(hx::Null< bool >  __o_alignRight,hx::Null< bool >  __o_fastUpdate)
{  hx::ObjectPtr< Stats_obj > result = new Stats_obj();
	result->__construct(__o_alignRight,__o_fastUpdate);
	return result;}

Dynamic Stats_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stats_obj > result = new Stats_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int Stats_obj::normalizeMem( Float _mem){
	HX_STACK_PUSH("Stats::normalizeMem","com/minigloop/util/Stats.hx",186);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_mem,"_mem");
	HX_STACK_LINE(186)
	return ::Std_obj::_int((::Math_obj::min((int)50,::Math_obj::sqrt(::Math_obj::sqrt((_mem * (int)5000)))) - (int)2));
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,normalizeMem,return )

Void Stats_obj::update( ::native::events::Event e){
{
		HX_STACK_PUSH("Stats::update","com/minigloop/util/Stats.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(126)
		this->timer = ::native::Lib_obj::getTimer();
		HX_STACK_LINE(129)
		if ((((this->timer - (int)1000) > this->ms_prev))){
			HX_STACK_LINE(131)
			this->mem = (::native::system::System_obj::get_totalMemory() * 0.000000954);
			HX_STACK_LINE(132)
			this->mem_max = (  (((this->mem_max > this->mem))) ? Float(this->mem_max) : Float(this->mem) );
			HX_STACK_LINE(134)
			this->fps_graph = ((int)50 - ::Std_obj::_int(::Math_obj::min((int)50,((Float(this->fps) / Float(this->_stage->frameRate)) * (int)50))));
			HX_STACK_LINE(136)
			this->mem_graph = ((int)50 - this->normalizeMem(this->mem));
			HX_STACK_LINE(137)
			this->mem_max_graph = ((int)50 - this->normalizeMem(this->mem_max));
			HX_STACK_LINE(139)
			this->ms_graph = ::Std_obj::_int(((int)50 - ((int((this->timer - this->ms)) >> int((int)1)))));
			HX_STACK_LINE(140)
			this->graph->scroll((int)-1,(int)0);
			HX_STACK_LINE(142)
			this->graph->fillRect(this->rectangle,(int)51);
			HX_STACK_LINE(143)
			this->graph->lock();
			HX_STACK_LINE(144)
			this->graph->setPixel((int)69,this->fps_graph,(int)16776960);
			HX_STACK_LINE(145)
			this->graph->setPixel((int)69,this->mem_graph,(int)65535);
			HX_STACK_LINE(146)
			this->graph->setPixel((int)69,this->mem_max_graph,(int)16711792);
			HX_STACK_LINE(147)
			this->graph->setPixel((int)69,this->ms_graph,(int)65280);
			HX_STACK_LINE(148)
			this->graph->unlock(null());
			HX_STACK_LINE(150)
			this->fpsStr = (((HX_CSTRING("FPS: ") + this->fps) + HX_CSTRING(" / ")) + this->get_stage()->frameRate);
			HX_STACK_LINE(151)
			this->memStr = (HX_CSTRING("MEM: ") + ::Math_obj::round(this->mem));
			HX_STACK_LINE(152)
			this->memMaxStr = (HX_CSTRING("MAX: ") + ::Math_obj::round(this->mem_max));
			HX_STACK_LINE(157)
			this->fps = (int)0;
			HX_STACK_LINE(158)
			this->ms_prev = this->timer;
			HX_STACK_LINE(160)
			if ((!(this->fastUpdate))){
				HX_STACK_LINE(161)
				this->text->set_htmlText(this->htmlText);
			}
			HX_STACK_LINE(163)
			return null();
		}
		HX_STACK_LINE(167)
		(this->fps)++;
		HX_STACK_LINE(169)
		this->msStr = (HX_CSTRING("MS: ") + ((this->timer - this->ms)));
		HX_STACK_LINE(170)
		this->ms = this->timer;
		HX_STACK_LINE(172)
		this->htmlText = ((((((((((((((((((((((HX_CSTRING("<font color='") + HX_CSTRING("#ffff00")) + HX_CSTRING("'>")) + this->fpsStr) + HX_CSTRING("</font>")) + HX_CSTRING("<br>")) + HX_CSTRING("<font color='")) + HX_CSTRING("#00ffff")) + HX_CSTRING("'>")) + this->memStr) + HX_CSTRING("</font>")) + HX_CSTRING("<br>")) + HX_CSTRING("<font color='")) + HX_CSTRING("#ff0070")) + HX_CSTRING("'>")) + this->memMaxStr) + HX_CSTRING("</font>")) + HX_CSTRING("<br>")) + HX_CSTRING("<font color='")) + HX_CSTRING("#00ff00")) + HX_CSTRING("'>")) + this->msStr) + HX_CSTRING("</font>"));
		HX_STACK_LINE(180)
		if ((this->fastUpdate)){
			HX_STACK_LINE(181)
			this->text->set_htmlText(this->htmlText);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,update,(void))

Void Stats_obj::destroy( ::native::events::Event e){
{
		HX_STACK_PUSH("Stats::destroy","com/minigloop/util/Stats.hx",111);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(113)
		this->get_graphics()->clear();
		HX_STACK_LINE(115)
		while(((this->get_numChildren() > (int)0))){
			HX_STACK_LINE(116)
			this->removeChildAt((int)0);
		}
		HX_STACK_LINE(118)
		this->graph->dispose();
		HX_STACK_LINE(120)
		this->removeEventListener(::native::events::Event_obj::ENTER_FRAME,this->update_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,destroy,(void))

Void Stats_obj::init( ::native::events::Event e){
{
		HX_STACK_PUSH("Stats::init","com/minigloop/util/Stats.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(94)
		this->_stage = ::nme::Lib_obj::get_current()->get_stage();
		HX_STACK_LINE(95)
		this->get_graphics()->beginFill((int)51,null());
		HX_STACK_LINE(96)
		this->get_graphics()->drawRect((int)0,(int)0,(int)70,(int)50);
		HX_STACK_LINE(97)
		this->get_graphics()->endFill();
		HX_STACK_LINE(99)
		this->addChild(this->text);
		HX_STACK_LINE(101)
		this->graph = ::native::display::BitmapData_obj::__new((int)70,(int)50,false,(int)51,null());
		HX_STACK_LINE(102)
		this->get_graphics()->beginBitmapFill(this->graph,::native::geom::Matrix_obj::__new((int)1,(int)0,(int)0,(int)1,(int)0,(int)50),null(),null());
		HX_STACK_LINE(103)
		this->get_graphics()->drawRect((int)0,(int)50,(int)70,(int)50);
		HX_STACK_LINE(105)
		this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->update_dyn(),null(),null(),null());
		HX_STACK_LINE(107)
		if ((this->alignRight)){
			HX_STACK_LINE(108)
			this->set_x((::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - this->get_width()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,init,(void))

int Stats_obj::GRAPH_WIDTH;

int Stats_obj::XPOS;

int Stats_obj::GRAPH_HEIGHT;

int Stats_obj::TEXT_HEIGHT;


Stats_obj::Stats_obj()
{
}

void Stats_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stats);
	HX_MARK_MEMBER_NAME(htmlText,"htmlText");
	HX_MARK_MEMBER_NAME(msStr,"msStr");
	HX_MARK_MEMBER_NAME(memMaxStr,"memMaxStr");
	HX_MARK_MEMBER_NAME(memStr,"memStr");
	HX_MARK_MEMBER_NAME(fpsStr,"fpsStr");
	HX_MARK_MEMBER_NAME(_stage,"_stage");
	HX_MARK_MEMBER_NAME(mem_max_graph,"mem_max_graph");
	HX_MARK_MEMBER_NAME(ms_graph,"ms_graph");
	HX_MARK_MEMBER_NAME(mem_graph,"mem_graph");
	HX_MARK_MEMBER_NAME(fps_graph,"fps_graph");
	HX_MARK_MEMBER_NAME(fastUpdate,"fastUpdate");
	HX_MARK_MEMBER_NAME(alignRight,"alignRight");
	HX_MARK_MEMBER_NAME(rectangle,"rectangle");
	HX_MARK_MEMBER_NAME(graph,"graph");
	HX_MARK_MEMBER_NAME(mem_max,"mem_max");
	HX_MARK_MEMBER_NAME(mem,"mem");
	HX_MARK_MEMBER_NAME(ms_prev,"ms_prev");
	HX_MARK_MEMBER_NAME(ms,"ms");
	HX_MARK_MEMBER_NAME(fps,"fps");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(text,"text");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Stats_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(htmlText,"htmlText");
	HX_VISIT_MEMBER_NAME(msStr,"msStr");
	HX_VISIT_MEMBER_NAME(memMaxStr,"memMaxStr");
	HX_VISIT_MEMBER_NAME(memStr,"memStr");
	HX_VISIT_MEMBER_NAME(fpsStr,"fpsStr");
	HX_VISIT_MEMBER_NAME(_stage,"_stage");
	HX_VISIT_MEMBER_NAME(mem_max_graph,"mem_max_graph");
	HX_VISIT_MEMBER_NAME(ms_graph,"ms_graph");
	HX_VISIT_MEMBER_NAME(mem_graph,"mem_graph");
	HX_VISIT_MEMBER_NAME(fps_graph,"fps_graph");
	HX_VISIT_MEMBER_NAME(fastUpdate,"fastUpdate");
	HX_VISIT_MEMBER_NAME(alignRight,"alignRight");
	HX_VISIT_MEMBER_NAME(rectangle,"rectangle");
	HX_VISIT_MEMBER_NAME(graph,"graph");
	HX_VISIT_MEMBER_NAME(mem_max,"mem_max");
	HX_VISIT_MEMBER_NAME(mem,"mem");
	HX_VISIT_MEMBER_NAME(ms_prev,"ms_prev");
	HX_VISIT_MEMBER_NAME(ms,"ms");
	HX_VISIT_MEMBER_NAME(fps,"fps");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(text,"text");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Stats_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ms") ) { return ms; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mem") ) { return mem; }
		if (HX_FIELD_EQ(inName,"fps") ) { return fps; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"XPOS") ) { return XPOS; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"text") ) { return text; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"msStr") ) { return msStr; }
		if (HX_FIELD_EQ(inName,"graph") ) { return graph; }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"memStr") ) { return memStr; }
		if (HX_FIELD_EQ(inName,"fpsStr") ) { return fpsStr; }
		if (HX_FIELD_EQ(inName,"_stage") ) { return _stage; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"mem_max") ) { return mem_max; }
		if (HX_FIELD_EQ(inName,"ms_prev") ) { return ms_prev; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"htmlText") ) { return htmlText; }
		if (HX_FIELD_EQ(inName,"ms_graph") ) { return ms_graph; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"memMaxStr") ) { return memMaxStr; }
		if (HX_FIELD_EQ(inName,"mem_graph") ) { return mem_graph; }
		if (HX_FIELD_EQ(inName,"fps_graph") ) { return fps_graph; }
		if (HX_FIELD_EQ(inName,"rectangle") ) { return rectangle; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fastUpdate") ) { return fastUpdate; }
		if (HX_FIELD_EQ(inName,"alignRight") ) { return alignRight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"GRAPH_WIDTH") ) { return GRAPH_WIDTH; }
		if (HX_FIELD_EQ(inName,"TEXT_HEIGHT") ) { return TEXT_HEIGHT; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GRAPH_HEIGHT") ) { return GRAPH_HEIGHT; }
		if (HX_FIELD_EQ(inName,"normalizeMem") ) { return normalizeMem_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mem_max_graph") ) { return mem_max_graph; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Stats_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ms") ) { ms=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mem") ) { mem=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fps") ) { fps=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"XPOS") ) { XPOS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"text") ) { text=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"msStr") ) { msStr=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"graph") ) { graph=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"memStr") ) { memStr=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fpsStr") ) { fpsStr=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stage") ) { _stage=inValue.Cast< ::native::display::Stage >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mem_max") ) { mem_max=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ms_prev") ) { ms_prev=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"htmlText") ) { htmlText=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ms_graph") ) { ms_graph=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"memMaxStr") ) { memMaxStr=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mem_graph") ) { mem_graph=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fps_graph") ) { fps_graph=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rectangle") ) { rectangle=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fastUpdate") ) { fastUpdate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alignRight") ) { alignRight=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"GRAPH_WIDTH") ) { GRAPH_WIDTH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TEXT_HEIGHT") ) { TEXT_HEIGHT=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GRAPH_HEIGHT") ) { GRAPH_HEIGHT=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mem_max_graph") ) { mem_max_graph=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Stats_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("htmlText"));
	outFields->push(HX_CSTRING("msStr"));
	outFields->push(HX_CSTRING("memMaxStr"));
	outFields->push(HX_CSTRING("memStr"));
	outFields->push(HX_CSTRING("fpsStr"));
	outFields->push(HX_CSTRING("_stage"));
	outFields->push(HX_CSTRING("mem_max_graph"));
	outFields->push(HX_CSTRING("ms_graph"));
	outFields->push(HX_CSTRING("mem_graph"));
	outFields->push(HX_CSTRING("fps_graph"));
	outFields->push(HX_CSTRING("fastUpdate"));
	outFields->push(HX_CSTRING("alignRight"));
	outFields->push(HX_CSTRING("rectangle"));
	outFields->push(HX_CSTRING("graph"));
	outFields->push(HX_CSTRING("mem_max"));
	outFields->push(HX_CSTRING("mem"));
	outFields->push(HX_CSTRING("ms_prev"));
	outFields->push(HX_CSTRING("ms"));
	outFields->push(HX_CSTRING("fps"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("text"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("GRAPH_WIDTH"),
	HX_CSTRING("XPOS"),
	HX_CSTRING("GRAPH_HEIGHT"),
	HX_CSTRING("TEXT_HEIGHT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("normalizeMem"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("init"),
	HX_CSTRING("htmlText"),
	HX_CSTRING("msStr"),
	HX_CSTRING("memMaxStr"),
	HX_CSTRING("memStr"),
	HX_CSTRING("fpsStr"),
	HX_CSTRING("_stage"),
	HX_CSTRING("mem_max_graph"),
	HX_CSTRING("ms_graph"),
	HX_CSTRING("mem_graph"),
	HX_CSTRING("fps_graph"),
	HX_CSTRING("fastUpdate"),
	HX_CSTRING("alignRight"),
	HX_CSTRING("rectangle"),
	HX_CSTRING("graph"),
	HX_CSTRING("mem_max"),
	HX_CSTRING("mem"),
	HX_CSTRING("ms_prev"),
	HX_CSTRING("ms"),
	HX_CSTRING("fps"),
	HX_CSTRING("timer"),
	HX_CSTRING("text"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stats_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Stats_obj::GRAPH_WIDTH,"GRAPH_WIDTH");
	HX_MARK_MEMBER_NAME(Stats_obj::XPOS,"XPOS");
	HX_MARK_MEMBER_NAME(Stats_obj::GRAPH_HEIGHT,"GRAPH_HEIGHT");
	HX_MARK_MEMBER_NAME(Stats_obj::TEXT_HEIGHT,"TEXT_HEIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stats_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Stats_obj::GRAPH_WIDTH,"GRAPH_WIDTH");
	HX_VISIT_MEMBER_NAME(Stats_obj::XPOS,"XPOS");
	HX_VISIT_MEMBER_NAME(Stats_obj::GRAPH_HEIGHT,"GRAPH_HEIGHT");
	HX_VISIT_MEMBER_NAME(Stats_obj::TEXT_HEIGHT,"TEXT_HEIGHT");
};

Class Stats_obj::__mClass;

void Stats_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.minigloop.util.Stats"), hx::TCanCast< Stats_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Stats_obj::__boot()
{
	GRAPH_WIDTH= (int)70;
	XPOS= (int)69;
	GRAPH_HEIGHT= (int)50;
	TEXT_HEIGHT= (int)50;
}

} // end namespace com
} // end namespace minigloop
} // end namespace util
