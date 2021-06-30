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

    cout.open("containers.out");
    cin.open("containers.in");


    int N;
    cin >> N;
    long long int d[N + 2];

    d[0] = 1;
    d[1] = 1;

    for (int i = 2; i < N + 2; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    cout << d[N + 1];


    return 0;
}
