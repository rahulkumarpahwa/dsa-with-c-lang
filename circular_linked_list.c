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

//case 1: Insertion In Between 
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


// 



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
head = linkedListInsertion(head, -1, 33); // head, index and value


linkedListTraversal(head);


}