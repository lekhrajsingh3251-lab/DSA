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

void traverse (TreeNode *root,vector<int> &a){
    if (root == nullptr) return;
    if(root->left)traverse(root->left,a);
    a.emplace_back(root->val);
    if(root->right)traverse(root->right,a);
    }

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> a;
    traverse(root,a);
    return a;
}

int main(){
    TreeNode b(20);
    TreeNode c(30);
    TreeNode root(10);
    TreeNode d(40);
    root.left=&b;
    root.right=&c;
    c.left = &d;
    vector<int> a;
    a = inorderTraversal(&root);
    for(int x : a) cout << x << " ";
}
