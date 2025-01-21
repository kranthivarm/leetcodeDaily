class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // int n=g.size(),m=g[0].size();
        int m=grid[0].size();
        vector<vector<long long>>g(2,vector<long long>(m,0));
        g[0][m-1]=grid[0][m-1];
        g[1][0]=grid[1][0];
        for(int i=m-2;i>-1;i--)g[0][i]+=grid[0][i]+g[0][i+1];//right to left
        for(int i=1;i<m;i++)g[1][i]+=grid[1][i]+g[1][i-1];//left to right 
        long long res=0;
        if(m>1)res=g[0][1];
        for(int i=1;i<m;i++){
            if(i+1<m && i-1>-1)res=min(res,max(g[0][i+1],g[1][i-1]));
            else if(i+1<m)res=min(res,g[0][i+1]);
            else res=min(res,g[1][i-1]);
        }
        return res;



        // g[n-1][m-1]=0,g[0][0]=0;
        // vector<vector<long long>>pref(n,vector<long long>(m));
        // for(int i=n-1;i>-1;i--){
        //     for(int j=m-1;j>-1;j--){
        //         if(i==n-1){
        //             pref[i][j]=g[i][j];
        //             if(j+1<m) pref[i][j]+=pref[i][j+1];
        //         }
        //         else if(j==m-1){
        //             pref[i][j]=g[i][j]+pref[i+1][j];                    
        //         }
        //         else{
        //             pref[i][j]=g[i][j]+max(pref[i+1][j],pref[i][j+1]);
        //         }
        //     }
        // }
        
        // for(auto i:pref){
        //     for(int j:i)cout<<j<<" ";
        //     cout<<endl;
        // }cout<<endl;cout<<endl;

        // int i=0,j=0;
        // while((i<n && j<m)){        
        //     g[i][j]=0;            
        //     if(i+1<n && j+1<m){
        //         if(pref[i+1][j]<=pref[i][j+1])j++;
        //         else i++;
        //     }
        //     else if(i+1<n)i++;
        //     else j++;
        // }
        // for(auto i:g){
        //     for(int j:i)cout<<j<<" ";
        //     cout<<endl;
        // }cout<<endl;cout<<endl;

        // vector<vector<long long>>t(n,vector<long long>(m));
        // pref={};
        // pref=t;
        // t={};
        // for(int i=n-1;i>-1;i--){
        //     for(int j=m-1;j>-1;j--){
        //         if(i==n-1){
        //             pref[i][j]=g[i][j];
        //             if(j+1<m) pref[i][j]+=pref[i][j+1];
        //         }
        //         else if(j==m-1){
        //             pref[i][j]=g[i][j]+pref[i+1][j];                    
        //         }
        //         else{
        //             pref[i][j]=g[i][j]+max(pref[i+1][j],pref[i][j+1]);
        //         }
        //     }
        // }
        // for(auto i:pref){
        //     for(int j:i)cout<<j<<" ";
        //     cout<<endl;
        // }
        // return pref[0][0];
    }
};