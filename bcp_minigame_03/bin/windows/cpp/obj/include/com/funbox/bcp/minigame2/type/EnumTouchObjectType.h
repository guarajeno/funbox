#ifndef INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType
#define INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,type,EnumTouchObjectType)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace type{


class EnumTouchObjectType_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EnumTouchObjectType_obj OBJ_;
		EnumTouchObjectType_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EnumTouchObjectType_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EnumTouchObjectType_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EnumTouchObjectType"); }

		static int PLAYER; /* REM */ 
		static int MONEY; /* REM */ 
		static int COIN; /* REM */ 
		static int BOT_COLLECTOR; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace type

#endif /* INCLUDED_com_funbox_bcp_minigame2_type_EnumTouchObjectType */ 
