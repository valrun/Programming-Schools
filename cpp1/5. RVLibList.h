//5. RVLibList.h
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <math.h>

struct Item
{
    int val;
    Item* next;

    bool hasNext()
    {
        return next != NULL;
    }
};

struct List
{
    Item* first;

    void create();

    void insertBegin(int val);
    Item* insertAfter(Item* target, int val);

    Item* find(int val);

    bool isEmpty();

    void deleteAfter(Item* target);
    void deleteItem(int val);

    void print();

    void destruct();
};
//__________________________________________________________
void List::create()
{
    first = NULL;
}

void List::insertBegin(int val)
{
    Item* tmp = (Item*)malloc(sizeof(Item*));
    tmp ->val = val;
    tmp ->next = first;
    first = tmp;
}

Item* List::insertAfter(Item* target, int val)
{
    Item* tmp = (Item*)malloc(sizeof(Item*));
    tmp ->val = val;
    tmp ->next = target -> next;
    target ->next = tmp;

    return tmp;
}

Item* List::find(int val)
{
    Item* current = first;
    while (current != NULL && current ->val != val)
    {
        current = current ->next;
    }
    return current;
}

bool List::isEmpty()
{
    return first != NULL;
}

void List::deleteAfter(Item* target)
{
    Item* tmp = target ->next;
    target ->next = tmp ->next;
    free(tmp);
}

void List::deleteItem(int val)
{
    Item* current = first;

    if(first ->val == val)
    {
        first = first ->next;
        free(current);
    }
    else
    {
        current = first;
        while (current ->next ->hasNext() && current ->next ->val != val)
        {
            current = current ->next;
        }

        if (current ->hasNext())
        {
            current ->next = current ->next ->next;
            free(current ->next);
        }
    }

}

void List::print()
{
    Item* current = first;
    printf("%d ", current ->val);

    while (current -> hasNext())
    {
        current = current ->next;
        printf("%d ", current ->val);
    }
    printf("\n");
}

void List::destruct()
{
    Item* current = (Item*)malloc(sizeof(Item*));

    while(first != NULL)
    {
        current = first;
        first = first ->next;
        free(current);
    }
}
