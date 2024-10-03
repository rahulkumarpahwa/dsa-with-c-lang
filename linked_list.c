#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node * next;
};

void linkedlistTraversal( struct Node * ptr ){
 while (ptr != NULL){
   printf("Element : %d", ptr->data);
   ptr = ptr->next;
 }
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
third-> next = NULL;


linkedlistTraversal(head);

}