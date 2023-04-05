#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void print_list(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_node(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int main() {
    struct Node* head = NULL;

    insert_node(&head, 5);
    insert_node(&head, 3);
    insert_node(&head, 8);
    insert_node(&head, 2);

    print_list(head);

    return 0;
}
