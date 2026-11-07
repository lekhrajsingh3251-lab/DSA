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
void traverse(TreeNode* root,vector<vector<int>>& ans,vector<int>& curr){
    if(!root) return;
    curr.push_back(root->val);
    if(!root->right && !root->left) ans.push_back(curr);
    traverse(root->left,ans,curr);
    traverse(root->right,ans,curr);
    curr.pop_back();
}
vector<vector<int>> allRootToLeaf(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> curr;
    traverse(root,ans,curr);
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
    a = allRootToLeaf(&root);
    for(vector<int> x : a){
        for(int i : x) cout<< i<< " ";
        cout<< "\n";
    }
}