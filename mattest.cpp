#include <iostream>
#include "nr3.h"
#include "nr3plus.h"
#include "matsave.h"

using namespace std;

int main()
{
	MATFile *pfile = matOpen("nrMat.mat", "w");
	Complex I(0, 1);

	// scalars
	Doub s(3.1415926535897932384626);
	matsave((Uchar)88, "s8", pfile);
	matsave((Int)99, "si", pfile);
	matsave(s, "s", pfile);
	Complex sc(3.1, 3.2);
	matsave(sc, "sc", pfile);

	// vectors
	VecUchar v8(3);
	v8[0] = 1; v8[1] = 2; v8[2] = 3;
	matsave(v8, "v8", pfile);
	VecInt vi(3);
	vi[0] = 1; vi[1] = 2; vi[2] = 3;
	matsave(vi, "vi", pfile);
	VecDoub v(3);
	v[0] = 1.; v[1] = 2.; v[2] = 3.;
	matsave(v, "v", pfile);
	VecComplex vc(3);
	for (Int i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i + I * (Doub)i;
	matsave(vc, "vc", pfile);

	// matrices
	MatUchar A8;
	A8.assign(2, 3, 0);
	A8[0][0] = 1; A8[0][1] = 3; A8[0][2] = 5.; A8[1][2] = 11;
	matsave(A8, "A8", pfile);

	MatInt AI;
	AI.assign(2, 3, 0);
	AI[0][0] = 1; AI[0][1] = 3; AI[0][2] = 5.; AI[1][2] = 11;
	matsave(AI, "AI", pfile);

	MatDoub A;
	A.assign(2, 3, 0.);
	A[0][0] = 1.; A[0][1] = 3.; A[0][2] = 5.; A[1][2] = 11;
	matsave(A, "A", pfile);
	
	MatComplex C(3, 3);
	Complex *pC{ &C[0][0] };
	for (Int i = 0; i < 9; ++i) {
		pC[i] = 1 + (Doub)i + I * (Doub)i;
	}
	matsave(C, "C", pfile);

	// matrix sampling
	A.resize(5, 7);
	for (Int i = 0; i < 35; ++i) {
		A[0][i] = (Doub)i;
	}
	matsave(A, "Asample", pfile, 2, 3);

	C.resize(5, 7);
	for (Int i = 0; i < 35; ++i) {
		C[0][i] = Complex(i, i + 1.);
	}
	matsave(C, "Csample", pfile, 2, 3);

	// 3d arrays
	Mat3DDoub A3;
	A3.resize(2, 2, 2);
	Doub *pA3 = A3[0][0];
	for (Int i = 0; i < 8; ++i)
		pA3[i] = 1. + (Doub)i;
	matsave(A3, "A3", pfile);

	Mat3DComplex C3;
	C3.resize(2, 2, 2);
	Complex *pC3 = C3[0][0];
	for (Int i = 0; i < 8; ++i)
		pC3[i] = Complex(1. + (Doub)i, (Doub)i);
	matsave(C3, "C3", pfile);

	// 3d array slicing + sampling
	A3.resize(5, 5, 5);
	VecInt slice(3);  slice[0] = 0; slice[1] = 2; slice[2] = 4;
	for (Int i = 0; i < 125; ++i)
		A3[0][0][i] = (Doub)i;
	matsave(A3, "A3slice", pfile, 'y', slice, 1, 2);

	C3.resize(5, 5, 5);
	for (Int i = 0; i < 125; ++i)
		C3[0][0][i] = Complex((Doub)i, i+1.);
	matsave(C3, "C3slice", pfile, 'y', slice, 1, 2);

	matClose(pfile);

	// read test

	// scalars
	//pfile = matOpen("nrMat.mat", "r");
	//s = 0.;
	//matload(s, "s", pfile);
	//cout.precision(16);
	//cout << s << endl;

	//sc = 0.;
	//matload(sc, "sc", pfile);
	//cout << sc << endl;

	//// vectors
	//v.resize(0);
	//matload(v, "v", pfile);
	//disp(v, 16);

	//vc.resize(0);
	//matload(vc, "vc", pfile);
	//disp(vc, 16);

	//// matrices
	//A.resize(0, 0);
	//matload(A, "A", pfile);
	//disp(A, 16);

	//C.resize(0, 0);
	//matload(C, "C", pfile);
	//disp(C, 16);

	//// 3D arrays
	//A3.resize(0, 0, 0);
	//matload(A3, "A3", pfile);

	//C3.resize(0, 0, 0);
	//matload(C3, "C3", pfile);

	//matClose(pfile);


}

