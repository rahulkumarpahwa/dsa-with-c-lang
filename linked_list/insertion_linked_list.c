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
struct Node * linkedListInsertionBetween(struct Node * head, int i, int data){
struct Node * p = (struct Node *) malloc (sizeof(struct Node));
 p->data = data;
struct Node * k = head;
int j;
for (j=0 ; j != i-1; j++){
  k = k->next;
}
p->next = k->next;
k->next = p;
return head;
}

//case 3: insert at the end.
struct Node * linkedListInsertionEnd(struct Node * head , int data){

struct Node * p = (struct Node *) malloc (sizeof(struct Node));
 p->data = data;
struct Node * k = head;
while (k->next != NULL){
  k = k->next;
}
k->next = p;
p->next = NULL;
return head;
}


//case 4: insert after given Node in the linked list.
struct Node * linkedListInsertionNode(struct Node * head, struct Node * ptr, int data){
struct Node * p = (struct Node *) malloc (sizeof(struct Node));
p->data = data;
p->next = ptr->next;
ptr->next = p;
return head;
}

//case 5: Insertion before a given node.
struct Node *insertAtGivenNode(struct Node *head, int val, struct Node *given)
{
  struct Node *p = head;
  struct Node *q = p->next;
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->data = val;
  if (n == NULL)
  {
    printf("Overflow, can't input");
    return NULL;
  }
  while (p->next != given && q != NULL)
  {
    p = p->next;
    q = q->next;
  }
  p->next = n;
  n->next = q;
  return head;
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
// head = linkedListInsertionAtBegin(head , p);


// case 2: insert in between the linked list.
// head = linkedListInsertionBetween(head , 2, 16); // arguments are the head, the index after we add and data we add.

//case 3: insert at the end.
// head = linkedListInsertionEnd(head, 34 ); // arguments are the head and the data we add.

//case 4: insert after given Node in the linked list.
// head = linkedListInsertionNode(head, second, 78); // arguments are the head, given node and data.

// case 5: Insertion before a given node.
head = insertAtGivenNode(head, 99, second );

// to show the linked list
linkedListTraversal(head);
}