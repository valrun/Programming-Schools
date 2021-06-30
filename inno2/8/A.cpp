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

    cout.open("gcd.out");
    cin.open("gcd.in");

    int l, r;
    cin >> l >> r;
    cout << (r != l ? r - 1 : l) << ' ' << r;
}
