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
/*
    ofstream cout;
    ifstream cin;

    cout.open("numbers.out");
    cin.open("numbers.in");
*/

    string s;
    cin >> s;

    bool flag = (s.length() % 2 == 0 ? true : false);

    int i = 0;
    while (flag && i < s.length() / 2) {
        if (s[i] != s[s.length() / 2 + i]) {
            flag = false;
        }
        i++;
    }

    cout << (flag ? "YES" : "NO");

    return 0;
}
