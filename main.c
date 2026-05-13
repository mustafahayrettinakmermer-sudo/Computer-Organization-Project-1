
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "visualize.h"
#include "bugs.h"

int main() {

    Node *head = NULL;


    printf("\n=============================");
    printf("\n   ACT 1: BUILDING THE LIST  ");
    printf("\n=============================\n");

    printf("\n>> insert_back 10\n");
    head = insert_back(head, 10);
    print_list(head);
    print_memory_map(head);

    printf("\n>> insert_back 20\n");
    head = insert_back(head, 20);
    print_list(head);
    print_memory_map(head);

    printf("\n>> insert_back 30\n");
    head = insert_back(head, 30);
    print_list(head);
    print_memory_map(head);

    printf("\n>> insert_front 5\n");
    head = insert_front(head, 5);
    print_list(head);
    print_memory_map(head);



    printf("\n=============================");
    printf("\n   ACT 2: DELETING A NODE    ");
    printf("\n=============================\n");

    printf("\n>> delete_node 20\n");
    head = delete_node(head, 20);
    print_list(head);
    print_memory_map(head);



    printf("\n=============================");
    printf("\n   ACT 3: FREEING MEMORY     ");
    printf("\n=============================\n");

    printf("\nCalling free_list...\n");
    free_list(head);
    printf("All nodes freed.\n");

    printf("\n=============================");
    printf("\n   ACT 4: BUG DEMOS          ");
    printf("\n=============================\n");

    demo_use_after_free();
    demo_memory_leak();

    return 0;
}