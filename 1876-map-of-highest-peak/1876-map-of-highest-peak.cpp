class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        // vector<vector<int>>res(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]){
                    q.push({i,j});
                    a[i][j]=-1;
                }                
                // a[i][j]=!a[i][j];
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i+1<n && a[i+1][j]==0){
                a[i+1][j]=((a[i][j]>-1)?a[i][j]:0)+1;
                q.push({i+1,j});
            }
            if(i-1>=0 && a[i-1][j]==0){
                a[i-1][j]=((a[i][j]>-1)?a[i][j]:0)+1;
                q.push({i-1,j});
            }
            if(j-1>=0 && a[i][j-1]==0){
                a[i][j-1]=((a[i][j]>-1)?a[i][j]:0)+1;                
                q.push({i,j-1});
            }
            if(j+1<m && a[i][j+1]==0){
                a[i][j+1]=((a[i][j]>-1)?a[i][j]:0)+1;
                q.push({i,j+1});
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]==-1)a[i][j]=0;
        return a;
    }
};