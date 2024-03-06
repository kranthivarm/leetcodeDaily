class Solution {
public:
    int recursion(vector<int>&nums,vector<int>&con,int i){
        if(con[i]!=-1)return con[i];        
        if(i+3<nums.size())con[i]=max(recursion(nums,con,i+3),con[i]);
        if(i+2<nums.size())con[i]=max(recursion(nums,con,i+2),con[i]);
        con[i]+=nums[i];
        return con[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>con(nums.size(),-1);        
        con[nums.size()-1]=nums[nums.size()-1];
        con[nums.size()-2]=nums[nums.size()-2];
        con[nums.size()-3]=nums[nums.size()-3]+nums[nums.size()-1];
        int x=recursion(nums,con,0);
        int y=recursion(nums,con,1);
        return max(x,y);
    }
};