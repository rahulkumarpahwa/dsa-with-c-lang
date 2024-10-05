#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node * next;
};

void linkedListTraversal( struct Node * head ){
 struct Node * p = head;
 do {
  printf("Element : %d\n", p->data);
  p = p->next;
 } while(p != head);
 
//or 

// other way of traversal:
// while(p->next != head){
//   printf("Element : %d\n", p->data);
//   p = p->next;
// }
// printf("Element : %d\n", p->data);
}

// case 1: insertion at the begin / start
struct Node * linkedListInsertStart(struct Node * head, int data){
struct Node * p = head; 
struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
ptr -> data = data;

// do {
//   p= p->next;
// } while (p->next != head);

// or 

while(p->next != head){
  p = p->next;
}

p->next = ptr;
ptr->next = head;
return ptr;
}


//case 2: Insertion In Between 
struct Node * linkedListInsertion(struct Node * head, int index , int data){
struct Node * p = head;
struct Node * q = (struct Node *) malloc (sizeof(struct Node));
q->data = data;
for (int i = 0 ; i < index ; i++){
p = p->next;
}
q->next = p->next;
p->next = q;
return head;
}


// case 3: deletion at the start:
struct Node * deleteAtStart(struct Node * head){
struct Node * p = head;
struct Node * q = head->next;

while (q->next != head){
q=q->next;
}
q-> next = p->next;
free(p);
return q->next;
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
third -> next = head; // connecting the last node to the head.


//case 1: Insertion In Between 
head = linkedListInsertion(head, 2, 33); // head, index and value

head = linkedListInsertStart(head , 444); // head and the value

head = deleteAtStart(head);

linkedListTraversal(head);

}