#include <iostream>
#include "nr3.h"
#include "nr3plus.h"
#include "matsave.h"

using namespace std;

// this test must be in dual mode

int main()
{
	
	// TODO: write 2 conversion functions for any file
	//mat2matt()
	//matt2mat()

	// convert waveInit.mat

	//mat2matt("waveInit.mat", "waveInit.matt");
	//mat2matt("nr.mat", "nr.matt");

	/*MATFile *pmatfile = matOpen("waveInit.mat", "r");
	Int Nx, Ny;
	Doub xmin, xmax, xc, ymin, ymax, yc;
	MatDoub Psi;
	matload(Nx, "Nx", pmatfile); matload(Ny, "Ny", pmatfile);
	matload(xmin, "xmin", pmatfile); matload(xmax, "xmax", pmatfile);
	matload(xc, "xc", pmatfile);
	matload(ymin, "ymin", pmatfile); matload(ymax, "ymax", pmatfile);
	matload(yc, "yc", pmatfile);
	matload(Psi, "Psi", pmatfile);
	matClose(pmatfile);

	MATTFile *pmattfile = mattOpen("waveInit.matt", "w");
	mattsave(Nx, "Nx", pmattfile); mattsave(Ny, "Ny", pmattfile);
	mattsave(xmin, "xmin", pmattfile); mattsave(xmax, "xmax", pmattfile);
	mattsave(xc, "xc", pmattfile);
	mattsave(ymin, "ymin", pmattfile); mattsave(ymax, "ymax", pmattfile);
	mattsave(yc, "yc", pmattfile);
	mattsave(Psi, "Psi", pmattfile);
	mattClose(pmattfile);*/
	
	MATFile *pfmat = matOpen("nr.mat", "w");
	MATTFile *pfmatt = mattOpen("nr.matt", "w");

	// scalars
	Doub s(3.1415926535897932384626);
	matsave((Uchar)88, "s8", pfmat);
	mattsave((Uchar)88, "s8", pfmatt);

	matsave((Int)99, "si", pfmat);
	mattsave((Int)99, "si", pfmatt);

	matsave(s, "s", pfmat);
	mattsave(s, "s", pfmatt);

	Complex sc(3.1, -3.2);
	matsave(sc, "sc", pfmat);
	mattsave(sc, "sc", pfmatt);

	// vectors
	VecUchar v8(3);
	v8[0] = 1; v8[1] = 2; v8[2] = 3;
	matsave(v8, "v8", pfmat);
	mattsave(v8, "v8", pfmatt);
	VecInt vi(3);
	vi[0] = 1; vi[1] = 2; vi[2] = 3;
	matsave(vi, "vi", pfmat);
	mattsave(vi, "vi", pfmatt);
	VecDoub v(3);
	v[0] = 1.; v[1] = 2.; v[2] = 3.;
	matsave(v, "v", pfmat);
	mattsave(v, "v", pfmatt);
	VecComplex vc(3);
	for (Int i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i - I * (Doub)i;
	matsave(vc, "vc", pfmat);
	mattsave(vc, "vc", pfmatt);

	// matrices
	MatUchar A8;
	A8.assign(2, 3, 0);
	A8[0][0] = 1; A8[0][1] = 3; A8[0][2] = 5; A8[1][2] = 11;
	matsave(A8, "A8", pfmat);
	mattsave(A8, "A8", pfmatt);

	MatInt AI;
	AI.assign(2, 3, 0);
	AI[0][0] = 1; AI[0][1] = 3; AI[0][2] = 5; AI[1][2] = 11;
	matsave(AI, "AI", pfmat);
	mattsave(AI, "AI", pfmatt);

	MatDoub A;
	A.assign(2, 3, 0.);
	A[0][0] = 1; A[0][1] = 3; A[0][2] = 5; A[1][2] = 11;
	matsave(A, "A", pfmat);
	mattsave(A, "A", pfmatt);

	MatComplex C(3, 3);
	Complex *pC{ &C[0][0] };
	for (Int i = 0; i < 9; ++i) {
		pC[i] = 1 + (Doub)i + I * (Doub)i;
	}
	matsave(C, "C", pfmat);
	mattsave(C, "C", pfmatt);

	// matrix sampling
	A.resize(5, 7);
	for (Int i = 0; i < 35; ++i) {
		A[0][i] = (Doub)i;
	}
	matsave(A, "Asample", pfmat, 2, 3);
	mattsave(A, "Asample", pfmatt, 2, 3);

	C.resize(5, 7);
	for (Int i = 0; i < 35; ++i) {
		C[0][i] = Complex(i, i + 1.);
	}
	matsave(C, "Csample", pfmat, 2, 3);
	mattsave(C, "Csample", pfmatt, 2, 3);

	//// 3d arrays
	Mat3DDoub A3;
	A3.resize(2, 2, 2);
	Doub *pA3 = A3[0][0];
	for (Int i = 0; i < 8; ++i)
		pA3[i] = 1. + (Doub)i;
	matsave(A3, "A3", pfmat);
	mattsave(A3, "A3", pfmatt);

	Mat3DComplex C3;
	C3.resize(2, 2, 2);
	Complex *pC3 = C3[0][0];
	for (Int i = 0; i < 8; ++i)
		pC3[i] = Complex(1. + (Doub)i, (Doub)i);
	matsave(C3, "C3", pfmat);
	mattsave(C3, "C3", pfmatt);

	// 3d array slicing + sampling
	A3.resize(5, 5, 5);
	VecInt slice(3);  slice[0] = 0; slice[1] = 2; slice[2] = 4;
	for (Int i = 0; i < 125; ++i)
		A3[0][0][i] = (Doub)i;
	matsave(A3, "A3slice", pfmat, 'y', slice, 1, 2);
	mattsave(A3, "A3slice", pfmatt, 'y', slice, 1, 2);

	C3.resize(5, 5, 5);
	for (Int i = 0; i < 125; ++i)
		C3[0][0][i] = Complex((Doub)i, i+1.);
	matsave(C3, "C3slice", pfmat, 'y', slice, 1, 2);
	mattsave(C3, "C3slice", pfmatt, 'y', slice, 1, 2);

	matClose(pfmat);
	mattClose(pfmatt);

	// read test

	// scalars
	pfmat = matOpen("nr.mat", "r");
	pfmatt = mattOpen("nr.matt", "r");
	Uchar s8;
	Int si;
	
	matload(s8, "s8", pfmat);
	cout << "s8 = " << (Int)s8 << '\n' << endl;
	s8 = 0;
	mattload(s8, "s8", pfmatt);
	cout << "s8 = " << (Int)s8 << '\n' << endl;


	matload(si, "si", pfmat);
	cout << "si = " << si << '\n' << endl;
	mattload(si, "si", pfmatt);
	cout << "si = " << si << '\n' << endl;

	s = 0.;
	cout.precision(16);
	matload(s, "s", pfmat);
	cout << "s = " << s << '\n' << endl;
	mattload(s, "s", pfmatt);
	cout << "s = " << s << '\n' << endl;

	sc = 0.;
	matload(sc, "sc", pfmat);
	cout << "sc = " << sc << '\n' << endl;
	mattload(sc, "sc", pfmatt);
	cout << "sc = " << sc << '\n' << endl;

	// vectors
	v8.resize(0);
	matload(v8, "v8", pfmat);
	cout << "v8 = " << endl;
	disp(v8, 16);
	v8.resize(0);
	mattload(v8, "v8", pfmatt);
	cout << "v8 = " << endl;
	disp(v8, 16);
	// TODO: disp(v8, 16);

	vi.resize(0);
	matload(vi, "vi", pfmat);
	cout << "vi = " << endl;
	disp(vi, 16);
	// TODO: disp(vi, 16);
	vi.resize(0);
	mattload(vi, "vi", pfmatt);
	cout << "vi = " << endl;
	disp(vi, 16);
	// TODO: disp(vi, 16);

	v.resize(0);
	matload(v, "v", pfmat);
	cout << "v = " << endl;
	disp(v, 16);
	v.resize(0);
	mattload(v, "v", pfmatt);
	cout << "v = " << endl;
	disp(v, 16);

	vc.resize(0);
	matload(vc, "vc", pfmat);
	cout << "vc = " << endl;
	disp(vc, 16);
	vc.resize(0);
	mattload(vc, "vc", pfmatt);
	cout << "vc = " << endl;
	disp(vc, 16);

	// matrices
	A8.resize(0, 0);
	matload(A8, "A8", pfmat);
	cout << "A8 = " << endl;
	disp(A8, 16);
	A.resize(0, 0);
	mattload(A8, "A8", pfmatt);
	cout << "A8 = " << endl;
	disp(A8, 16);

	AI.resize(0, 0);
	matload(AI, "AI", pfmat);
	cout << "AI = " << endl;
	disp(AI, 16);
	AI.resize(0, 0);
	mattload(AI, "AI", pfmatt);
	cout << "AI = " << endl;
	disp(AI, 16);

	A.resize(0, 0);
	matload(A, "A", pfmat);
	cout << "A = " << endl;
	disp(A, 16);
	A.resize(0, 0);
	mattload(A, "A", pfmatt);
	cout << "A = " << endl;
	disp(A, 16);

	C.resize(0, 0);
	matload(C, "C", pfmat);
	cout << "C = " << endl;
	disp(C, 16);
	C.resize(0, 0);
	mattload(C, "C", pfmatt);
	cout << "C = " << endl;
	disp(C, 16);

	// 3D arrays
	A3.resize(0, 0, 0);
	matload(A3, "A3", pfmat);
	A3.resize(0, 0, 0);
	mattload(A3, "A3", pfmatt);
	//TODO design 3d disp

	C3.resize(0, 0, 0);
	matload(C3, "C3", pfmat);
	C3.resize(0, 0, 0);
	mattload(C3, "C3", pfmatt);

	matClose(pfmat);
	mattClose(pfmatt);
}

