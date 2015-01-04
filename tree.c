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

struct Node * add(int number, struct Node * current) {
    if (current == NULL) {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node -> element = number;
        new_node -> right = NULL;
        new_node -> left = NULL;
        return new_node;
    }
    if (current -> left == NULL) {
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

void preorder(struct Node *root){
    printf("%d \n",root->element);
    if(root->left !=NULL)preorder(root->left);
    if(root->right !=NULL)preorder(root->right);
}
void postorder(struct Node *root)
{
    if(root->left !=NULL)postorder(root->left);
    if(root->right!=NULL) postorder(root->right);
    printf("%d\n",root->element);
}
int main() {
    root = bst_add(4, root);
    root = bst_add(5, root);
    root = bst_add(1, root);
    //root = add(2, root);
    //root = add(7, root);
    postorder(root);
}
