#!bin/bash
clear
echo "----WF-STARTUP----"



echo "---- WF COMPILE----"
cd wf_server
sudo make all
./wf_main.o
cd ..
