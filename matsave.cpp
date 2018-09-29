#include "matsave.h"

using namespace std;

#if defined(MATFILE_BINARY) || defined(MATFILE_DUAL)

void matsave(Uchar_I s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
	Uchar *pps = (Uchar*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

void matsave(Int_I s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
	Int *pps = (Int*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

void matsave(Doub_I s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = mxCreateDoubleMatrix(1, 1, mxREAL);
	auto pps = mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

void matsave(Comp_I s, const string &varname, MATFile *pfile)
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

void matsave(VecUchar_I &v, const string &varname, MATFile *pfile)
{
	Long i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateUninitNumericMatrix(1, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppv = (Uchar*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecInt_I &v, const string &varname, MATFile *pfile)
{
	Long i, n;
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
	Long i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxREAL);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

void matsave(VecComp_I &v, const string &varname, MATFile *pfile)
{
	Long i, n;
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

void matsave(MatUchar_I &a, const string &varname, MATFile *pfile,
	Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	mxArray *pa;

	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppa = (Uchar*)mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j) {
			ppa[i + m * j] = a[step1*i][step2*j];
		}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatInt_I &a, const string &varname, MATFile *pfile,
	Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	mxArray *pa;
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
	Int *ppa = (Int*)mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j) {
			ppa[i + m * j] = a[step1*i][step2*j];
		}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatDoub_I &a, const string &varname, MATFile *pfile, 
			Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	mxArray *pa;
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
	auto ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j) {
			ppa[i + m*j] = a[step1*i][step2*j];
		}
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(MatComp_I &a, const string &varname, MATFile *pfile,
			Long_I step1, Long_I step2)
{
	Long i, j, m, n, ind;
	Comp c;
	mxArray *pa;
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
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(Mat3Doub_I &a, const string &varname, MATFile *pfile,
	Long_I step1, Long_I step2, Long_I step3)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa;
	m = a.dim1(); n = a.dim2(); q = a.dim3(); mn = m * n;
	m = (m + step1 - 1) / step1; n = (n + step2 - 1) / step2;
	q = (q + step3 - 1) / step3;
	size_t sz[3]{ size_t(m), size_t(n), size_t(q) };
	pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
	auto ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			for (k = 0; k < q; ++k)
				ppa[i + m * j + mn * k] = a[step1*i][step2*j][step3*k];
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}


void matsave(Mat3Doub_I &a, const string &varname, MATFile *pfile,
			Char_I xyz, VecInt_I &slice, Long_I step1, Long_I step2)
{
	Long i, j, k, m, n, mn, Nslice{ slice.size() }, ind;
	mxArray *pa;
	if (xyz == 'x') {
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ size_t(m), size_t(n), size_t(Nslice) };
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
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ size_t(m), size_t(n), size_t(Nslice) };
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
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ size_t(m), size_t(n), size_t(Nslice) };
		pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
		auto ppa = mxGetPr(pa);
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (i = 0; i < m; ++i)
				for (j = 0; j < n; ++j)
					ppa[i + m*j + mn*k] = a[step1*i][step2*j][ind];
		}
	}
	else
		error("error! illegal value of xyz")
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matsave(Mat3Comp_I &a, const string &varname, MATFile *pfile,
	Long_I step1, Long_I step2, Long_I step3)
{
	Long i, j, k, m, n, q, mn, ind;
	mxArray *pa;
	Comp c;
	m = a.dim1(); n = a.dim2(); q = a.dim3(); mn = m * n;
	if (step1 > 1 || step2 > 1 || step3 > 1) {
		m = (m + step1 - 1) / step1; n = (n + step2 - 1) / step2;
		q = (q + step3 - 1) / step3;
		size_t sz[3]{ size_t(m), size_t(n), size_t(q) };
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
		size_t sz[3]{ size_t(m), size_t(n), size_t(q) };
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

void matsave(Mat3Comp_I &a, const string &varname, MATFile *pfile,
			Char_I xyz, VecInt_I &slice, Long_I step1, Long_I step2)
{	
	Long i, j, k, m, n, mn, inda, Nslice{ slice.size() }, ind;
	mxArray *pa;
	Comp c;
	if (xyz == 'x') {
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ size_t(m), size_t(n), size_t(Nslice) };
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
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ size_t(m), size_t(n), size_t(Nslice) };
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
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2; mn = m * n;
		size_t sz[3]{ size_t(m), size_t(n), size_t(Nslice) };
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
	else
		error("illegal value of xyz!")
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

void matload(Uchar &i, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	if (!mxIsUint8(ps))
		error("matload(Uchar &i...): wrong type!")
	Uchar *pps = (Uchar *)mxGetPr(ps);
	i = pps[0];
	mxDestroyArray(ps);
}

void matload(Int &i, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	if (!mxIsInt32(ps))
		error("matload(Int &i...): wrong type!")
	Int *pps = (Int *)mxGetPr(ps);
	i = pps[0];
	mxDestroyArray(ps);
}

void matload(Doub &s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(ps))
		error("matload(Doub &s...): wrong type!")
	if (mxIsComplex(ps))
		error("matload(Doub &s...): wrong type!")
	auto pps = mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

void matload(Comp &s, const string &varname, MATFile *pfile)
{
	mxArray *ps;
	ps = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(ps))
		error("matload(Comp &s...): wrong type!");
	auto ppsr = mxGetPr(ps);
	auto ppsi = mxGetPi(ps);
	if (ppsi)
		s = Comp(ppsr[0], ppsi[0]);
	else
		s = ppsr[0];
	mxDestroyArray(ps);
}

void matload(VecUchar_O &v, const string &varname, MATFile *pfile)
{
	Long i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	if (!mxIsUint8(pv))
		error("matload(VecUchar_O &v...): wrong type!")
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Uchar *ppv = (Uchar *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

void matload(VecInt_O &v, const string &varname, MATFile *pfile)
{
	Long i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	if (!mxIsInt32(pv))
		error("matload(VecInt_O &v...): wrong type!")
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Int *ppv = (Int *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

void matload(VecDoub_O &v, const string &varname, MATFile *pfile)
{
	Long i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(pv))
		error("matload(VecDoub_O &v...): wrong type!")
	if (mxIsComplex(pv))
		error("matload(VecDoub_O &v...): wrong type!")
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	auto ppv = mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

void matload(VecComp_O &v, const string &varname, MATFile *pfile)
{
	Long i, n;
	mxArray *pv;
	pv = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(pv))
		error("matload(VecComp_O &v...): wrong type!")
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	if (ppvi)
		for (i = 0; i < n; ++i)
			v[i] = Comp(ppvr[i], ppvi[i]);
	else
		for (i = 0; i < n; ++i)
			v[i] = ppvr[i];
	mxDestroyArray(pv);
}

void matload(MatUchar_O &a, const string &varname, MATFile *pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	if (!mxIsUint8(pa))
		error("matload(MatUchar_O &a...): wrong type!")
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
	Uchar *ppa = (Uchar *)mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = ppa[m*j + i];
	mxDestroyArray(pa);
}

void matload(MatInt_O &a, const string &varname, MATFile *pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	if (!mxIsInt32(pa))
		error("matload(MatInt_O &a...): wrong type!")
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
	Int *ppa = (Int *)mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = ppa[m*j + i];
	mxDestroyArray(pa);
}

void matload(MatDoub_O &a, const string &varname, MATFile *pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(pa))
		error("matload(MatDoub_O &a...): wrong type!")
	if (mxIsComplex(pa))
		error("matload(MatDoub_O &a...): wrong type!")
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
	auto ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = ppa[m*j + i];
	mxDestroyArray(pa);
}

void matload(MatComp_O &a, const string &varname, MATFile *pfile)
{
	Long i, j, m, n, ind;
	mxArray *pa;
	pa = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(pa))
		error("matload(MatComp_O &a...): wrong type!")
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
	auto ppar = mxGetPr(pa);
	auto ppai = mxGetPi(pa);
	if (ppai)
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j){
			ind = i + m * j;
			a[i][j] = Comp(ppar[ind], ppai[ind]);
		}
	else
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = ppar[i + m*j];
	mxDestroyArray(pa);
}

void matload(Mat3Doub_O &a, const string &varname, MATFile *pfile)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(pa))
		error("matload(Mat3Doub_O &a...): wrong type!")
	if (mxIsComplex(pa))
		error("matload(Mat3Doub_O &a...): wrong type!")
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1]; q = sz[2]; mn = m*n;
	a.resize(m, n, q);
	auto *ppa = mxGetPr(pa);
	for (i = 0; i < m; ++i)
	for (j = 0; j < n; ++j)
	for (k = 0; k < q; ++k)
		a[i][j][k] = ppa[i + m*j + mn*k];
	mxDestroyArray(pa);
}

void matload(Mat3Comp_O &a, const string &varname, MATFile *pfile)
{
	Long i, j, k, m, n, q, mn, ind;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
	if (!mxIsDouble(pa))
		error("matload(Mat3Complex_O &a...): wrong type!")
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1]; q = sz[2]; mn = m*n;
	a.resize(m, n, q);
	auto *ppar = mxGetPr(pa);
	auto *ppai = mxGetPi(pa);
	if (ppai)
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
		for (k = 0; k < q; ++k){
			ind = i + m*j + mn*k;
			a[i][j][k] = Comp(ppar[ind], ppai[ind]);
		}
	else
		for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
		for (k = 0; k < q; ++k)
			a[i][j][k] = ppar[i + m*j + mn*k];
	mxDestroyArray(pa);
}

