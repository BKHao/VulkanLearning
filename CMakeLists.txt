cmake_minimum_required(VERSION 3.17)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_CMAKE_PATH})
project(VulkanLearning)
SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})

# Default Build_type RELEASE
# set(CMAKE_BUILD_TYPE RELEASE)
# CXX STANDARD
set(CMAKE_CXX_STANDARD 20)
# Set Version
set(VERSION 1.0)
# Set lib output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/DEBUG)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/DEBUG)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/DEBUG)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)

# # include header from project_source_dir
# include_directories(${PROJECT_SOURCE_DIR}/include)

option(BUILD_SHARED_LIBS "build dynamic libs" OFF)
if(BUILD_SHARED_LIBS)
  add_definitions(-DBUILD_SHARED_LIBS)
endif()

find_package(glfw3 CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

if(WIN32 AND NOT MINGW)
  if(NOT DEFINED CMAKE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX "d")
  endif()
  if(NOT DEFINED CMAKE_RELWITHDEBINFO_POSTFIX)
    set(CMAKE_RELWITHDEBINFO_POSTFIX "rd")
  endif()
  if(NOT DEFINED CMAKE_MINSIZEREL_POSTFIX)
    set(CMAKE_MINSIZEREL_POSTFIX "s")
  endif()
endif()

set(VKL_LIBS vkl_core)

add_subdirectory(source/vkl_core)
add_subdirectory(main)


install(TARGETS ${VKEx_LIBS} run
	EXPORT ${PROJECT_NAME}Targets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	PUBLIC_HEADER DESTINATION include
	)	
install(DIRECTORY ./source/ DESTINATION include
        FILES_MATCHING PATTERN "*.h")
install(EXPORT ${PROJECT_NAME}Targets
	FILE ${PROJECT_NAME}-config.cmake
	NAMESPACE ${PROJECT_NAME}::
	DESTINATION lib/cmake/${PROJECT_NAME}
	)

