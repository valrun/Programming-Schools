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

    cout.open("grig.out");
    cin.open("grig.in");


    int N, k;
    cin >> N >> k;

    int arr[N];
    int d[N];
    d[0] = 1;

    for (int i = 1; i < N; i++)
    {
        int j = 1;
        d[i] = 0;
        while (j <= k && i - j >= 0)
        {
            d[i] += d[i - j];
            //cout << d[i - j] << '!';
            j++;
        }
        //cout << d[i] << ' ' << j << '\n';
    }
    //cout << '\n';
    cout << d[N - 1];

    return 0;
}
