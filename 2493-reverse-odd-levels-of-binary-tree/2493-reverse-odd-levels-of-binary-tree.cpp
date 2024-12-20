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
    void recursion(TreeNode* root,int i,vector<vector<int>>&con,vector<int>&cnt,bool ptr){
        if(root){
            if(ptr){
                if(con.size()<=i)con.push_back({});
                con[i].push_back(root->val);
                recursion(root->left,i+1,con,cnt,ptr);
                recursion(root->right,i+1,con,cnt,ptr);
                return;
            }
            if(i%2){
                int n=con[i].size();
                root->val=con[i][n-cnt[i]-1];
            }
            
            cnt[i]++;
            recursion(root->left,i+1,con,cnt,ptr);
            recursion(root->right,i+1,con,cnt,ptr);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>>con;
        vector<int>t;
        recursion(root,0,con,t,true);
        vector<int>cnt(con.size(),0);
        recursion(root,0,con,cnt,false);
        return root;
    }
};