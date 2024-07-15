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
    string dfs(TreeNode* root,unordered_map<string,int>&mp,vector<TreeNode*>&v){
        if(root==NULL)return "[-1]";
        string ans="[";
        ans+=dfs(root->left,mp,v);
        ans+=to_string(root->val);
        ans+=dfs(root->right,mp,v);
        ans+="]";
        cout<<root->val<<" "<<ans<<endl;
        if(mp.find(ans)==mp.end()){
            mp[ans]=root->val;
        }else if(mp[ans]!=-1e9){
            v.push_back(root);
            mp[ans]=-1e9;
        }
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>v;
        unordered_map<string,int>mp;
        dfs(root,mp,v);
        return v;
    }
};