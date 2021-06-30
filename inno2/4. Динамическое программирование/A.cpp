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

    cout.open("tickets.out");
    cin.open("tickets.in");



    int N;
    cin >> N;

    int arr[N][3];
    int d[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        switch (i)
        {
        case 0:
            d[0] = arr[0][0];
            break;

        case 1:
            d[1] = min(d[0] + arr[1][0], arr[0][1]);
            break;

        case 2:
            d[2] = min(d[1] + arr[2][0], min(d[0] + arr[1][1], arr[0][2]));
            break;

        default:
            d[i] = min(d[i - 3] + arr[i - 2][2], min(d[i - 2] + arr[i - 1][1], d[i - 1] + arr[i][0]));
            break;

        }
    }

    cout << d[N - 1];

    return 0;
}
