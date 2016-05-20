//
// Created by Ben on 20/05/2016.
//

#include "GFTimer_LightTest.h"

#include "GFUtils.h"


GFTimer_LightTest::GFTimer_LightTest( GFMCPPro_State* mcp_state ){
	_mcp_state = mcp_state;
}


void GFTimer_LightTest::_run_action() {

	// This function will only be called once by the trigger logic.

	GFUtils::Log("GFTimer_LightTest::_run_action fired.\n");
	_mcp_state->_dref_light_test->_int_value = 0;

}



// eof
