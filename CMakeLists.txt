cmake_minimum_required(VERSION 2.8)
project(cg_ufrn)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})

macro(opengl_executable src_file)
    get_filename_component(__target_name ${src_file} NAME_WE)
    add_executable(${__target_name} ${src_file})
    target_link_libraries(${__target_name} 
        -lm
        ${OPENGL_LIBRARIES}
        ${GLUT_glut_LIBRARY})
endmacro()

macro(opengl_examples list_of_files)
    foreach(src_file ${list_of_files})
        opengl_executable(${src_file})
    endforeach()
endmacro()

set(EXAMPLE_SOURCES
    "src/hello.c"
    "src/cube.c"
    "src/double.c"
    "src/clip.c"
    "src/smooth.c"
    "src/planet.c"
    "src/robot.c"
    "src/light.c"
    "src/checker.c"
    "src/mipmap.c"
    "src/texgen.c"
    "src/alpha.c"
    "src/alpha3D.c"
    "src/aargb.c"
    "src/aaindex.c"
    "src/torus.c"
    "src/list.c"
)

opengl_examples("${EXAMPLE_SOURCES}")
