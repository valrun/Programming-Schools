//6. RVLibQueue.h
//#include "5. RVLibList.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

struct Node
{
    int val;
    Node* next = NULL;
};

struct Queue
{
    Node** head;

    void create()
    {
       head = (Node**) malloc(sizeof(Node*));
       (*head) = NULL;
    }

    void add(int newVal)
    {
        if((*head) == NULL) {
           pushHead(newVal) ;
        } else {
            Node* last = getLast();
            Node *tmp = (Node*) malloc(sizeof(Node));
            tmp->val = newVal;
            tmp->next = NULL;
            last->next = tmp;
        }
    }

    void pushHead(int newVal)
    {
        Node *tmp = (Node*) malloc(sizeof(Node));
        tmp->val = newVal;
        tmp->next = (*head);
        (*head) = tmp;
    }


    bool poll(int* out) {
        if ((*head) == NULL) {
            return false;
        }
        if(out != NULL)
        {
            (*out) = (**head).val;
        }
        Node* prev = (*head);
        (*head) = (*head)->next;
        free(prev);
        return true;
    }

    bool peek(int* out) {
        if ((*head) == NULL) {
            return false;
        }
        if(out != NULL)
        {
            (*out) = (**head).val;
            return true;
        }
    }

    Node* getLast() {
        Node* last = (*head);
        if (last == NULL) {
            return NULL;
        }
        while(last->next != NULL) {
            last = last->next;
        }
        return last;
    }

    void destruct()
    {
        while ((*head) != NULL) {
            poll(NULL);
        }
        free(head);
        head = NULL;
    }

    bool isEmpty()
    {
        return (*head) != NULL;
    }

    void print()
    {
        if((*head) == NULL)
        {
            printf("print null");
            return;
        }
        Node* current = (*head);
        while(current != NULL)
        {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }

};
/*
struct Queue
{
    List list;
    Item* tail;

    void create();
    Item* getHead();
    void add(int val);

    void poll(int* out);
    void peek(int* out);

    bool isEmpty();

    void print();

    void destruct();
};
//___________________________________________
void Queue::create()
{
    list.create();
    tail = list.first;
}

Item* Queue::getHead()
{
    return list.first;
}

void Queue::add(int val)
{
    if (!list.isEmpty())
    {
        list.insertBegin(val);
        tail = list.first;
    }
    else
    {
        tail = list.insertAfter(tail, val);
    }
}

void Queue::poll(int* out)
{
    (* out) == getHead() ->val;
    list.deleteItem(getHead() ->val);
    if (list.isEmpty())
    {
        tail = NULL;
    }
}

void Queue::peek(int* out)
{
    (* out) = list.isEmpty() ? NULL : getHead() ->val;
}

void Queue::print()
{
    Item* current = getHead();
    printf("%d ", current ->val);

    while (current -> hasNext())
    {
        current = current ->next;
        printf("%d ", current ->val);
    }
    printf("\n");
}

void Queue::destruct()
{
    Item* current = (Item*)malloc(sizeof(Item*));
    while(getHead() != NULL)
    {
        current = getHead();
        list.first = list.first ->next;
        free(current);
    }
    free(tail);
}
*/
