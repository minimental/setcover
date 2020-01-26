// Given a positive integer, computes the harmonic number
int harmonic_number(int n, double* Hn) {
	// index needs to be positive
	if (!(n > 0)) return -1;
	
	*Hn = 0;
	for (int i = 1; i <= n; ++i)
		*Hn += 1.0/(i * 1.0);
	
	return 0;
}