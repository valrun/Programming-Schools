#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

enum Vis {
Not, Visit, Out};

int main()
{
/*
    ofstream cout;
    ifstream cin;

    cout.open("components.out");
    cin.open("components.in");
*/

    int M, N;
    cin >> M >> N;

    Vis Ver[M];
    int from[M];
    for (int i = 0; i < M; i++) {
        Ver[i] = Not;
        from[i] = -1;
    }

    int arr[2][N];
    for (int i = 0; i < N; i++) {
        cin >> arr[0][i] >> arr[1][i];
        arr[0][i]--;
        arr[1][i]--;
    }

    int k = 0;
    while (true) {
        cout << "Let's go ";
        int i = 0;
        while (i < N) {
            if (arr[0][i] == k) {
                Ver[k] = Visit;
                arr[0][k] = -1;
                from[arr[1][i]] = k;
                k = arr[1][i];
                break;
            }
            i++;
        }
        cout << k << ' ' << Ver[k] << '\n';

        if (Ver[k] == Out) {
            Ver[k] = Out;
            k = from[k];
            if (k == -1) {
                for (int j = 0; j < M; j++) {
                    if (Ver[j] == Not) {
                        k = j;
                        break;
                    }
                }
                if (k == -1) {
                    cout << "NO";
                    break;
                }
            }
        }
        else if (Ver[k] == Visit) {
            cout << "OOO";
            break;
        }

        if (i == N) {
            Ver[k] = Out;
            k = -1;
            for (int j = 0; j < M; j++) {
                if (Ver[j] == Not) {
                    k = j;
                    break;
                }
            }
            if (k == -1) {
                cout << "NO";
                break;
            }
        }

    }

    return 0;
}
