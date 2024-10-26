add_subdirectory(openvr)

add_library(openvr INTERFACE)
target_include_directories(openvr INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/openvr/headers")

add_subdirectory(rcmp)

target_include_directories(rcmp INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/rcmp/include")

add_library(LeapC INTERFACE)
target_include_directories(LeapC INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/leapsdk/include")
target_link_directories(LeapC INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/leapsdk/lib/x64")