#!bin/bash
clear
echo "----WF BUILD STARTUP----"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cd wf_server/


echo "----WF-MAKE MAIN----"
sh make_wf_server.sh


cd ..

echo "----START---"
sh wf_autostart.sh
