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
    //freopen("prefix.in","r",stdin);
    //freopen("prefix.out","w",stdout);
    cout.precision(10);

    Point One;
    cin >> One.x >> One.y;

    Point Two;
    cin >> Two.x >> Two.y;

    double a, b, c;
    cin >> a >> b >> c;

    if (b == 0)
    {
        if (a == 0)
        {
            cout << (c == 0 ? "YES" : "NO"); return 0;
        }
        if ((One.x > c / a && Two.x > c / a) || (One.x < c / a && Two.x < c / a))
        {
            cout << "YES"; return 0;
        }
        else
        {
            cout << "NO"; return 0;
        }
    }
    else
    {
        if (a != 0)
        {
            if (((One.x > (b * One.y + c) / a && Two.x > (b * Two.y + c) / a ) || (One.x > (b * One.y + c) / a  && Two.x > (b * Two.y + c) / a )) &&
                ((One.y > (b * One.x + c) / a && Two.y > (b * Two.x + c) / a ) || (One.y > (b * One.x + c) / a  && Two.y > (b * Two.x + c) / a )))
        {
                cout << "YES"; return 0;
            }
            else
            {
                cout << "NO"; return 0;
            }
        }
        else
        {
            if ((One.y > c / b && Two.y > c / b) || (One.y < c / b && Two.y < c / b))
            {
                cout << "YES"; return 0;
            }
            else
            {
                cout << "NO"; return 0;
        }
        }

    }


    return 0;
}
