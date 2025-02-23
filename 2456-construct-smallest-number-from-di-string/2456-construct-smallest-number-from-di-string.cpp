class Solution {
public:
    string smallestNumber(string p) {
        vector<bool>con(10);
        string res="";
        int cnt=0;
        int n=p.size(),small=1;
        for(int i=0;i<n;i++){            
           if(p[i]=='I'){            
            for(int j=1;j<=9 ;j++){
                if(con[j]==false){
                    res+=(j+'0');                
                    con[j]=true;
                    if(i==n-1)res+=((j+1)+'0');
                    break;
                }
            }
            // con[small]=true;
            // res+=(small+'0');                
            // small++;                    
            // if(i==n-1)res+=(small+'0');
            // small++;            
           }
           else {
            cnt=1;
            for(int j=i+1;j<n;j++){
                if(p[j]=='D')cnt++;
                else break;
            }
            i+=cnt;
            cnt++;
            string t="";            
            for(int j=1;j<10 && cnt;j++){
                if(con[j]==false){
                    con[j]=true;
                    cnt--;
                    t=(char(j+'0'))+t;
                }
            }

            // for(int j=small;j<10 && cnt;j++){
            //     if(!con[j]){
            //         con[j]=true;
            //         cnt--;
            //         t=(char(j+'0'))+t;
            //         small++;
            //     }
            // }
            res+=t;
            cout<<i;
            if(i==n-1 && p[i]=='I'){                
                for(int j=1;j<10;j++){
                    if(con[j]==false){
                        con[j]=true;
                        // t=(char(j+'0'))+t;
                        res+=(j+'0');
                        break;
                    }
                }
            }
           }           
        }
        // cout<<res;
        // if(res.size()==p.size())return res;        
        // for(int j=1;j<10;j++){
        //     if(con[j]==false){                
        //         res+=(j+'0');
        //         return res;
        //     }
        // }
        return res;
    }
};