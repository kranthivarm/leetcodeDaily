class Solution {
public:
    string customSortString(string order, string s) {
        int i,l=max(order.size(),s.size());
        vector<int>con1(26,0),con2(26,0);
        for(i=0;i<l;i++){
            if(i<order.size()){
                int x=order[i]- 'a' ;
                con1[x]++;
            }
            if(i<s.size()){
                int x=s[i]- 'a' ;
                con2[x]++;
            }
        }
        string res="";
        for(i=0;i<order.size();i++){
            int x=order[i]- 'a' ;
            if(con1[x]>0 and con2[x]>0){
                res+=order[i];
                con1[x]--;
                con2[x]--;                
                for(int j=0;j<con2[x];j++)res+=order[i];
                con2[x]=0;                
            }
        }
        for(i=0;i<26;i++){
            while(con2[i]>0){
                char ch= 'a' +i;
                res+=ch;
                con2[i]--;
            }
        }
        return res;
    }
};