#endif

#ifndef MATFILE_BINARY

// read the next variable after previous '\n'
Long scanInverse(ifstream &fin)
{
	Char c;
	Long ind, i, N;

	ind = fin.tellg();
	for (i = 2; i < 100; ++i) {
		fin.seekg(ind - i); c = fin.get();
		if (c == '\n') break;
	}
	fin >> N;
	fin.seekg(ind - i);
	return N;
}

// get var names and positions from the end of the file
// after return, pfile->ind[i] points to the first matrix element;
void getprofile(MATTFile *pfile)
{
	Int i, j, n, temp;
	vector<Long> size;
	string name;
	ifstream &fin = pfile->in;

	// read number of variables and their positions
	fin.seekg(0, fin.end);
	pfile->n = (Int)scanInverse(fin);
	for (i = 0; i < pfile->n; ++i)
		pfile->ind.push_back(scanInverse(fin));

	// loop through each variable
	for (i = 0; i < pfile->n; ++i) {
		fin.seekg(pfile->ind[i]);
		// read var name
		fin >> n;
		name.resize(0);
		for (j = 0; j < n; ++j) {
			fin >> temp; name.push_back((char)temp);
		}
		pfile->name.push_back(name);
		// read var type
		fin >> temp; pfile->type.push_back(temp);
		// read var dim
		fin >> n;
		size.resize(0);
		for (j = 0; j < n; ++j) {
			fin >> temp; size.push_back(temp);
		}
		pfile->size.push_back(size);
		pfile->ind[i] = fin.tellg();
	}
}

