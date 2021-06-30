#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    //freopen("z.in","r",stdin);
    //freopen("z.out","w",stdout);

    string s;
    cin >> s;

    int z[s.length()];
    z[0] = 0;

    for (int i = 0; i < s.length(); i++) {
        t = p[i - 1];
        while (t > 0 && s[i] != s[t]) {
            t = p[t - 1];
        }
        p[i] = (t == 0 ? s[i] == s[0] : t + 1);

        cout << p[i] << ' ';
    }

    return 0;
}
