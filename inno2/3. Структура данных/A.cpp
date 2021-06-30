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

    cout.open("cobbler.out");
    cin.open("cobbler.in");

*/

    int N;
    cin >> N;

    int arr[N], e = 0, com;

    for (int i = 0; i < N; i++)
    {
        cin >> com;
        if (com == 1)
        {
            cin >> arr[e];
            e++;
        }
        else
        {
            e--;
            cout << arr[e] << '\n';
        }
        //cout << arr[e] << '\n';
    }

    return 0;
}
