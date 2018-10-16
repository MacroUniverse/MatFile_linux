#include "../MatFile_linux/matsave.h"
#include "../SLISC/disp.h"

void test_dual()
{
	using std::cout; using std::endl;
	using namespace slisc;

	// write to file
	MATFile *pfmat = matOpen("test.mat", "w");
	MATTFile *pfmatt = mattOpen("test.matt", "w");

	// scalars
	Uchar s8 = 88;
	matsave(s8, "s8", pfmat);
	mattsave(s8, "s8", pfmatt);

	Int si = 99;
	matsave(si, "si", pfmat);
	mattsave(si, "si", pfmatt);

	Doub s(3.14159265358979323);
	matsave(s, "s", pfmat);
	mattsave(s, "s", pfmatt);

	Comp sc(s, -s);
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
	VecComp vc(3);
	for (Int i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i - I * (Doub)i;
	matsave(vc, "vc", pfmat);
	mattsave(vc, "vc", pfmatt);

	// matrices
	MatUchar A8(2, 3);
	A8 = 0;
	A8[0][0] = 1; A8[0][1] = 3; A8[0][2] = 5; A8[1][2] = 11;
	matsave(A8, "A8", pfmat);
	mattsave(A8, "A8", pfmatt);

	MatInt AI(2, 3);
	AI = 0;
	AI[0][0] = 1; AI[0][1] = 3; AI[0][2] = 5; AI[1][2] = 11;
	matsave(AI, "AI", pfmat);
	mattsave(AI, "AI", pfmatt);

	MatDoub A(2, 3);
	A = 0;
	A[0][0] = 1; A[0][1] = 3; A[0][2] = 5; A[1][2] = 11;
	matsave(A, "A", pfmat);
	mattsave(A, "A", pfmatt);

	MatComp C(3, 3);
	Comp *pC{ &C[0][0] };
	for (Int i = 0; i < 9; ++i) {
		pC[i] = 1 + (Doub)i + I * (Doub)i;
	}
	matsave(C, "C", pfmat);
	mattsave(C, "C", pfmatt);

	// 3d arrays
	Mat3Doub A3;
	A3.resize(2, 2, 2);
	Doub *pA3 = A3[0][0];
	for (Int i = 0; i < 8; ++i)
		pA3[i] = 1. + (Doub)i;
	matsave(A3, "A3", pfmat);
	mattsave(A3, "A3", pfmatt);

	Mat3Comp C3;
	C3.resize(2, 2, 2);
	Comp *pC3 = C3[0][0];
	for (Int i = 0; i < 8; ++i)
		pC3[i] = Comp(1. + (Doub)i, (Doub)i);
	matsave(C3, "C3", pfmat);
	mattsave(C3, "C3", pfmatt);

	matClose(pfmat);
	mattClose(pfmatt);

	// read test

	// scalars
	pfmat = matOpen("test.mat", "r");
	pfmatt = mattOpen("test.matt", "r");
	Uchar r_s8;
	matload(r_s8, "s8", pfmat);
	if (r_s8 != s8) error("failed!");
	r_s8 = 0;
	mattload(r_s8, "s8", pfmatt);
	if (r_s8 != s8) error("failed!");

	Int r_si;
	matload(r_si, "si", pfmat);
	if (r_si != si) error("failed!");
	r_si = 0;
	mattload(r_si, "si", pfmatt);
	if (r_si != si) error("failed!");

	Doub r_s;
	matload(r_s, "s", pfmat);
	if (abs(r_s-s) > 1e-15) error("failed!");
	r_s = 0.;
	mattload(r_s, "s", pfmatt);
	if (abs(r_s-s) > 1e-15) error("failed!");

	Comp r_sc;
	matload(r_sc, "sc", pfmat);
	if (abs(r_sc-sc) > 1e-15) error("failed!");
	r_sc = 0.;
	mattload(r_sc, "sc", pfmatt);
	if (abs(r_sc-sc) > 1e-15) error("failed!");

	// vectors
	VecUchar r_v8;
	matload(r_v8, "v8", pfmat);
	if (r_v8 != v8) error("failed!");
	r_v8.resize(0);
	mattload(r_v8, "v8", pfmatt);
	if (r_v8 != v8) error("failed!");

	VecInt r_vi;
	matload(r_vi, "vi", pfmat);
	if (r_vi != vi) error("failed!");
	r_vi.resize(0);
	mattload(r_vi, "vi", pfmatt);
	if (r_vi != vi) error("failed!");

	VecDoub r_v;
	matload(r_v, "v", pfmat);
	r_v -= v;
	if (norm(r_v) > 1e-15) error("failed!");
	r_v.resize(0);
	mattload(r_v, "v", pfmatt);
	r_v -= v;
	if (norm(r_v) > 1e-15) error("failed!");

	VecComp r_vc;
	matload(r_vc, "vc", pfmat);
	r_vc -= vc;
	if (norm(r_v) > 1e-15) error("failed!");
	r_vc.resize(0);
	mattload(r_vc, "vc", pfmatt);
	r_vc -= vc;
	if (norm(r_v) > 1e-15) error("failed!");

	// matrices
	MatUchar r_A8;
	matload(r_A8, "A8", pfmat);
	if (r_A8 != A8)  error("failed!");
	r_A8.resize(0, 0);
	mattload(r_A8, "A8", pfmatt);
	if (r_A8 != A8) error("failed!");

	MatInt r_AI;
	matload(r_AI, "AI", pfmat);
	if (r_AI != AI) error("failed!");
	r_AI.resize(0, 0);
	mattload(r_AI, "AI", pfmatt);
	if (r_AI != AI) error("failed!");

	MatDoub r_A;
	matload(r_A, "A", pfmat);
	r_A -= A;
	if (norm(r_A) > 1e-15) error("failed!");
	r_A.resize(0, 0);
	mattload(r_A, "A", pfmatt);
	r_A -= A;
	if (norm(r_A) > 1e-15) error("failed!");

	MatComp r_C;
	matload(r_C, "C", pfmat);
	r_C -= C;
	if (norm(r_C) > 1e-15) error("failed!");
	r_C.resize(0, 0);
	mattload(r_C, "C", pfmatt);
	r_C -= C;
	if (norm(r_C) > 1e-15) error("failed!");

	// 3D arrays
	Mat3Doub r_A3;
	matload(r_A3, "A3", pfmat);
	r_A3 -= A3;
	if (norm(r_A3) > 1e-15) error("failed!");
	r_A3.resize(0, 0, 0);
	mattload(r_A3, "A3", pfmatt);
	r_A3 -= A3;
	if (norm(r_A3) > 1e-15) error("failed!");

	Mat3Comp r_C3;
	matload(r_C3, "C3", pfmat);
	r_C3 -= C3;
	if (norm(r_C3) > 1e-15) error("failed!");
	r_C3.resize(0, 0, 0);
	mattload(r_C3, "C3", pfmatt);
	r_C3 -= C3;
	if (norm(r_C3) > 1e-15) error("failed!");

	matClose(pfmat);
	mattClose(pfmatt);
}
