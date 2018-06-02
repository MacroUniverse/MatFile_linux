// save vectors and matrices defined in "nr3.h" (see Numerical Recipes) into .mat file for Matlab
// can't figure out how to directly save to complex matrix yet

#include "matsave.h"

using namespace std;

// matsave()

void matsave(const Doub s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateDoubleMatrix(1, 1, mxREAL);
	auto pps = mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

void matsave(const Complex s, const string &varname, MATFile *pfile)
{
	mxArray *pa;
	pa = mxCreateDoubleMatrix(1, 1, mxCOMPLEX);

	auto ppa = mxGetPr(pa);
	ppa[0] = real(s);
	ppa = mxGetPi(pa);
	ppa[0] = imag(s);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(VecInt_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateDoubleMatrix(1, n, mxREAL);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = (Doub)v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecDoub_I &v, const string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateDoubleMatrix(1, n, mxREAL);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecComplex_I &v, const string &varname, MATFile *pfile)
{
	Int i, n;
	string str;
	mxArray *pv;
	n = v.size();
	pv = mxCreateDoubleMatrix(1, n, mxCOMPLEX);
	auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	for (i = 0; i < n; ++i) {
		ppvr[i] = real(v[i]);
		ppvi[i] = imag(v[i]);
	}
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(MatDoub_I &a, const string &varname, MATFile *pfile, 
			const Int step1, const Int step2)
{
	Int i, j, m, n;
	mxArray *pa;
	if (step1 > 1 || step2 > 1) {
		m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
		pa = mxCreateDoubleMatrix(m, n, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m*j] = a[step1*i][step2*j];
			}
	}
	else {
		m = a.nrows(); n = a.ncols();
		pa = mxCreateDoubleMatrix(m, n, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m*j] = a[i][j];
			}
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatComplex_I &a, const string &varname, MATFile *pfile,
			const Int step1, const Int step2)
{
	Int i, j, m, n, ind;
	Complex c;
	mxArray *pa;
	if (step1 > 1 || step2 > 1) {
		m = (a.nrows() + step1 - 1)/step1; n = (a.ncols() + step2 - 1)/step2;
		pa = mxCreateDoubleMatrix(m, n, mxCOMPLEX);
		auto ppar = mxGetPr(pa);
		auto ppai = mxGetPi(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ind = i + m * j; c = a[step1*i][step2*j];
				ppar[ind] = real(c);
				ppai[ind] = imag(c);
			}
	}
	else {
		m = a.nrows(); n = a.ncols();
		pa = mxCreateDoubleMatrix(m, n, mxCOMPLEX);
		auto ppar = mxGetPr(pa);
		auto ppai = mxGetPi(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ind = i + m * j; c = a[i][j];
				ppar[ind] = real(c);
				ppai[ind] = imag(c);
			}
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(Mat3DDoub_I &a, const std::string &varname, MATFile *pfile,
	const Int step1, const Int step2, const Int step3)
{
	Int i, j, k, m, n, q, mn;
	mxArray *pa;
	m = a.dim1(); n = a.dim2(); q = a.dim3(); mn = m * n;
	if (step1 > 1 || step2 > 1 || step3 > 1) {
		m = (m + step1 - 1) / step1; n = (n + step2 - 1) / step2;
		q = (q + step3 - 1) / step3;
		size_t sz[3]{ (size_t)m,(size_t)n,(size_t)q };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				for (k = 0; k < q; ++k)
					ppa[i + m * j + mn * k] = a[step1*i][step2*j][step3*k];
	}
	else {
		size_t sz[3]{ (size_t)m,(size_t)n,(size_t)q };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				for (k = 0; k < q; ++k)
					ppa[i + m * j + mn * k] = a[i][j][k];
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

/* specify xyz = 'x','y' or 'z', and take Nslice at indslice[i]
if xyz = 'x', step1 is in y direction, step2 is in z direction, save pa[iy][iz][ix].
if xyz = 'y', step1 is in z direction, step2 is in x direction, save pa[iz][ix][iy].
if xyz = 'z', step1 is in x direction, step2 is in y direction, save pa[ix][iy][iz]. */
void matsave(Mat3DDoub_I &a, const std::string &varname, MATFile *pfile,
			const Char xyz, VecInt_I &slice, const Int step1, const Int step2)
{
	Int i, j, k, m, n, mn, Nslice{ slice.size() };
	mxArray *pa;
	if (xyz == 'x') {
		Int ind;
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)Nslice };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < Nslice; ++i) {
			ind = slice[i];
			for (j = 0; j < m; ++j)
				for (k = 0; k < n; ++k)
					ppa[j + m*k + mn*i] = a[ind][step1*j][step2*k];
		}
	}
	else if (xyz == 'y') {
		Int ind;
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)Nslice };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (j = 0; j < Nslice; ++j) {
			ind = slice[j];
			for (k = 0; k < m; ++k)
				for (i = 0; i < n; ++i)
					ppa[k + m*i + mn*j] = a[step2*i][ind][step1*k];
		}
	}
	else if (xyz == 'z') {
		Int ind;
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)Nslice };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (i = 0; i < m; ++i)
				for (j = 0; j < n; ++j)
					ppa[i + m*j + mn*k] = a[step1*i][step2*j][ind];
		}
	}
	else {
		cout << "error! illegal value of xyz" << endl; return;
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(Mat3DComplex_I &a, const std::string &varname, MATFile *pfile,
	const Int step1, const Int step2, const Int step3)
{
	Int i, j, k, m, n, q, mn, ind;
	mxArray *pa;
	Complex c;
	m = a.dim1(); n = a.dim2(); q = a.dim3(); mn = m * n;
	if (step1 > 1 || step2 > 1 || step3 > 1) {
		m = (m + step1 - 1) / step1; n = (n + step2 - 1) / step2;
		q = (q + step3 - 1) / step3;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)q };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
		auto ppar = mxGetPr(pa); auto ppai = mxGetPi(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				for (k = 0; k < q; ++k) {
					ind = i + m * j + mn * k;
					c = a[step1*i][step2*j][step3*k];
					ppar[ind] = real(c); ppai[ind] = imag(c);
				}
	}
	else {
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)q };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
		auto ppar = mxGetPr(pa); auto ppai = mxGetPi(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				for (k = 0; k < q; ++k) {
					ind = i + m * j + mn * k;
					c = a[i][j][k];
					ppar[ind] = real(c); ppai[ind] = imag(c);
				}
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

/* specify xyz = 'x','y' or 'z', and take Nslice at indslice[i]
if xyz = 'x', step1 is in y direction, step2 is in z direction, save pa[iy][iz][ix].
if xyz = 'y', step1 is in z direction, step2 is in x direction, save pa[iz][ix][iy].
if xyz = 'z', step1 is in x direction, step2 is in y direction, save pa[ix][iy][iz]. */
void matsave(Mat3DComplex_I &a, const std::string &varname, MATFile *pfile,
			const Char xyz, VecInt_I &slice, const Int step1, const Int step2)
{	
	Int i, j, k, m, n, mn, inda, Nslice{ slice.size() };
	mxArray *pa;
	Complex c;
	if (xyz == 'x') {
		Int ind;
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)Nslice };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
		auto ppar = mxGetPr(pa); auto ppai = mxGetPi(pa);
		for (i = 0; i < Nslice; ++i) {
			ind = slice[i];
			for (j = 0; j < m; ++j)
				for (k = 0; k < n; ++k) {
					inda = j + m * k + mn * i;
					c = a[ind][step1*j][step2*k];
					ppar[inda] = real(c); ppai[inda] = imag(c);
				}
		}
	}
	else if (xyz == 'y') {
		Int ind;
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)Nslice };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
		auto ppar = mxGetPr(pa); auto ppai = mxGetPi(pa);
		for (j = 0; j < Nslice; ++j) {
			ind = slice[j];
			for (k = 0; k < m; ++k)
				for (i = 0; i < n; ++i) {
					inda = k + m * i + mn * j;
					c = a[step2*i][ind][step1*k];
					ppar[inda] = real(c); ppai[inda] = imag(c);
				}
		}
	}
	else if (xyz == 'z') {
		Int ind;
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ (size_t)m, (size_t)n, (size_t)Nslice };
		pa = mxCreateNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
		auto ppar = mxGetPr(pa); auto ppai = mxGetPi(pa);
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (i = 0; i < m; ++i)
				for (j = 0; j < n; ++j) {
					inda = i + m * j + mn * k;
					c = a[step1*i][step2*j][ind];
					ppar[inda] = real(c); ppai[inda] = imag(c);
				}
		}
	}
	else {
		cout << "error! illegal value of xyz" << endl; return;
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

// matload()

void matload(Int &i, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	auto pps = mxGetPr(ps);
	i = (Int)pps[0];
	mxDestroyArray(ps);
}

void matload(Doub &s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	auto pps = mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

void matload(Complex &s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	auto ppsr = mxGetPr(ps);
	auto ppsi = mxGetPi(ps);
	if (ppsi)
		s = Complex(ppsr[0], ppsi[0]);
	else
		s = ppsr[0];
	mxDestroyArray(ps);
}

void matload(VecInt_O &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	n = (Int)mxGetDimensions(pv)[1];
	if (v.size() != n) v.resize(n);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = (Int)round(ppv[i]);
	mxDestroyArray(pv);
}

void matload(VecDoub_O &v, const string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	n = (Int)mxGetDimensions(pv)[1];
	if (v.size() != n) v.resize(n);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

void matload(VecComplex_O &v, const string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	n = (Int)mxGetDimensions(pv)[1];
	v.resize(n);
	auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	if (ppvi)
		for (i = 0; i < n; ++i)
			v[i] = Complex(ppvr[i], ppvi[i]);
	else
		for (i = 0; i < n; ++i)
			v[i] = ppvr[i];
	mxDestroyArray(pv);
}


void matload(MatDoub_O &a, const string &varname, MATFile *pfile)
{
	Int i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	const mwSize *sz = mxGetDimensions(pa);
	m = (Int)sz[0]; n = (Int)sz[1];
	if (a.nrows() != m || a.ncols() != n) a.resize(m, n);
	auto ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = ppa[m*j + i];
	mxDestroyArray(pa);
}

void matload(MatComplex_O &a, const string &varname, MATFile *pfile)
{
	Int i, j, m, n, ind;
	mxArray *pa;
	pa = matGetVariable(pfile, varname.c_str());
	const mwSize *sz = mxGetDimensions(pa);
	m = (Int)sz[0]; n = (Int)sz[1];
	a.resize(m, n);
	auto ppar = mxGetPr(pa);
	auto ppai = mxGetPi(pa);
	if (ppai)
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j){
			ind = i + m * j;
			a[i][j] = Complex(ppar[ind], ppai[ind]);
		}
	else
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = ppar[i + m*j];
	mxDestroyArray(pa);
}

void matload(Mat3DDoub_O &a, const std::string &varname, MATFile *pfile)
{
	Int i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	const mwSize *sz = mxGetDimensions(pa);
	m = (Int)sz[0]; n = (Int)sz[1]; q = (Int)sz[2]; mn = m*n;
	a.resize(m, n, q);
	auto *ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
	for (j = 0; j < n; ++j)
	for (k = 0; k < q; ++k)
		a[i][j][k] = ppa[i + m*j + mn*k];
	mxDestroyArray(pa);
}

void matload(Mat3DComplex_O &a, const std::string &varname, MATFile *pfile)
{
	Int i, j, k, m, n, q, mn, ind;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	const mwSize *sz = mxGetDimensions(pa);
	m = (Int)sz[0]; n = (Int)sz[1]; q = (Int)sz[2]; mn = m*n;
	a.resize(m, n, q);
	auto *ppar = mxGetPr(pa);
	auto *ppai = mxGetPi(pa);
	if (ppai)
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
		for (k = 0; k < q; ++k){
			ind = i + m*j + mn*k;
			a[i][j][k] = Complex(ppar[ind], ppai[ind]);
		}
	else
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
		for (k = 0; k < q; ++k)
			a[i][j][k] = ppar[i + m*j + mn*k];
	mxDestroyArray(pa);
}
