class Solution {
public:
    string countAndSay(int n) {   
        string res="1",temp="";
        for(int i=2;i<=n;i++){
            temp="";
            char pre=res[0],cnt=1;
            for(int j=1;j<res.size();j++){
                if(res[j]==pre)cnt++;
                else {
                    temp+=((to_string(cnt))+pre);
                    pre=res[j];
                    cnt=1;
                }
            }
            if(cnt)temp+=((to_string(cnt))+pre);
            res=temp;
        }
        return res;
    }
};