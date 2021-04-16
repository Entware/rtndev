#!/bin/sh

cd /opt/tmp
ln -s /opt/lib/libcryptopp.so libcryptopp.so
cryptest.exe tv all
if [ $? -ne 0 ]; then
    echo 'libcryptopp tests failed! Possibly broken by -02 flag.'
    exit 1
fi
cryptest.exe v
