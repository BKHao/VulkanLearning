cmake_minimum_required(VERSION 3.17)

add_executable(run main.cpp)
target_link_libraries(run PRIVATE ${VKL_LIBS})
target_include_directories(run PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>
)

