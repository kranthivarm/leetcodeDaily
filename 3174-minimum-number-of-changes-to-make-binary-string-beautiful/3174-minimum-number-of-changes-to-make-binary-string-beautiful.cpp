class Solution {
public:
    int fun(string s, int st){
        int cnt=0;
        for(int i=st;i<s.size();i++){
            if(s[i]==s[i-1])cnt++;
            else return cnt;
        }
        return cnt;
    }
    int minChanges(string s) {
        int res=0,cnt=1;;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                if(cnt%2){
                    // int x=1+fun(s,i+1);
                    // if(x%2){
                    //     res++;
                    //     cnt=0;//this odd and prev odd cancel
                    // }
                    // else {
                    //     res++;
                    // }
                    res++;
                    cnt=0;
                } 
                else
                cnt=1;               
            }
            else cnt++;
        }return res;
    }
};