MATTFile *mattOpen(string fname, Char_I *rw)
{
	// must open file in binary mode, otherwise, '\n' will be written as "\r\n"
	// and seekg() will not work the same in linux.
	#ifndef MATFILE_DUAL // TEXT mode
		fname += "t";
	#endif

	MATTFile* pfile = new MATTFile;
	if (rw[0] == 'w') {
		pfile->rw = 'w';
		pfile->n = 0;
		pfile->out = ofstream(fname, ios_base::binary);
		#ifdef MATFILE_PRECISION
			pfile->out.precision(MATFILE_PRECISION);
		#endif
	}
	else {
		pfile->rw = 'r';
		pfile->in = ifstream(fname, ios_base::binary);
		if (!pfile->in)
			error("error: file not found: ")
		pfile->in.precision(17);
		getprofile(pfile); // get var names
	}
	return pfile;
}

void mattClose(MATTFile* pfile)
{
	Llong i;
	if (pfile->rw == 'w') {
		ofstream &fout = pfile->out;
		// write position of variables
		for (i = pfile->ind.size() - 1; i >= 0; --i)
			fout << pfile->ind[i] << "\n";
		// write number of variables
		fout << pfile->n;
		pfile->out.close();
	}
	else {
		pfile->in.close();
	}
	delete pfile;
}

void mattsave(Uchar_I s, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 3 << '\n';
	// write dimension info
	fout << 0 << '\n';
	// write scalar
	fout << (Int)s << '\n';
}

void mattsave(Int_I s, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 2 << '\n';
	// write dimension info
	fout << 0 << '\n';
	// write matrix data
	fout << s << '\n';
}

