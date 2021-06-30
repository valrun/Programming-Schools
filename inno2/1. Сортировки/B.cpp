#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

//std::string s;

using namespace std;

const int N=1000;
int arr[N];

void sort (int l, int r);

int main()
{
    srand(time(NULL));
/*
    ofstream cout;
    ifstream cin;

    cout.open("cobbler.out");
    cin.open("cobbler.in");

*/
    int n, k;
    cin >> n >> k;

    for  (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    //cout << '\n';

    sort (0, k - 1);

    int sum = 0, kol = 0;
    while (sum <= n)
    {
        sum += arr[kol];
        kol++;
    }
    cout << kol - 1;

    return 0;
}

void sort (int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int x = rand() % (r - l + 1) + l;
    int l1 = l, r1 = r;
    int pivot = arr[x];
    while (l <= r)
    {
        while (arr[l] < pivot)
        {
            l++;
        }
        while (arr[r] > pivot)
        {
            r--;
        }

        if (r >= l)
        {
            long int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }
        sort(l1, r);
        sort(r+1, r1);
}
