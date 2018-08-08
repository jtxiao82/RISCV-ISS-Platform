#!/bin/sh

srcdir=/home/jtxiao/NTHU/Research/Git/RISCV-ISS-Platform/dependency/ArchC
prefix=/home/jtxiao/NTHU/Research/Git/RISCV-ISS-Platform/dependency/../install/archc
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include

export LD_LIBRARY_PATH="/home/jtxiao/NTHU/Research/Git/RISCV-ISS-Platform/dependency/../install/systemc/lib-linux64:$LD_LIBRARY_PATH"
export PKG_CONFIG_PATH="/home/jtxiao/NTHU/Research/Git/RISCV-ISS-Platform/dependency/../install/systemc/lib-linux64/pkgconfig:$PKG_CONFIG_PATH"

export PATH="$exec_prefix/bin:$PATH"
export LD_LIBRARY_PATH="$libdir:$LD_LIBRARY_PATH"
export PKG_CONFIG_PATH="$libdir/pkgconfig:$PKG_CONFIG_PATH"
export ARCHC_PREFIX="$prefix"

function acroot {
    if [ "$srcdir" ]; then
        cd "$srcdir"
    else
        echo "Couldn't locate the top of the ArchC source code."
    fi
}

function acprefix {
    if [ "$prefix" ]; then
        cd "$prefix"
    else
        echo "Couldn't locate the ArchC installation path."
    fi
}


