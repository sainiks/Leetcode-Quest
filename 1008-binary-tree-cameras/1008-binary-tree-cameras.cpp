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
    int dfs(TreeNode* root,TreeNode* parent,set<TreeNode*>&st){
        if(root!= NULL and root->right==NULL and root->left==NULL and parent==NULL){
            return 1;
        }
        if(root==NULL or (root->left==NULL and root->right==NULL)){
            return 0;
        }
        int ans =0;
        ans+=dfs(root->left,root,st);
        ans+=dfs(root->right,root,st);
        if(st.count(root->left)==0 or st.count(root->right)==0){
            st.insert(root->left);
            st.insert(root->right);
            st.insert(root);
            st.insert(parent);  
            ans++;
        }
        else if(st.count(root)==0 and parent==NULL){
                st.insert(root);
                ans++;
            }
            return ans;
        }
    int minCameraCover(TreeNode* root){
        set<TreeNode*>st;
        st.insert(NULL);
        return dfs(root,NULL,st);
    }
};