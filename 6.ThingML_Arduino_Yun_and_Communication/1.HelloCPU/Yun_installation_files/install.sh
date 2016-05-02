#!/bin/sh

echo "Libraries Installation"

if test -d /usr/lib/Headers
	then cp ./Headers/* /usr/lib/Headers/
	else cp -r ./Headers /usr/lib/
fi

cp ./lib/* /usr/lib/

echo "Shutting Bridge down"

sed -i'' '/ttyATH0/ s/^/#/' /etc/inittab

echo "You can now reboot the CPU of your Yùn"

