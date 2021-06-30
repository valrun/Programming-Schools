#include <stdlib.h>
//#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    ofstream cout;
    ifstream cin;

    cout.open("bus.out");
    cin.open("bus.in");


    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b, k, c, x, y;
    cin >> b >> k >> c >> x >> y;

    for (int i = 0; i < n; i++) {
        int price;

        if (y * a[i] / x < a[i] / x * c * x)
        {
            price = y * a[i] / x;
        }
        else {
            price = a[i] / x * c * x;
        }

        if (a[i] * b < a[i] * c + k) {
            cout << a[i] * b << ' ';
        }
        else {
            //cout << a[i] / x  << ' ' << a[i] % x  << ' ';
            if ((a[i] % x) * c > y)
            {
                cout << price + y + k << ' ';
            }
            else {
                cout << price + (a[i] % x) * c + k << ' ';
            }
        }
        //cout << '\n';
    }


    return 0;
}
