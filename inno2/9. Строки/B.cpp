#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <string>
#define lli long long int
using namespace std;

int main(){
    //freopen("prefix.in","r",stdin);
    //freopen("prefix.out","w",stdout);
    string s, s1;
    cin >> s;
    cin >> s1;

    for (int i=0; i < (int)s.length(); i++){
        if(s[i] == '0'){
        s[i] = 'o';
        }
        if(s[i] == '3'){
        s   [i] = 'e';
        }
        if(s[i] == '1'){
            s[i] = 'i';
        }
        if(s[i] == '7'){
            s[i] = 't';
        }
        if(s[i] == '4'){
            s[i] = 'a';
        }
        if(s[i] == '5'){
            s[i] = 's';
        }
    }
    int lol = s1.length(), t;
    s1 += s;

    int p[s1.length()];
    p[0] = 0;
    for (int i = 1; i < s1.length(); i++) {
        t = p[i - 1];
        while (t > 0 && s1[i] != s1[t]) {
            t = p[t - 1];
        }
        p[i] = (t == 0 ? s1[i] == s1[0] : t + 1);

        if (p[i] == lol)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
