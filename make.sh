g++ -std=c++11 mattest.cpp matsave.cpp nr3plus.cpp -o mattest.x -Wl,-rpath-link,./bin -L./bin -l mat -l mx

LD_LIBRARY_PATH="./bin" ./mattest.x
