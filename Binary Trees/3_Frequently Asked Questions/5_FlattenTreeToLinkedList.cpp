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