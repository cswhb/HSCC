#!/bin/bash
git clone https://github.com/google/glog.git
ls
tar -zxvf glog
cd g
cd glog/
ls
./autogen.sh
./configure 
make
sudo make install
cd ..

yum install python-dev

wget http://sourceforge.net/projects/boost/files/boost/1.59.0/boost_1_59_0.tar.gz
chmod +x boost_1_59_0.tar.gz 
tar -zxvf boost_1_59_0.tar.gz 
cd boost_1_59_0
./bootstrap.sh 
./bjam
sudo ./bjam install
cd ..

wget https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.10/hdf5-1.10.1/src/hdf5-1.10.1.tar.gz
tar -zxvf hdf5-1.10.1.tar.gz
cd hdf5-1.10.1
./confugure
make
sudo make install
cd ..

wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz
tar -zxvf libconfig-1.7.2.tar.gz
cd libconfig-1.7.2
./confugure
make
sudo make install
cd ..
