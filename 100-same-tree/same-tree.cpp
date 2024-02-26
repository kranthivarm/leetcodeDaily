class Solution {
public:
    bool traversal(TreeNode*p,TreeNode*q){
        if(p and q){
            if(p->val != q->val)return false;
            if(traversal(p->left,q->left) and traversal(p->right,q->right))return true;
            return false;
        }
        else if(!p and !q)return true;
        else return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p,q);
    }
};
