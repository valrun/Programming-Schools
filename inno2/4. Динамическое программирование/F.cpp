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

    cout.open("numbers.out");
    cin.open("numbers.in");
*/
    int K, S;
    cin >> K >> S;

    int d[K + 1][S + 1];
    d[0][0] = 0;

    for (int i = 1; i < !; i++)
    {
        for (int j = 0; j < !; j++)
        d[i][j] = K;

        cout << d[i][j] << ' ';
    }

    cout << d[S - 1][j];
}
