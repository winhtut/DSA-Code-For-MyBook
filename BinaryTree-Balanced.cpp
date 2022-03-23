#include <stdio.h>
#include <stdlib.h>
#define bool int
struct node {
    int item;
    struct node *left;
    struct node *right;
};
struct node *newNode(int item) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

bool balanceChecking(struct node *root, int *height) {
    int leftHeight = 0, rightHeight = 0;
    int l = 0, r = 0;

    if (root == NULL) {
        *height = 0;
        return 1;
    }

    l = balanceChecking(root->left, &leftHeight);
    r = balanceChecking(root->right, &rightHeight);
    // calculate height if we got right and left height
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
 // checking our balanced factor if we got two or that is unbalanced
    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
        return 0;

    else
        return l && r;
}

int main() {
    int height = 0;

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
    int data=balanceChecking(root, &height);
    if (data)
        printf("Balanced tree was found! ");
    else
        printf("Balanced tree was not found!");
}
