#!/bin/bash

cd ~/

stty -echo
read -p "[sudo] password : " password
stty echo

# install gcc gcc-c++ autoconf
echo $password | sudo -S yum install -y gcc gcc-c++

# install autoconf
curl -L -O http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.gz
chmod +x autoconf-2.69.tar.gz
tar -zxvf autoconf-2.69.tar.gz
cd autoconf-2.69
echo $password | sudo -S yum install -y openssl-devel
./configure
make & make install

# install glog
git clone https://github.com/google/glog.git
cd glog/
./autogen.sh
./configure
make
echo $password | sudo -S make install
cd ..

# install python
echo $password | sudo -S yum install -y python-devel

# install boost
wget http://sourceforge.net/projects/boost/files/boost/1.59.0/boost_1_59_0.tar.gz
chmod +x boost_1_59_0.tar.gz 
tar -zxvf boost_1_59_0.tar.gz 
cd boost_1_59_0
./bootstrap.sh 
./bjam
echo $password | sudo -S ./bjam install
cd ..

# install hdf5
wget https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.10/hdf5-1.10.1/src/hdf5-1.10.1.tar.gz
chmod +x hdf5-1.10.1.tar.gz
tar -zxvf hdf5-1.10.1.tar.gz
cd hdf5-1.10.1
./confugure
make
echo $password | sudo -S make install
cd ..

# install libconfig
wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz
chmod +x libconfig-1.7.2.tar.gz
tar -zxvf libconfig-1.7.2.tar.gz
cd libconfig-1.7.2
./confugure
make
echo $password | sudo -S make install
cd ..
