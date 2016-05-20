//
// Created by Ben on 20/05/2016.
//

#ifndef GF_MCP_PRO_PARENT_GFTIMER_H
#define GF_MCP_PRO_PARENT_GFTIMER_H

//#include "GFDataref.h"

#include <XPLMDataAccess.h>

class GFTimer {
public:
	GFTimer();
	~GFTimer();

	void run();
	void reset();

	// toggle flag
	bool _enabled;

	// timer duration.
	float _duration;


private:
	//action logic..
	virtual void _run_action();


	//get time from x-p
	float _now();

	//sim time dref.
	XPLMDataRef _dref;

	// timer reference marker.
	float _start_marker;

};


#endif //GF_MCP_PRO_PARENT_GFTIMER_H
