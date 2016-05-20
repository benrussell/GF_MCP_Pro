cmake_minimum_required(VERSION 2.8)
project(GF_MCP_Pro)


add_definitions( -DGOFLIGHT_XPL_PRODUCT_NAME="${PROJECT_NAME}" )

set( BINARY_NAME "${PROJECT_NAME}_DEFAULT" )
set( EXTRA_LIBS "" )


add_definitions( -DXPLM200=1 -DXPLM210=1 )
set( XP_SDK "${CMAKE_HOME_DIRECTORY}/../../XP_SDK_213" )
message( ${XP_SDK} )




# Linux
IF(CMAKE_SYSTEM_NAME STREQUAL Linux)
    set( BINARY_NAME "${PROJECT_NAME}_lin" )
    add_definitions( -DLIN=1 )
    set( CMAKE_SHARED_LINKER_FLAGS "-v" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") #-std=c++11" )
    set( HID_C_FILE "${CMAKE_HOME_DIRECTORY}/../../hidapi/linux/hid.c" )
ENDIF(CMAKE_SYSTEM_NAME STREQUAL Linux)



IF( APPLE )
    set( BINARY_NAME "${PROJECT_NAME}_mac" )
    add_definitions( -DAPL=1 )
    set( MAC_FRAMEWORKS "-framework IOKit -framework Carbon" )
    set( CMAKE_SHARED_LINKER_FLAGS "${MAC_FRAMEWORKS} -undefined warning -flat_namespace -v" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # -std=c++11" )
    set( HID_C_FILE "${CMAKE_HOME_DIRECTORY}/../../hidapi/mac/hid.c" )
ENDIF( APPLE )



IF(CMAKE_SYSTEM_NAME STREQUAL Windows)
    set( BINARY_NAME "${PROJECT_NAME}_win" )
    add_definitions( -DIBM=1 )

    LINK_DIRECTORIES(
            "C:/Program Files (x86)/Windows Kits/8.0/Lib/win8/um/x64"
            "${XP_SDK}/Libraries/Win"
    )

    set( EXTRA_LIBS
            XPLM_64.lib
            XPWidgets_64.lib
            hid.lib
            setupapi.lib
            )

    set( CMAKE_SHARED_LINKER_FLAGS "-v" )
    set( HID_C_FILE "${CMAKE_HOME_DIRECTORY}/../../hidapi/windows/hid.c" )

ENDIF(CMAKE_SYSTEM_NAME STREQUAL Windows)



set( HID_API_FOLDER "${CMAKE_HOME_DIRECTORY}/../../hidapi/hidapi/" )
message( ${HID_API_FOLDER} )



# Configure our include paths.
set( INC_XPLANE_SDK
        "${XP_SDK}/CHeaders/Widgets"
        "${XP_SDK}/CHeaders/Wrappers"
        "${XP_SDK}/CHeaders/XPLM"
        )
message(${INC_XPLANE_SDK})


include_directories( ${HID_API_FOLDER} ${INC_XPLANE_SDK} )



set(SOURCE_FILES ${HID_C_FILE} XPLGlue.cpp XPLGlue.h GFUtils.cpp GFUtils.h GFMCPPro.cpp GFMCPPro.h GFDataref.cpp GFDataref.h GFCommand.cpp GFCommand.h GFMCPPro_LEDS.cpp GFMCPPro_LEDS.h GFMCPPro_Buttons.cpp GFMCPPro_Buttons.h GFMCPPro_7Seg.cpp GFMCPPro_7Seg.h GFMCPPro_State.cpp GFMCPPro_State.h Windows_snprintf.h GFTimer.cpp GFTimer.h GFTimer_LightTest.cpp GFTimer_LightTest.h)

SET( OUTPUT_FILENAME ${BINARY_NAME} )

add_library(${OUTPUT_FILENAME} SHARED ${SOURCE_FILES})

SET_TARGET_PROPERTIES(${OUTPUT_FILENAME} PROPERTIES PREFIX  "" )
SET_TARGET_PROPERTIES(${OUTPUT_FILENAME} PROPERTIES SUFFIX ".xpl")


# Perform actual compile and link.
target_link_libraries( ${OUTPUT_FILENAME} ${EXTRA_LIBS} )

