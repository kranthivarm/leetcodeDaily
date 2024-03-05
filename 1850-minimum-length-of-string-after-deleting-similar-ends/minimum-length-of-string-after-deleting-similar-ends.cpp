class Solution {
public:
    int minimumLength(string s) {
        int st=0,end=s.size()-1;
        while(st!=end){
            char preSt=s[st],preEnd=s[end];
            if(preSt!=preEnd)break;
            while(st<s.size() and s[st]==preSt)st++;
            if(st>=end)return 0;
            while(end>-1 and s[end]==preEnd)end--;
            if(st>end)return 0;
        }
        return end-st+1;
        //below correct but less beats
    //     int st=0,end=s.size()-1;
    //     while(st!=end and s[st]==s[end]){
    //         char preSt=s[st],preEnd=s[end];            
    //         while(st<=end){
    //             int x=0;
    //             if(s[st]==preSt){
    //                 st++;
    //                 x=1;
    //             }
    //             if(st<=end){
    //                 if(preEnd==s[end]){
    //                     end--;
    //                     x=1;
    //                 }
    //             }
    //             else return 0;
    //             if(x==0)break;
    //         }
    //         if(st>end)return 0;
    //     }
    //     for(int i=st;i<=end;i++)cout<<s[i];
    //     cout<<st<<" "<<end;
    //     // if(st==0 and end==s.size()-1)return s.size();
    //     if(st>end)return 0;
    //     return end-st+1;
    }
};