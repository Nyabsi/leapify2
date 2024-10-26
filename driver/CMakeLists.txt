set(SRC src)

set(SOURCE_FILES 
	${SRC}/main.cc
	${SRC}/TrackedDeviceProvider.cc
	${SRC}/InterfaceFactory.cc
)

add_library(driver_leapify SHARED ${SOURCE_FILES})

target_include_directories(driver_leapify PRIVATE include)

target_link_libraries(driver_leapify PRIVATE rcmp LeapC openvr)