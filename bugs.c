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

    printf("\nExplanation:\n");
    printf("- node still holds the old address\n");
    printf("- but that memory belongs to allocator now\n");
    printf("- reading it is undefined behavior\n");
    printf("- value might look ok, might be garbage\n");
    printf("- Valgrind will catch this exactly\n");
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

    printf("\nFunction returns WITHOUT calling free_list.\n");
    printf("All 3 nodes are now leaked.\n");
    printf("Valgrind will report exactly 3 lost blocks.\n");

    // deliberately NOT calling free_list(head)
    free_list(head);
    printf("Fixed: free_list called. No leaks. \n");
}