void mattsave(Doub_I s, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 0 << '\n';
	// write dimension info
	fout << 0 << '\n';
	// write matrix data
	fout << s << '\n';
}

void mattsave(Comp_I s, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 1 << '\n';
	// write dimension info
	fout << 0 << '\n';
	// write matrix data
	if (imag(s) == 0)
		fout << real(s) << '\n';
	else if (imag(s) < 0)
		fout << real(s) << imag(s) << "i\n";
	else
		fout << real(s) << '+' << imag(s) << "i\n";
}

void mattsave(VecUchar_I &v, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 3 << '\n';
	// write dimension info
	n = v.size();
	fout << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		fout << (Int)v[i] << '\n';
	}
}

void mattsave(VecInt_I &v, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 2 << '\n';
	// write dimension info
	n = v.size();
	fout << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		fout << v[i] << '\n';
	}
}

void mattsave(VecDoub_I &v, const string &varname, MATTFile *pfile)
{
	Long i, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 0 << '\n';
	// write dimension info
	n = v.size();
	fout << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		fout << v[i] << '\n';
	}
}

void mattsave(VecComp_I &v, const string &varname, MATTFile *pfile)
{
	Long i, n;
	Doub cr, ci;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i)
		fout << (Int)varname.at(i) << '\n';
	// write data type info
	fout << 1 << '\n';
	// write dimension info
	n = v.size();
	fout << 1 << '\n' << n << '\n';
	// write matrix data
	for (i = 0; i < n; ++i) {
		cr = real(v[i]); ci = imag(v[i]);
		if (ci == 0)
			fout << cr << '\n';
		else if (ci < 0)
			fout << cr << ci << "i\n";
		else
			fout << cr << '+' << ci << "i\n";
	}
}

void mattsave(MatUchar_I &a, const string &varname, MATTFile *pfile,
	Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 3 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	fout << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			fout << (Int)a[step1*i][step2*j] << '\n';
		}
}

void mattsave(MatInt_I &a, const string &varname, MATTFile *pfile,
	Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 2 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	fout << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			fout << a[step1*i][step2*j] << '\n';
		}
}

void mattsave(MatDoub_I &a, const string &varname, MATTFile *pfile,
	Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 0 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	fout << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			fout << a[step1*i][step2*j] << '\n';
		}
}

void mattsave(MatComp_I &a, const string &varname, MATTFile *pfile,
	Long_I step1, Long_I step2)
{
	Long i, j, m, n;
	Comp c; Doub cr, ci;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 1 << '\n';
	// write dimension info
	m = (a.nrows() + step1 - 1) / step1; n = (a.ncols() + step2 - 1) / step2;
	fout << 2 << '\n' << m << '\n' << n << '\n';
	// write matrix data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			c = a[step1*i][step2*j]; cr = real(c); ci = imag(c);
			if (ci == 0)
				fout << cr << '\n';
			else if (ci < 0)
				fout << cr << ci << "i\n";
			else
				fout << cr << '+' << ci << "i\n";
		}
}

void mattsave(Mat3Doub_I &a, const string &varname, MATTFile *pfile,
	Long_I step1, Long_I step2, Long_I step3)
{
	Long i, j, k, m, n, q;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 0 << '\n';
	// write dimension info
	m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
	q = (a.dim3() + step3 - 1) / step3;
	fout << 3 << '\n' << m << '\n' << n << '\n' << q << '\n';
	// write matrix data
	for (k = 0; k < q; ++k)
	for (j = 0; j < n; ++j)
	for (i = 0; i < m; ++i)
		fout << a[step1*i][step2*j][step3*k] << '\n';
}

