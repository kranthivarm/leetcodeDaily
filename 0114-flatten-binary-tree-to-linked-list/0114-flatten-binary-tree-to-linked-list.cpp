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
    TreeNode* per;
public:    
void recuu(TreeNode* per){
    if(per){
        cout<<per->val;
        recuu(per->right);
    }
}
    TreeNode* ll(TreeNode* temp){
        // recuu(per);
        // cout<<endl;
        if(temp){
            // cout<<temp->val<<endl;
            if(!(temp->left) && !(temp ->right))return temp;
            if(!(temp->left)){
                return ll(temp->right);
            }
            TreeNode* r=temp->right;
            temp->right=temp->left;
            temp->left=NULL;
            TreeNode* t=ll(temp->right);//templeft sent for recuu
            if(t){
                if(r){
                    t->right=r;
                    return ll(t->right);                        
                }
                else return t;
            }
            return t;
        }    
        return NULL;
    }
    void flatten(TreeNode* root) { 
        per=root;              
        if(!root)return ;
        TreeNode* t=ll(root);        
    }
};