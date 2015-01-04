#include <stdio.h>
#include <stdlib.h>

struct Node {
    int element;
    struct Node *left;
    struct Node *right;
};

struct Node * root = NULL;

struct Node * bst_add(int number, struct Node * current) {
    if (current == NULL) {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node -> element = number;
        new_node -> right = NULL;
        new_node -> left = NULL;
        return new_node;
    }
    if (number < current -> element) {
        current -> left = bst_add(number, current -> left);
    }
    else {
        current -> right = bst_add(number, current -> right);
    }
    return current;
}

void in_order(struct Node *root) {
    if (root -> left != NULL) in_order(root -> left);
    printf("%d\n", root -> element);
    if (root -> right != NULL) in_order(root -> right);
}

int main() {
    root = bst_add(4, root);
    root = bst_add(5, root);
    root = bst_add(3, root);
    root = bst_add(1, root);
    root = bst_add(7, root);
    in_order(root);
}
