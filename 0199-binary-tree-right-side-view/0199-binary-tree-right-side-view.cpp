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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        while(q.size()>0){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL){
                if(!q.empty())
                    q.push(NULL);
                    continue;
            }
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            if(q.front()==NULL){
                ans.push_back(cur->val);
            }
        }  
        return ans;      
    }
};