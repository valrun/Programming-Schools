#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

//std::string s;

using namespace std;

int main()
{
    srand(time(NULL));
/*
    ofstream cout;
    ifstream cin;

    cout.open("excess.out");
    cin.open("excess.in");

*/
    int n;
    cin >> n;

    int arr[n];
    int count[n];

    for  (int i = 0; i < n; i++)
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

    for  (int i = 0; i < n; i++)
    {
        if(count[i] % 4 != 0)
        {
            cout << arr[i];
            break;
        }
    }
    return 0;
}
