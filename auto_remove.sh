#!bin/sh
echo "---------------------------------"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cd ..
rm -R WeatherFrame-FPGA-EDITION
git clone https://github.com/RBEGamer/WeatherFrame-FPGA-EDITION.git
cd WeatherFrame-FPGA-EDITION
sh auto_clone.sh