void mattsave(Mat3Doub_I &a, const string &varname, MATTFile *pfile,
	Char_I xyz, VecInt_I &slice, Long_I step1, Long_I step2)
{
	Long i, j, k, m, n, ind, Nslice{ slice.size() };
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 0 << '\n';
	if (xyz == 'x') {
		// write dimension info
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2;
		fout << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (i = 0; i < Nslice; ++i) {
			ind = slice[i];
			for (k = 0; k < n; ++k)
				for (j = 0; j < m; ++j)
					fout << a[ind][step1*j][step2*k] << '\n';
		}
	}
	else if (xyz == 'y') {
		// write dimension info
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2;
		fout << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (j = 0; j < Nslice; ++j) {
			ind = slice[j];
			for (i = 0; i < n; ++i)
				for (k = 0; k < m; ++k)
					fout << a[step2*i][ind][step1*k] << '\n';
		}
	}
	else if (xyz == 'z') {
		// write dimension info
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
		fout << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (j = 0; j < n; ++j)
				for (i = 0; i < m; ++i)
					fout << a[step1*i][step2*j][ind] << '\n';
		}
	}
	else
		error("illegal value of xyz")
}

void mattsave(Mat3Comp_I &a, const string &varname, MATTFile *pfile,
	Long_I step1, Long_I step2, Long_I step3)
{
	Long i, j, k, m, n, q;
	Comp c; Doub cr, ci;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 1 << '\n';
	// write dimension info
	m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
	q = (a.dim3() + step3 - 1) / step3;
	fout << 3 << '\n' << m << '\n' << n << '\n' << q << '\n';
	// write matrix data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i) {
				c = a[step1*i][step2*j][step3*k]; cr = real(c); ci = imag(c);
				if (ci == 0)
					fout << cr << '\n';
				else if (ci < 0)
					fout << cr << ci << "i\n";
				else
					fout << cr << '+' << ci << "i\n";
			}
}

void mattsave(Mat3Comp_I &a, const string &varname, MATTFile *pfile,
	Char_I xyz, VecInt_I &slice, Long_I step1, Long_I step2)
{
	Long i, j, k, m, n, ind, Nslice{ slice.size() };
	Comp c; Doub cr, ci;
	ofstream &fout = pfile->out;
	++pfile->n; pfile->ind.push_back(fout.tellp());
	// write variable name info
	n = varname.size();
	fout << n << '\n';
	for (i = 0; i < n; ++i) {
		fout << (Int)varname.at(i) << '\n';
	}
	// write data type info
	fout << 1 << '\n';
	if (xyz == 'x') {
		// write dimension info
		m = (a.dim2() + step1 - 1) / step1; n = (a.dim3() + step2 - 1) / step2;
		fout << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (i = 0; i < Nslice; ++i) {
			ind = slice[i];
			for (k = 0; k < n; ++k)
				for (j = 0; j < m; ++j)
				{
					c = a[ind][step1*j][step2*k]; cr = real(c); ci = imag(c);
					if (ci == 0)
						fout << cr << '\n';
					else if (ci < 0)
						fout << cr << ci << "i\n";
					else
						fout << cr << '+' << ci << "i\n";
				}
					
		}
	}
	else if (xyz == 'y') {
		// write dimension info
		m = (a.dim3() + step1 - 1) / step1; n = (a.dim1() + step2 - 1) / step2;
		fout << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (j = 0; j < Nslice; ++j) {
			ind = slice[j];
			for (i = 0; i < n; ++i)
				for (k = 0; k < m; ++k) {
					c = a[step2*i][ind][step1*k]; cr = real(c); ci = imag(c);
					if (ci == 0)
						fout << cr << '\n';
					else if (ci < 0)
						fout << cr << ci << "i\n";
					else
						fout << cr << '+' << ci << "i\n";
				}
		}
	}
	else if (xyz == 'z') {
		// write dimension info
		m = (a.dim1() + step1 - 1) / step1; n = (a.dim2() + step2 - 1) / step2;
		fout << 3 << '\n' << m << '\n' << n << '\n' << Nslice << '\n';
		// write matrix data
		for (k = 0; k < Nslice; ++k) {
			ind = slice[k];
			for (j = 0; j < n; ++j)
				for (i = 0; i < m; ++i) {
					c = a[step1*i][step2*j][ind]; cr = real(c); ci = imag(c);
					if (ci == 0)
						fout << cr << '\n';
					else if (ci < 0)
						fout << cr << ci << "i\n";
					else
						fout << cr << '+' << ci << "i\n";
				}
		}
	}
	else
		error("illegal value of xyz")
}

// search variable in file by name
inline Int nameSearch(const string &name, MATTFile *pfile)
{
	for (Int i = 0; i < pfile->n; ++i)
		if (name == pfile->name[i])
			return i;
	error("variable name not found!")
	return -1;
}

