#include <stdlib.h>
//#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{

    ofstream cout;
    ifstream cin;

    cout.open("lepus.out");
    cin.open("lepus.in");



    int N;
    cin >> N;

    int d[N];

    for (int i = 0; i < N; i++)
    {
        char s;
        cin >> s;
        d[i] = 0;

        switch (s)
        {
        case 'w':
            d[i] = -1;
            break;

        case '.':
            switch (i)
            {
            case 0:
                d[0] = 0;
                break;

            case 1:
                d[1] = 0;
                break;

            case 2:
                d[i] = (d[i - 1] != -1 ? d[i - 1] : -1);
                break;

            case 3:
                d[i] = max((d[i - 1] != -1 ? d[i - 1] : -1), (d[i - 3] != -1 ? d[i - 3] : -1));
                break;

            case 4:
                d[i] = max((d[i - 1] != -1 ? d[i - 1] : -1), (d[i - 3] != -1 ? d[i - 3] : -1));
                break;

            default:
                d[i] = max((d[i - 1] != -1 ? d[i - 1] : -1), max((d[i - 3] != -1 ? d[i - 3] : -1), (d[i - 5] != -1 ? d[i - 5] : -1)));
                break;
            }
            break;

        case '"':
            switch (i)
            {
            case 1:
                d[1] = 1;
                break;

            case 2:
                d[i] = (d[i - 1] != -1 ? d[i - 1] : -1) + 1;
                break;

            case 3:
                d[i] = max((d[i - 1] != -1 ? d[i - 1] + 1 : -1), (d[i - 3] != -1 ? d[i - 3] + 1 : -1));
                break;

            case 4:
                d[i] = max((d[i - 1] != -1 ? d[i - 1] + 1 : -1), (d[i - 3] != -1 ? d[i - 3] + 1 : -1));
                break;

            default:
                d[i] = max((d[i - 1] != -1 ? d[i - 1] + 1 : -1), max((d[i - 3] != -1 ? d[i - 3] + 1 : -1), (d[i - 5] != -1 ? d[i - 5] + 1 : -1)));
                break;
            }
            break;
        }
        //cout << d[i] << ' ';
    }
    //cout << '\n';
    cout << d[N - 1];

    return 0;
}
