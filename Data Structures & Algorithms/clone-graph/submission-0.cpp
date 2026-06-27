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
    Node* cloneGraph(Node* node) {

        if(!node) return nullptr;

        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> mp;

        mp[node] = new Node(node->val);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(auto x : curr->neighbors){
                if(!mp.count(x)){
                    mp[x] = new Node(x->val);
                    q.push(x);
                }

                mp[curr]->neighbors.push_back(mp[x]);
            }
        }

        return mp[node];
    }
};
