class Solution {
public:
    int numDecodings(string s) {
        // return 0;
        if(s[0]=='0')return 0;
        for(int i=1;i<s.size();i++)if(s[i]=='0' && (s[i-1]> '2' or s[i-1]=='0'))return 0;
        int n=s.size();
        vector<int>con(n+2);
        if(s[n-1]!='0')con[n-1]=1;
        con[n]=1;
        for(int i=n-2;i>-1;i--){
        //      if(s[i]=='1') con[i]=con[i+1]+(s[i+1]!='0');
        //    else if(s[i]=='2')con[i]=con[i+1]+(s[i+1]<='6' && s[i+1]!='0');
        //     else con[i]=con[i+1];
            if(s[i]=='0')continue;
            con[i]=con[i+1];
            if(s[i]=='1') con[i]+=con[i+2];
            else if(s[i]=='2')con[i]+=(s[i+1]<='6')?con[i+2]:0;
        }
        return con[0];
    }
};