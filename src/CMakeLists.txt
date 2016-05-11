cmake_minimum_required(VERSION 2.8)
project(GF_MCP_Pro)



set( BINARY_NAME "GF_MCP_Pro_DEFAULT" )



IF( APPLE )

    set( BINARY_NAME "GF_MCP_Pro_mac" )

    add_definitions( -DAPL=1 )

    set( MAC_FRAMEWORKS "-framework IOKit -framework Carbon" )
    set( CMAKE_SHARED_LINKER_FLAGS "${MAC_FRAMEWORKS} -undefined warning -flat_namespace -v" )
    #set( CMAKE_EXE_LINKER_FLAGS "${MAC_FRAMEWORKS}" )

    set( HID_C_FILE "${CMAKE_HOME_DIRECTORY}/../../hidapi/mac/hid.c" )

ENDIF( APPLE )



IF(CMAKE_SYSTEM_NAME STREQUAL Windows)

    set( BINARY_NAME "GF_MCP_Pro_win" )

    add_definitions( -DIBM=1 )

    set( HID_C_FILE "${CMAKE_HOME_DIRECTORY}/../../hidapi/windows/hid.c" )

ENDIF(CMAKE_SYSTEM_NAME STREQUAL Windows)



set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )






add_definitions( -DXPLM200=1 -DXPLM210=1 )

set( HID_API_FOLDER "${CMAKE_HOME_DIRECTORY}/../../hidapi/hidapi/" )
message( ${HID_API_FOLDER} )

set( XP_SDK "${CMAKE_HOME_DIRECTORY}/../../XP_SDK_213" )
message( ${XP_SDK} )


# Configure our include paths.
set( INC_XPLANE_SDK
        "${XP_SDK}/CHeaders/Widgets"
        "${XP_SDK}/CHeaders/Wrappers"
        "${XP_SDK}/CHeaders/XPLM"
        )
message(${INC_XPLANE_SDK})


include_directories( ${HID_API_FOLDER} ${INC_XPLANE_SDK} )








set(SOURCE_FILES ${HID_C_FILE} XPLGlue.cpp XPLGlue.h GFUtils.cpp GFUtils.h GFMCPPro.cpp GFMCPPro.h GFDataref.cpp GFDataref.h GFCommand.cpp GFCommand.h GFMCPPro_LEDS.cpp GFMCPPro_LEDS.h GFMCPPro_Buttons.cpp GFMCPPro_Buttons.h GFMCPPro_7Seg.cpp GFMCPPro_7Seg.h GFMCPPro_State.cpp GFMCPPro_State.h Windows_snprintf.h)

SET( OUTPUT_FILENAME ${BINARY_NAME} )

add_library(${OUTPUT_FILENAME} SHARED ${SOURCE_FILES})

SET_TARGET_PROPERTIES(${OUTPUT_FILENAME} PROPERTIES PREFIX  "" )
SET_TARGET_PROPERTIES(${OUTPUT_FILENAME} PROPERTIES SUFFIX ".xpl")


# Perform actual compile and link.
target_link_libraries( ${OUTPUT_FILENAME}  )