inline void scanComplex(Comp &c, ifstream &fin)
{
	Doub cr = 0, ci = 0;
	Uchar ch;
	fin >> cr;
	ch = fin.get();
	if (ch == '\n') {
		c = cr; return;
	}
	fin >> ci;
	if (ch == '-')
		ci *= -1.;
	c = Comp(cr, ci);
	fin.ignore(100, '\n');
}

void mattload(Uchar &I, const string &varname, MATTFile *pfile)
{
	Int i, temp;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	if (pfile->type[i] != 3 || pfile->size[i].size() != 0)
		error("wrong type or dim!")
	// read var data
	fin >> temp; I = Uchar(temp);
}

void mattload(Int &I, const string &varname, MATTFile *pfile)
{
	Int i;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);
	
	// read var type and dim
	if (pfile->type[i] < 2 || pfile->size[i].size() != 0)
		error("wrong type or dim!")
	// read var data
	fin >> I;
}

void mattload(Doub &I, const string &varname, MATTFile *pfile)
{
	Int i;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	if (pfile->type[i] == 1 || pfile->size[i].size() != 0)
		error("wrong type or dim!")
	// read var data
	fin >> I;
}

void mattload(Comp &I, const string &varname, MATTFile *pfile)
{
	Int i;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	if (pfile->size[i].size() != 0)
		error("wrong type or dim!")
	// read var data
	scanComplex(I, fin);
}

void mattload(VecUchar_O &v, const string &varname, MATTFile *pfile)
{
	Long i, n, dim, temp;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] != 3 || dim != 1)
		error("wrong type or dim!")
	n = pfile->size[i][0]; v.resize(n);
	// read var data
	for (i = 0; i < n; ++i) {
		fin >> temp;  v[i] = (Uchar)temp;
	}
}

void mattload(VecInt_O &v, const string &varname, MATTFile *pfile)
{
	Long i, dim, n;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] < 2 || dim != 1)
		error("wrong type or dim!")
	n = pfile->size[i][0]; v.resize(n);
	// read var data
	for (i = 0; i < n; ++i)
		fin >> v[i];
}

void mattload(VecDoub_O &v, const string &varname, MATTFile *pfile)
{
	Long i, dim, n;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] == 1 || dim != 1)
		error("wrong type or dim!")
	n = pfile->size[i][0]; v.resize(n);
	// read var data
	for (i = 0; i < n; ++i)
		fin >> v[i];
}

void mattload(VecComp_O &v, const string &varname, MATTFile *pfile)
{
	Long i, dim, n;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (dim != 1)
		error("wrong type or dim!")
	n = pfile->size[i][0]; v.resize(n);
	// read var data
	for (i = 0; i < n; ++i)
		scanComplex(v[i], fin);
}

void mattload(MatUchar_O &a, const string &varname, MATTFile *pfile)
{
	Long i, j, dim, m, n, temp;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] != 3 || dim != 2)
		error("wrong type or dim!")
	m = pfile->size[i][0]; n = pfile->size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i) {
			fin >> temp;  a[i][j] = (Uchar)temp;
		}
}

void mattload(MatInt_O &a, const string &varname, MATTFile *pfile)
{
	Long i, j, dim, m, n;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] < 2 || dim != 2)
		error("wrong type or dim!")
	m = pfile->size[i][0]; n = pfile->size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			fin >> a[i][j];
}

void mattload(MatDoub_O &a, const string &varname, MATTFile *pfile)
{
	Long i, j, dim, m, n;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] == 1 || dim != 2)
		error("wrong type or dim!")
	m = pfile->size[i][0]; n = pfile->size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			fin >> a[i][j];
}

void mattload(MatComp_O &a, const string &varname, MATTFile *pfile)
{
	Long i, j, dim, m, n;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (dim != 2)
		error("wrong type or dim!")
	m = pfile->size[i][0]; n = pfile->size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			scanComplex(a[i][j], fin);
}

void mattload(Mat3Doub_O &a, const string &varname, MATTFile *pfile)
{
	Long i, j, k, dim, m, n, q;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (pfile->type[i] == 1 || dim != 3)
		error("wrong type or dim!")
	m = pfile->size[i][0]; n = pfile->size[i][1]; q = pfile->size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i)
				fin >> a[i][j][k];
}

