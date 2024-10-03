#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node * next;

};

void linkedListTraversal(struct Node * ptr){
  while(ptr != NULL){
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
  }
}

// case 1 : insert at the beginning of the list.
struct Node * linkedListInsertionAtBegin( struct Node * ptr, struct Node * p){
 p->next = ptr;
 return p;
}


// case 2: insert in between the linked list.
void linkedListInsertionBetween(struct Node * ptr, struct Node * p, int i){
// struct Node * k = (struct Node *) malloc (sizeof(struct Node));
for(int j = 0; j<=i ; j++){
  ptr = ptr->next;
}
p->next = ptr->next;
ptr->next = p;
}



void main(){
struct Node * head = (struct Node *) malloc (sizeof(struct Node)); 
struct Node * second = (struct Node *) malloc (sizeof(struct Node)); 
struct Node * third = (struct Node *) malloc (sizeof(struct Node)); 

head->data = 7;
head->next = second;

second->data = 14;
second->next = third;

(*third).data = 21; // same as third->data = 21;
third->next = NULL;

// insertion of the node in the linked list:
// creating a node to add.
struct Node * p = (struct Node *) malloc (sizeof(struct Node));
 p->data = 6; // value can be anything


// case 1 : insert at the beginning of the list.
head = linkedListInsertionAtBegin(head , p);


// case 2: insert in between the linked list.
linkedListInsertionBetween(head , p , 3); // arguments are the head, the node we want to add and the index after which we want to insert.

//case 3: insert at the end.

//case 4: insert after given Node in the linked list.


// to show the linked list
linkedListTraversal(head);
}