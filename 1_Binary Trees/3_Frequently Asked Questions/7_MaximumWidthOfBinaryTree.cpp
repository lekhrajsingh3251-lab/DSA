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
        return max(depth(root->right),depth(root->left))+1;
    }
    void traverse(TreeNode* root,int level,vector<vector<long long>>& store,long long pos){
        if(!root) return;
        store[level].push_back(pos);
        long long normalized_pos = pos - store[level][0];
        traverse(root->left,level+1,store,normalized_pos*2);
        traverse(root->right,level+1,store,(normalized_pos*2)+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int n = depth(root);
        vector<vector<long long>> store(n+1);
        long long ans = 1;
        traverse(root,0,store,0);
        for(vector<long long> a : store){
            if(a.size()>1) ans = max(ans,a.back()-a.front()+1);
        }
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
    cout << widthOfBinaryTree(&root);
}