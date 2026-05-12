#include <stdio.h>
#include "visualize.h"

void print_list(Node *head) {
    Node *current = head;
    printf("\nList: ");
    while (current != NULL) {
        printf("[%d] -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void print_memory_map(Node *head) {
    Node *current = head;
    int index = 0;

    printf("\n--- Memory Map ---\n");
    printf("%-6s %-18s %-10s %-18s\n", "Node", "Address", "Value", "Next points to");
    printf("---------------------------------------------------\n");

    while (current != NULL) {
        printf("%-6d %-18p %-10d %-18p\n",
               index,
               (void*)current,
               current->value,
               (void*)current->next);
        current = current->next;
        index++;
    }
    printf("---------------------------------------------------\n");
}


