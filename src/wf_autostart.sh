#!bin/bash
clear
echo "----WF-STARTUP----"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cd wf_server


echo "---- WF CMAKE----"
cmake CMakeLists.txt

echo "---- WF CMAKE CLEANUP----"
rm cmake_install.cmake
rm CMakeCache.txt
rm -R -f CMakeFiles


echo "---- WF COMPILE----"
make all


clear
echo "---- WF START----"
./bin/wf_server




cd ..



