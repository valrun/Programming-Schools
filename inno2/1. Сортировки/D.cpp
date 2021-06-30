#include <stdlib.h>
//#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

//std::string s;

using namespace std;

const int N=100000;
long int arr[N];

void sort (int l, int r);

int main()
{
    srand(time(NULL));

    ofstream cout;
    ifstream cin;

    cout.open("sort.out");
    cin.open("sort.in");


    int n;
    cin >> n;

    for  (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //cout << '\n';

    sort (0, n - 1);

    for  (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

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
    long int pivot = arr[x];
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
