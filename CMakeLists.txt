cmake_minimum_required(VERSION 3.3)
project(GF_MCP_Pro)


add_definitions( -DAPL=1 )

add_definitions( -DXPLM200=1 -DXPLM210=1 )



set( HID_API_FOLDER "$ENV{HOME}/Dropbox/Dev/hidapi/hidapi/" )
message( ${HID_API_FOLDER} )


set( XP_SDK "$ENV{HOME}/Dropbox/Dev/XP_SDK_213" )
message( ${XP_SDK} )


# Configure our include paths.
set( INC_XPLANE_SDK
        "${XP_SDK}/CHeaders/Widgets"
        "${XP_SDK}/CHeaders/Wrappers"
        "${XP_SDK}/CHeaders/XPLM"
        )
message(${INC_XPLANE_SDK})


include_directories( ${HID_API_FOLDER} ${INC_XPLANE_SDK} )



set(SOURCE_FILES hid.c XPLGlue.cpp XPLGlue.h GFUtils.cpp GFUtils.h GFMCPPro.cpp GFMCPPro.h GFDataref.cpp GFDataref.h GFCommand.cpp GFCommand.h GFMCPPro_LEDS.cpp GFMCPPro_LEDS.h GFMCPPro_Buttons.cpp GFMCPPro_Buttons.h GFMCPPro_7Seg.cpp GFMCPPro_7Seg.h)




set( MAC_FRAMEWORKS "-framework IOKit -framework Carbon" )

set(CMAKE_SHARED_LINKER_FLAGS "${MAC_FRAMEWORKS} -undefined warning -flat_namespace -v")
set( CMAKE_EXE_LINKER_FLAGS "${MAC_FRAMEWORKS}" )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11")



#add_executable(GF_MCP_Pro_exe ${SOURCE_FILES})

SET( OUTPUT_FILENAME "GF_MCP_Pro_mac" )

add_library(${OUTPUT_FILENAME} SHARED ${SOURCE_FILES})

SET_TARGET_PROPERTIES(${OUTPUT_FILENAME} PROPERTIES PREFIX  "" )
SET_TARGET_PROPERTIES(${OUTPUT_FILENAME} PROPERTIES SUFFIX ".xpl")

target_link_libraries( ${OUTPUT_FILENAME}  )


#add_library(GF_MCP_Pro SHARED ${SOURCE_FILES})