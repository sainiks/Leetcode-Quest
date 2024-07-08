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
        if(root->left==NULL){
            return root->val;
        }
        return findsmallest(root->left);
    }
    int findgreatest(TreeNode* root){
        if(root->right==NULL){
            return root->val;
        }
        return findgreatest(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL and root->right==NULL){
                return NULL;
            }
            if(root->left==NULL or root->right==NULL){
                TreeNode* temp;
                if(root->left){
                    int x=findgreatest(root->left);
                    root->val=x;
                    root->left=deleteNode(root->left,x);
                    return root;
                }
                if(root->right){
                    int x=findsmallest(root->right);
                    root->val=x;
                    root->right=deleteNode(root->right,x);
                    return root;
                }
            }
            int x=findsmallest(root->right);
            root->val=x;
            root->right=deleteNode(root->right,x);
        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};