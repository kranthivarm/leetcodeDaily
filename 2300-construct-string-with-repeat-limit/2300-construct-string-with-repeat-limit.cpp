class Solution {
public:
    string repeatLimitedString(string s, int rl) {        
        vector<int>con(26,0);
        vector<char>ch;
        for(char i:s)con[i-'a']++;
        for(int i=25;i>-1;i--){
            if(con[i]) ch.push_back(i+'a');            
        }
        int in=0;
        string res="";
        while(in<ch.size()){            
            int x=ch[in]-'a';
            if(con[x]==0){
                in++;
                continue;
            }
            if(con[x]<=rl){                
                for(int i=0;i<con[x];i++)res+=ch[in];
                con[x]=0;
                in++;
            }
            else {                
                for(int i=0;i<rl;i++)res+=ch[in];
                con[x]-=rl;   
                bool ptr=true; 
                for(int j=in+1;j<ch.size();j++)            {
                    x=ch[j]-'a';
                    if(con[x]){
                        res+=ch[j];
                        con[x]--;
                        ptr=false;
                        break;
                    }
                    else continue;
                }
                if(ptr)break;
                // if(in+1<ch.size()){
                //     x=ch[in+1]-'a';
                //     if(con[x]){
                //         res+=ch[in+1];
                //         con[x]--;
                //     }
                //     else in++;
                // }
                // else break;
            }
        }
        return res;
    }
};