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
vector<long long>con;
    void recursion(TreeNode *root,int lvl){
        if(root){            
            if(lvl>con.size())con.push_back(0);
            con[lvl-1]+=root->val;
            recursion(root->left,lvl+1);
            recursion(root->right,lvl+1);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        recursion(root,1);
        if(con.size()<k)return -1;
        sort(con.begin(),con.end());
        return con[con.size()-k];
    }
};