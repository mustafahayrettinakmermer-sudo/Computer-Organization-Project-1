#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *insert_front(Node *head, int value);
Node *insert_back(Node *head, int value);
Node *delete_node(Node *head, int value);
void free_list(Node *head);

#endif
