#include <iostream>
using namespace std;
struct Node {
  int key;
  struct Node *left, *right;
};
int depth(Node *node) {
  int d = 0;
  while (node != NULL) {
    d++;
    node = node->left;
  }
  return d;
}
bool isPerfectR(struct Node *root, int d, int level = 0) {
  if (root == NULL)
    return true;

  if (root->left == NULL && root->right == NULL)
    return (d == level + 1);

  if (root->left == NULL || root->right == NULL)
    return false;

  return isPerfectR(root->left, d, level + 1) &&
       isPerfectR(root->right, d, level + 1);
}

bool isPerfect(Node *root) {
  int d = depth(root);
  return isPerfectR(root, d);
}

struct Node *newNode(int k) {
  struct Node *node = new Node;
  node->key = k;
  node->right = node->left = NULL;
  return node;
}

int main() {
  struct Node *root = NULL;
  root = newNode(8);
  root->left = newNode(10);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(2);
  root->right->left = newNode(17);
  root->right->right = newNode(7);

  if (isPerfect(root))
    cout << "Perfect Binary Tree Found\n";
  else
    cout << "Perfect Binary Tree not Found\n";
}
