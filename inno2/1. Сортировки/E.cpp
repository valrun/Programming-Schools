#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

//std::string s;

using namespace std;

const int N=100000;
int arr[N][2];

void sort (int l, int r);

int main()
{
/*
    ofstream cout;
    ifstream cin;

    cout.open("cobbler.out");
    cin.open("cobbler.in");

*/
    int n, k;
    cin >> n;

    for  (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    //cout << '\n';

    sort (0, n - 1);

    int sum = 0, kol = 0;
    while (sum <= n)
    {
        sum += arr[kol];
        kol++;
    }
    cout << kol - 1;

    return 0;
}

void sort0 (int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int x = rand() % (r - l + 1) + l;
    int l1 = l, r1 = r;
    int pivot = arr[x][0];
    while (l <= r)
    {
        while (arr[l][0] < pivot)
        {
            l++;
        }
        while (arr[r][0] > pivot)
        {
            r--;
        }

        if (r >= l)
        {
            long int tmp = arr[l][0];
            arr[l][0] = arr[r][0];
            arr[r][0] = tmp;
            l++;
            r--;
        }
    }
        sort0(l1, r);
        sort0(r+1, r1);
}
