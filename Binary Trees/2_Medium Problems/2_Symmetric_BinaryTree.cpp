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

    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    void TraverseLeft(TreeNode* root,int level,vector<vector<int>>& ans,int& n){
        if(level>n) return;
        if(root) ans[level].push_back(root->val);
        else ans[level].push_back(1000);
        if(root) TraverseLeft(root->left,level+1,ans,n); 
        if(root) TraverseLeft(root->right,level+1,ans,n); 
        return;
    }
    void TraverseRight(TreeNode* root,int level,vector<vector<int>>& ans,int& n){
        if(level>n) return;
        if(root) ans[level].push_back(root->val);
        else ans[level].push_back(1000);
        if(root) TraverseRight(root->right,level+1,ans,n); 
        if(root) TraverseRight(root->left,level+1,ans,n); 
        return;
    }
    bool isSymmetric(TreeNode* root) {
        int n = depth(root);
        vector<vector<int>> right(n+1);
        vector<vector<int>> left(n+1);
        TraverseLeft(root,0,left,n);
        TraverseRight(root,0,right,n);
        return left==right;
    }
    int main(){
    TreeNode b(20);
    TreeNode c(30);
    TreeNode root(10);
    TreeNode d(40);
    root.left=&b;
    root.right=&c;
    c.left = &d;
    return 0;
}
    