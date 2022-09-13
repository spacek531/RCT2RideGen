cmake_minimum_required (VERSION 3.1)
project (RCT2RideGen C)

find_package(PNG REQUIRED)
find_package(embree 3 REQUIRED)
find_package(assimp CONFIG REQUIRED)

if (MSVC) # assumes vcpkg
set(EMBREE embree3)
set(ASSIMP assimp::assimp)
set(MATH_LIB "")
else()
set(EMBREE embree3)
set(ASSIMP assimp)
set(MATH_LIB m)
endif()

include_directories(${PNG_INCLUDE_DIR} ${JANSSON_INCLUDE_DIR} ${EMBREE_INCLUDE_DIR} ../libIsoRender/src)
link_directories(../libIsoRender)
link_directories(${EMBREE_ROOT_DIR}/lib ${ASSIMP_LIBRARY_DIRS})

add_executable(makeride src/main.c src/project.c)
set_property(TARGET makeride PROPERTY C_STANDARD 99)
target_link_libraries (makeride ${PNG_LIBRARY} IsoRender ${EMBREE} ${ASSIMP} jansson ${MATH_LIB})

