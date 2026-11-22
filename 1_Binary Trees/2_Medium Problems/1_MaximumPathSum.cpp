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
// This is my attempt by checking level order traversal of the tree from left and right there are better ways
int depth(TreeNode* root, int&ans){
    if(!root) return 0;
    int left = depth(root->left,ans);
    int right = depth(root->right,ans);
    int curr = max({root->val,left+root->val,right+root->val});
    ans = max({ans,curr,left+right+root->val});
    return curr;
}
int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
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
    int a = maxPathSum(&root);
    cout << a;
}