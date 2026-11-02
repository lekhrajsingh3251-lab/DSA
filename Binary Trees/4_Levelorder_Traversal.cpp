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
// This was my attempt there is a better way with queue
int depth(TreeNode* root){
    if(!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}
void traverse(TreeNode* root,int level,vector<vector<int>>& ans){
    if(!root)return;
    ans[level].push_back(root->val);
    traverse(root->left,level+1,ans);
    traverse(root->right,level+1,ans);
}
vector<vector<int>> LevelorderTraversal(TreeNode* root){
    int n = depth(root);
    vector<vector<int>> ans(n);
    traverse(root,0,ans);
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
    vector<vector<int>> a;
    a = LevelorderTraversal(&root);
    for(vector<int> x : a) for(int i : x) cout<< i<< " ";
}
