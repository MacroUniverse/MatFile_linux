// TODO: sampling and slicing are not tested at all!

	matrix sampling
	A.resize(5, 7);
	for (Int i = 0; i < 35; ++i) {
		A[0][i] = (Doub)i;
	}
	matsave(A, "Asample", pfmat, 2, 3);
	mattsave(A, "Asample", pfmatt, 2, 3);

	C.resize(5, 7);
	for (Int i = 0; i < 35; ++i) {
		C[0][i] = Comp(i, i + 1.);
	}
	matsave(C, "Csample", pfmat, 2, 3);
	mattsave(C, "Csample", pfmatt, 2, 3);


	3d array slicing + sampling
	A3.resize(5, 5, 5);
	VecInt slice(3);  slice[0] = 0; slice[1] = 2; slice[2] = 4;
	for (Int i = 0; i < 125; ++i)
		A3[0][0][i] = (Doub)i;
	matsave(A3, "A3slice", pfmat, 'y', slice, 1, 2);
	mattsave(A3, "A3slice", pfmatt, 'y', slice, 1, 2);

	C3.resize(5, 5, 5);
	for (Int i = 0; i < 125; ++i)
		C3[0][0][i] = Comp((Doub)i, i+1.);
	matsave(C3, "C3slice", pfmat, 'y', slice, 1, 2);
	mattsave(C3, "C3slice", pfmatt, 'y', slice, 1, 2);
	