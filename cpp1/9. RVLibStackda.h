//8. RVLibStack.h
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <math.h>

struct Number
{
    int* number;
    int memory;
    int count;

    void create()
    {
        memory = 10;
        count = 0;
        number = (int*)calloc(memory, sizeof(int));
    }

    void add()
    {
        memory += 10;
        number = (int*)realloc(number, memory * sizeof(int));
    }

    void destruct()
    {
        free(number);
        number = NULL;
        memory = 0;
        count = 0;
    }
};

struct Stack
{
    Number* arr;
    int top;
    int memory;

    void create();
    void destruct();

    void push(Number x);
    bool pop(Number* out);
    bool getTop(Number* out);

    bool isEmpty();
    void print();
};
//__________________________________________________
void Stack::create()
{
    memory = 10;
    arr = (Number*)malloc(memory * sizeof(Number));
    top = -1;
}

void Stack::destruct()
{
    free(arr);
    arr = NULL;
    memory = 0;
}

void Stack::push(Number x)
{
    top++;
    if (top == memory - 1)
    {
        memory += 10;
        arr = (Number*)realloc(arr, memory * sizeof(Number));
    }
    arr[top] = x;
}

bool Stack::pop(Number* out)
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

bool Stack::getTop(Number* out)
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

