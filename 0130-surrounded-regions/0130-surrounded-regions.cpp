class Solution {
public:
    void solve(vector<vector<char>>& b) {
        
        // in this border zeros  and their follwed zeros can't be replaced 
        int n=b.size(),m=b[0].size();
        vector<vector<bool>>con(n,vector<bool>(m));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)if(b[i][0]=='O')q.push({i,0});        
        for(int i=0;i<n;i++)if(b[i][m-1]=='O')q.push({i,m-1});
        for(int i=0;i<m;i++)if(b[0][i]=='O')q.push({0,i});
        for(int i=0;i<m;i++)if(b[n-1][i]=='O')q.push({n-1,i});    
        // cout<<q.size()    ;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            cout<<"{"<<x<<","<<y<<"}";
            q.pop();
            if(con[x][y] || b[x][y]=='X')continue;
            con[x][y]=true;
            if(b[x][y]=='O')b[x][y]='R';
            if(x+1<n)q.push({x+1,y});
            if(x-1>=0)q.push({x-1,y});
            if(y+1<m)q.push({x,y+1});
            if(y-1>=0)q.push({x,y-1});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='R')b[i][j]='O';
                else if(b[i][j]=='O')b[i][j]='X';
            }
        }
    }
};