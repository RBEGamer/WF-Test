#!bin/bash
clear
echo "----WF BUILD STARTUP----"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cd wf_server/


echo "----WF-MAKE LIBS----"
cd ini_parser/
sh make_lib_ini_parser.sh
cd ..



echo "----WF-MAKE MAIN----"
sh make_wf_server.sh



clear
echo "---- WF START----"
./bin/wf_server




cd ..



