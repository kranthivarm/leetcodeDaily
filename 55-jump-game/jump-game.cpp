class Solution {
public:
    bool recursion(vector<int>& nums,vector<char>&con,int ind){
        if(con[ind]!='#'){
            if(con[ind]=='T')return true;
            else if(con[ind]=='F')return false;
        }
        for(int i=1;i<=nums[ind];i++){
            if(ind+i>=nums.size())break;
            if(con[ind+i]!='#'){
                if(con[ind+i]=='T'){
                    con[ind]='T';
                    return true;
                }
                else con[i]='F';
            }
            else {
                bool t=recursion(nums,con,ind+i);
                con[ind+i]='T';
                con[ind]='T';
                if(t)return true;  
                else {
                    con[ind+i]='F';
                    con[ind]='F';
                }
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<char>con(nums.size(),'#');
        con[nums.size()-1]='T';
        return recursion(nums,con,0);
    }
};