void mattload(Mat3Comp_O &a, const string &varname, MATTFile *pfile)
{
	Long i, j, k, dim, m, n, q;
	ifstream &fin = pfile->in;
	i = nameSearch(varname, pfile);
	fin.seekg(pfile->ind[i]);

	// read var type and dim
	dim = pfile->size[i].size();
	if (dim != 3)
		error("wrong type or dim!")
	m = pfile->size[i][0]; n = pfile->size[i][1]; q = pfile->size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i)
				scanComplex(a[i][j][k], fin);
}

#endif

#ifdef MATFILE_DUAL
void mat2matt(const string &fmat, const string &fmatt)
{
	Int n;
	Long i, ndim;
	char **names;
	MATFile *pfmat = matOpen(fmat.c_str(), "r");
	MATTFile *pfmatt = mattOpen(fmatt, "w");
	
	// get number of variables n and names
	names = matGetDir(pfmat, &n);
	for (i = 0; i < n; ++i){
		mxArray *pa = matGetVariable(pfmat, names[i]);
		ndim = mxGetNumberOfDimensions(pa);
		const mwSize *sz = mxGetDimensions(pa);
		if (ndim == 2) {
			if (sz[0] == 0 || sz[1] == 0)
				error("empty variable unsupported!")
			else if (sz[0] == 1 && sz[1] == 1) {
				// scalar
				if (mxIsComplex(pa)) {
					Comp c;
					matload(c, names[i], pfmat);
					mattsave(c, names[i], pfmatt);
				}
				else if (mxIsDouble(pa)) {
					Doub s;
					matload(s, names[i], pfmat);
					mattsave(s, names[i], pfmatt);
				}
				else if (mxIsInt32(pa)) {
					Int s;
					matload(s, names[i], pfmat);
					mattsave(s, names[i], pfmatt);
				}
				else if (mxIsUint8(pa)) {
					Uchar ch;
					matload(ch, names[i], pfmat);
					mattsave(ch, names[i], pfmatt);
				}
				else
					error("type unsupported!")
			}
			else if (sz[0] == 1 || sz[1] == 1) {
				// save to vector
				if (mxIsComplex(pa)) {
					VecComp v;
					matload(v, names[i], pfmat);
					mattsave(v, names[i], pfmatt);
				}
				else if (mxIsDouble(pa)) {
					VecDoub v;
					matload(v, names[i], pfmat);
					mattsave(v, names[i], pfmatt);
				}
				else if (mxIsInt32(pa)) {
					VecInt v;
					matload(v, names[i], pfmat);
					mattsave(v, names[i], pfmatt);
				}
				else if (mxIsUint8(pa)) {
					VecUchar v;
					matload(v, names[i], pfmat);
					mattsave(v, names[i], pfmatt);
				}
				else
					error("type unsupported!")
			}
			else {
				// save to matrix
				if (mxIsComplex(pa)) {
					MatComp a;
					matload(a, names[i], pfmat);
					mattsave(a, names[i], pfmatt);
				}
				else if (mxIsDouble(pa)) {
					MatDoub a;
					matload(a, names[i], pfmat);
					mattsave(a, names[i], pfmatt);
				}
				else if (mxIsInt32(pa)) {
					MatInt a;
					matload(a, names[i], pfmat);
					mattsave(a, names[i], pfmatt);
				}
				else if (mxIsUint8(pa)) {
					MatUchar a;
					matload(a, names[i], pfmat);
					mattsave(a, names[i], pfmatt);
				}
				else
					error("type unsupported!")
			}
		}
		else if (ndim == 3) {
			// save to matrix
			if (mxIsComplex(pa)) {
				Mat3Comp a3;
				matload(a3, names[i], pfmat);
				mattsave(a3, names[i], pfmatt);
			}
			else if (mxIsDouble(pa)) {
				Mat3Doub a3;
				matload(a3, names[i], pfmat);
				mattsave(a3, names[i], pfmatt);
			}
			else
				error("type unsupported!")
		}
		else
			error("unsupported dimension!")
	}
	matClose(pfmat);
	mattClose(pfmatt);
}

void matt2mat(const string &fmatt, const string &fmat)
{
	error("this function is not complete")
}
#endif