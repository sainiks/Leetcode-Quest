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
    pair<int , int> dfs(TreeNode* root){
        if(root==NULL){
            return{0,0};
        }
        int withoutchild =0,withchild=0,leftmax=0,rightmax=0;
        if(root->left){
            auto leftans = dfs(root->left);
            withchild+=leftans.first;        
            withoutchild+=leftans.second;  
            leftmax=max(leftans.first,leftans.second);      
        }
        if(root->right){
            auto rightans = dfs(root->right);
            withchild+=rightans.first;        
            withoutchild+=rightans.second;     
            rightmax=max(rightans.first,rightans.second);    
        }
        int withroot=0,withoutroot=0;
        withroot=root->val+withoutchild;
        withoutroot=leftmax+rightmax;
        return{withroot,withoutroot};
    }
    int rob(TreeNode* root) {
        auto ans=dfs(root);
        return max(ans.first,ans.second);
    }
};