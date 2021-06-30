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

    cout.open("ladder.out");
    cin.open("ladder.in");



    int N;
    cin >> N;

    int arr[N];
    int d[N + 1];
    d[0] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        switch (i)
        {
        case 0:
            d[1] = arr[0];
            break;


        default:
            d[i + 1] = max(d[i] + arr[i],d[i - 1] + arr[i]);
            break;

        }
    }

    cout << d[N];

    return 0;
}
