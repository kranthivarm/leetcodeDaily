class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>con(n,{1,1});
        // first is positive 
        // second is negative
        for(int i=1;i<n;i++){            
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){//positive;
                    con[i].first=max(con[i].first,1+con[j].second);
                }
                if(nums[i]<nums[j]){//negative;
                    con[i].second=max(con[i].second,1+con[j].first);
                }
            }
        }
        int res=0;
        for(auto i:con)res=max(res,max(i.first,i.second));
        return res;
    }
};