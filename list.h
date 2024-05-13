#include "node.h"
#include <stdio.h>


typedef struct DoublyLinkedList {
    Node *head;
    Node *tail;
} DoublyLinkedList;

struct Node* search(DoublyLinkedList* list, int attribute);

void prepend(DoublyLinkedList* list, int attribute);

void insert(Node* newNode, Node* indexNode);

void delete(DoublyLinkedList* list, Node* targetNode);


