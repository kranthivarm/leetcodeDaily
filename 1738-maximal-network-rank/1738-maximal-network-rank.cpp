class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        vector<int>con(n);
        for(auto i:r){con[i[0]]++;con[i[1]]++;}
        map<pair<int,int>,bool>ump;
        for(auto i:r)ump[{i[0],i[1]}]=true;
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ump.find({i,j})!=ump.end() or ump.find({j,i})!=ump.end())res=max(res,(con[i]+con[j]-1));
                else res=max(res,(con[i]+con[j]));
            }
        }
        return res;
    }
};