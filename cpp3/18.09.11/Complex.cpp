#include <iostream>
#include <cmath>

using namespace std;

struct ComplexNumber {
    double a;
    double b;

    void create(double a, double b) {
        this -> a = a;
        this -> b = b;
    }

    void print() {
        if (a != 0) {
            cout << a;
            if (b != 0) {
                cout << (b > 0 ? " + " : " - ") << abs(b) << 'i';
            }
        } else if (b != 0) {
            cout << b << 'i';
        }
        cout << '\n';
    }

    void add(ComplexNumber other) {
        a = a + other.a;
        b = b + other.b;
    }

    void mult(ComplexNumber other) {
        double tmp = a;
        a = a * other.a - b * other.b;
        b = tmp * other.b + b * other.a;
    }
};

int main() {
    ComplexNumber n1;
    n1.create(1., 2.);
    n1.print();

    ComplexNumber n2;
    n2.create(3., 4.);
    n2.print();

    cout << '\n';

    n1.add(n2);
    n1.print();
    n2.print();

    cout << '\n';

    n2.mult(n1);
    n1.print();
    n2.print();

    return 0;
}
