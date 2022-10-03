#include <stdio.h>
#include <stdlib.h>
struct Node_t {
    int val;
    struct Node_t *next;
 
};

typedef struct Node_t Node;

void push(Node **head, int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;
    
    if(*head == NULL) {
        *head = temp;
    }else {
        temp->next = *head;
        *head = temp;
    }
}

void printList(Node *head) {
    
    while(head != NULL) {
        printf("=> %d", head->val);
        head = head->next;
    }
}


int main()
{
    printf("Hello World");

    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    
   printList(head);

    return 0;
}
