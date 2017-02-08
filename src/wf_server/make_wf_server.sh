#!bin/bash


file="bin/wf_server"
if [ -f "$file" ]
then
rm $file
fi

echo "---- WF CMAKE----"
cmake -G "Unix Makefiles" CMakeLists.txt
echo "---- WF COMPILE----"
make all
echo "---- WF CMAKE CLEANUP----"
rm cmake_install.cmake
rm CMakeCache.txt
rm -R -f CMakeFiles
