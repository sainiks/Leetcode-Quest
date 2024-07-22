/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:
    Node* dfs(Node* rnode,unordered_map<Node*, Node*>&nodemap){
        if(rnode ==NULL){
            return NULL;
        }
        Node* cnode = new  Node(rnode->val);
        nodemap[rnode]=cnode;
        for(auto u:rnode->neighbors){
            if(nodemap.find(u)==nodemap.end()){
                Node* x =dfs(u,nodemap);
                cnode->neighbors.push_back(x);
            }else{
                Node* x=nodemap[u];
                cnode->neighbors.push_back(x);
            }
        }
        return cnode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>nodemap;
        Node* ans=dfs(node,nodemap);
        return ans;
    }
};