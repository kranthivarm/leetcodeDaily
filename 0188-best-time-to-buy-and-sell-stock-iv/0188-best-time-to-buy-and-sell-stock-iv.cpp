class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>con(n+1,vector<vector<int>>(2,vector<int>(k+1)));
        for(int i=n-1;i>-1;i--){
            for(int buy=0;buy<2;buy++){
                for(int transaction=1;transaction<=k;transaction++){
                    if(buy==0){//need to buy
                        con[i][buy][transaction]=max(
                                -prices[i]+con[i+1][1][transaction], con[i+1][buy][transaction]
                            );
                    }
                    else {//sell
                        con[i][buy][transaction]=max(
                            prices[i]+con[i+1][0][transaction-1], con[i+1][buy][transaction]
                        );
                    }
                }
            }
        }
        return con[0][0][k];
    }
};