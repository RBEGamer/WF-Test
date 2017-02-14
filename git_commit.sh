#!bin/bash
echo "---------------------------------"

if [ "$(id -u)" != "0" ]; then
echo "Please run with sudo !"
exit 1
fi

#add all files
git add .
#create commit
git commit -a -m "git commit from git_commit.sh please check changed files"
#push to git
PKEY=~/.ssh/id_rsa.pub git push

exit 0
