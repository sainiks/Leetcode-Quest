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
    int findgreatest(TreeNode* root){
        if(root->right==NULL){
            return root->val;
        }
        return findgreatest(root->right);
    }
    int findsmallest(TreeNode* root){
        if(root->left==NULL){
            return root->val;
        }
        return findsmallest(root->left);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool ans=true;
        if(root->left)
            ans&=isValidBST(root->left);
        if(root->right)
            ans&=isValidBST(root->right);
        if (root->left and findgreatest(root->left)>=root->val)ans=false;
        if (root-> right and findsmallest(root->right)<=root->val)ans=false;
        return ans;   
    }
};