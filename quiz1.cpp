#include <iostream>
#include <stdlib.h>
using namespace std;


struct vector{
	
	int size;
	
	
	vector(){
		
	}
	
	vector(int initsize){
		
		size = initsize;
		
	}
	
	double* array = new double[size];
	
	void random(){
	
		int randomMax = 30;
		int randomMin = -30;
		
		for (int i = 0 ; i < size ; i++){
			
			double f = (double)rand() / RAND_MAX;
	    	double random =  -30 + f * (randomMax - randomMin);
	    	
	    	array[i] = random;
			
		}
		
	}
	
	void operator+=(vector& vector){
		
		for ( int i = 0 ; i < size ; i++ ){
			
			array[i] = array[i] + vector.array[i];
			
		}
		
	}
	
	void operator*=(vector& vector){
		
		double dot;
		
		for ( int i = 0 ; i < size ; i++ ){
			
			dot += array[i] * vector.array[i];
			
		}
		
		cout << "Dot product of two vectors = " << dot << endl;
		
	}
		
};

ostream& operator<<(ostream& out, vector& v){
	
	for(int i = 0 ; i < v.size ; i++ ){
		
		out << v.array[i] << " ";
		
	}
	
	return out;
	
}


int main(int argc, char** argv) {
	
	vector myVector(4);
	myVector.random();
	
	cout << "First Vector : " << myVector << endl;
	
	vector myVector2(4);
	myVector2.random();
	
	cout << "Second Vector : " << myVector2 << endl;
	
	// dot product.
	myVector *= myVector2;
	
	// sum of two vectors.
	myVector += myVector2;
	
	cout << "Sum of two vectors : " << myVector << endl;
	
	return 0;
}
