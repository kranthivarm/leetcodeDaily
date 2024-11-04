class Solution {
public:
    string compressedString(string s) {
        string res="";
        char pre=s[0];
        int cnt=1;
        for(int i=1;i<s.size();i++){
            if(pre==s[i]) cnt++;
            else {
                for(int j=cnt;j>0;j-=9){
                    res+=(j>9)?'9':('0'+j);
                    res+=pre;
                }
                pre=s[i];
                cnt=1;
            }
        }
        for(int j=cnt;j>0;j-=9){
            res+=(j>9)?'9':('0'+j);
            res+=pre;
        }
        return res;
    }
};