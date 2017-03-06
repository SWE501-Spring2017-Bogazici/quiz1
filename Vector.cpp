#include <iostream>
#include <ctime>

using namespace std;

// representation of Vector type with structure
struct Vect {
    int size;
    int *array;
    
    Vect(int n) {
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }
    }
    
    ~Vect() {
        cout << "Vect number destructed.."<< endl;
    }
    
    void random(int min, int max)
    {
        for (int i = 0; i < size; i++) {
            int rand = min + (std::rand() % (int)(max - min + 1));
            array[i] = rand;
        }
    }
    
    int operator*=(Vect& z) {
        int val = 0;
        
        if (this->size != z.size) {
            cout << "Arrays size are not equal! " << endl;
        } else {
            for (int i = 0; i < size; i++) {
                val += array[i] * z.array[i];
            }
        }
        return val;
    }
    
    void operator+=(Vect& z) {
        if (this->size != z.size) {
            cout << "Arrays size are not equal! " << endl;
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
    
};

// left shift operator overloading for Complex Numbers
ostream& operator<<(ostream& out, Vect& z) {
    for (int i = 0; i < z.size; i++) {
        out << z.array[i] << " ";
    }
    
    return out;
}

int main() {
    
    // Initializing v1
    Vect v1(10);
    v1.random(0, 50);
    
    // Initializing v2
    Vect v2(10);
    v2.random(0, 50);
    
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    
    v1 += v2;
    cout << "v1 += v2 : " << v1 << endl;
    
    int mult = v1 *= v2;
    cout << "v1 *= v2 : " << mult << endl;
    
    v1 -= v2;
    cout << "v1 -= v2 : " << v1 << endl;
    
    return 0;
}
