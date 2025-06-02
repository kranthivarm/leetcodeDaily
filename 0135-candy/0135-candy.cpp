class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int>res(n,-1) ;       
        // priority_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;        
        for(int i=0;i<n;i++)pq.push({r[i],i});
        // pair<int,int>tPair;
        int ans=0;
        while(!pq.empty()){  
            int y=pq.top().second;
            // cout<<y<<" "          ;
            if(y+1<n && y-1>-1){                                                  
                // res[y]=max(res[y+1],res[y-1]);
                // if(res[y]==-1)res[y]=1;
                
                if(max(res[y+1],res[y-1])==-1)res[y]=1;
                else{
                    if(res[y+1]!=-1){
                        res[y]=res[y+1];
                        if(r[y]!=r[y+1])res[y]++;
                        else res[y]=1;
                    }
                    if(res[y-1]!=-1){
                        if(r[y]!=r[y-1]){
                            res[y]=max(res[y],res[y-1]+1);
                        }
                        else {
                            res[y]=max(1,res[y]);
                        }
                    }
                }
                // else if(r[y] != max(r[y+1],r[y-1]))res[y]++;
                // else {
                //     res[y]=1;
                // }
            }
            else if(y+1<n){
                res[y]=res[y+1];
                if(res[y]==-1)res[y]=1;
                else if(r[y]!=r[y+1])res[y]++;
                else res[y]=1;
            }
            else if(y-1>-1){
                res[y]=res[y-1];
                if(res[y]==-1)res[y]=1;
                else if(r[y]!=r[y-1])res[y]++;
                else res[y]=1;
            }
            else res[y]=1;
            ans+=res[y];
            pq.pop();
        }
        for(auto i:res)cout<<i<<" ";
        return ans;
    }
};
















// class Solution {
// public:
//     int candy(vector<int>& rate) {
//         int sum=0,i,l=rate.size();
//         vector<int>con(l,1);
//         for(i=l-1;i>=0;i--){
//             if(rate[i]>0){
//                 if(i==l-1){
//                     if(i-1>-1){
//                         if(rate[i]>rate[i-1]){
//                             if(rate[i]==1 and rate[i-1]==0)con[i]=2;                            
//                             else con[i]=rate[i];
//                         }
//                     }
//                 }
//                 else if(i==0){
//                    if(i+1<l){
//                     if(rate[i]>rate[i+1])
//                         con[i]=rate[i];
//                    }
//                 }
//                 else{
//                     if(rate[i]>rate[i-1]&& rate[i]>=rate[i+1]){
//                         if(rate[i]==0||rate[i-1]==0){
//                             if(rate[i]==1)con[i]=2;
//                         }
//                         else con[i]=rate[i];
//                     }
//                     else if(rate[i]>rate[i-1]&& rate[i]<rate[i+1]){
//                         if(rate[i+1]==0||rate[i-1]==0){
//                             if(rate[i]==1)con[i]=2;
//                         }
//                         else con[i]=rate[i-1]+1;
//                     }
//                     else if(rate[i]<rate[i-1]&& rate[i]>rate[i+1]){
//                         if(rate[i+1]==0||rate[i-1]==0){
//                             if(rate[i]==1)con[i]=2;
//                         }
//                         else con[i]=rate[i+1]+1;
//                     }
//                     else if(rate[i]==rate[i-1]||rate[i]==rate[i+1]){
//                         if(rate[i+1]==0||rate[i-1]==0){
//                             if(rate[i]==1)con[i]=2;
//                         }
//                         else con[i]=1;
//                     }
//                 }
//             }            
//         }
//         for(i=0;i<l;i++)sum+=con[i];
//         return sum;
//     }
// };