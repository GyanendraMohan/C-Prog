#include<stdio.h>

void main(){
    struct node{
        int data;
        struct node *next;
    };

    typedef struct node node;

    node a = {10,NULL};
    node b = {20,NULL};
    node c = {30,NULL};
    node d = {40,NULL};

    a.next = &b;
    b.next = &c;
    c.next =  &d;

    node *head = NULL;
    head = &a;

    printf("%d\n", head -> data);
    printf("%d\n", head -> next -> next -> next -> data);
    // printf("%u", head -> next);

    if(head->next != NULL){
        int count = 0;
        node *temp = head;
        while(temp != NULL) {
            printf("%d\t", temp->data);
            count++;
            temp = temp->next;
        }
        printf("\nLength of the linked list is : %d", count);
    }
}