// we will create doubly linked list with forward and backword traversal and printing values.
//else commands can be done by self like insertion, deletion and others.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
};

void linkedListTraversal( struct Node * head){
struct Node * ptr = head;

while(ptr->next != NULL){
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
}
 printf("Element : %d\n", ptr->data);
while(ptr!= NULL){
    printf("Element : %d\n", ptr->data);
    ptr = ptr->prev;
}
}

void main(){
 struct Node * head = (struct Node * )malloc(sizeof(struct Node));
 struct Node * second = (struct Node * )malloc(sizeof(struct Node));
 struct Node * third = (struct Node * )malloc(sizeof(struct Node));

head->data = 44;
head->next = second;
head->prev= NULL;

second->data =88;
second->next = third;
second->prev = head;

third->data = 888;
third->next = NULL;
third->prev = second;

linkedListTraversal(head);


}