// save vectors and matrices defined in "nr3.h"
//
// ==========   1. Binary Mode ==================
// define MATFILE_BINARY in this file or the compiler to save to ".mat" file for Matlab
// in this case, directories and library path must be set for the compiler.
// use matsave(*, <varname>.mat, *) to save
//
// ==========   2. Text Mode ===================
// save data to text file with extension ".matt", totally compatible with binary mode
// use "matread(<filename>)" matlab function to read ".matt" file, just like load();
// in this case, only need to include "matsave.h", "matsave.cpp" and "nr3.h".
// use matsave(*, <varname>.mat, *) to save, don't use <varname>.matt
// define macro MATFILE_PRECISION and set a value to change output precision
// one number class code: Doub=0, Complex=1, Int=2, Uchar=3.

#pragma once
//#define MATFILE_BINARY
#ifndef MATFILE_PRECISION
#define MATFILE_PRECISION 16
#endif
#include "nr3.h"

#ifdef MATFILE_BINARY
#include "mat.h"
#else
typedef std::ofstream MATFile;

MATFile *matOpen(std::string fname, std::string rw);

void matClose(MATFile *pfile);
#endif

// matsave()

void matsave(const Uchar s, const std::string &varname, MATFile *pfile);

void matsave(const Int s, const std::string &varname, MATFile *pfile);

void matsave(const Doub s, const std::string &varname, MATFile *pfile);

void matsave(const Complex s, const std::string &varname, MATFile *pfile);

void matsave(VecUchar_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecInt_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecDoub_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecComplex_I &v, const std::string &varname, MATFile *pfile);

void matsave(MatUchar_I &a, const std::string &varname, MATFile *pfile,
	const Int step1 = 1, const Int step2 = 1);

void matsave(MatInt_I &a, const std::string &varname, MATFile *pfile,
			const Int step1 = 1, const Int step2 = 1);

void matsave(MatDoub_I &a, const std::string &varname, MATFile *pfile,
			const Int step1 = 1, const Int step2 = 1);

void matsave(MatComplex_I &a, const std::string &varname, MATFile *pfile,
			const Int step1 = 1, const Int step2 = 1);

void matsave(Mat3DDoub_I &a, const std::string &varname, MATFile *pfile,
			const Int step1 = 1, const Int step2 = 1, const Int step3 = 1);

void matsave(Mat3DDoub_I &a, const std::string &varname, MATFile *pfile,
			const Char xyz, const VecInt_I &slice, const Int step1 = 1, const Int step2 = 1);

void matsave(Mat3DComplex_I &a, const std::string &varname, MATFile *pfile,
	const Int step1 = 1, const Int step2 = 1, const Int step3 = 1);

void matsave(Mat3DComplex_I &a, const std::string &varname, MATFile *pfile,
			const Char xyz, VecInt_I &slice, const Int step1 = 1, const Int step2 = 1);

// matload()

void matload(Int &i, const std::string &varname, MATFile *pfile);

void matload(Doub &s, const std::string &varname, MATFile *pfile);

void matload(Complex &s, const std::string &varname, MATFile *pfile);

void matload(VecInt_O &v, const std::string &varname, MATFile *pfile);

void matload(VecDoub_O &v, const std::string &varname, MATFile *pfile);

void matload(VecComplex_O &v, const std::string &varname, MATFile *pfile);

void matload(MatInt_O &a, const std::string &varname, MATFile *pfile);

void matload(MatDoub_O &a, const std::string &varname, MATFile *pfile);

void matload(MatComplex_O &a, const std::string &varname, MATFile *pfile);

void matload(Mat3DDoub_O &a, const std::string &varname, MATFile *pfile);

void matload(Mat3DComplex_O &a, const std::string &varname, MATFile *pfile);