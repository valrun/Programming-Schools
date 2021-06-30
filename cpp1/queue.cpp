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

    void destruct()
    {
        while ((*head) != NULL) {
            pop(NULL);
            *head = (*head)->next;
        }
        free(head);
        head = NULL;
    }

    void print()
    {
        if(*head == NULL)
        {
            return;
        }
        Node* current = (*head);
        printf("\n");
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
    for(int i = 0; i < 20; i++)
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
        queue.push(i);
    }
    queue.print();
    queue.destruct();
    printf("-------------------");
    return 0;
}

