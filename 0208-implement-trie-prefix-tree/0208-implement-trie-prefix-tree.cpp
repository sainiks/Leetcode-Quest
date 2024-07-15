class TrieNode{
public:
    char c;
    bool end;
    unordered_map<char,TrieNode*>childmap;
    TrieNode(char c){
        this->c=c;
        this->end=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('#');
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(auto c :word){
            if(cur->childmap.find(c)==cur->childmap.end()){
                TrieNode* x=new TrieNode(c);
                cur->childmap[c]=x;
            }
            cur=cur->childmap[c];
        }
        cur->end=true;
    }
    
    bool search(string word) {
        TrieNode* cur= root;
        for(auto c : word){
            if(cur->childmap.find(c)==cur->childmap.end()){
                return false;
            }
            cur=cur->childmap[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur= root;
        for(auto c : prefix){
            if(cur->childmap.find(c)==cur->childmap.end()){
                return false;
            }
            cur=cur->childmap[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */