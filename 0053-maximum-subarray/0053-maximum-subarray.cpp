class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0],cur=0;       
        for(int i:nums){
            cur+=i;
            res=max(res,cur);
            if(cur<0)cur=0;
        }
        return res;
    }
};