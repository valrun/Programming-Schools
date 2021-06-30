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

    cout.open("source.out");
    cin.open("source.in");


    int N;
    cin >> N;
    bool arr[N][N];

    bool flag[2][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            flag[j][i] = true;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];

            flag[1][i] = (arr[i][j] ? false : flag[1][i]);
            flag[0][j] = (arr[i][j] ? false : flag[0][j]);
        }
    }

    int countI = 0, countS = 0;
    for (int i = 0; i < N; i++)
    {
        countI += flag[0][i];
        countS += flag[1][i];
    }

    cout << countI << ' ';
    int i = 0;
    while (countI != 0)
    {
        if (flag[0][i])
        {
            cout << i + 1 << ' ';
            countI--;
        }
        i++;
    }

    cout << '\n' << countS << ' ';
    i = 0;
    while (countS != 0)
    {
        if (flag[1][i])
        {
            cout << i + 1 << ' ';
            countS--;
        }
        i++;
    }

    return 0;
}
