class Solution {
public:
    int minDistance(string w, string w2) {
        int n=w.size(),m=w2.size();
        vector<vector<int>>con(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++)con[i][m]=n-i;
        for(int i=0;i<m;i++)con[n][i]=m-i;
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){                
                if(w[i]==w2[j]){
                    con[i][j]=con[i+1][j+1];
                    continue;
                }
                else {
                    con[i][j]=1+min(con[i+1][j],con[i][j+1]);
                }
            }
        }
        return con[0][0];
    }
};