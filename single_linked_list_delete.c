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
    printf("\n");
}

void delete(Node **head, int val) {
    Node *prev = NULL;
    Node *curr = *head;
    
    if((*head)->val == val) {
        Node *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        return;
    }
    
    Node *temp = curr;
    while(curr != NULL && curr->val != val) {
        prev = curr;
        curr = curr->next;
    }
    
    if(temp == NULL) {
        printf("\n no node found with val %d\n", val);
        return;
    }
    
    prev->next = curr->next;
    return;
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
   
   delete(&head, 10);
   
   printList(head);

    return 0;
}
