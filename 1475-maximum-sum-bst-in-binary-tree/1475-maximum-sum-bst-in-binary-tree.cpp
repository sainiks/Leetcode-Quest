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
    int findsmallest(TreeNode* root){
        if(root->left==NULL)return root->val;
        return findsmallest(root->left);
    }
    int findgreatest(TreeNode* root){
        if(root->right==NULL)return root->val;
        return findgreatest(root->right);
    }
    int sumBST(TreeNode* root,int& ans ){
        if(root==NULL){
            return 0;
        }
        int l=sumBST(root->left,ans);
        int r=sumBST(root->right,ans);
        if(l==-2e9 or r==-2e9){
            return -2e9;
        }
        int mn=-1e9,mx=1e9;
        if(root->left){
            mn=findgreatest(root->left);
        }
        if(root->right){
            mx=findsmallest(root->right);
        }
        if(root->val>mn and root->val<mx){
            ans=max(ans,l+r+root->val);
            return l+r+root->val;
        }
        return -2e9;
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        sumBST(root,ans);
        return ans;

    }
};