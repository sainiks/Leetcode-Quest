/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,TreeNode* p ,TreeNode* q,TreeNode*& ans){
        if(root==NULL){
            return 0;
        }
        int cnt=0;
        if(root==p or root==q){
            cnt++;
        }
        cnt+=dfs(root->left,p,q,ans);
        cnt+=dfs(root->right,p,q,ans);
        if(cnt==2 and ans==NULL){
            ans=root;
        }
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        dfs(root,p,q,ans);
        return ans;
    }
};