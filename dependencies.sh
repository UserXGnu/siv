#!/bin/bash 

OS=$(awk '/DISTRIB_ID=/' /etc/*-release | sed 's/DISTRIB_ID=//' | tr '[:upper:]' '[:lower:]')

if [ -z "$OS" ]; then
    OS=$(awk '{print $1}' /etc/*-release | tr '[:upper:]' '[:lower:]')
fi

if [ "$OS" == "arch" ]; then
	sudo pacman -Syy && sudo pacman -S git gcc nasm make intltool pkg-config gnome-doc-utils devhelp gtk3 gstreamer clutter webkitgtk3 libgda gobject-introspection

elif [ "$OS" == "ubuntu" ]; then
UN=$(cat /etc/apt/sources.list | grep universe | cut -d " " -f5)
	if [ "$UN" != "universe" ]; then
		echo -e "\n\n\n\t\t\tAdding universe repository to sources.list\n\n\n"
		su -c 'echo "deb http://us.archive.ubuntu.com/ubuntu xenial main universe" >> /etc/apt/sources.list'
		sleep 3
	fi
	sudo apt update && sudo apt install git build-essential gcc nasm pkg-config libgtk-3-dev libgtk-3-doc
elif [ "$OS" == "debian" ]; then
	su -c 'apt update && sudo apt install git build-essential gcc nasm pkg-config libgtk-3-dev libgtk-3-doc intltool'
else

	other_OS=$(echo $OS |grep pretty_name | awk -F "=" '{print $2}' | awk -F "\"" '{ print $2 }' | awk -F " " '{print $1 }')
	#echo -e "$other_OS"

	if [ "$other_OS" == "debian" ]; then
		su -c 'apt update && apt install git build-essential gcc nasm pkg-config libgtk-3-dev libgtk-3-doc intltool'
	fi
fi
echo -e "\n\n\n\t\t\tCOMPILING JWASM FROM ORIGINAL REPOS\n\n\n"
sleep 3

wget https://github.com/JWasm/JWasm/archive/master.zip
unzip master.zip
rm -rf master.zip 
cd JWasm-master
make -f GccUnix.mak 

echo -e "\n\n\n\t\t\t\t\tINSTALLING JWASM\n\n\n"
sudo cp GccUnixR/jwasm /usr/bin/ 
sleep 3

cd ../ 
rm -rf JWasm-master

echo -e "\n\n\n\t\t\tALL DEPENDENCIES SUCCESSFULLY INSTALLED [!!]\n\n\n"
