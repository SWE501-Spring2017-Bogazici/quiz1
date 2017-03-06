#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// representation of Vector type with structure
class Vect {
    int size;
    int *array;

public:
    Vect(int n) {
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }
    }

    // Copy constructor
    Vect(Vect& z) {
        size = z.size;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = z.array[i];
        }
    }


    ~Vect() {
    		delete [] array;
        cout << "Vect number destructed.."<< endl;
    }

    void random(int min, int max)
    {
        for (int i = 0; i < size; i++) {
            int u = min + (rand() % (int)(max - min + 1));
            array[i] = u;
        }
    }

    int operator*(Vect& z) {
        int val = 0;

        if (size != z.size) {
            cout << "Arrays sizes are not equal! " << endl;
        } else {
            for (int i = 0; i < size; i++) {
                val += array[i] * z.array[i];
            }
        }
        return val;
    }

    void operator+=(Vect& z) {
        if (size != z.size) {
            cout << "Arrays sizes are not equal! " << endl;
        } else {
            for (int i = 0; i < size; i++) {
                array[i] += z.array[i];
            }
        }
    }

    void operator-=(Vect& z) {
        if (this->size != z.size) {
            cout << "Arrays size are not equal! " << endl;
        } else {
            for (int i = 0; i < size; i++) {
                array[i] -= z.array[i];
            }
        }
    }

    void operator=(Vect& z) {
        if (this->size != z.size) {
             cout << "Arrays size are not equal! " << endl;
         } else {
             for (int i = 0; i < size; i++) {
                 array[i] = z.array[i];
             }
         }

    }

    int operator[](int i) {
    		return array[i];
    }

    int getSize() {
    		return size;
    }

    void setSize(int newSize) {
    		size = newSize;
    		int *temp = new int[size];

    		for (int i=0; i<size; i++) {
    			temp[i] = array[i];
    		}

    		delete[] array;
    		array = temp;
    }

};

// left shift operator overloading for Vect
ostream& operator<<(ostream& out, Vect& z) {
    for (int i = 0; i < z.getSize(); i++) {
        out << z[i] << " ";
    }

    return out;
}

int main() {

    srand(time(NULL));

    // Initializing v1
    Vect v1(10);
    v1.random(0, 50);

    // Initializing v2
    Vect v2(10);

    v2 = v1;

    cout << v2 << endl;

    v2.random(10, 50);

    cout << v1 << endl;

    Vect v3 = v1;

    cout << v3 << endl;

    v3.setSize(2);

    cout <<  v3;

    return 0;
}

