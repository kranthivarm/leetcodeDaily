class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // lets find longest increasing subsequence
        vector<int>lenOfLis={nums[0]};
        for(int i=1;i<nums.size();i++){
            if(nums[i]>lenOfLis[lenOfLis.size()-1])lenOfLis.push_back(nums[i]);
            else{
                //replace it with lowerbound in lenOfLis
                int l=0,r=lenOfLis.size()-1;
                while(l<=r){
                    int mi=l+((r-l)/2);                    
                    if(lenOfLis[mi]<nums[i]){
                        l=mi+1;
                    }
                    else r=mi-1;
                }
                lenOfLis[l]=nums[i];//replace
            }
            if(lenOfLis.size()>=3)return true;
        }
        return false;
    }
};