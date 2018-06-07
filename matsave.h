// save vectors and matrices defined in "nr3.h" (see Numerical Recipes) into .mat file for Matlab

#pragma once
#include "nr3.h"
#include "mat.h"

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