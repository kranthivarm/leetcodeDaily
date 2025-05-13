class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long>con(26);
        for(auto i:s)con[i-'a']++;
        long long res=0,x=(1e9)+7;
        while(t--){
            vector<long long>temp(26);
            for(int i=0;i<25;i++){
                if(con[i]){
                    // con[i+1]=(con[i+1]+con[i])%x;
                    // con[i]=0;
                    temp[i+1]=con[i];
                }
            }
            if(con[25]){
                // con[0]=(con[0]+con[25])%x;
                // con[1]=(con[1]+con[25])%x;
                // con[25]=0;
                temp[0]=con[25];
                temp[1]=(temp[1]+con[25])%x;
            }
            con=temp;
        }        
        for(auto i:con)res=(i+res)%x;
        return int(res);
    }
};