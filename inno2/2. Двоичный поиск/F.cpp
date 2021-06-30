#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
/*
    ofstream cout;
    ifstream cin;

    cout.open("cobbler.out");
    cin.open("cobbler.in");

*/
    int w,h,n;
    cin >> w >> h >> n;
    int l = min(w, h), r = max(w, h) * n, m;
    for (int i = 0; i < 20; i++)
    {
            m = (l + r) / 2;
            if (m*m >= n * h * w)
            {
                r = m;
            }
            else
            {
                l = m;
            }
                cout << m << '\n';
    }
    cout << r;

    return 0;
}
