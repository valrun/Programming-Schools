//9. StackStr.h

//#include <stdlib.h>
//#include <stdio.h>


struct StackStr
{
    char* arr;
    int top;
    int memory;

    void create();
    void destruct();

    void push(char x);
    bool pop(char* out);
    bool getTop(char* out);

    bool isEmpty();
    void print();
};
//__________________________________________________
void StackStr::create()
{
    memory = 10;
    arr = (char*)calloc(memory, sizeof(char));
    top = -1;
}

void StackStr::destruct()
{
    free(arr);
    arr = NULL;
    memory = 0;
}

void StackStr::push(char x)
{
    top++;
    if (top == memory - 1)
    {
        memory += 10;
        arr = (char*)realloc(arr, memory * sizeof(char));
    }
    arr[top] = x;
}

bool StackStr::pop(char* out)
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

bool StackStr::getTop(char* out)
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

bool StackStr::isEmpty()
{
    return top != -1;
}

void StackStr::print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%ñ", arr[i]);
    }
    printf("\n");
}
