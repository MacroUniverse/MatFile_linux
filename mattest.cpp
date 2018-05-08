// nr3.h must be place after mat.h, or the compilation gets an error! I don't know why!
#include "mat.h"
#include "nr3.h"
#include "matsave.h"

using namespace std;

int main() {

	MATFile *pfile = matOpen("nrMat.mat", "w");
	Complex I(0, 1);

	// scalars
	Doub s(3.1415);
	matsave(s, "s", pfile);
	Complex sc(3.1, 3.2);
	matsave(sc, "sc", pfile);

	// vectors
	VecDoub v(3);
	v[0] = 1.; v[1] = 2.; v[2] = 3.;
	matsave(v, "v", pfile);
	VecComplex vc(3);
	for (Int i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i + I * (Doub)i;
	matsave(vc, "vc", pfile);

	// matrices
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

	matClose(pfile);
}


