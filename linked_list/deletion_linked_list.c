#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node * next;
};

void linkedListTraversal( struct Node * ptr ){
 while (ptr != NULL){
   printf("Element : %d\n", ptr->data);
   ptr = ptr->next;
 }
}

// case 1: deletion at the start 
struct Node * deletionAtStart(struct Node * head){
  struct Node * p = head;
  head = head->next;
  free(p);
  return head;
}

// case 2: deletion in between 
struct Node * deletionInBetween(struct Node * head , int index){
struct Node * p = head;
int j=0;
while (j < index-1){
p= p->next;
j++;
}
struct Node * q = p->next;
p-> next = q->next;
free(q);
return head;
}


// case 3: delete at the end.
struct Node * deleteAtEnd(struct Node * head){
  struct Node *p = head;
  struct Node *q = head->next;

  while (q->next != NULL){
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}


// case 4: deletion at first node with the given value.
struct Node * deletionAtValue(struct Node * head, int value){
struct Node * p = head;
struct Node * q = head->next;

while (q->data != value && q->next != NULL ){
q= q->next;
p= p->next;
}
if(q->data == value){
p-> next = q->next;
free(q);
}

return head;
}



void main(){

// allocating memory for the nodes in the heap
struct Node * head = (struct Node *) malloc (sizeof(struct Node));
struct Node * second = (struct Node *) malloc (sizeof(struct Node));
struct Node * third = (struct Node *) malloc (sizeof(struct Node));

head->data = 7;
head->next = second; // linking first to the second 

second -> data = 11;
second -> next = third;

third -> data = 22;
third -> next = NULL;

// case 1: deletion at the start 
head = deletionAtStart(head);

// case 2: deletion in between 
head = deletionInBetween(head , 2); // head and index at which we want delete starting from 0.

// case 3: delete at the end.
head = deleteAtEnd(head);

// case 4: deletion at first node with the given value.
head = deletionAtValue(head, 22);

linkedListTraversal(head);
}