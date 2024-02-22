class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>judgeBelif(n,0),BelifOnJudge(n,0);
        for(int i=0;i<trust.size();i++){
            judgeBelif[trust[i][0]-1]++;
            BelifOnJudge[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++){
            // cout<<judgeBelif[i]<<","<<BelifOnJudge[i]<<"  ";
            if(judgeBelif[i]==0 and BelifOnJudge[i]==n-1)return i+1;
        }
        return -1;
    }
};