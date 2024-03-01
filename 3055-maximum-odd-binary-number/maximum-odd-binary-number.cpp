class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0,i=0;
        for(char i:s)if(i=='1')one++;
        one--;
        s[s.size()-1]='1';        
        for(i=0;i<one;i++)s[i]='1';
        for(;i<s.size()-1;i++)s[i]='0';
        return s;
    }
};