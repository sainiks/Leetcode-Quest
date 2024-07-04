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
    void dfs(TreeNode* root,vector<int>& path , vector<vector<int>>&ans, int sum,int t){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL){
            if(sum==t){
                ans.push_back(path);
            }
            path.pop_back();
            sum+=root->val;
            return;
        }
        dfs(root->left,path,ans,sum,t);
        dfs(root->right,path,ans,sum,t);
        sum-=root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    
    vector<vector<int>>ans;
    vector<int>path;
    dfs(root,path,ans,0,targetSum);
    return ans;
    }
};