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
    ofstream cout;
    ifstream cin;

    cout.open("queue.out");
    cin.open("queue.in");


    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int arr[N], e = 0, b = 0;
    char com;

    for (int i = 0; i < N; i++)
    {
        cin >> com;
        if (com == '+')
        {
            cin >> arr[e];
            e++;
        }
        else
        {
            cout << arr[b] << '\n';
            b++;
        }
    }

    return 0;
}
