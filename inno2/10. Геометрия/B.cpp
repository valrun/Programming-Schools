#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#define lli long long int
using namespace std;

int main(){
    //freopen("prefix.in","r",stdin);
    //freopen("prefix.out","w",stdout);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << acos((x1 * x2 + y1 * y2) / (sqrt(pow(x1, 2) + pow(y1, 2)) + sqrt(pow(x2, 2) + pow(y2, 2))));

    return 0;
}
