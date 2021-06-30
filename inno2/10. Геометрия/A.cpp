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

    int x, y;
    cin >> x >> y;

    cout << fixed << (y < 0 ? 2 * PI + atan2(y, x) : atan2(y, x));

    return 0;
}
