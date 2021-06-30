#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    int n, k;
    cin >> n;

    int arr[n];
    int count[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[i] = 0;
        for  (int j = 0; j <= i; j++)
        {
            if (arr[i] == arr[j])
            {
                count[j]++;
                break;
            }
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == tmp)
            {
                cout << count[j] << '\n';
                break;
            }
            if (j == n - 1)
            {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
