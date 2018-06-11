#include "matsave.h"

using namespace std;

#ifdef MATFILE_BINARY

// matsave()

void matsave(const Uchar s, const std::string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
	Uchar *pps = (Uchar*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

void matsave(const Int s, const std::string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
	Int *pps = (Int*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

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

void matsave(VecUchar_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateUninitNumericMatrix(1, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppv = (Uchar*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecInt_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateUninitNumericMatrix(1, n, mxINT32_CLASS, mxREAL);
	Int *ppv = (Int*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecDoub_I &v, const string &varname, MATFile *pfile)
{
	Int i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxREAL);
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
	pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxCOMPLEX);
	auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	for (i = 0; i < n; ++i) {
		ppvr[i] = real(v[i]);
		ppvi[i] = imag(v[i]);
	}
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(MatUchar_I &a, const std::string &varname, MATFile *pfile,
	const Int step1, const Int step2)
{
	Int i, j, m, n;
	mxArray *pa;
	if (step1 > 1 || step2 > 1) {
		m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
		pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
		Uchar *ppa = (Uchar*)mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m * j] = a[step1*i][step2*j];
			}
	}
	else {
		m = a.nrows(); n = a.ncols();
		pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
		Uchar *ppa = (Uchar*)mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m * j] = a[i][j];
			}
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatInt_I &a, const std::string &varname, MATFile *pfile,
	const Int step1, const Int step2)
{
	Int i, j, m, n;
	mxArray *pa;
	if (step1 > 1 || step2 > 1) {
		m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
		pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
		Int *ppa = (Int*)mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m * j] = a[step1*i][step2*j];
			}
	}
	else {
		m = a.nrows(); n = a.ncols();
		pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
		Int *ppa = (Int*)mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m * j] = a[i][j];
			}
	}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatDoub_I &a, const string &varname, MATFile *pfile, 
			const Int step1, const Int step2)
{
	Int i, j, m, n;
	mxArray *pa;
	if (step1 > 1 || step2 > 1) {
		m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
		pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j) {
				ppa[i + m*j] = a[step1*i][step2*j];
			}
	}
	else {
		m = a.nrows(); n = a.ncols();
		pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
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
		pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxCOMPLEX);
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
		pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxCOMPLEX);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				for (k = 0; k < q; ++k)
					ppa[i + m * j + mn * k] = a[step1*i][step2*j][step3*k];
	}
	else {
		size_t sz[3]{ (size_t)m,(size_t)n,(size_t)q };
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
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
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
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

void matload(MatInt_O &a, const std::string &varname, MATFile *pfile)
{
	Int i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	const mwSize *sz = mxGetDimensions(pa);
	m = (Int)sz[0]; n = (Int)sz[1];
	a.resize(m, n);
	auto ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = (Int)ppa[m*j + i];
	mxDestroyArray(pa);
}

void matload(MatDoub_O &a, const string &varname, MATFile *pfile)
{
	Int i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	const mwSize *sz = mxGetDimensions(pa);
	m = (Int)sz[0]; n = (Int)sz[1];
	a.resize(m, n);
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

#else /*#ifdef MATFILE_BINARY*/
// text mode

// change extension from ".mat" to
MATFile *matOpen(std::string fname, std::string rw)
{
	Int N = (Int)fname.size();
	fname += "t";
	MATFile* pfile = new ofstream;
	*pfile = ofstream(fname);
#ifdef MATFILE_PRECISION
	pfile->precision(MATFILE_PRECISION);
#endif
	return pfile;
}

void matClose(MATFile* pfile)
{
	pfile->close();
	delete pfile;
}

void matsave(const Uchar s, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 3 << '\n';
	// write dimension info
	*pfile << 0 << '\n';
	// write matrix data
	*pfile << (Int)s << '\n';
}

void matsave(const Int s, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 2 << '\n';
	// write dimension info
	*pfile << 0 << '\n';
	// write matrix data
	*pfile << s << '\n';
}

void matsave(const Doub s, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 0 << '\n';
	// write dimension info
	*pfile << 0 << '\n';
	// write matrix data
	*pfile << s << '\n';
}

void matsave(const Complex s, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 1 << '\n';
	// write dimension info
	*pfile << 0 << '\n';
	// write matrix data
	if (imag(s) == 0)
		*pfile << real(s) << '\n';
	else
		*pfile << real(s) << '+' << imag(s) << "i\n";
}

void matsave(VecUchar_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 3 << '\n';
	// write dimension info
	n = v.size();
	*pfile << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		*pfile << (Int)v[i] << '\n';
	}
}

void matsave(VecInt_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 2 << '\n';
	// write dimension info
	n = v.size();
	*pfile << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		*pfile << v[i] << '\n';
	}
}

