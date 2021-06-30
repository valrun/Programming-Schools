#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

char inversionBrackts(char brackts)
{
    switch (brackts)
    {
    case '(':
        brackts = ')';
        break;
    case '[':
        brackts = ']';
        break;
    case '{':
        brackts = '}';
        break;
    case ')':
        brackts = '(';
        break;
    case ']':
        brackts = '[';
        break;
    case '}':
        brackts = '{';
        break;
    }
    return brackts;
}

int main()
{

    ofstream cout;
    ifstream cin;

    cout.open("card-game.out");
    cin.open("card-game.in");


    ios::sync_with_stdio(0);

    string S;
    cin >> S;

    int n = S.length();

    if (S[0] == '(' || S[0] == '{' || S[0] == '[')
    {
        for (int i = 1; i < n; i++)
        {
            if (S[i] == inversionBrackts(S[i-1]))
            {

            }
        }
    }


    return 0;
}
