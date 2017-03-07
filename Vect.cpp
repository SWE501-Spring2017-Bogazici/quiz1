// Firat Atalay
// firatatalay@gmail.com

#include <iostream>
#include <random>
using namespace std;

struct Vect {
	int size;
	double *array = new double[size];
	double dotPro = 0;

	Vect(int init_size)
    {
    	size = init_size;
    	random();
    }
    ~Vect(){
   		delete [] array;
    }

    double fRand(double fMin, double fMax){
	    double f = (double)rand() / RAND_MAX;
	    return fMin + f * (fMax - fMin);
	}
	

    void random(){
	    for (int i = 0; i < size; ++i)
    	{	
    		array[i] = fRand(0,100);
    	}    	
    }

    double operator*(Vect &a){
    	for (int i = 0; i < size; ++i)
    	{
    		dotPro += array[i] * a.array[i];
    	}
    	return dotPro;
    }

};

int main() {
	int size;
	cout << "Enter the size of the vector: " << flush;
	cin >> size;
	Vect v(size);
	Vect vv(size);

	cout << "First vector: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << v.array[i] << endl;
	}

	cout << "Second vector: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << vv.array[i] << endl;
	}


	cout << "The dot product: " << endl;
	cout << v*vv << endl;
	
}
