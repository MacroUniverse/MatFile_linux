see "matfile.h" and "test_matfile.cpp" in SLISC0 project.
The binary files are copied from a Matlab installation on Ubuntu 16.04 on x86-64 platform. Compatibility with other linux distributions has not been tested.

reference: https://www.mathworks.com/help/matlab/cc-mx-matrix-library.html

------- old README.txt --------------------

Matfile_linux project and Matfile_win64 project are considered the same project. All ".h", ".cpp", ".m" files and this file should be the same, only binary files are different.

============ Win64 ===================

* For new Win64 projects using NR3 and this project, use Visual Studio to create an empty console project with Windows Desktop Wizard, copy "matsave.h", "matsave.cpp", and NR3 files ("nr3.h", "nr3plus.h", "nr3plus.cpp") over, this should be all that's required to save to ".matt" format. This also works in Win32.
* To save to ".mat", first make sure to use "x64", then define MATFILE_BINARY in "matsave.h" or in Project Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions. To set up the library:
	1.In VC++ Directories -> Include Directories, add path to Matfile_win64 project (...\MatFile_win64).
	2.In Linker -> Input, add "libmat.lib" and "libmx.lib", in Linker -> General -> Additional Library Directories, add the library folder (...\MatFile_win64\bin).
	3.In Debugging -> Environment, add the library folder (...\MatFile_win64\bin;%PATH%).
	4.Alternative to 3, add the library folder to system Path variable, Computer -> Properties -> Advanced System Settings -> Environment Variables -> User Variables -> Path -> Edit. Note that for CUDA debugging, must use this method instead of step 3, or the dll will not be found. Restart VS or windows if necessary after changing path.
* Alternatively, use VS property sheet "matfile.props" to import properties (does not include step 3 above). And then either use step 3 or 4 above.
and the program should run successfully.

===============  Text Mode ==============
* Type checking is not strict, as long as no accuracy is lost. For example, Uchar can be loaded as Int or Doub or Complex, Int can be loaded as Doub or Complex but not Uchar, Double can be loaded as Complex, etc. Complex can not be loaded as double even if all imaginary parts are 0.

=============== Binary Mode ==============
* For simplicy of the code, type checking is as strict as possible for matload() functions, any type unmatch will result in an error. However, you can load double data to complex types, or load complex data to double types when all imaginary parts are zero.
* It is ok if a file is not closed if there is at least one variable in it.
