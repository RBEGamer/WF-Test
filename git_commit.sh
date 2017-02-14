#!bin/bash
echo "---------------------------------"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi


git commit -a

git push

exit 0
