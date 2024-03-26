class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //below doesn't work
        // long long unsigned posSum=0;
        // int posCnt=0,ma=0,mi=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>0){
        //         if(nums[i]>ma)ma=nums[i];//max +ve in nums
        //         if(mi==-1)mi=nums[i];//min +ve in nums
        //         else if(nums[i]<mi)mi=nums[i];
        //         posSum+=nums[i];//+ve sum
        //         posCnt++;//+ve count
        //     }
        // }
        // if(posCnt==0)return 1;
        // if(mi>1)return 1;
        // long long unsigned nthSum=((ma)*(ma+1))/2;
        // if(posSum==nthSum)return ma+1;
        // else return nthSum-posSum;

        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size() && nums[i]<=0)i++;
        if(i>=nums.size())return 1;
        if(nums[i]!=1)return 1;
        for(;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>1)return nums[i]+1;
        }
        return nums[nums.size()-1]+1;
    }
};