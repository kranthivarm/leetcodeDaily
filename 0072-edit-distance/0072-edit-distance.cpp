class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++)dp[i][m]=n-i;
        for(int i=0;i<m;i++)dp[n][i]=m-i;
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                if(w1[i]==w2[j])dp[i][j]=dp[i+1][j+1];
                else{
                    int x=1+ dp[i+1][j+1];//replace i or j;
                    int x1=1+dp[i][j+1];//insert i;
                    int y1=1+dp[i+1][j] ;//insert j
                    dp[i][j]=min(x,min(x1,y1));
                }
            }
        }
        return dp[0][0];
    }
};