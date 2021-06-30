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

    cout.open("calcul.out");
    cin.open("calcul.in");
*/

    int N, M;
    cin >> N >> M;
    int arr[N][M];
    int d[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];

            if(i == 0 && j == 0)
            {
                d[i][j] = arr[i][j];
            }
            else if (i == 0)
            {
                d[i][j] = d[i][j - 1] + arr[i][j];
            }
            else if (j == 0)
            {
                d[i][j] = d[i - 1][j] + arr[i][j];
            }
            else
            {
                d[i][j] = min(d[i - 1][j], d[i][j - 1]) + arr[i][j];
            }

            ///cout << d[i][j] << ' ';
        }
        //cout << '\n';
    }

    cout << d[N - 1][M - 1];

    return 0;
}
