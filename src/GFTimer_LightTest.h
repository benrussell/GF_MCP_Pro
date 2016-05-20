//
// Created by Ben on 20/05/2016.
//

#ifndef GF_MCP_PRO_PARENT_GFTIMER_LIGHTTEST_H
#define GF_MCP_PRO_PARENT_GFTIMER_LIGHTTEST_H

#include "GFTimer.h"

#include "GFMCPPro_State.h"

class GFTimer_LightTest : public GFTimer {
public:
	GFTimer_LightTest( GFMCPPro_State* mcp_state );
	~GFTimer_LightTest();
	virtual void _run_action();

private:
	GFMCPPro_State* _mcp_state;

};


#endif //GF_MCP_PRO_PARENT_GFTIMER_LIGHTTEST_H
