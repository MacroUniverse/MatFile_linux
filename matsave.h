// save vectors and matrices defined in "nr3.h" to ".mat" or ".matt" files.
// see README.txt for details
// class types: Doub=0, Complex=1, Int=2, Uchar=3.

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
	std::vector<std::vector<Int>> size; // variable dimensions
	std::vector<size_t> ind; // variable positions (line indices)
};

MATTFile *mattOpen(std::string fname, const Char *rw);

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

void matload(Uchar &i, const std::string &varname, MATFile *pfile);

void matload(Int &i, const std::string &varname, MATFile *pfile);

void matload(Doub &s, const std::string &varname, MATFile *pfile);

void matload(Complex &s, const std::string &varname, MATFile *pfile);

void matload(VecUchar_O &v, const std::string &varname, MATFile *pfile);

void matload(VecInt_O &v, const std::string &varname, MATFile *pfile);

void matload(VecDoub_O &v, const std::string &varname, MATFile *pfile);

void matload(VecComplex_O &v, const std::string &varname, MATFile *pfile);

void matload(MatUchar_O &a, const std::string &varname, MATFile *pfile);

void matload(MatInt_O &a, const std::string &varname, MATFile *pfile);

void matload(MatDoub_O &a, const std::string &varname, MATFile *pfile);

void matload(MatComplex_O &a, const std::string &varname, MATFile *pfile);

void matload(Mat3DDoub_O &a, const std::string &varname, MATFile *pfile);

void matload(Mat3DComplex_O &a, const std::string &varname, MATFile *pfile);

#ifdef MATFILE_DUAL
void mattsave(const Uchar s, const std::string &varname, MATTFile *pfile);

void mattsave(const Int s, const std::string &varname, MATTFile *pfile);

void mattsave(const Doub s, const std::string &varname, MATTFile *pfile);

void mattsave(const Complex s, const std::string &varname, MATTFile *pfile);

void mattsave(VecUchar_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(VecInt_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(VecDoub_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(VecComplex_I &v, const std::string &varname, MATTFile *pfile);

void mattsave(MatUchar_I &a, const std::string &varname, MATTFile *pfile,
	const Int step1 = 1, const Int step2 = 1);

void mattsave(MatInt_I &a, const std::string &varname, MATTFile *pfile,
	const Int step1 = 1, const Int step2 = 1);

void mattsave(MatDoub_I &a, const std::string &varname, MATTFile *pfile,
	const Int step1 = 1, const Int step2 = 1);

void mattsave(MatComplex_I &a, const std::string &varname, MATTFile *pfile,
	const Int step1 = 1, const Int step2 = 1);

void mattsave(Mat3DDoub_I &a, const std::string &varname, MATTFile *pfile,
	const Int step1 = 1, const Int step2 = 1, const Int step3 = 1);

void mattsave(Mat3DDoub_I &a, const std::string &varname, MATTFile *pfile,
	const Char xyz, const VecInt_I &slice, const Int step1 = 1, const Int step2 = 1);

void mattsave(Mat3DComplex_I &a, const std::string &varname, MATTFile *pfile,
	const Int step1 = 1, const Int step2 = 1, const Int step3 = 1);

void mattsave(Mat3DComplex_I &a, const std::string &varname, MATTFile *pfile,
	const Char xyz, VecInt_I &slice, const Int step1 = 1, const Int step2 = 1);

// matload()

void mattload(Uchar &i, const std::string &varname, MATTFile *pfile);

void mattload(Int &i, const std::string &varname, MATTFile *pfile);

void mattload(Doub &s, const std::string &varname, MATTFile *pfile);

void mattload(Complex &s, const std::string &varname, MATTFile *pfile);

void mattload(VecUchar_O &v, const std::string &varname, MATTFile *pfile);

void mattload(VecInt_O &v, const std::string &varname, MATTFile *pfile);

void mattload(VecDoub_O &v, const std::string &varname, MATTFile *pfile);

void mattload(VecComplex_O &v, const std::string &varname, MATTFile *pfile);

void mattload(MatUchar_O &a, const std::string &varname, MATTFile *pfile);

void mattload(MatInt_O &a, const std::string &varname, MATTFile *pfile);

void mattload(MatDoub_O &a, const std::string &varname, MATTFile *pfile);

void mattload(MatComplex_O &a, const std::string &varname, MATTFile *pfile);

void mattload(Mat3DDoub_O &a, const std::string &varname, MATTFile *pfile);

void mattload(Mat3DComplex_O &a, const std::string &varname, MATTFile *pfile);

void mat2matt(const std::string &fmat, const std::string &fmatt);

void matt2mat(const std::string &fmatt, const std::string &fmat);
#endif