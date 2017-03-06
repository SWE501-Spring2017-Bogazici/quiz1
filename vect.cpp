//============================================================================
// Name        : vect.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Vect {
	int size;
	double contents[100];

	Vect(int t) {
		size=t;
		for (int i=0;i<size;i++) {
			contents[i]+=0;
		}
	}


	void operator+=(Vect& y) {
		for (int i=0;i<size;i++) {
			contents[i]+=y.contents[i];
		}
	}

	void random() {
		for (int i=0;i<size;i++) {
			contents[i]=rand() % 100;
		}
	}
};

ostream& operator<<(ostream& out, Vect& z) {
	out << '[';
	for (int i=0;i<z.size;i++) {
		if (i==(z.size-1)) {
			out << z.contents[i];
		} else {
			out << z.contents[i] << ',';
		}


	}
	out << ']' << endl;

    return out;
}

int main() {



	Vect v1=Vect(4);
	Vect v2=Vect(4);
	v1.random();v2.random();

	cout << v1;
	cout << v2;

	v1+=v2;
	cout << v1;
	return 0;
}
