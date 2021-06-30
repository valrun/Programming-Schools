#include "4. RVLibArr.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Array arr;
    arr.create(0, 7, 10);

    arr.print();
    arr.sortComb();
    arr.print();

    return 0;
}

