include_directories(${MyProject_SOURCE_DIR}/src})
link_directories(${MyProject_SOURCE_DIR}/src})

file(GLOB src
        "*.h"
        "*.cpp"
)

add_executable(QSim ${src})