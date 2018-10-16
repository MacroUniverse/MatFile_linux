# Makefile

exe = main.x
BinPath = ../MatFile_linux/MatFile_linux/bin/
#========  settings for MatFile ====================a
mode = 3
ifeq ($(mode),1)
    # binary mode
    MatCompile = -I $(MatFilePath) -D MATFILE_BINARY 
    MatLink = -Wl,-rpath,$(BinPath) -L$(BinPath) -l mat -l mx
endif
ifeq ($(mode),2)
    # text mode
    MatCompile = -D MATFILE_PRECISION=8
endif
ifeq ($(mode),3)
    # dual mode
    MatCompile = -D MATFILE_DUAL -D MATFILE_PRECISION=17
    MatLink = -Wl,-rpath,$(BinPath) -L$(BinPath) -l mat -l mx
endif
#=================================================


source = main.cpp
objects = main.o
compiler = g++

flags = -g -std=c++11 -O3
# -g -O3 -fopenmp

macro = -D _CHECKBOUNDS_

$(exe):$(objects)
	$(compiler) -o $(exe) $(flags) $(objects) $(MatLink)

$(objects):$(source)
	$(compiler) -c $(flags) $(source) $(MatCompile) $(macro)

clean:
	rm -f *.o *.x *.gch *.mat *.matt
