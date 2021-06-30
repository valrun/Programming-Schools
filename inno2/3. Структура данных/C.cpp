#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
/*
struct Heap
{
    int arr[100000];
    int e = 0;

    void Insert(int x)
    {
        arr[e] = x;
        e++;

        int i = e - 1, tmp;

        while (i >= 0 && arr[i] > arr[(i - 1)/ 2])
        {
            tmp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = tmp;

            i = (i - 1) / 2;
        }
    }

    int Extract()
    {
        e--;
        int max = arr[0];
        arr[0] = arr[e];
        int i = 0, tmp;

        while ((arr[i] < arr[i * 2 + 1] || arr[i] < arr[i * 2 + 2]) && i < e) //
        {
            if (arr[i * 2 + 1] < arr[i * 2 + 2] && i * 2 + 2 < e)
            {
                tmp = arr[i];
                arr[i] = arr[i * 2 + 2];
                arr[i * 2 + 2] = tmp;

                i = i * 2 + 2;
            }
            else
            {
                if (i * 2 + 1 < e)
                {
                    tmp = arr[i];
                    arr[i] = arr[i * 2 + 1];
                    arr[i * 2 + 1] = tmp;

                    i = i * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        return max;
    }
};
*/
int main()
{
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
	int s = pow(2, k);

	int *arr = new int[s];
	bool *pol = new bool[s];
	arr[0] = n;
	pol[0] = true;

    for (int i = 1; i < s; i++)
    {
		if (pol[(i - 1) / 2] == false)
		{
			pol[i] = true;
			arr[i] = 

		}
    }

    return 0;
}
