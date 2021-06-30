#include <stdlib.h>
#include <stdio.h>

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

    void push(int newVal)
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


    bool pop(int* out) {
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
            pop(NULL);
        }
        free(head);
        head = NULL;
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

int main()
{
    Queue queue;
    queue.create();
    for(int i = 0; i < 21; i++)
    {
        queue.push(i);
    }
    queue.print();
    int val = 0;
    for(int i = 0; i < 10; i++)
    {
        queue.pop(&val);
    }
    queue.print();
    for(int i = 0; i < 20; i++)
    {

        queue.pushHead(i);
    }
    queue.print();
    queue.destruct();
    printf("-------------------");
    return 0;
}

