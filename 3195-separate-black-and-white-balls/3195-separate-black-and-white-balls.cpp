class Solution {
public:
    long long minimumSteps(string s) {
        int o=0,z=0,n=s.size();
        long long res=0;
        for(char i:s)i=='0'?++z:++o;
        int i=0,j=n-1;
        // if(!o or !z)return 0;
        while(i<=j){//i points '0' and j points '1'
            while(i<=j){
                // if(s[i]=='0' && i<z)i++;
                // else if(s[i]=='1' && i<z)break;
                if(s[i]=='1' && i<z)break;
                else i++;                
            }
            while(i<=j){
                if(s[j]=='0' && j>=z)break;
                else j--;
            }
            if(i<n && j>=0 && s[i]=='1' && s[j]=='0'){
                cout<<i<<" "<<j<<endl;
                // s[i]='0',s[j]='1';
                res+=j-i;
                j--;
                i++;
            }            
        }
        return res;
    }
};