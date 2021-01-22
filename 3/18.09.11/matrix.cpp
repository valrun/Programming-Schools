#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
struct matrix {
    double arr[4][4];

    void create() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               arr[i][j] = (rand() % 100 + 1) / 10.0;
            }
        }
    }

    void create(matrix other) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               arr[i][j] = other.arr[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%6.2f   ", arr[i][j]);
            }
            printf("\n");
        }
    }

    void add(matrix other) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               arr[i][j] += other.arr[i][j];
            }
        }
    }

    void mult(matrix other) {
        matrix tmp;
        //tmp.create();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               tmp.arr[i][j] = 0;
               for (int r = 0; r < 4; r++) {
                    tmp.arr[i][j] += arr[i][r] * other.arr[r][j];
               }
            }
        }
        this -> create(tmp);
    }
};

int main(){
    srand (time(NULL));

    matrix m1;
    m1.create();
    m1.print();
    printf("\n");

    matrix m2;
    m2.create();
    m2.print();
    printf("\n");

    m1.add(m2);
    m1.print();
    printf("\n");

    m2.mult(m1);
    m2.print();
    printf("\n");

    return 0;
}
