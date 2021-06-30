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

    cout.open("check.out");
    cin.open("check.in");


    int N;
    cin >> N;
    int arr[N][N];

    bool O = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (j < i)
            {
                O = (arr[i][j] == arr[j][i] ? true : false);
            }
            if (j == i)
            {
                O = (arr[i][j] == 0 ? true : false);
            }

            if (O == false)
            {
                break;
            }
        }
    }

    cout << (O ? "YES" : "NO");

    return 0;
}
