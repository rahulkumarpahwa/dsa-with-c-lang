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
  head = head->next;
  return head;
}

// case 2: deletion in between 
struct Node * deletionInBetween(struct Node * head , int index){


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
head = deletionInBetween(head , 2); // head and index at which we want delete.

linkedListTraversal(head);
}