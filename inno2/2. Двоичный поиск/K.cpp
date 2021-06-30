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
    double C;
    cin >> C;
    double l = 0, r = C, m;
    for (int i = 0; i < 60; i++)
    {
            m = (l + r) / 2.000000;
            if (m*m + sqrt(m) > C)
            {
                r = m;
            }
            else
            {
                l = m;
            }
    }
    cout << m;

    return 0;
}

