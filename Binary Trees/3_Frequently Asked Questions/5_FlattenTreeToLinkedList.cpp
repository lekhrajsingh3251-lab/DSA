#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    void traverse(TreeNode* root, TreeNode*& curr) {
        if (!root) return;
        curr->right = new TreeNode(root->val);
        curr = curr->right;
        traverse(root->left, curr);
        traverse(root->right, curr);
    }
    // This was made with O(n) space complexity by making a extra tree but it can be done with O(1)
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode dummy(0);
        TreeNode* curr = &dummy;
        traverse(root, curr);
        root->left = nullptr;
        root->right = dummy.right->right;
    }
    // Space optimal O(1) code for flattening
    void Optimal_flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree (pre-order predecessor of curr->right)
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                // Wire the original right subtree to the end of the left subtree
                prev->right = curr->right;
                // Move the left subtree to the right and clear left
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Advance down the flattened right chain
            curr = curr->right;
        }
    }
 int main(){
    TreeNode b(20);
    TreeNode c(30);
    TreeNode root(10);
    TreeNode d(40);
    root.left=&b;
    root.right=&c;
    c.left = &d;
    flatten(&root);
    while(&root){
        cout<< root.val<< " ";
        root = *root.right;
    }
}