class Solution {
public:
    int maxDiff(int num) {
        string big="",small;
        while(num){
            big+=(num%10)+'0';
            // small+=(num%10)+'0';            
            num/=10;
        }
        reverse(big.begin(),big.end());
        int i=0,n=big.size();
        small=big;
        //big creation;
        while(i<n && big[i]=='9')i++;
        if(i!=n)for(int j=i;j<n;j++)if(big[j]==small[i])big[j]='9';
        //small creation;
        i=0;
        if(small[i]=='1'){
            if(n==1)return stoi(big)-1;
            while(i<n && (small[i]=='1' or small[i]=='0'))i++;
            if(i!=n){
                char temp=small[i];
                for(int j=i;j<n;j++)if(small[j]==temp)small[j]='0';
            }
        }
        else {
            char temp=small[0];            
            for(int j=0;j<n;j++)if(small[j]==temp)small[j]='1';
        }
        cout<<big <<" ---  " <<small;
        return stoi(big)-stoi(small);
    }
};