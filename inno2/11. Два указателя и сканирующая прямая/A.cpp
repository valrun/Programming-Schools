#include <iostream>
#include <cmath>
//#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#define lli long long int

using namespace std;

void sort (int l, int r);

int arr[200000][2];

int main(){
/*
    freopen("point.in","r",stdin);
    freopen("point.out","w",stdout);
*/

    int n;
    cin >> n;

    int h, m, s;
    int night = 0;

    for (int i = 0; i < n; i++) {
        cin >> h >> m >> s;
        arr[2 * i][0] = s + m * 60 + h * 3600;
        arr[2 * i][1] = 0;

        cin >> h >> m >> s;
        arr[2 * i + 1][0] = s + m * 60 + h * 3600;
        arr[2 * i + 1][1] = 1;

        if (arr[2 * i + 1][0] <= arr[2 * i][0]) {
            night++;
        }
    }

    sort (0, 2 * n - 1);
    long int time = 0;
    bool all = night == n;

    for (int i = 0; i < 2 * n; i++) {
        if (arr[i][1] == 0) {
            night++;
        }
        else {
            night--;
        }

        if (all && night != n) {
            all =  false;
            time += arr[i][0];
        }
        if (night == n && !all) {
            all = true;
            time -= arr[i][0];
        }

        cout << arr[i][0] << ' ' << arr[i][1] << ' ' << night << ' '  << time << ' ' << all <<'\n';
    }

    cout << time;

    return 0;
}

void sort (int l, int r)  {
    if (l >= r) {
        return;
    }
    int x = rand() % (r - l + 1) + l;
    int l1 = l, r1 = r;
    long int pivot = arr[x][0];
    while (l <= r) {
        while (arr[l][0] < pivot) {
            l++;
        }
        while (arr[r][0] > pivot) {
            r--;
        }

        if (r >= l) {
            int tmp = arr[l][0];
            arr[l][0] = arr[r][0];
            arr[r][0] = tmp;

            tmp = arr[l][1];
            arr[l][1] = arr[r][1];
            arr[r][1] = tmp;

            l++;
            r--;
        }
    }
        sort(l1, r);
        sort(r+1, r1);
}
