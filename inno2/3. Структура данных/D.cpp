#include <stdlib.h>
#include <iostream>
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

    cout.open("card-game.out");
    cin.open("card-game.in");


    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int first[N/2 + 200000], efirst = 0, bfirst = 0;
    int second[N/2 + 200000], esecond = 0, bsecond = 0;

    for (int i = 0; i < N / 2; i++)
    {
        cin >> first[i];
        efirst++;
    }
    for (int i = 0; i < N / 2; i++)
    {
        cin >> second[i];
        esecond++;
    }

    for (int i = 0; i < 200000; i++)
    {
        if ((first[bfirst] > second[bsecond] || (first[bfirst] == 0 && second[bsecond]== N - 1)) && !(first[bfirst] == N - 1 && second[bsecond]== 0))
        {
            first[efirst] = first[bfirst];
            first[efirst + 1] = second[bsecond];
            efirst += 2;
            //cout << first[efirst - 2] << ' ';
        }
        else
        {
            second[esecond] = first[bfirst];
            second[esecond + 1] = second[bsecond];
            esecond += 2;
            //cout << second[esecond - 1] << ' ';
        }
        bfirst++;
        bsecond++;

        if (efirst - bfirst == N)
        {
            cout << "first " << i + 1;
            break;
        }
        if (esecond - bsecond == N)
        {
            cout << "second " << i + 1;
            break;
        }
    }

    if (efirst - bfirst != N && esecond - bsecond != N)
    {
        cout << "draw";
    }

    return 0;
}
