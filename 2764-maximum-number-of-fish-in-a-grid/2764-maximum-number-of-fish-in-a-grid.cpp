class Solution {
public:
    int findMaxFish(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<vector<bool>>con(n,vector<bool>(m));
        int fishMax=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //searching 
                if(con[i][j]==true or g[i][j]==0)continue;
                queue<pair<int,int>>q;
                q.push({i,j});
                int fish=0;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    if(!con[x][y])fish+=g[x][y];                    
                    else continue;
                    con[x][y]=true;
                    if(x+1<n && g[x+1][y]>0 && !con[x+1][y])q.push({x+1,y});
                    if(x-1>=0 && g[x-1][y]>0 && !con[x-1][y])q.push({x-1,y});
                    if(y+1<m && g[x][y+1]>0 && !con[x][y+1])q.push({x,y+1});
                    if(y-1>=0 && g[x][y-1]>0 && !con[x][y-1])q.push({x,y-1});                    
                }
                fishMax=max(fishMax,fish);                
            }
        }
        return fishMax;
    }
};