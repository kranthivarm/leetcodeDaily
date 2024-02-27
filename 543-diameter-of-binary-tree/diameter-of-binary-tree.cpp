struct dp{
    int leftval,rightval;
    dp *dpleft;
    dp *dpright;
    // dp() : leftval(0),rightval(0), left(nullptr), right(nullptr) {}
    // dp(int x,int y) : leftval(x),rightval(y), left(nullptr), right(nullptr) {}
    // dp(int x,int y, dp *left, dp *right) : leftval(x) ,rightval(y), left(left), right(right) {}
    dp(int x,int y){
        leftval=x;
        rightval=y;
        dpleft=NULL;
        dpright=NULL;        
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };*/
class Solution {
public:
    dp* buildDpTree(TreeNode *root){
        if(root){
            if(!root->left and !root->right)return new dp(0,0);
            dp* nn=new dp(0,0);
            if(!root->right){//root->left exists;
                nn->dpleft= buildDpTree(root->left);
                if(nn->dpleft)nn->leftval=max(nn->dpleft->leftval +1,nn->dpleft->rightval +1);
                
                nn->rightval=0;
            }
            else if(!root->left){//right exists;
                nn->dpright=buildDpTree(root->right);

                nn->leftval=0;
                if(nn->dpright)nn->rightval=max(nn->dpright->rightval +1,nn->dpright->leftval+1);
            }
            else {//this node has both left and right childs
                //left child;
                nn->dpleft= buildDpTree(root->left);
                int x=0,y=0,l=0,r=0;
                if(nn->dpleft)x=nn->dpleft->leftval +1;
                if(nn->dpleft)y=nn->dpleft->rightval +1;
                l=max(x,y);
                //right child;
                nn->dpright=buildDpTree(root->right);
                if(nn->dpright)x=nn->dpright->leftval +1;
                if(nn->dpright)y=nn->dpright->rightval +1;
                r=max(x,y);

                nn->leftval=l;
                nn->rightval=r;
            }
            return nn;
        }
        return NULL;
    }
    int ma=0;
    void dpTreeTraverse(dp *newDpTree){
        if(newDpTree){
            int x=newDpTree->leftval,y=newDpTree->rightval;

            if(ma < x + y )ma=newDpTree->leftval + newDpTree->rightval;
            cout<<newDpTree->leftval<<" "<<newDpTree->rightval<<endl;
            dpTreeTraverse(newDpTree->dpleft);
            dpTreeTraverse(newDpTree->dpright);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //creating dp tree with 2 values (left size and right size)
        dp* newDpTree=buildDpTree(root);
        dpTreeTraverse(newDpTree);
        return ma;
    }
};
// class Solution {
// public:
//     int x=0;
//     void recursion(TreeNode *root,int lvl){
//         if(root){
//             recursion(root->left,lvl+1);
//             recursion(root->right,lvl+1);
//         }
//         else{
//             if(lvl>x)x=lvl;
//         }
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root->left and !root->right)return 0;
//         recursion(root->left,0);//x is level
//         int le=x;
//         x=0;
//         recursion(root->right,0);
//         int ri=x;        
//         if(!ri)return le;
//         if(!le)return ri;        
//         return ri+le;
//     }
// };
