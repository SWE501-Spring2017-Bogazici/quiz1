//      Tugcan Olgun
// 

#include <iostream>
#include <cstdlib>

using namespace std;

struct Vect{
    int num[3];
    Vect(int i) {
        int num[i];
    }
    void Random() {
        for (int i = 0; i < sizeof(num)-1; ++i) {
            num[i] = rand()%100;
        }
    }
};

void operator+=(Vect &first, Vect &second)
{
    if(sizeof(first.num) == sizeof(second.num)) {
        for (int i = 0; i <= ((sizeof(first.num)/4)-1); ++i) {
            first.num[i] += second.num[i];
        }
    }
}
int operator*(Vect &first, Vect &second)
{
    int count;
    if(sizeof(first.num) == sizeof(second.num)) {
        for (int i = 0; i <= ((sizeof(first.num)/4)-1); ++i) {
            count += first.num[i] * second.num[i];
        }
    }
    return count;
}

ostream& operator<<(ostream &out, Vect &val ) {
    for (int i = 0; i <= ((sizeof(val.num)/4)-1); ++i) {
        cout << val.num[i] << " ";
    }
    return out;
}


int main() {
    int i;
    cout << "Please enter the dimentions of the arrays: " << endl;
    cin >> i;
    Vect arr(i), vrr(i);
    arr.Random();
    arr.Random();
    vrr.Random();
    cout << "First array: " << arr << endl;
    cout << "Second array: " << vrr << endl;
    Vect temp(i);
    temp = arr;
    arr += vrr;
    cout << "Sum: " << arr << endl;
    arr = temp;
    int count = arr*vrr;
    cout << "Mul: " << count << endl;


    return 0;
}