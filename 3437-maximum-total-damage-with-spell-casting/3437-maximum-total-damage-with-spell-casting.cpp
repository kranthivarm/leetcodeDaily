class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int siz=0;
        unordered_map<int,long long>ump;
        for(int i=0;i<power.size();i++){
            ump[power[i]]++;
            if(ump[power[i]]==1){
                power[siz++]=power[i];
            }
        }
        sort(power.begin(),power.begin()+siz);
        vector<long long>dp(siz);
        for(int i=siz-1;i>=0;i--){
            long long ma=0;
            int j=i+1;
            for(;j<i+3 && j<siz;j++)if(power[j]>power[i]+2)break;
            if(j<siz){
                int k=j;
                for(;k<j+3 && k<siz;k++){
                    if(power[k]>power[j]+2)break;
                    ma=max(ma,dp[k]);
                }
            }
            dp[i]=ma+(power[i]*ump[power[i]]);
            // for(int j=3;j<=5;j++){
            //     if(ump.find(power[i]+j)!=ump.end()){
            //         ma=max
            //     }
            // }
        }

        return *max_element(dp.begin(),dp.end());
    }
};