void matsave(VecDoub_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 0 << '\n';
	// write dimension info
	n = v.size();
	*pfile << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		*pfile << v[i] << '\n';
	}
}

void matsave(VecComplex_I &v, const std::string &varname, MATFile *pfile)
{
	Int i, n;
	Doub cr, ci;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 1 << '\n';
	// write dimension info
	n = v.size();
	*pfile << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		cr = real(v[i]); ci = imag(v[i]);
		if (ci == 0)
			*pfile << cr << '\n';
		else
			*pfile << cr << '+' << ci << "i\n";
	}
}

void matsave(MatUchar_I &a, const string &varname, MATFile *pfile,
	const Int step1, const Int step2)
{
	Int i, j, m, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 3 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	*pfile << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			*pfile << (Int)a[step1*i][step2*j] << '\n';
		}
}

void matsave(MatInt_I &a, const string &varname, MATFile *pfile,
	const Int step1, const Int step2)
{
	Int i, j, m, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 2 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	*pfile << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			*pfile << a[step1*i][step2*j] << '\n';
		}
}

void matsave(MatDoub_I &a, const string &varname, MATFile *pfile,
	const Int step1, const Int step2)
{
	Int i, j, m, n;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 0 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	*pfile << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			*pfile << a[step1*i][step2*j] << '\n';
		}
}

void matsave(MatComplex_I &a, const string &varname, MATFile *pfile,
	const Int step1, const Int step2)
{
	Int i, j, m, n;
	Complex c; Doub cr, ci;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 1 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	*pfile << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			c = a[step1*i][step2*j]; cr = real(c); ci = imag(c);
			if (ci == 0)
				*pfile << cr << '\n';
			else
				*pfile << cr << '+' << ci << "i\n";
		}
}

void matsave(Mat3DDoub_I &a, const std::string &varname, MATFile *pfile,
	const Int step1, const Int step2, const Int step3)
{
	Int i, j, k, m, n, q;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 0 << '\n';
	// write dimension info
	m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
	q = (a.dim3() + step3 - 1) / step3;
	*pfile << 3 << '\n' << m << '\n' << n << '\n' << q << '\n';
	// write matrix data
	for (k = 0; k < q; ++k)
	for (j = 0; j < n; ++j)
	for (i = 0; i < m; ++i)
		*pfile << a[step1*i][step2*j][step3*k] << '\n';
}

/* specify xyz = 'x','y' or 'z', and take Nslice at indslice[i]
if xyz = 'x', step1 is in y direction, step2 is in z direction, save pa[iy][iz][ix].
if xyz = 'y', step1 is in z direction, step2 is in x direction, save pa[iz][ix][iy].
if xyz = 'z', step1 is in x direction, step2 is in y direction, save pa[ix][iy][iz]. */
void matsave(Mat3DDoub_I &a, const std::string &varname, MATFile *pfile,
	const Char xyz, VecInt_I &slice, const Int step1, const Int step2)
{
	Int i, j, k, m, n, ind, Nslice{ slice.size() };
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 0 << '\n';
	if (xyz == 'x') {
		// write dimension info
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2;
		*pfile << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (i = 0; i < Nslice; ++i) {
			ind = slice[i];
			for (k = 0; k < n; ++k)
				for (j = 0; j < m; ++j)
					*pfile << a[ind][step1*j][step2*k] << '\n';
		}
	}
	else if (xyz == 'y') {
		// write dimension info
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2;
		*pfile << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (j = 0; j < Nslice; ++j) {
			ind = slice[j];
			for (i = 0; i < n; ++i)
				for (k = 0; k < m; ++k)
					*pfile << a[step2*i][ind][step1*k] << '\n';
		}
	}
	else if (xyz == 'z') {
		// write dimension info
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
		*pfile << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (j = 0; j < n; ++j)
				for (i = 0; i < m; ++i)
					*pfile << a[step1*i][step2*j][ind] << '\n';
		}
	}
	else {
		cout << "error! illegal value of xyz" << endl; return;
	}
}

