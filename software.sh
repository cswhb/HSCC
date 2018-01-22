#!/bin/bash

cd ~/

stty -echo
read -p "[sudo] password : " password
stty echo

# install gcc gcc-c++
echo $password | sudo -S yum install -y gcc gcc-c++

stty -echo
read -p "gcc installation complete" tmp
stty echo

# install python bzip2
echo $password | sudo -S yum install -y python-devel bzip2-devel

stty -echo
read -p "python installation complete" tmp
stty echo

# install boost
wget http://sourceforge.net/projects/boost/files/boost/1.59.0/boost_1_59_0.tar.gz
chmod +x boost_1_59_0.tar.gz 
tar -zxvf boost_1_59_0.tar.gz 
cd boost_1_59_0
./bootstrap.sh
./bjam
echo $password | sudo -S ./bjam install
cd ..
# echo $password | sudo -S yum install -y boost

stty -echo
read -p "boost installation complete" tmp
stty echo

# install hdf5
wget https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.10/hdf5-1.10.1/src/hdf5-1.10.1.tar.gz
chmod +x hdf5-1.10.1.tar.gz
tar -zxvf hdf5-1.10.1.tar.gz
cd hdf5-1.10.1
./confugure
make
echo $password | sudo -S make install
cd ..

stty -echo
read -p "hdf5 installation complete" tmp
stty echo

# install libconfig
wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz
chmod +x libconfig-1.7.2.tar.gz
tar -zxvf libconfig-1.7.2.tar.gz
cd libconfig-1.7.2
./configure
make
echo $password | sudo -S make install
cd ..

stty -echo
read -p "libconfig installation complete" tmp
stty echo

# install scons
wget https://nchc.dl.sourceforge.net/project/scons/scons/3.0.1/scons-3.0.1.tar.gz
chmod +x scons-3.0.1.tar.gz
tar -zxvf scons-3.0.1.tar.gz
cd scons-3.0.1
echo $password | sudo -S python setup.py install
cd ..

stty -echo
read -p "scons installation complete" tmp
stty echo

# install libelf
echo $password | sudo -S yum install -y elfutils-libelf-devel

stty -echo
read -p "libelf installation complete" tmp
stty echo

# install autoconf automake autogen
echo $password | sudo -S yum install -y autoconf automake autogen libtool libtool-ltdl-devel
curl -L -O http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.gz
chmod +x autoconf-2.69.tar.gz
tar -zxvf autoconf-2.69.tar.gz
cd autoconf-2.69
echo $password | sudo -S yum install -y openssl-devel
./configure
make
echo $password | sudo -S make install

stty -echo
read -p "autotool installation complete" tmp
stty echo

# install glog
git clone https://github.com/google/glog.git
cd glog/
./autogen.sh
./configure
make
echo $password | sudo -S make install
cd ..

stty -echo
read -p "glog installation complete" tmp
stty echo
