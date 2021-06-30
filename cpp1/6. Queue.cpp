#include "6. RVLibQueue.h";

using namespace std;

int main()
{
    srand(time(NULL));

    Queue q;
    q.create();

    for (int i = 0; i < 5; i++)
    {
        q.add(i);
    }

    int a;
    q.poll(&a);
    q.print();
    printf("%d",q.isEmpty());
}
