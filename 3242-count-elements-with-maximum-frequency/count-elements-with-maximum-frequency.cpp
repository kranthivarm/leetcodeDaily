class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums)mp[i]++;
        int ma=-1,res=0;
        for(auto i:mp)if((i.second)>ma)ma=i.second;
        for(auto i:mp)if((i.second)==ma)res++;
        return res*ma;
    }
};