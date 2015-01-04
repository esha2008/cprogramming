#include <stdio.h>
#include <stdlib.h>

struct Node {
    int element;
    struct Node *left;
    struct Node *right;
};

struct Node * root = NULL;

struct Node * add(int number, struct Node * current) {
    if (current == NULL) {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node -> element = number;
        new_node -> right = NULL;
        new_node -> left = NULL;
        return new_node;
    }
    if (number < current -> element) {
        current -> left = add(number, current -> left);
    }
    else {
        current -> right = add(number, current -> right);
    }
    return current;
}

void in_order(struct Node *root) {
    if (root -> left != NULL) in_order(root -> left);
    printf("%d\n", root -> element);
    if (root -> right != NULL) in_order(root -> right);
}

int main() {
    root = add(4, root);
    root = add(5, root);
    root = add(3, root);
    root = add(1, root);
    root = add(7, root);
    in_order(root);
}
