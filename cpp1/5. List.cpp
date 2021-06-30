#include "5. RVLibList.h";

using namespace std;

int main()
{
    srand(time(NULL));

    List list;
    list.create();
    for (int i = 0; i < 10; i++)
    {
        list.insertBegin(rand() % (3));
    }
    list.print();

    list.deleteAfter(list.find(0));
    list.print();

    list.deleteItem(3);
    list.print();
}
