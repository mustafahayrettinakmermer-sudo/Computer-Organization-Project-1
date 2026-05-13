// bugs.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bugs.h"

void demo_use_after_free() {

    printf("\n=============================");
    printf("\n   BUG 1: USE AFTER FREE     ");
    printf("\n=============================\n");

    Node *node = malloc(sizeof(Node));
    node->value = 42;
    node->next = NULL;

    printf("\nAllocated node at: %p\n", (void*)node);
    printf("Value before free: %d\n", node->value);

    free(node);
    printf("\nMemory freed.\n");

    printf("\nAccessing node->value AFTER free: %d\n",
           node->value);

}

void demo_memory_leak() {

    printf("\n=============================");
    printf("\n   BUG 2: MEMORY LEAK        ");
    printf("\n=============================\n");

    Node *head = NULL;

    head = insert_front(head, 1);
    head = insert_front(head, 2);
    head = insert_front(head, 3);

    printf("\nBuilt a list of 3 nodes.\n");
    printf("Node addresses:\n");

    Node *current = head;
    while (current != NULL) {
        printf("  %p\n", (void*)current);
        current = current->next;
    }

    free_list(head);
}