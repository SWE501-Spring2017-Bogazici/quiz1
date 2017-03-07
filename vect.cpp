#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Vect {
    int dimension;
    int arr[1000];

    Vect(int d)
    {
        dimension = d;
    }

    void Random()
    {
        for (int i = 0; i < dimension; ++i) {
            int ran = rand() % 100;
            arr[i] = ran;
        }
    }
};

ostream& operator<<(ostream& out, Vect& v)
{
    for (int i = 0; i < v.dimension; ++i) {
        out << v.arr[i] << endl;
    }
    return out;
}

Vect& operator+=(Vect& out, Vect& u){
    for (int i = 0; i < out.dimension; ++i) {
        out.arr[i]+=u.arr[i];
    }
}

int operator*(Vect& out, Vect& u){
    int result = 0;
    for (int i = 0; i < out.dimension; ++i) {
        result+= out.arr[i] * u.arr[i];
    }

    return result;
}

int main() {
    srand (time(NULL));

    Vect v(3);
    Vect w(3);
    v.Random();
    w.Random();
    cout << v;
    cout << endl;
    cout << w;
    cout << endl;

    v+=w;
    cout << v << endl;
    cout << v*w << endl;
    return 0;
}