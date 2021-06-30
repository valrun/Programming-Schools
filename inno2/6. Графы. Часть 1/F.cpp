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

    cout.open("components.out");
    cin.open("components.in");


    int M, N;
    cin >> M >> N;

    int Ver[M], kom = 0;
    for (int i = 0; i < M; i++) {
        Ver[i] = 0;
    }

    int a, b;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;

        a--;
        b--;

        if (Ver[a] == Ver[b] && Ver[a] == 0) {
            kom++;
            Ver[a] = kom;
            Ver[b] = kom;
        }
        else if (Ver[a] != Ver[b] && Ver[a] == 0) {
            Ver[a] = Ver[b];
        }
        else if (Ver[a] != Ver[b] && Ver[b] == 0) {
            Ver[b] = Ver[a];
        }
        else if (Ver[a] != Ver[b]) {
            kom--;

            int tmp = Ver[b];
            Ver[b] = (Ver[a] <= Ver[b]? Ver[a] : Ver[b]);
            Ver[a] = (Ver[a] == Ver[b] ? tmp : Ver[a]);

            for (int j = 0; j < M; j++) {
                Ver[j] = (Ver[j] == Ver[a] ? Ver[b] : Ver[j]);
                Ver[j] = (Ver[j] > Ver[a] ? Ver[j] - 1 : Ver[j]);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (Ver[i] == 0) {
            kom++;
            Ver[i] = kom;
        }
    }

    cout << kom << '\n';
    for (int j = 0; j < M; j++) {
        cout << Ver[j] << ' ';
    }

    return 0;
}
