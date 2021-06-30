#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#define lli long long int
using namespace std;

const double PI = 3.14159265358979323846;


int main(){
    //freopen("prefix.in","r",stdin);
    //freopen("prefix.out","w",stdout);
    cout.precision(10);

    double a1, b1, c1;
    cin >> a1 >> b1 >> c1;

    double a2, b2, c2;
    cin >> a2 >> b2 >> c2;

    double y = (a2 * c1 - a1 * c2) / (b2 * a1 - b1 * a2);

    cout << fixed << (a1 != 0 ? - (c1 + b1 * y) / a1 : - (c2 + b2 * y) / a2) << ' ' << y;

    return 0;
}
