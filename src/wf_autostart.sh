#!bin/bash
clear
echo "----WF-STARTUP----"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cd wf_server


echo "---- WF CMAKE----"
cmake -G "Unix Makefiles" CMakeLists.txt






echo "---- WF COMPILE----"
make all


echo "---- WF CMAKE CLEANUP----"
rm cmake_install.cmake
rm CMakeCache.txt
rm -R -f CMakeFiles


#clear
echo "---- WF START----"
./bin/wf_server




cd ..



