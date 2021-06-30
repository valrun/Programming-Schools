#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#define lli long long int
using namespace std;

const double PI = 3.14159265358979323846;

struct Point
{
    double x, y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
};

int main(){
    freopen("point.in","r",stdin);
    freopen("point.out","w",stdout);
    cout.precision(10);

    Point p;
    cin >> p.x >> p.y;

    Point One;
    cin >> One.x >> One.y;

    Point Two;
    cin >> Two.x >> Two.y;

    cout << fixed << ((One.y - Two.y) * p.x + (Two.x - One.x) * p.y + Two.y * One.x - Two.x * One.y == 0 ? "YES" : "NO");

    return 0;
}
