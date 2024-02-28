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
    int ans,max=-1;
    void recurse(TreeNode *t,int c){
        if(t){
            if(c>max){
                max=c;
                ans=t->val;
            }
            recurse(t->left,c+1);
            recurse(t->right,c+1);
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        recurse(root,0);
        return ans;
    }
};