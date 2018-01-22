#!/bin/sh
# PINPATH=~/pin_kit
PINPATH=~/HSCC/zsim-nvmain/pin_kit
NVMAINPATH=~/HSCC/zsim-nvmain/nvmain
ZSIMPATH=~/HSCC/zsim-nvmain
BOOST=~/boost_1_59_0
HDF5=~/hdf5-1.10.1/hdf5
LIBCONFIG=~/libconfig-1.7.2

# SIMPOINT_DIR=path of simpoint
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PINPATH/intel64/lib:$PINPATH/intel64/runtime:$PINPATH/intel64/lib:$PINPATH/intel64/lib-ext:$BOOST/stage/lib:$HDF5/lib:/usr/local/gmp-4.3.2/lib:/usr/local/mpfr-2.4.2/lib:/usr/local/mpc-0.8.1/lib
INCLUDE=$INCLUDE:$HDF5/include
LIBRARY_PATH=$LIBRARY_PATH:$HDF5/lib
CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$HDF5/include
export ZSIMPATH PINPATH NVMAINPATH LD_LIBRARY_PATH BOOST CPLUS_INCLUDE_PATH LIBRARY_PATH SIMPOINT_DIR
