class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {        
        int n=q.size();
        vector<long long>con(n+1,0),suffixMax(n+1,0);
        for(int i=n-1;i>-1;i--){
            long long ma=0;
            if(i+q[i][1]+1<n){
                ma=suffixMax[i+q[i][1]+1];
            }
            con[i]=q[i][0]+ma;
            suffixMax[i]=max(con[i],suffixMax[i+1]);
        }
        return *max_element(con.begin(),con.end());
    }
};