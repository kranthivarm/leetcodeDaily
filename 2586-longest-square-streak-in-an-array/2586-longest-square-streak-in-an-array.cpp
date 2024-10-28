class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<bool>ptr(nums.size(),false);
        unordered_map<int,bool>ump,ele;//ump is already visited;        
        for(int i:nums)ele[i]=true;
        int res=0;
        for(int i:nums){
            if(!ump[i]){
                int cnt=1;
                long long x=i;  
                x=x*x;              
                while(x<=10e5 && ele[x] && ump[x]==false){
                    cnt++;
                    ump[x]=true;
                    x=x*x;                    
                }
                res=max(res,cnt);
            }
        }
        if(res==1)return -1;
        return res;
    }
};