# CMake File for the WF Repo
cmake_minimum_required (VERSION 2.8.11)
project (WF_SERVER)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(OUTPUT_NAME "wf_server")
add_executable(wf_server wf_server_main.cpp)
