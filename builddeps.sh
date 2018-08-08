#!/bin/bash

BASE=$PWD/dependency
cd ${BASE}/systemc-2.3.1
./autogen.sh
./configure --prefix=${BASE}/../install/systemc
make all install

cd ${BASE}/ArchC
./autogen.sh
./configure --prefix=${BASE}/../install/archc --with-systemc=${BASE}/../install/systemc
make all install

cd ${BASE}/../
ln -s install/archc/etc/env.sh .
