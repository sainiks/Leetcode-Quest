class TrieNode{
public:
    TrieNode* left;
    TrieNode* right;
    TrieNode(){
        this->right=NULL;
        this->left=NULL;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        this->root =new TrieNode();
    }

    void insert(int x ){
        TrieNode* cur = this->root;
        for(int i=31;i>=0;i--){
            if((x>>i)&1){
                if(cur->right==NULL){
                    cur->right = new TrieNode();
                }
                cur = cur->right;
            }else{
                if(cur->left==NULL){
                    cur->left = new TrieNode();
                }
                cur = cur->left;
            }
        }
    }
    int maxXor(int x ){
        int ans =0;
        TrieNode* cur=root;
        for(int i=31; i>=0;i--){
            if((x>>i)&1){
                if(cur->left){
                    ans+=(1<<i);
                    cur=cur->left;
                }else{
                    cur = cur->right;
                }
            }else{
                if(cur->right){
                    ans+=(1<<i);
                    cur=cur->right;
                }else{
                    cur=cur->left;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t ;
        for(int i=0; i<nums.size();i++){
            t.insert(nums[i]);
        }
        int ans =0;
        for(int i =0; i<nums.size();i++){
            ans=max(ans,t.maxXor(nums[i]));
        }
        return ans;
    }
};