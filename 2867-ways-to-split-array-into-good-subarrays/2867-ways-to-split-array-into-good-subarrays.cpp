class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {        
        int i=0;
        for(int i=0;i<nums.size();i++)if(nums[i])break;
        if(i==nums.size())return 0;
        // i++;
        long long res=0,zero=0,x=(1e9)+7;
        for(;i<nums.size();i++){
            zero++;
            if(nums[i]){                
                if(res)res=(res*zero)%x;
                else res=1;
                zero=0;
            }            
        }
        return res;
    }
};