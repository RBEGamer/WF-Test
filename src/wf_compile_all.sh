#!bin/sh
clear
echo "----WF BUILD STARTUP----"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

cd wf_server/


echo "----WF-MAKE LIBS----"
#cd ini_parser/
#sh make_lib_ini_parser.sh
#cd ..

#cd debug_logger/
#sh make_lib_debug_logger.sh
#cd ..


#cd bitmap_loader/
#sh make_lib_bitmap_loader.sh
#cd ..

cd rpi_spi_lib/
sh make_lib_rpi_spi.sh
cd ..

echo "----WF-MAKE MAIN----"
sh make_wf_server.sh





sh wf_start.sh


