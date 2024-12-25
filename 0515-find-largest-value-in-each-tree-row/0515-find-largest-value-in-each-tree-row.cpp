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
    vector<int>res;    
    void fun(TreeNode *root,int cnt){
        if(root){
            fun(root->left,cnt+1);
            if(res.size()<cnt+1)res.push_back(root->val);
            if(res[cnt]<root->val)res[cnt]=root->val;
            fun(root->right,cnt+1);
            if(res.size()<cnt+1)res.push_back(root->val);
            if(res[cnt]<root->val)res[cnt]=root->val;
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        // if(root==NULL)return res;
        // fun(root,0);
        // return res;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        int ma=root->val;
        TreeNode* en=NULL;
        if(root->left){
            en=root->left;
        }
        else if(root->right){
            en=root->right;
        }        
        while(!q.empty()){
            // cout<<en->val;
            TreeNode *t=q.front();
            q.pop();
            // cout<<t->val;
            if(en==t){ 
                cout<<t->val;  
                ans.push_back(ma);
                ma=t->val;
                en=NULL;
            }
            if(en==NULL){//en==NULL;                
                if(t->left)en=t->left;
                else if(t->right)en=t->right;                
            }
            ma=max(ma,t->val);
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        ans.push_back(ma);
        return ans;
    }
};