#!bin/sh

echo "---------------------------------"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi





cd ..
if [ -d "WeatherFrame-FPGA-EDITION" ]; then
cd WeatherFrame-FPGA-EDITION
echo "---- WF PULL ----"
#PKEY=~/.ssh/id_rsa.pub git pull
cd src
sh ./wf_compile_all.sh
sh ./wf_autostart.sh
exit 0
else
# Control will enter here if $DIRECTORY exists.
cd ..
echo "---- WF CLONE----"
PKEY=~/.ssh/id_rsa.pub git clone git@github.com:RBEGamer/WeatherFrame-FPGA-EDITION.git
cd WeatherFrame-FPGA-EDITION
cd src
sh ./wf_compile_all.sh
sh ./wf_autostart.sh
exit 0
fi
