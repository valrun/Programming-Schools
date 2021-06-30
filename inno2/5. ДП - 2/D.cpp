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

    cout.open("numbers.out");
    cin.open("numbers.in");
*/
    int N;
    cin >> N;

    int arr[N], d[N], ans[N], sortD[N];
    cin >> arr[0];
    d[0] = 1;
    sortD[0] = 0;
    ans[0] = -1;
    int j;
    cout << d[0] << ' ';

    for (int i = 1; i < N; i++)
    {
        cin >> arr[i];

        j = i - 1;
        while (j > -1)
        {
            if (arr[sortD[j]] >= arr[i])
            {
                break;
            }
            j--; // + MAX!????
        }

        if (j == -1)
        {
            d[i] = 1;
            ans[i] = -1;
        }
        else
        {
            d[i] = d[j] + 1;
            ans[i] = j;
        }

        //SORT D
        j = i - 1;
        while (j > -1)
        {
            if (d[sortD[j]] >= d[j + 1])
            {
                sortD[j]
                break;
            }
            int tmp =
            j--; // + MAX!????
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';

    cout << d[max] << '\n';
    j = max;
    int i = 1;
    d[0] = arr[j];

    while (ans[j] != -1)
    {
        j = ans[j];
        d[i] = arr[j];
        i++;
    }
    i--;

    for(i; i >= 0; i--)
    {
        cout << d[i] << ' ';
    }
}
