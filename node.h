#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct Node {
    struct Node* prev;
    int attribute;
    struct Node* next;
} Node;

#endif