class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        int pre=0,res=0;
        for(int i:nums){
            if(i&1) pre++;                            
            ump[pre]++;
            if(pre==k)res++;
            if(pre>=k)res+=ump[pre-k];            
        }
        return res;
    }
};