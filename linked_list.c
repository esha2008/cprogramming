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

// Search. Return position  from head if present. Return -1 otherwise.
int search(int element) {
    int c=1;
    while(head!=NULL)
    {

        if(head-> number == element)
        {
            return (c);

        }
        else{
            c++;
            head=head->next;
        }
    }
    return(-1);
}


/* Remove an element from LinkedList. 
 * If empty list, return -2.
 * If element not found, return -1.
 * If element found, remove it, and return 0. In your main program, print the list before and after removal
 */

int remove_element(int element) {
    if(head==NULL) 
        return (-2);

    // Case 1: Element found as the first element
    if (head -> number == element) {
        head = head -> next;
        return 0;
    }

    // Case 2: Element found in the middle of list
    struct Node * current = head;
    while(current -> next != NULL) {
        if (current -> next -> number == element) {
            current -> next = current -> next -> next;
            return 0;
        }
        current = current -> next;
    }

    // Case 3: Element found at the end
    if (current -> number == element) {
        current = NULL;
        return 0;
    }

    return -1;
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

    printf("Original List \n");
    print(head);

    remove_element(15);

    printf("List after removal \n");
    print(head);

    return 0;
}
