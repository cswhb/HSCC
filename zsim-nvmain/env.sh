#!/bin/sh
ZSIMPATH=/home/whb/HSCC/zsim-nvmain
PINPATH=$ZSIMPATH/pin_kit
NVMAINPATH=$ZSIMPATH/nvmain
ZSIMBIN=$ZSIMPATH/bin/zsim
BOOST=/usr/local/boost-1.59
HDF5=/usr/local/hdf5-1.8.3
LIBCONFIG=/usr/local/libconfig-1.5
GUPSPATH=/home/wxy/gups
MPICHPATH=/home/wxy/mpich
PATH=$MPICHPATH/lib:/home/wxy/mpich/bin:$PATH
LD_LIBRARY_PATH=$PINPATH/intel64/lib:$PINPATH/intel64/runtime:$PINPATH/intel64/lib:$PINPATH/intel64/lib-ext:$BOOST/lib:$HDF5/lib:/usr/local/gmp/lib:/usr/local/mpfr/lib:/usr/local/mpc/lib:$LIBCONFIG/lib:/usr/local/lib:$MPICHPATH/lib:
INCLUDE=$INCLUDE:$HDF5/include:$LIBCONFIG/include:/usr/local/lib
LIBRARY_PATH=$LIBRARY_PATH:$HDF5/lib:$LIBCONFIG/lib
CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$HDF5/include:$LIBCONFIG/include
SIMPOINT_DIR=/home/chenji/hscc/simpoints
HSCC_CONFIG=/home/chenji/hscc/config
PBBPATH=/home/wxy/benchmark/pbbs
CPUSPECPATH=/home/wxy/benchmark/spec_cpu2006/benchspec/CPU2006
PARSECPATH=/home/wxy/benchmark/parsec-3.0/pkgs

Graph500PATH=/public/disk/wxy/benchmark/graph500/src
GUPSPATH=/home/wxy/benchmark/gups
TMPFILE=/public/disk/wxy/benchmark/graph500/outputs/graph500_23
REUSEFILE=1

export Graph500PATH TMPFILE REUSEFILE PATH GUPSPATH MPICHPATH ZSIMPATH PINPATH NVMAINPATH LD_LIBRARY_PATH BOOST CPLUS_INCLUDE_PATH LIBRARY_PATH HSCC_CONFIG PBBPATH CPUSPECPATH PARSECPATH SIMPOINT_DIR ZSIMBIN
