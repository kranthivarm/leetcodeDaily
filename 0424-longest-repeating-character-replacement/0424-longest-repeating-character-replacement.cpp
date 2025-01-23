class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0,n=s.size(),i=0,j=0;
        vector<int>fre(26);
        for(;j<n;j++){
            cout<<i<<" "<<j<<endl;
            fre[s[j]-'A']++;
            while((j-i+1)-(*max_element(fre.begin(),fre.end()))>k){
                res=max(j-i,res);
                fre[s[i]-'A']--;
                i++;
            }
        }
        // return (res==0)?(j-i): res;
        return max(res,(j-i));
    }
};