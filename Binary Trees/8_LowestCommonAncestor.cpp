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
void solve(TreeNode* root,vector<TreeNode*>& path,TreeNode* val,bool& ans){
    if(!root || ans)return;
    if(root==val){
        path.push_back(root);
        ans = true;
    }
    if(ans) return;
    path.push_back(root);
    solve(root->left,path,val,ans);
    if(ans) return;
    solve(root->right,path,val,ans);
    if(ans) return;
    path.pop_back();
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> a;
    vector<TreeNode*> b;
    bool check = false;
    solve(root,a,p,check);
    check = false;
    solve(root,b,q,check);
    int n = a.size();
    int m = b.size();
    n = min(n,m);
    TreeNode* ans;
    for(int i = 0;i<n;i++) if(a[i]==b[i]) ans = a[i]; else break;
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
    cout << lowestCommonAncestor(&root,&d,&b)->val;
}