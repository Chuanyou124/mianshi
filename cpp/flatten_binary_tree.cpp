#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *flattenRT(TreeNode *root) {
    TreeNode *right = root->right;
    if (root->left) {
        root->right = root->left;
        TreeNode *leftRightMost = flattenRT(root->right);
        leftRightMost->right = right;
        if(right) {
            return flattenRT(right);
        }
        return root;
    }
    if (right) {
        return flattenRT(right);
    }
    return root;
}

void flatten(TreeNode *root) {
    if (!root) {
        return;
    }
    TreeNode *x = flattenRT(root);
}

void printTree(TreeNode *r) {
    if (!r) {
        return;
    }
    cout << r->val << "->";
    printTree(r->left);
    printTree(r->right);
}

int main() {
    TreeNode *r = new TreeNode(1);
    TreeNode *rr = new TreeNode(2);
    r->right = rr;

    flatten(r);
    printTree(r);

    return 0;
}
