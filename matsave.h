// save vectors and matrices defined in "nr3.h" (see Numerical Recipes) into .mat file for Matlab
// can't figure out how to directly save to complex matrix yet

#pragma once
#include "mat.h"
#include "nr3.h"

void matsave(const Doub s, const std::string &varname, MATFile *pfile);

void matsave(const Complex s, const std::string &varname, MATFile *pfile);

void matsave(VecDoub_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecComplex_I &v, const std::string &varname, MATFile *pfile);

void matsave(MatDoub_I &a, const std::string &varname, MATFile *pfile);

void matsave(MatComplex_I &a, const std::string &varname, MATFile *pfile);
