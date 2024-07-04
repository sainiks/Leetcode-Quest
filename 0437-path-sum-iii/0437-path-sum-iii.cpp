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
    int findtarget(TreeNode* root, long sum,int target){
        if(root==NULL){
            return 0;
        }
        int cnt=0;
        sum+=root->val;
        if(sum==target){
            cnt++;
        }
        cnt+=findtarget(root->left,sum,target);
        cnt+=findtarget(root->right,sum,target);
        return cnt;
    }
    int dfs(TreeNode* root,int target){
        if(root==NULL)return 0;
        int ans=0;
        ans+=findtarget(root,0,target);
        ans+=dfs(root->left,target);
        ans+=dfs(root->right,target);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=dfs(root,targetSum);
        return ans;
    }
};