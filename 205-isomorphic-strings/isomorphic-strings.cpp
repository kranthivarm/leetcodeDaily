class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // vector<int>con(26,-1);
        // for(int  i=0;i<s.size();i++){
        //     int x=s[i]-'a',y=t[i]-'a';
        //     // if(s[i]==t[i])continue;
        //     if(con[x]!=-1){
        //         if(con[x]!=y)return false;
        //     }
        //     else {
        //         for(int i=0;i<26;i++){
        //             if(con[i]==y)return false;
        //         }
        //         con[x]=y;
        //     }
        // }
        // return true;
        unordered_map<char,char>mp;
        unordered_map<char,int>check;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]){
                if(mp[s[i]]!=t[i])return false;                
            }
            else{
                if(check[t[i]])return false;
                mp[s[i]]=t[i];
                check[t[i]]++;
            }
        }
        // cout<<mp['a'];
        return true;
    }
};