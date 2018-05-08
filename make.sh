g++ -std=c++11 mattest.cpp matsave.cpp -o mattest.x -Wl,-rpath-link,./bin -L./bin -l mat -l mx

LD_LIBRARY_PATH="./bin" ./mattest.x
