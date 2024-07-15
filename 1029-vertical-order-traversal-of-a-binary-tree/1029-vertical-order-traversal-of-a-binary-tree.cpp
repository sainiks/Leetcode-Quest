/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,unordered_map<int,vector<pair<int,int>>>& mp,int col,int row ,int& l ,int& r){
        if(root==NULL)return;
        mp[col].push_back({row,root->val});
        l=min(l,col);
        r=max(r,col);
        dfs(root->left,mp,col-1,row+1,l,r);
        dfs(root->right,mp,col+1,row+1,l,r);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>>mp;
        int l=0,r=0;
        dfs(root,mp,0,0,l,r);
        vector<vector<int>>ans;
        for(int i=l; i<=r; i++){
            vector<pair<int,int>>c=mp[i];
            sort(c.begin(),c.end());
            vector<int>v;
            for(auto u:c){
                v.push_back(u.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};