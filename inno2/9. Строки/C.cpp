#include <stdlib.h>
//#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    ofstream cout;
    ifstream cin;

    cout.open("prefix.out");
    cin.open("prefix.in");


    string s;
    cin >> s;

    int p[s.length()];
    p[0] = 0;
    cout << p[0] << ' ';
    int t;

    for (int i = 1; i < s.length(); i++) {
        t = p[i - 1];
        while (t > 0 && s[i] != s[t]) {
            t = p[t - 1];
        }
        p[i] = (t == 0 ? s[i] == s[0] : t + 1);

        cout << p[i] << ' ';
    }

    return 0;
}
