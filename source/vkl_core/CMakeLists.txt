cmake_minimum_required(VERSION 3.17)

set(UTILS_SOURCE
        utils/utils.h)
source_group("utils" FILES ${UTILS_SOURCE})

set(WINDOW_SOURCE
        window/vkl_win.h
        window/app.h
        window/app.cpp
        window/window.h
        window/window.cpp)
source_group("window" FILES ${WINDOW_SOURCE})

set(CORE_SOURCE_FILES 
        ${WINDOW_SOURCE}
        ${UTILS_SOURCE})

if(BUILD_SHARED_LIBS)
        add_library(vkl_core SHARED ${CORE_SOURCE_FILES})
else()
        add_library(vkl_core STATIC ${CORE_SOURCE_FILES})
endif()
set_target_properties(vkl_core PROPERTIES VERSION ${VERSION})
set_target_properties(vkl_core PROPERTIES CLEAN_DIRECT_OUTPUT 1)

target_include_directories(vkl_core PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>
	$<INSTALL_INTERFACE:include>
        ${Vulkan_INCLUDE_DIRS})

target_link_libraries(vkl_core PUBLIC glfw ${Vulkan_LIBRARIES})

