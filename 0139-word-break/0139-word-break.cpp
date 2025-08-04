class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        int n,mi=w[0].size(),ma=w[0].size();
        unordered_map<string,bool>mp;
        for(auto i:w){
            n=i.size();
            mi=min(mi,n);
            ma=max(ma,n);
            mp[i]=true;
        }
        cout<<mi<<" "<<ma;
        n=s.size();
        vector<bool>con(n+1);
        con[n]=true;
        for(int i=n-1;i>-1;i--){
            string temp="";
            for(int j=i;j<=i+ma && j<n;j++){
                temp+=s[j];
                if(j-i+1 < mi)continue;
                if(con[j+1] && mp.find(temp)!=mp.end())con[i]=true;                
            }            
        }
        return con[0];
    }
};

















// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& w) {
//         unordered_map<string,bool>ump;
//         int minSize=w[0].size();
//         int maxSize=w[0].size();
//         int n=w.size();
//         for(int i=n-1;i>-1;i--){
//             int m=w[i].size();
//             minSize=min(minSize,m);
//             maxSize=max(maxSize,m);
//             ump[w[i]]=true;
//             w.pop_back();
//         }               
//         n=s.size();        
//         vector<bool>con(n+1);        
//         con[0]=true;// empty string 
//         // for(int i=0;i<minSize;i++)cout<<con[i];
//         for(int i=minSize-1;i<n;i++){
//             cout<<i<<" ";
//             for(int j=minSize;j<=maxSize && j<=i+1;j++){
//                 string t=s.substr((i-j+1),j);
//                 cout<<j<<" "<<t<<endl;
//                 if(ump.find(t)!=ump.end()){
//                     if(i-j>=0 && con[i-j])con[i+1]=true;
//                     else con[i+1]=true;
//                     break;
//                 }
//             }
//             // cout<<con[i];
//             // cout<<endl;
//         }
//         for(auto i:con)cout<<i;
//         return con.back();
//     }
// };