class Solution {
public:
    bool freqCheck(unordered_map<char,int>&smp,unordered_map<char,int>&tmp){
        for(auto i:tmp){
            if(smp[i.first]<i.second)return false;        
        }
        return true;
    }
    string minWindow(string s, string t) {
        int sn=s.size(),tn=t.size();
        if(tn>sn)return "";
        if(tn==1){
            for(auto i:s)if(i==t[0])return t;
        }
        unordered_map<char,int>smp,tmp;
        for(auto i:t)tmp[i]++;
        int st=0,len=INT_MAX,ptri=-1,ptrj=-1;
        smp[s[0]]++;
        for(int i=1;i<sn;i++){
            smp[s[i]]++;
            // if(tmp.find(s[i])==tmp.end())continue;
            // if(smp[s[i]]>=tmp[s[i]] && smp.size()>=tmp.size()){
            //     if(!freqCheck(smp,tmp))continue;
            // }
            while(st<i && freqCheck(smp,tmp)){
                if((i-st)<len){
                    len=(i-st);
                    ptri=st;
                    ptrj=i;
                }
                smp[s[st++]]--;                
            }            
        }
        
        if(ptri==-1)return "";
        string res="";
        for(int i=ptri;i<=ptrj;i++)res+=s[i];
        return res;
    }
};