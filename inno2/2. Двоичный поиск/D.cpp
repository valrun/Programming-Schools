#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

const int N = 100000;
int arr[N];

void sort (int l, int r);

int main()
{
    srand(time(NULL));

    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(0, n - 1);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int tmpL, tmpR;
        cin >> tmpL >> tmpR;
        if (tmpL <= arr[n-1] && tmpR >= arr[0])
        {
            int l = 0, r = n - 1, m;
            while (r - l > 1)
            {
                m = (l + r) / 2;
                //cout << m << 'm' << arr[m] << "arr[m]";
                if (arr[m] > tmpL)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
                //cout << l << 'l' << r << 'r' << '\n';
            }
            int L = (arr[l] < tmpL ? l + 1 : l);
            //cout << L << 'L';

            l = 0;
            r = n - 1;
            while (r - l > 1)
            {
                m = (l + r) / 2;
                //cout << m << 'm' << arr[m] << "arr[m]";
                if (arr[m] > tmpR)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
                //cout << l << 'l' << r << 'r' << '\n';
            }
            int R = (arr[r] > tmpR ? r - 1 : r);
            //cout << R <<'R';
            cout << R - L + 1 << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }

    return 0;
}
//____________
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
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }
        sort(l1, r);
        sort(r+1, r1);
}
