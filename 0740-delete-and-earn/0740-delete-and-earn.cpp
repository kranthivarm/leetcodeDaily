class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,long long>ump;        
        int in = 0 ;  
        for(auto i:nums){
            ump[i]++;
            if(ump[i]==1){
                nums[in++]=i;
            }
        }
        sort(nums.begin(),nums.begin()+in);
        for(int i=0;i<in;i++)cout<<nums[i]<<" ";
        vector<long long>dp(in);
        dp[0]=nums[0]*(ump[nums[0]]);
        if(in>1){
            dp[1]=nums[1]*(ump[nums[1]]);
            if(nums[0]!=nums[1]-1)dp[1]+=dp[0];
        }
        if(in>2)   {
            dp[2]=nums[2]*(ump[nums[2]]);
            if(nums[2]==nums[1]+1) dp[2]+=dp[0];            
            else dp[2]+=max(dp[1],dp[0]);
        }    

        for(int i=3;i<in;i++){
            dp[i]=nums[i]*(ump[nums[i]]);
            if(nums[i]==nums[i-1]+1) dp[i]+=max(dp[i-2],dp[i-3]);            
            else dp[i]+=max(dp[i-2],dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};