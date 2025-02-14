/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // Node* connect(Node* root) {        
    //     if(root){
    //         queue<Node*>q;  
    //         Node* temp=NULL;          
    //         q.push(root);
    //         int cnt=1,i,j;
    //         while(q.size()>0){
    //             for(i=0;i<cnt;i++){
    //                 temp=q.pop();
    //                 if(i==0){
    //                     for(j=0;j<q.size()-1;j++){
    //                         q[j]->next=q[j+1];
    //                     }
    //                 }                   
    //                 q[j]->next=NULL;
    //                 if(temp->left)q.push(temp->left);
    //                 if(temp->right)q.push(temp->right);
    //             }
    //             cnt*=2;
    //         }
    //         return root;
    //     }
    //     else return root;
    // }
      void queueTraverse(Node* temp){
        queue<Node*> q;
        q.push(temp);
        while(q.size()>0){
            int size=q.size();
            for(int i=1;i<=size;i++){
                Node* nn=q.front();
                q.pop();
                if(i<size){
                    nn->next=q.front();
                }
                if(nn->left) q.push(nn->left);
                if(nn->right) q.push(nn->right);
            }
        }

    }
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queueTraverse(root);
        return root;
    }
};