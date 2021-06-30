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

    cout.open("numbers.out");
    cin.open("numbers.in");

    int N;
    cin >> N;

    long int d[N][10];
    d[0][0] = 0;   d[0][1] = 1;   d[0][2] = 1;
    d[0][3] = 1;   d[0][4] = 1;   d[0][5] = 1;
    d[0][6] = 1;   d[0][7] = 1;   d[0][8] = 1;   d[0][9] = 1;

    for (int i = 1; i < N; i++)
    {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        for (int j = 1; j < 9; j++)
        {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j] + d[i - 1][j + 1];
        }
        d[i][9] = d[i - 1][9] + d[i - 1][8];
    }

    long long int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += d[N - 1][i];
    }
    cout << sum;
}
