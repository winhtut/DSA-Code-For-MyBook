#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
void postorder(struct Node* node) {
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << "->";
}

void inorder(struct Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << "->";
    inorder(node->right);
}
void preorder(struct Node* node) {
    if (node == NULL)
        return;

    cout << node->data << "->";
    preorder(node->left);
    preorder(node->right);
}
int main() {
    struct Node *root = new Node(8);
    root->left = new Node(10);
    root->right = new Node(3);
    root->right->left = new Node(17);
    root->left->left = new Node(4);
    root->left->right = new Node(2);

    cout << "Inorder traversal ";
    inorder(root);

    cout << "\nPreorder traversal ";
    preorder(root);

    cout << "\nPostorder traversal ";
    postorder(root);

}

/* 
Inorder traversal 4->10->2->8->17->3->
Preorder traversal 8->10->4->2->3->17->
Postorder traversal 4->2->10->17->3->8->
*/
