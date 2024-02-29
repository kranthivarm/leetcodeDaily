class Solution {
public:
vector<int>lvlLastValue;
    bool check(TreeNode * root,int lvl){
        if(root){
            if(lvl%2){//odd lvl should has evenval
                if((root->val)%2)return false;                
            }
            else{//even lvl should has odd val;
                if((root->val)%2==0)return false;
            }
            if(lvlLastValue.size()<lvl+1)lvlLastValue.push_back(root->val);
            else{
                if(lvl%2){//odd decreasing;
                    if(lvlLastValue[lvl]<=root->val){
                        // cout<<","<<root->val;
                        return false;
                    }
                    else lvlLastValue[lvl]=root->val;
                }
                else {//even increasing
                    if(lvlLastValue[lvl]>=root->val){
                        // cout<<" , "<<root->val;
                        return false;
                    }
                    else lvlLastValue[lvl]=root->val;
                }                
            }  
            if(!check(root->left,lvl+1))return false;
            if(!check(root->right,lvl+1))return false;                      
            return true;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        // for(int i:lvlLastValue)cout<<i<<" ";
        return check(root,0);
    }
};