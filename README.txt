Save NR3 vectors/matrices to ".mat" or ".matt"

Matfile_linux project and Matfile_win64 project are considered the same project. All ".h", ".cpp", ".m" files and this file should be the same, only binary files are different.

For new linux projucts using NR3 and this project, copy "matsave.h", "matsave.cpp" and "Makefile" to the new project, this should be all that's required to save to ".matt" format. To save to ".mat", all other files/folder are required. Either set path in Makefile to this project (recommended) or copy the files/folder to the new project.

To use this project with CUDA, use the template in CUDATest project.



