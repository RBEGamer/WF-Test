# CMake File for the WF Repo
cmake_minimum_required (VERSION 2.8.11)
project (wf_server)
set(EXECUTABLE_OUTPUT_PATH "bin")
set(OUTPUT_NAME "wf_server")
file(GLOB Sources "*.cpp")









add_executable(wf_server ${Sources})


# INI PARSER LIB
# target_link_libraries(wf_server ${PROJECT_SOURCE_DIR}/bin/ini_parser.a)
# target_link_libraries(wf_server ${PROJECT_SOURCE_DIR}/bin/debug_logger.a)
# arget_link_libraries(wf_server ${PROJECT_SOURCE_DIR}/bin/bitmap_loader.a)
target_link_libraries(wf_server ${PROJECT_SOURCE_DIR}/bin/rpi_spi.a)
