#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#define lli long long int
using namespace std;

struct Point
{
    double x, y;

    Point(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
};

int main(){
    //freopen("prefix.in","r",stdin);
    //freopen("prefix.out","w",stdout);

    cout.precision(10);

    double x, y;
    cin >> x >> y;
    Point One(x, y);

    cin >> x >> y;
    Point Two(x, y);

    cin >> x >> y;
    Point Thr(x, y);

    cout << fixed << abs(((Two.x - One.x) * (Thr.y - One.y) - (Two.y - One.y) * (Thr.x - One.x)) / 2.0);

    return 0;
}
