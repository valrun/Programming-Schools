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


    int M, N;
    cin >> M >> N;
    int arr[2][N];

    bool flag = false;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[0][i] >> arr[1][i];
        int tmp;

        int j = i;
        while (j > 0 && arr[0][j] < arr[0][j - 1])
        {
            tmp = arr[0][j];
            arr[0][j] = arr[0][j - 1];
            arr[0][j - 1] = tmp;

            tmp = arr[1][j];
            arr[1][j] = arr[1][j - 1];
            arr[1][j - 1] = tmp;

            j--;
        }

        tmp = j;

        while (j > 0 && arr[0][tmp] == arr[0][j - 1])
        {
            //cout << arr[0][j - 1] << ' ' << arr[1][j - 1] << '\n';
            flag = (arr[1][tmp] == arr[1][j - 1] ? true : false);
            if (flag)
            {
                break;
            }
            j--;

        }

        if (flag)
        {
            break;
        }

    }

    cout << (flag ? "YES" : "NO");

    return 0;
}
