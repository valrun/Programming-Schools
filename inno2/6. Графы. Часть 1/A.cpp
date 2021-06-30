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

    cout.open("altom.out");
    cin.open("altom.in");


    int N;
    cin >> N;
    int arr[N][N];

    int a, num;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = 0;
        }
        for (int j = 0; j < N; j++)
        {
            if (j < a)
            {
                cin >> num;
                arr[i][num - 1] = 1;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
