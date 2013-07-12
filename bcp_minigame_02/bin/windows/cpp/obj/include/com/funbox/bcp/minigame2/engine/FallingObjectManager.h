#ifndef INCLUDED_com_funbox_bcp_minigame2_engine_FallingObjectManager
#define INCLUDED_com_funbox_bcp_minigame2_engine_FallingObjectManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,EntitiesController)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,engine,FallingObjectManager)
HX_DECLARE_CLASS5(com,funbox,bcp,minigame2,util,NInterval)
namespace com{
namespace funbox{
namespace bcp{
namespace minigame2{
namespace engine{


class FallingObjectManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FallingObjectManager_obj OBJ_;
		FallingObjectManager_obj();
		Void __construct(::com::funbox::bcp::minigame2::engine::EntitiesController entitiesController);

	public:
		static hx::ObjectPtr< FallingObjectManager_obj > __new(::com::funbox::bcp::minigame2::engine::EntitiesController entitiesController);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FallingObjectManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FallingObjectManager"); }

		virtual Void free( );
		Dynamic free_dyn();

		virtual Void update( int dt);
		Dynamic update_dyn();

		virtual Void onCreateEntitie( );
		Dynamic onCreateEntitie_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void onFinishThenCreate_2( );
		Dynamic onFinishThenCreate_2_dyn();

		virtual Void onFinishThenCreate_1( );
		Dynamic onFinishThenCreate_1_dyn();

		Array< int > mTouchObjectsToChoose; /* REM */ 
		bool mStarted; /* REM */ 
		::com::funbox::bcp::minigame2::util::NInterval mIntervalCreation_2; /* REM */ 
		::com::funbox::bcp::minigame2::util::NInterval mIntervalCreation_1; /* REM */ 
		::com::funbox::bcp::minigame2::engine::EntitiesController mEntitiesController; /* REM */ 
};

} // end namespace com
} // end namespace funbox
} // end namespace bcp
} // end namespace minigame2
} // end namespace engine

#endif /* INCLUDED_com_funbox_bcp_minigame2_engine_FallingObjectManager */ 
