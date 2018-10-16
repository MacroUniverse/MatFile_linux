#include <iostream>
#include "test/test_dual.h"

using std::cout; using std::endl;

// this test must be in dual mode

int main()
{
	cout << "test dual mode..." << endl;
	test_dual();
	cout << "done testing!" << endl;

	//using namespace slisc;
	// TODO: write 2 conversion functions for any file
	//mat2matt("waveInit.mat", "waveInit.matt");
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
}
