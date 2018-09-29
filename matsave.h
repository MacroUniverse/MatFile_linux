// save vectors and matrices defined in "nr3.h" to ".mat" or ".matt" files.
// see README.txt for details
// class types: Doub=0, Comp=1, Int=2, Uchar=3.

#pragma once
//#define MATFILE_BINARY
//#define MATFILE_DUAL

#ifndef MATFILE_PRECISION
#define MATFILE_PRECISION 16
#endif

#include <algorithm>
#include "nr3.h"

#if defined(MATFILE_BINARY) || defined(MATFILE_DUAL)
#include "mat.h"
#endif

#ifndef MATFILE_BINARY
// MATFile class for text mode
struct MATTFile {
	char rw; // 'r' for read 'w' for write
	std::ifstream in; // read file
	std::ofstream out; // write file
	Int n; // variable numbers
	std::vector<std::string> name; // variable names
	std::vector<Int> type; // variable types
	std::vector<std::vector<Long>> size; // variable dimensions
	std::vector<Long> ind; // variable positions (line indices)
};

MATTFile *mattOpen(std::string fname, Char_I *rw);

void mattClose(MATTFile *pfile);
#endif

#if !(defined(MATFILE_BINARY) || defined(MATFILE_DUAL))
typedef MATTFile MATFile;
#define matOpen mattOpen
#define matClose mattClose
#define matsave mattsave
#define matload mattload
#endif

// matsave()

void matsave(Uchar_I s, const std::string &varname, MATFile *pfile);

void matsave(Int_I s, const std::string &varname, MATFile *pfile);

void matsave(Doub_I s, const std::string &varname, MATFile *pfile);

void matsave(Comp_I s, const std::string &varname, MATFile *pfile);

void matsave(VecUchar_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecInt_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecDoub_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecComp_I &v, const std::string &varname, MATFile *pfile);

void matsave(MatUchar_I &a, const std::string &varname, MATFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1);

void matsave(MatInt_I &a, const std::string &varname, MATFile *pfile,
			Long_I step1 = 1, Long_I step2 = 1);

void matsave(MatDoub_I &a, const std::string &varname, MATFile *pfile,
			Long_I step1 = 1, Long_I step2 = 1);

void matsave(MatComp_I &a, const std::string &varname, MATFile *pfile,
			Long_I step1 = 1, Long_I step2 = 1);

void matsave(Mat3Doub_I &a, const std::string &varname, MATFile *pfile,
			Long_I step1 = 1, Long_I step2 = 1, Long_I step3 = 1);

void matsave(Mat3Doub_I &a, const std::string &varname, MATFile *pfile,
			Char_I xyz, const VecInt_I &slice, Long_I step1 = 1, Long_I step2 = 1);

void matsave(Mat3Comp_I &a, const std::string &varname, MATFile *pfile,
			Long_I step1 = 1, Long_I step2 = 1, Long_I step3 = 1);

void matsave(Mat3Comp_I &a, const std::string &varname, MATFile *pfile,
			Char_I xyz, VecInt_I &slice, Long_I step1 = 1, Long_I step2 = 1);

// matload()

void matload(Uchar &i, const std::string &varname, MATFile *pfile);

void matload(Int &i, const std::string &varname, MATFile *pfile);

void matload(Doub &s, const std::string &varname, MATFile *pfile);

void matload(Comp &s, const std::string &varname, MATFile *pfile);

void matload(VecUchar_O &v, const std::string &varname, MATFile *pfile);

void matload(VecInt_O &v, const std::string &varname, MATFile *pfile);

void matload(VecDoub_O &v, const std::string &varname, MATFile *pfile);

void matload(VecComp_O &v, const std::string &varname, MATFile *pfile);

void matload(MatUchar_O &a, const std::string &varname, MATFile *pfile);

void matload(MatInt_O &a, const std::string &varname, MATFile *pfile);

void matload(MatDoub_O &a, const std::string &varname, MATFile *pfile);

void matload(MatComp_O &a, const std::string &varname, MATFile *pfile);

void matload(Mat3Doub_O &a, const std::string &varname, MATFile *pfile);

void matload(Mat3Comp_O &a, const std::string &varname, MATFile *pfile);

#ifdef MATFILE_DUAL
void mattsave(Uchar_I s, const std::string &varname, MATTFile *pfile);

void mattsave(Int_I s, const std::string &varname, MATTFile *pfile);

void mattsave(Doub_I s, const std::string &varname, MATTFile *pfile);

void mattsave(Comp_I s, const std::string &varname, MATTFile *pfile);

void mattsave(VecUchar_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(VecInt_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(VecDoub_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(VecComp_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(MatUchar_I &a, const std::string &varname, MATTFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1);

void mattsave(MatInt_I &a, const std::string &varname, MATTFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1);

void mattsave(MatDoub_I &a, const std::string &varname, MATTFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1);

void mattsave(MatComp_I &a, const std::string &varname, MATTFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1);

void mattsave(Mat3Doub_I &a, const std::string &varname, MATTFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1, Long_I step3 = 1);

void mattsave(Mat3Doub_I &a, const std::string &varname, MATTFile *pfile,
	Char_I xyz, const VecInt_I &slice, Long_I step1 = 1, Long_I step2 = 1);

void mattsave(Mat3Comp_I &a, const std::string &varname, MATTFile *pfile,
	Long_I step1 = 1, Long_I step2 = 1, Long_I step3 = 1);

void mattsave(Mat3Comp_I &a, const std::string &varname, MATTFile *pfile,
	Char_I xyz, VecInt_I &slice, Long_I step1 = 1, Long_I step2 = 1);

// matload()

void mattload(Uchar &i, const std::string &varname, MATTFile *pfile);

void mattload(Int &i, const std::string &varname, MATTFile *pfile);

void mattload(Doub &s, const std::string &varname, MATTFile *pfile);

void mattload(Comp &s, const std::string &varname, MATTFile *pfile);

void mattload(VecUchar_O &v, const std::string &varname, MATTFile *pfile);

void mattload(VecInt_O &v, const std::string &varname, MATTFile *pfile);

void mattload(VecDoub_O &v, const std::string &varname, MATTFile *pfile);

void mattload(VecComp_O &v, const std::string &varname, MATTFile *pfile);

void mattload(MatUchar_O &a, const std::string &varname, MATTFile *pfile);

void mattload(MatInt_O &a, const std::string &varname, MATTFile *pfile);

void mattload(MatDoub_O &a, const std::string &varname, MATTFile *pfile);

void mattload(MatComp_O &a, const std::string &varname, MATTFile *pfile);

void mattload(Mat3Doub_O &a, const std::string &varname, MATTFile *pfile);

void mattload(Mat3Comp_O &a, const std::string &varname, MATTFile *pfile);

void mat2matt(const std::string &fmat, const std::string &fmatt);

void matt2mat(const std::string &fmatt, const std::string &fmat);
#endif