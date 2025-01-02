class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int m=w.size();
        vector<int>pre(m,0);
        // vector<int>pre(q.size()),post(q.size());
        int n=w[0].size();
        if((w[0][0]=='a' || w[0][0]=='e' || w[0][0]=='i' || w[0][0]=='o' || w[0][0]=='u' ) and (w[0][n-1]=='a' || w[0][n-1]=='e' || w[0][n-1]=='i' || w[0][n-1]=='o' || w[0][n-1]=='u' ))pre[0]=1;
        // if((w[n-1][0]=='a' || w[n-1][0]=='e' || w[n-1][0]=='i' || w[n-1][0]=='o' || w[n-1][0]=='u' ) and (w[n-1][n-1]=='a' || w[n-1][n-1]=='e' || w[n-1][n-1]=='i' || w[n-1][n-1]=='o' || w[n-1][n-1]=='u' ))
        //     post[n-1]=1;        
        for(int i=1;i<m;i++){
            n=w[i].size();
           if((w[i][0]=='a' || w[i][0]=='e' || w[i][0]=='i' || w[i][0]=='o' || w[i][0]=='u' ) and  (w[i][n-1]=='a' || w[i][n-1]=='e' || w[i][n-1]=='i' || w[i][n-1]=='o' || w[i][n-1]=='u' ))
           pre[i]=pre[i-1]+1;
           else pre[i]=pre[i-1];
        }
        // for(int i=n-2;i>-1;i--){
        //    if( (w[i][0]=='a' || w[i][0]=='e' || w[i][0]=='i' || w[i][0]=='o' || w[i][0]=='u' ) and  (w[0][n-1]=='a' || w[i][n-1]=='e' || w[i][n-1]=='i' || w[i][n-1]=='o' || w[i][n-1]=='u' ))
        //    pre[i]=pre[i+1]+1;
        //    else pre[i]=pre[i+1];
        // }
        vector<int>res;
        for(int i=0;i<q.size();i++){
            // if(pre[q[i][0]] ==pre[q[i][1]]){
            //     if(q[i][0]>0)res.push_back(pre[q[i][0]]-pre[q[i][0]-1]);
            //  else   res.push_back(pre[q[i][1]]);
            // }
            // else if(pre[q[i][0]] && pre[q[i][1]])res.push_back(pre[q[i][1]]-pre[q[i][0]-1]);
            if(q[i][0])res.push_back(pre[q[i][1]]-pre[q[i][0]-1]);
            else res.push_back(pre[q[i][1]]);
        }
        return res;
    }
};