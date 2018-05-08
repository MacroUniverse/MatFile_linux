// save vectors and matrices defined in "nr3.h" (see Numerical Recipes) into .mat file for Matlab
// can't figure out how to directly save to complex matrix yet

#include "matsave.h"

using namespace std;

// save Doub
void matsave(const Doub s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateDoubleMatrix(1, 1, mxREAL);
	auto pps = mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

// save Complex
void matsave(const Complex s, const string &varname, MATFile *pfile)
{
	string str;
	mxArray *ps1, *ps2;
	ps1 = mxCreateDoubleMatrix(1, 1, mxREAL);
	ps2 = mxCreateDoubleMatrix(1, 1, mxREAL);
	auto pps1 = mxGetPr(ps1);
	auto pps2 = mxGetPr(ps2);
	pps1[0] = real(s);
	pps2[0] = imag(s);
	str = varname + "_R";
	matPutVariable(pfile, str.c_str(), ps1);
	str = varname + "_I";
	matPutVariable(pfile, str.c_str(), ps2);
	mxDestroyArray(ps1);
	mxDestroyArray(ps2);
}

void matsave(VecDoub_I &v, const string &varname, MATFile *pfile)
{
	int i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateDoubleMatrix(1, n, mxREAL);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i) {
		ppv[i] = v[i];
	}
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecComplex_I &v, const string &varname, MATFile *pfile)
{
	int i, n;
	string str;
	mxArray *pv1, *pv2;
	n = v.size();
	pv1 = mxCreateDoubleMatrix(1, n, mxREAL);
	pv2 = mxCreateDoubleMatrix(1, n, mxREAL);
	auto ppv1 = mxGetPr(pv1);
	auto ppv2 = mxGetPr(pv2);
	for (i = 0; i < n; ++i) {
		ppv1[i] = real(v[i]);
		ppv2[i] = imag(v[i]);
	}
	str = varname + "_R";
	matPutVariable(pfile, str.c_str(), pv1);
	str = varname + "_I";
	matPutVariable(pfile, str.c_str(), pv2);
	mxDestroyArray(pv1);
	mxDestroyArray(pv2);
}


void matsave(MatDoub_I &a, const string &varname, MATFile *pfile)
{
	int i, j, m, n;
	mxArray *pa;
	m = a.nrows(); n = a.ncols();
	pa = mxCreateDoubleMatrix(m, n, mxREAL);
	auto ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			ppa[m*j + i] = a[i][j];
		}
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatComplex_I &a, const string &varname, MATFile *pfile)
{
	int i, j, m, n;
	string str;
	mxArray *pa1, *pa2;
	m = a.nrows(); n = a.ncols();
	pa1 = mxCreateDoubleMatrix(m, n, mxREAL);
	pa2 = mxCreateDoubleMatrix(m, n, mxREAL);
	auto ppa1 = mxGetPr(pa1);
	auto ppa2 = mxGetPr(pa2);
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			ppa1[m*j + i] = real(a[i][j]);
			ppa2[m*j + i] = imag(a[i][j]);
		}
	}
	str = varname + "_R";
	matPutVariable(pfile, str.c_str(), pa1);
	str = varname + "_I";
	matPutVariable(pfile, str.c_str(), pa2);
	mxDestroyArray(pa1);
	mxDestroyArray(pa2);
}