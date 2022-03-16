#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *newNode(char k) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
// node အရေအတွက်ကို အရင်ဆုံး ရေတွက်ရန် nodes ဆိုတဲ့ function ကိုရေးထားပါတယ်။
int nodes(struct Node *root) {
    if (root == NULL)
        return (0);

    return (1 + nodes(root->left)+ nodes(root->right));
}

bool checkComplete(struct Node *root, int index, int numberNodes) {

    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) &&
        checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main() {
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    int numNodes = nodes(root);
    int index = 0;

    if (checkComplete(root, index, numNodes))
        cout << "Complete Binary Tree Found \n";
    else
        cout << "Complete Binary Tree not Found\n";
}



