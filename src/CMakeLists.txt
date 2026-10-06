add_library(motion_core
  version.cpp
)
add_library(motion::core ALIAS motion_core)

target_include_directories(motion_core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(motion_core PUBLIC cxx_std_23)
target_compile_definitions(motion_core PRIVATE MOTION_VERSION="${PROJECT_VERSION}")
motion_set_warnings(motion_core)
