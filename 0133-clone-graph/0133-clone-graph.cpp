class Solution {
public:
    map<Node*, Node*> mp; 
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL; 
        }        
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);    
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();            
            for (Node* neighbor : current->neighbors) {
                if (mp.find(neighbor) == mp.end()) { 
                    mp[neighbor] = new Node(neighbor->val); 
                    q.push(neighbor);
                }                
                mp[current]->neighbors.push_back(mp[neighbor]);
            }
        }
        return mp[node]; 
    }
};
// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// */

// class Solution {
// public:
//     vector<Node*>con;
//     unordered_map<int,bool>ump;
//     void intialise(){        
//         Node *t=new Node();
//         con.resize(100,t);
//         for(int i=1;i<101;i++){
//             t=new Node(i);
//             con[i]=t;
//         }
//     }
//     void recuu(Node* n){
//         int val=n->val;
//         if(ump[val])return ;
//         ump[val]=true;
//         for(int i=0;i<(n->neighbors).size();i++){
//             int neighVal=((n->neighbors)[i])->val;
//             (con[val]->neighbors).push_back(con[neighVal]);            
//             recuu((n->neighbors)[i]);
//         }        
//     }
//     Node* cloneGraph(Node* node) {
//         intialise();
//         recuu(node);
//         return con[1];
//     }
// };