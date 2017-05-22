#!/bin/bash 

OS=$(awk '/DISTRIB_ID=/' /etc/*-release | sed 's/DISTRIB_ID=//' | tr '[:upper:]' '[:lower:]')

if [ -z "$OS" ]; then
    OS=$(awk '{print $1}' /etc/*-release | tr '[:upper:]' '[:lower:]')
fi

if [ "$OS" == "arch" ]; then
	sudo pacman -S git gcc nasm make intltool pkg-config gnome-doc-utils devhelp gtk3 gstreamer clutter webkitgtk3 libgda gobject-introspection

elif [ "$OS" == "ubuntu" ]; then
	sudo apt install git build-essential gcc nasm pkg-config libgtk-3-dev libgstreamer1.0-dev libclutter-1.0-dev libwebkit2gtk-4.0-dev libgda-5.0-dev libgtk-3-doc gstreamer1.0-doc libclutter-1.0-doc libwebkit2gtk-4.0-doc libgda-5.0-doc 

elif [ "$OS" == "debian" ]; then
	sudo apt install git build-essential gcc nasm pkg-config libgtk-3-dev libgtk-3-doc intltool
fi

other_OS=$(echo $OS |grep pretty_name | awk -F "=" '{print $2}' | awk -F "\"" '{ print $2 }' | awk -F " " '{print $1 }')
#echo -e "$other_OS"

if [ "$other_OS" == "debian" ]; then
	sudo apt install git build-essential gcc nasm pkg-config libgtk-3-dev libgtk-3-doc intltool
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

echo -e "\n\n\n\t\t\tALL DEPENDENCIES INSTALLED WITH SUCCESS [!!]\n\n\n"
