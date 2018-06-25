Save NR3 vectors/matrices to ".mat" or ".matt"

Matfile_linux project and Matfile_win64 project are considered the same project. All ".h", ".cpp", ".m" files and this file should be the same, only binary files are different.

============ Linux ==================

* For new linux projucts using NR3 ("nr3.h", "nr3plus.h", "nr3plus.cpp") and this project, copy "matsave.h", "matsave.cpp" and "Makefile" to the new project, this should be all that's required to save to ".matt" format.
* To save to ".mat", all other files/folder are required. Either set path in Makefile to this project (recommended) or copy the files/folder to the new project.
* To use this project with CUDA in linux, use the template in CUDATest project.


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
* First, when using Git, it is best to set "*.matt" as binary (create .gitattribute file for the repo, add "*.matt binary"). This will prevent git from diffing "*.matt" files and most importantly, from doing autocrlf. It's also recommanded to add "*.matt binary" to "~/.config/git/attributes" to make this setting global.
* If neither MATFILE_BINARY nor MATFILE_DUAL macro is defined, the program uses text mode. You can also set MATFILE_PRECISION to define the writing precision, note that the reading precision is not affected by MATFILE_PRECISION and is always as accurate as possible.
* The available functions are "matOpen(), matClose(), matsave() matload()".
* Type checking is not strict, as long as no accuracy is lost. For example, Uchar can be loaded as Int or Doub or Complex, Int can be loaded as Doub or Complex but not Uchar, Double can be loaded as Complex, etc. Complex can not be loaded as double even if all imaginary parts are 0.

=============== Binary Mode ==============
* If MATFILE_BINARY is defined, then the program uses binary mode.
* The available functions are "matOpen(), matClose(), matsave() matload()".
* For simplicy of the code, type checking is as strict as possible for matload() functions, any type unmatch will result in an error. However, you can load double data to complex types, or load complex dat to double types when all imaginary parts are zero.


=============== Dual Mode ================
If MATFILE_DUAL is set, use "matOpen(), matClose(), matsave() matload()" for ".mat" files, and "mattOpen(), mattClose(), mattsave() mattload()" for ".matt" files.


Save 3D slices:

/* specify xyz = 'x','y' or 'z', and take Nslice at indslice[i]
if xyz = 'x', step1 is in y direction, step2 is in z direction, save pa[iy][iz][ix].
if xyz = 'y', step1 is in z direction, step2 is in x direction, save pa[iz][ix][iy].
if xyz = 'z', step1 is in x direction, step2 is in y direction, save pa[ix][iy][iz]. */

mattOpen() will check file existence, but matOpen() will not!