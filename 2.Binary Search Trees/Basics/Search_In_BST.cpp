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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root->val == val) return root;
        TreeNode* left = searchBST(root->left,val);
        TreeNode* right = searchBST(root->right,val);
        if(left) return left;
        if(right) return right;
        return left;
    }
int main(){
    TreeNode b(20);
    TreeNode c(30);
    TreeNode root(10);
    TreeNode d(40);
    root.left=&b;
    root.right=&c;
    c.left = &d;
    cout << searchBST(&root,10)->val;
}