void matsave(Mat3DComplex_I &a, const std::string &varname, MATFile *pfile,
	const Int step1, const Int step2, const Int step3)
{
	Int i, j, k, m, n, q;
	Complex c; Doub cr, ci;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 1 << '\n';
	// write dimension info
	m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
	q = (a.dim3() + step3 - 1) / step3;
	*pfile << 3 << '\n' << m << '\n' << n << '\n' << q << '\n';
	// write matrix data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i) {
				c = a[step1*i][step2*j][step3*k]; cr = real(c); ci = imag(c);
				if (ci == 0)
					*pfile << cr << '\n';
				else
					*pfile << cr << '+' << ci << "i\n";
			}
}

/* specify xyz = 'x','y' or 'z', and take Nslice at indslice[i]
if xyz = 'x', step1 is in y direction, step2 is in z direction, save pa[iy][iz][ix].
if xyz = 'y', step1 is in z direction, step2 is in x direction, save pa[iz][ix][iy].
if xyz = 'z', step1 is in x direction, step2 is in y direction, save pa[ix][iy][iz]. */
void matsave(Mat3DComplex_I &a, const std::string &varname, MATFile *pfile,
	const Char xyz, VecInt_I &slice, const Int step1, const Int step2)
{
	Int i, j, k, m, n, ind, Nslice{ slice.size() };
	Complex c; Doub cr, ci;
	// write variable name info
	n = (Int)varname.size();
	*pfile << n << '\n';
	for (i = 0; i < n; ++i) {
		*pfile << (Int)varname.at(i) << '\n';
	}
	// write data type info
	*pfile << 1 << '\n';
	if (xyz == 'x') {
		// write dimension info
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2;
		*pfile << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (i = 0; i < Nslice; ++i) {
			ind = slice[i];
			for (k = 0; k < n; ++k)
				for (j = 0; j < m; ++j)
				{
					c = a[ind][step1*j][step2*k]; cr = real(c); ci = imag(c);
					if (ci == 0)
						*pfile << cr << '\n';
					else
						*pfile << cr << '+' << ci << "i\n";
				}
					
		}
	}
	else if (xyz == 'y') {
		// write dimension info
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2;
		*pfile << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (j = 0; j < Nslice; ++j) {
			ind = slice[j];
			for (i = 0; i < n; ++i)
				for (k = 0; k < m; ++k) {
					c = a[step2*i][ind][step1*k]; cr = real(c); ci = imag(c);
					if (ci == 0)
						*pfile << cr << '\n';
					else
						*pfile << cr << '+' << ci << "i\n";
				}
		}
	}
	else if (xyz == 'z') {
		// write dimension info
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
		*pfile << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (j = 0; j < n; ++j)
				for (i = 0; i < m; ++i) {
					c = a[step1*i][step2*j][ind]; cr = real(c); ci = imag(c);
					if (ci == 0)
						*pfile << cr << '\n';
					else
						*pfile << cr << '+' << ci << "i\n";
				}
		}
	}
	else {
		cout << "error! illegal value of xyz" << endl; return;
	}
}

// matread functions

// how to write matread() functions in c++
//ifstream fin("test.matt");
//Doub cr = 0, ci = 0, d3 = 0, d4 = 0;
//Uchar suchar;
//fin >> cr;
//suchar = fin.get();
//fin >> ci;
//suchar = fin.get();
//suchar = fin.get();
//fin >> d3;
//fin >> suchar;
//fin >> d4;
//fin >> suchar;
//fin.ignore(1000, '\n');
//fin.close();

#endif /*#ifdef MATFILE_BINARY*/