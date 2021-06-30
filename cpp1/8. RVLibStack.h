//8. RVLibStack.h
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <math.h>

struct Stack
{
    int* arr;
    int top;
    int memory;

    void create();
    void destruct();

    void push(int x);
    bool pop(int* out);
    bool getTop(int* out);

    bool isEmpty();
    void print();
};
//__________________________________________________
void Stack::create()
{
    memory = 10;
    arr = (int*)calloc(memory, sizeof(int));
    top = -1;
}

void Stack::destruct()
{
    free(arr);
    arr = NULL;
    memory = 0;
}

void Stack::push(int x)
{
    top++;
    if (top == memory - 1)
    {
        memory += 10;
        arr = (int*)realloc(arr, memory * sizeof(int));
    }
    arr[top] = x;
}

bool Stack::pop(int* out)
{
    if (top > -1)
    {
        *out = arr[top--];
        return true;
    }
    else
    {
        return false;
    }

}

bool Stack::getTop(int* out)
{
    if (top > -1)
    {
        *out = arr[top];
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isEmpty()
{
    return top != -1;
}

void Stack::print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

