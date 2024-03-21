#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

void create_node();
void print_list();
int print_length(node *head);
void insert_beginning(node **head);
void insert_end(node *head);
node *middle_of_list(node *head);
// int insert_at_pos(node **head);

int main() {
    int choice, no_of_nodes;
    int position;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &no_of_nodes);

    for (int i = 0; i < no_of_nodes; i++) {
        create_node();
    }
    print_list();

    int exit_choice = 0;
    while (!exit_choice) {
        printf("\n1. Print the list\n");
        printf("2. Print the length of the list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Find the middle of the list\n");
        // printf("6. Insert Node at Given Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_list();
                break;
            case 2:
                printf("Length of the Linked list is : %d\n", print_length(head));
                break;
            case 3:
                insert_beginning(&head);
                print_list();
                break;
            case 4:
                insert_end(head);
                print_list();
                break;
            case 5:
                printf("Middle of the linked list: %d\n", middle_of_list(head)->data);
                break;
            // case 6:
            //     printf("Enter the position  to insert the new node: \n");
            //     scanf("%d",&position);
            //     insert_at_pos(position, &head);
            //     print_list();
            //     break;
            case 6:
                exit_choice = 1;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void print_list(){
    node *p = head;
    if(p == NULL) {
        printf("\nList is Empty");
        return;
    }
    printf("Linked list elements are: ");
    while(p !=NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
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

// int insert_at_pos(int position, node **head) {
//     int length = print_length(*head);
//     if(position <= 0 || position > length + 1) {
//         printf("Invalid position!\n");
//         return 1
//     }
//     if(position == 1) {
//         insert_beginning(*head);
//         return 1;
//     }
//     if(position == length + 1){
//         insert_end(*head);
//         return 1;
//     }
//     else{
//         int k =1;
//         node *p = *head; //to iterate through list from beginning 
//         node *temp = (node * )malloc(sizeof(node));
//         if(temp == NULL) exit(1);
//         printf("Enter the data element to add node at position %d: ",&position);
//         scanf("%d", &temp->data);
//         temp->next = NULL;
//         while(k < position -1) {
//             p = p->next;
//             k++;
//         }
//         temp->next = p->next;
//         p -> next = temp;
//         p = NULL;
//         temp = NULL;
//     }
// } 