class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt=0,pro=1,oneZeroInd=-1;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]){
                zeroCnt++;
                oneZeroInd=i;
            }
            else pro*=nums[i];
        }
        if(zeroCnt){
            vector<int>res(nums.size(),0);
            if(zeroCnt==1) {
                // for(int i=0;i<nums.size();i++){
                //     if(!nums[i])res[i]=pro;
                // }
                res[oneZeroInd]=pro;
            }            
            return res;
        }        
        vector<int>res(nums.size(),0);
        for(int i=0;i<nums.size();i++)res[i]=pro/nums[i];
        return res;
    }
};