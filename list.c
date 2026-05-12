#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *insert_front(Node *head, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = head;
    return new_node;
}
Node *insert_back(Node *head, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

Node *delete_node(Node *head, int value) {
    if (head == NULL) {
        return NULL;
    }

    if (head->value == value) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *current = head;
    while (current->next != NULL) {
        if (current->next->value == value) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }
        current = current->next;
    }

    return head;
}

void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;

    }
    
}

