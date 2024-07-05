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
    int dfs(TreeNode* root,int& moves){
        if(root==NULL)return 0;
        int coins=root->val;
        int l=dfs(root->left,moves);
        int r=dfs(root->right,moves);
        moves+=abs(l)+abs(r);
        coins+=l+r;
        return coins-1;
    }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        dfs(root,moves);
        return moves;
    }
};