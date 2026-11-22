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
    int depth (TreeNode* root,bool& ans){
        if(!root) return 0;
        int left = depth(root->left,ans);
        int right = depth(root->right,ans);
        ans = ans && abs(left-right)<=1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        bool ans = true;
        depth(root,ans);
        return ans;
    }
int main(){
    TreeNode b(20);
    TreeNode c(30);
    TreeNode root(10);
    TreeNode d(40);
    root.left=&b;
    root.right=&c;
    c.left = &d;
    cout << isBalanced(&root);
}