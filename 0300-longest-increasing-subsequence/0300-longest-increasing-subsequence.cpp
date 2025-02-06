class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int>lenOfLis={nums[0]};
       for(int i=1;i<nums.size();i++){
        if(nums[i]>lenOfLis.back())lenOfLis.push_back(nums[i]);
        else {
            int l=0,h=lenOfLis.size()-1;
            while(l<=h){
                int mi=l+((h-l)/2);
                // int mi=(l+h)/2;
                if(lenOfLis[mi]<nums[i])l=mi+1;
                else h=mi-1;
            }
            lenOfLis[l]=nums[i];
        }
       }
       return lenOfLis.size();
    }
};