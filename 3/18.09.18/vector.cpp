#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct vector {
    int size = 0;
    double* arr;

    void create(int size) {
        this -> size = size;
        arr = (double*) calloc(size, sizeof(double));
    }

    void init () {
        for (int i = 0; i < size; i++) {
            arr[i] = (rand() % 100  + 1)/ 10.0;
        }
    }

    void print() {
        if (size != 0) {
            cout << '(';
            for (int i = 0; i < size - 1; i++) {
                cout << arr[i] << "; " ;
            }
            cout << arr[size - 1] << ')' << '\n';
        }
    }

    void add(vector other) {
        if (other.size == size) {
            for (int i = 0; i < size; i++) {
                arr[i] += other.arr[i];
            }
        } else {
            cout << "ERROR with add" << '\n';
        }
    }

    void subtrac(vector other) {
        if (other.size == size) {
            for (int i = 0; i < size; i++) {
                arr[i] -= other.arr[i];
            }
        } else {
            cout << "ERROR with subtrac" << '\n';
        }
    }

    double mult(vector other) {
        double tmp = 0;
        if (other.size == size) {
            for (int i = 0; i < size; i++) {
                tmp += arr[i] * other.arr[i];
            }
        } else {
            cout << "ERROR with mult" << '\n';
            return -9999.0;
        }
        return tmp;
    }


    void multscal(double k) {
        for (int i = 0; i < size; i++) {
            arr[i] *= k;
        }
    }

    void destruct() {
        free(arr);
    }
};

int main() {
    srand (time(NULL));

    vector n1;
    vector n2;
    vector n3;

    n1.create(5);
    n2.create(5);
    n3.create(4);

    n1.init();
    n2.init();
    n3.init();

    n1.print();
    n2.print();
    n3.print();

    cout << '\n';

    n1.add(n2);
    n3.add(n2);

    n1.print();
    n2.print();
    n3.print();

    cout << '\n';

    n1.subtrac(n2);
    n1.subtrac(n3);

    n1.print();
    n2.print();
    n3.print();

    cout << '\n';

    cout << n1.mult(n2) << '\n';
    cout << n1.mult(n3) << '\n';

    cout << '\n';

    n1.multscal(1.0);
    n3.multscal(8.0);

    n1.print();
    n2.print();
    n3.print();

    cout << '\n';

    n1.destruct();
    n2.destruct();
    n3.destruct();

    return 0;
}
