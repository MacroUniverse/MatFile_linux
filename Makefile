# Makefile

exe = mattest.x

#========  settings for MatFile ====================
ifeq (1,2)
    # binary mode
    MatPath = ../MatFile_linux/
    MatCompile = -I $(MatPath) -D MATFILE_BINARY 
    MatLink = -Wl,-rpath,$(MatPath)bin/ -L$(MatPath)bin/ -l mat -l mx
else
    # text mode
    MatCompile = -D MATFILE_PRECISION=8
endif
#=================================================


source = mattest.cpp nr3plus.cpp matsave.cpp
objects = $(source:.cpp=.o)
compiler = g++

flags = -O3 -std=c++11
# -g -O3 -fopenmp

$(exe):$(objects)
	$(compiler) -o $(exe) $(flags) $(objects) $(MatLink)

$(objects):$(source)
	$(compiler) -c $(flags) $(source) $(MatCompile)

clean:
	rm -f *.o *.x *.gch *.mat *.matt

