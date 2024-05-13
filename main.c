#include <stdio.h>
#include "node.h"
#include "list.h"
#include "list.c"
#include <string.h>
#include <stdlib.h>

void prepend(DoublyLinkedList *list, int attribute)
{
    struct Node *nodePtr = (struct Node *)malloc(sizeof(struct Node));
    nodePtr->attribute = attribute;
    nodePtr->next = list->head;
    nodePtr->prev = NULL;

    if (list->head)
    {
        list->head->prev = nodePtr;
    }
    list->head = nodePtr;
};

struct Node *search(DoublyLinkedList *list, int attribute)
{
    struct Node *x;
    x = list->head;

    while (x && x->attribute != attribute)
    {
        if (x->next)
        {
            x = x->next;
        }
        else
        {
            x->attribute = 0;
            return x;
        }
    }
    return x;
}

void insert(Node *newNode, Node *targetNode)
{
    newNode->next = targetNode->next;
    newNode->prev = targetNode;

    if (targetNode->prev)
    {
        targetNode->next->prev = newNode;
    }

    targetNode->next = newNode;
}

void delete(DoublyLinkedList *list, Node *targetNode)
{
    if (targetNode->prev) {
        targetNode->prev->next = targetNode->next;
    } else {
        list->head = targetNode->next;
    }

    if (targetNode->next)
    {
        targetNode->next->prev = targetNode->prev;
    }

    
}

int main()
{
    DoublyLinkedList list;
    list = Make_List();

    prepend(&list, 6);
   

    struct Node *node;
    struct Node *newNode;
    newNode->attribute = 25;
    node = search(&list, 10);

    if (node->attribute)
    {
        printf("Found node: %d\n", node->attribute);
    }
    else
    {
        printf("Found No node :(\n");
    }

    insert(newNode, node);

    node = search(&list, 25);

    if (node->attribute)
    {
        printf("Found node: %d\n", node->attribute);
    }
    else
    {
        printf("Found No node :(\n");
    }

    delete(&list, node);

    node = search(&list, 25);


    if (node->attribute)
    {
        printf("Found node: %d\n", node->attribute);
    }
    else
    {
        printf("Found No node :(\n");
    }


    EXIT_SUCCESS;
}