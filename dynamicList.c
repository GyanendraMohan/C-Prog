#include<stdio.h>
#include<stdlib.h>

struct node {
    int data; //member variable
    struct node *next; //member variable
};

typedef struct node node;//alias
node *head = NULL;//initial node Global variable

void create_node();
void print_list();
int print_length(node *head);
void insert_beginning(node **head);
void insert_end(node *head);
node *middle_of_list(node *head);

void main() {
    int i , no_of_nodes;
    printf("Enter the number of nodes you want in your linked list : ");
    scanf("%d", &no_of_nodes);
    for(i =1; i<=no_of_nodes;i++) {
        create_node();
    }
    printf("Linked list elements are: ");
    print_list();

    printf("\nLength of the Linked list is : %d\n", print_length(head));

    insert_beginning(&head); // Pass the address of the head pointer
    printf("\nNew Linked list after adding the node at beginning: ");
    print_list();

    insert_end(head);  //Passing the head pointer itself to add a new node at end
    printf("\nNew Linked list after adding the node at End:");
    print_list();

    printf("\nMiddle of the linked list: %d", middle_of_list(head)->data);
}

//printing the linke list element
void print_list(){
    node *p = head;
    while(p !=NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void create_node() {
    node *temp;
    temp = (node *) malloc(sizeof(node));//dynamic memory allocation
    if(temp == NULL) {
        printf("Node not created \n");
        exit(1);
    }
    printf("Enter the data element: ");
    scanf("%d", &temp->data);//adding data in data part of newly created node 
    temp->next = NULL;//making next as null initially
    if(head == NULL) {
        head = temp;//if there is no node then make this new node the first node
    }
    else {
        node *p = head;
        while(p->next !=NULL){
            p = p->next;
        }
        p->next = temp;//connecting last node with new node
        p=NULL;
    }
    temp=NULL;
}

int print_length(node *head){
    int length = 0;
    if(head == NULL){
        return length;
    }
    else {
        node *p = head;//one node in list 
        length = 1;
        while(p->next != NULL) {
            p = p -> next;
            length++;
        }
        p = NULL;
        return length;
    }
}

void insert_beginning(node **head) {
    //creating a new node to insert in begning
    node *temp = (node * )malloc(sizeof(node));
    if(temp == NULL) {
        exit(1);
    }
    printf("Enter data for new node to add in begining: ");
    scanf( "%d" ,&temp->data );
    temp->next = NULL;
    if(*head==NULL) {
        *head = temp;
    }
    else {
        temp->next = *head;
        *head = temp;
    }
    temp = NULL;
}

void insert_end(node *head) {
    node *temp = (node *) malloc( sizeof( node ) );
    if (temp == NULL) {
        exit(1);
    }
    printf("\nEnter data for the new node to add in end of list: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    }
    else {
        node *p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        p = NULL;
    }
}

node *middle_of_list(node *head) {
    node *slow = head;
    node *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}