#LD_LIBRARY_PATH="/usr/local/MATLAB/R2017a/bin/glnxa64"
g++ -std=c++11 mattest.cpp matsave.cpp -o mattest.x -Wl,-rpath-link,/usr/local/MATLAB/R2017a/bin/glnxa64 -L/usr/local/MATLAB/R2017a/bin/glnxa64 -l mat -l mx
#g++ -std=c++11 mattest.cpp -L/usr/local/MATLAB/R2017a/bin/glnxa64 -l mat -l mx -l mwfl -l mwfoundation_usm -l mwi18n -l ut 

LD_LIBRARY_PATH="/usr/local/MATLAB/R2017a/bin/glnxa64" ./mattest.x
