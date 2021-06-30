#include <stdlib.h>
//#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>

//std::string s;

using namespace std;

string s;

void sort (int l, int r);

int main()
{
    srand(time(NULL));

    ofstream cout;
    ifstream cin;

    cout.open("palindrom.out");
    cin.open("palindrom.in");


    cin >> s;

    sort (0, s.length() - 1);

    //cout << s << '\n';
    int p = 0;
    char middle = '0';
    string palindrome;


    for (int i = 0; i < s.length(); i++)
    {
        //cout << i <<' ' << s[i] << ' ';
        if (s[i] == s[i + 1] && i + 1 < s.length())
        {
            palindrome += s[i];
            i++;
            p++;
        }
        else if (middle == '0')
        {
            middle = s[i];
        }
        //cout << palindrome << '\n';
    }

    cout << palindrome;
    if (middle != '0')
    {
        cout << middle;
    }
    for (int i = palindrome.length() - 1; i >= 0; i--)
    {
        cout << palindrome[i];
    }

    return 0;
}

void sort (int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int x = rand() % (r - l + 1) + l;
    int l1 = l, r1 = r;
    int pivot = s[x];
    while (l <= r)
    {
        while (s[l] < pivot)
        {
            l++;
        }
        while (s[r] > pivot)
        {
            r--;
        }

        if (r >= l)
        {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
        sort(l1, r);
        sort(r+1, r1);
}
