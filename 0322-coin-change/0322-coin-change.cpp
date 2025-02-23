class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount));/
        vector<int>dp((amount+1),-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){            
            // cout<<i<<endl;
            int minCoin=INT_MAX;
            for(int j=0;j<n;j++){
                // cout<<j;
                if(coins[j]<=i){
                    if( dp[i-coins[j]]!=-1){
                        minCoin=min(minCoin,dp[i-coins[j]]);
                    }
                }
                else break;
            }
            if(minCoin!=INT_MAX)dp[i]=minCoin+1;            
        }
        return dp[amount];
    }
};