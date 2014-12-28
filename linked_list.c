#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node * next;
};

struct Node * head = NULL;

void add(int element) {
    struct Node * new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> number = element;
    if (head == NULL) {
        new_node -> next = NULL;
        head = new_node;
    }
    else {
        new_node -> next = head;
        head = new_node;
    }
}

void print(struct Node * head) {
    while(head != NULL) {
        printf("%d\n", head -> number);
        head = head -> next;
    }
}

int main() {
    add(10);
    add(15);
    add(20);
    add(25);

    print(head);
    return 0;
}
