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

    cout.open("count.out");
    cin.open("count.in");


    int N;
    cin >> N;
    int arr[N][N];

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (j > i && arr[i][j] == 1)
            {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
