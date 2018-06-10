# Makefile

exe = mattest.x

#========  settings for MatFile ====================
ifeq (1,1)
	MatPath = ../MatFile_linux/
	MatSource = -D MATFILE_BINARY $(MatPath)matsave.cpp
	MatObject = matsave.o -I $(MatPath) -Wl,-rpath,$(MatPath)bin/ -L$(MatPath)bin/ -l mat -l mx
else
	MatPath = ../MatFile_linux/
	MatSource = $(MatPath)matsave.cpp
	MatObject = matsave.o  -I $(MatPath)
endif
#=================================================


source = mattest.cpp nr3plus.cpp
objects = $(source:.cpp=.o)
compiler = g++

flags = -O3 -std=c++11
# -g -O3 -fopenmp

$(exe):$(objects)
	$(compiler) -o $(exe) $(flags) $(objects) $(MatObject)

$(objects):$(source)
	$(compiler) -c $(flags) $(source) $(MatSource)

clean:
	rm -f *.o *.x *.gch *.mat

