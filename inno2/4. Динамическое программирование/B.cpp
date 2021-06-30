#include <stdlib.h>
//#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{

    ofstream cout;
    ifstream cin;

    cout.open("calcul.out");
    cin.open("calcul.in");


    int N;
    cin >> N;

    int d[N + 1];
    int p[N + 1];



    d[1] = 0;
    p[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        d[i] = d[i - 1] + 1;
        p[i] = i - 1;

        if (i % 2 == 0 && d[i / 2] + 1 < d[i])
        {
            d[i] = d[i / 2] + 1;
            p[i] = i / 2;
        }

        if (i % 3 == 0 && d[i / 3] + 1 < d[i])
        {
            d[i] = d[i / 3] + 1;
            p[i] = i / 3;
        }

        //cout << i << ' ' << d[i] << '!';
    }

    cout << d[N] << '\n';

    int ans[d[N] + 1];
    int i = N , j = d[N] + 1;

    while (i > 1)
    {
        ans[j] = i;
        j--;
        i = p[i];
    }

    cout << 1 << ' ';
    for (i = 2; i <= d[N] + 1; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
