#include <stdio.h>
#include <stdlib.h>

struct Node_t {
    int val;
    struct Node_t *prev;
    struct Node_t *next;
};

typedef struct Node_t Node;


void push(Node **head, int val) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = NULL;
    tmp->prev = NULL;
    
    if(*head == NULL) {
        *head = tmp;
        return;
    }
    
    tmp->next = *head;
    (*head)->prev = tmp;
    
    *head = tmp;
    return;
}

void delete(Node **head, int val) {
        
    if(*head == NULL)
        return;
        
    if((*head)->val == val) {
        Node *temp = *head;
        *head = (*head)->next;
        if(temp->next)
        if(temp->next)
            temp->next->prev = NULL;
        temp->next = NULL;
        return;
    }
    

    Node *curr = *head;
    while(curr != NULL && curr->val != val) {
        curr = curr->next;
    }
    
    if(curr == NULL)
        return;
        
    if(curr->next)
        curr->next->prev = curr->prev;
    if(curr->prev)
        curr->prev->next = curr->next;
    
    return;
}


void printList(Node *head) {
    while(head) {
        printf(" => %d", head->val);
        head = head->next;
    }
    
    printf("\n");
}

int main()
{
   // printf("Hello World");

    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
   
    
    printList(head);
    
    delete(&head, 10);
    
     printList(head);

    return 0;
}
