BASE=/home/jtxiao/NTHU/Research/Git/FaultInjectionPlatform
./autogen.sh
INSTALLDIR=${BASE}/install/archc          # Set installdir to the parent folder, subfolder install
SYSTEMCPATH=${BASE}/install/systemc     # Where we previously installed SystemC
./configure --prefix=$INSTALLDIR --with-systemc=$SYSTEMCPATH
make clean
make
make install
source ../env.sh         # Configure your PATH environment
cd ..                 # Return to prev dir
acsim -h              # Check if it works
