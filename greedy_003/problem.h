struct set {
	double cost;
	int numberOfElements;
	int* elements;
};

struct problem {
	int numberOfSets;
	int numberOfElements;
	struct set** sets;
};