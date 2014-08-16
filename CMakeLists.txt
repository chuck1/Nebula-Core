CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(nebula_core)

FIND_PACKAGE(CMakeHelper)
FIND_PACKAGE(glfw)
FIND_PACKAGE(Galaxy COMPONENTS
	std
	log
	console
	REQUIRED)

cmh_boost_static()
FIND_PACKAGE(Boost 1.55 COMPONENTS
	serialization
	REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -D_DEBUG -std=c++0x")

include_directories("/usr/include/freetype2")
include_directories("../glm")
#include_directories(${physx_INCLUDE_DIR})

ADD_DEFINITIONS("-D_DEBUG -DGLM_FORCE_RADIANS")

# custom include extensions
set(include_extensions obj)

SET(GRU_VERSION 0.1.1)


SET(libs ${libs}
	${Galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	${glfw_LIBRARIES}
	)

cmh_static_library()



PROJECT(nebula_core_shared)

SET(Galaxy_SHARED TRUE)
FIND_PACKAGE(Galaxy COMPONENTS
	std
	log
	console
	REQUIRED)

cmh_boost_shared()
FIND_PACKAGE(Boost 1.55 COMPONENTS
	python
	serialization
	REQUIRED)

SET(libs
	${Galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	${glfw_LIBRARIES}
	python2.7
	)


cmh_shared_library()

add_subdirectory(test)




