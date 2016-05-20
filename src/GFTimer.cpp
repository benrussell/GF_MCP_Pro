//
// Created by Ben on 20/05/2016.
//

#include "GFTimer.h"

#include "GFUtils.h"


GFTimer::GFTimer(){

	_dref = XPLMFindDataRef( "sim/time/total_running_time_sec" );
	_duration = 1.f; //1 second default.
	_enabled = false;

}



GFTimer::~GFTimer(){
	//no cleanup required for now.
}



void GFTimer::run() {

	float marker_delta = _now() - _start_marker;

	if( marker_delta > _duration ){
		_run_action();
		_enabled = false;
	}

}



void GFTimer::reset() {

	_start_marker = _now();
	_enabled = true;

}



void GFTimer::_run_action() {

	GFUtils::Log("GFTimer::run_action default.\n");

}



float GFTimer::_now(){

	return XPLMGetDataf( _dref );

}



// eof
