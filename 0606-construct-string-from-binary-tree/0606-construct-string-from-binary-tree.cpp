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
    void dfs(TreeNode* root, string& ans){
        if(root->val>=0){
            ans+=to_string(root->val);
        }
        else{
            ans+='-';
            ans+=to_string(abs(root->val));
        }
        if(root->left){
            ans+='(';
            dfs(root->left,ans);
            ans+=')';
        }
        if(root->right){
            if(root->left==NULL){
                ans+='(';
                ans+=')';
            }
        }
        if(root->right){
            ans+='(';
            dfs(root->right,ans);
            ans+=')';
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        if(root!=NULL){
            dfs(root,ans);
        }
        return ans;   
    }
};