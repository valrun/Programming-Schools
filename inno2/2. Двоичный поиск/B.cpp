#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

int main()
{
/*
    ofstream cout;
    ifstream cin;

    cout.open("cobbler.out");
    cin.open("cobbler.in");

*/
    int n, k;
    cin >> n >> k;

    int N[n];

    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        int l = 0, r = n - 1, m;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            if (N[m] >= tmp)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        tmp = (tmp - N[l] <= N[r] - tmp ? N[l] : N[r]);
        cout << tmp << '\n';
    }

    return 0;
}
