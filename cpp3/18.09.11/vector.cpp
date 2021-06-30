#include <iostream>

using namespace std;

struct vector {
    double x;
    double y;

    void create(double x, double y) {
        this -> x = x;
        this -> y = y;
    }

    void print() {
        cout << '(' << x << "; " << y << ')' << '\n';
    }

    void add(vector other) {
        x = x + other.x;
        y = y + other.y;
    }

    void subtrac(vector other) {
        x = x - other.x;
        y = y - other.y;
    }

    double mult(vector other) {
        return x * other.x + y * other.y;
    }
};

int main() {
    vector n1;
    vector n2;

    n1.create(1., 2.);
    n2.create(3., 4.);

    n1.print();
    n2.print();

    cout << '\n';

    n1.add(n2);
    n1.print();
    n2.print();

    cout << '\n';

    n1.subtrac(n2);
    n1.print();
    n2.print();

    cout << '\n';

    cout << n1.mult(n2);

    return 0;
}
