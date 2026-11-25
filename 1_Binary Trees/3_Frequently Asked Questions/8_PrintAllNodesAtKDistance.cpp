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
    void traverse(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp){
        if(!root) return;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        traverse(root->left,mp);
        traverse(root->right,mp);
    }
    void solve(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp,int k,vector<int>& ans,TreeNode* last){
        if(!root) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(mp[root]!= last) solve(mp[root],mp,k-1,ans,root);
        if(root->right!=last) solve(root->right,mp,k-1,ans,root);
        if(root->left!=last) solve(root->left,mp,k-1,ans,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root] = nullptr;
        traverse(root,mp);
        solve(target,mp,k,ans,nullptr);
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
    vector<int> show = distanceK(&root,&c,1);
    for(int x : show) cout << x << " ";

}