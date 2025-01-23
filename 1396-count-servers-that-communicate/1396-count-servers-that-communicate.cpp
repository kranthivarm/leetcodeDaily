class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int res=0,x=-1,y=-1;
        map<pair<int,int>,bool>mp;
        for(int i=0;i<g.size();i++){
            x=-1,y=-1;
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]){
                    if(x==-1)x=i,y=j;                
                    else{
                        if(mp[{i,j}]==false){
                            res++;
                            mp[{i,j}]=true;
                        }
                        if(x!=-2 && mp[{x,y}]==false){
                            res++;
                            mp[{x,y}]=true;
                            x=-2;
                        }
                    }
                }
            // cout<<res;
            }
        }
        for(int j=0;j<g[0].size();j++){
            x=-1,y=-1;
            for(int i=0;i<g.size();i++){
                if(g[i][j]){
                    if(x==-1)x=i,y=j;                
                    else{
                        if(mp[{i,j}]==false){
                            res++;
                            mp[{i,j}]=true;
                        }
                        if(x!=-2 && mp[{x,y}]==false){
                            res++;
                            mp[{x,y}]=true;
                            x=-2;
                        }
                    }
                }
            }
        }
        return res;
    }
};