//7. RVLibMaze.h
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <math.h>

enum TypeCells
{
    Carrot, Rabbit, Wall, Blank, Way
};

//__________________________________________________________
//___________________________________________

struct Item
{
    int val;
    TypeCells type;
    int x;
    int y;
};

struct Node
{
    Node* next = NULL;
    Item item;
};

struct Queue
{
    Node** head;

    void create()
    {
       head = (Node**) malloc(sizeof(Node*));
       (*head) = NULL;
    }

    void add(Item newItem)
    {
        if((*head) == NULL) {
           pushHead(newItem) ;
        } else {
            Node* last = getLast();
            Node *tmp = (Node*) malloc(sizeof(Node));
            tmp->item = newItem;
            tmp->next = NULL;
            last->next = tmp;
        }
    }

    void pushHead(Item newItem)
    {
        Node *tmp = (Node*) malloc(sizeof(Node));
        tmp->item = newItem;
        tmp->next = (*head);
        (*head) = tmp;
    }

    bool poll(Item* out) {
        if ((*head) == NULL) {
            return false;
        }
        if(out != NULL)
        {
            (*out) = (**head).item;
        }
        Node* prev = (*head);
        (*head) = (*head)->next;
        free(prev);
        return true;
    }

    bool peek(Item* out) {
        if ((*head) == NULL) {
            return false;
        }
        if(out != NULL)
        {
            (*out) = (**head).item;
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
/*
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
*/
    TypeCells type()
    {
        return (*head) ->item.type;
    }

    int val()
    {
        return (*head) ->item.val;
    }

    int x()
    {
        return (*head) ->item.x;
    }

    int y()
    {
        return (*head) ->item.y;
    }


};
