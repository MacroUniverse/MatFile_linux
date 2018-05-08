// save vectors and matrices defined in "nr3.h" (see Numerical Recipes) into .mat file for Matlab

#pragma once
#include "nr3.h"
#include "mat.h"

void matsave(const Doub s, const std::string &varname, MATFile *pfile);

void matsave(const Complex s, const std::string &varname, MATFile *pfile);

void matsave(VecDoub_I &v, const std::string &varname, MATFile *pfile);

void matsave(VecComplex_I &v, const std::string &varname, MATFile *pfile);

void matsave(MatDoub_I &a, const std::string &varname, MATFile *pfile);

void matsave(MatComplex_I &a, const std::string &varname, MATFile *pfile);
