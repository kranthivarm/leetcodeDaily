class Solution {
public:    
    int lowerPlusUpperBoundResult(vector<vector<int>>& fruits, int x, int y, vector<int>&prefixFruits) {
        int n=fruits.size();
         int l=0, h=n-1,mid;
            int st=-1,end=-1;
            while(l<=h){//st
                mid=(l+h)/2;
                if(mid>=n or mid<0)break;
                // if(fruits[mid][1]>(startPos-remSteps)){
                if(fruits[mid][0]>x){
                    st=mid;
                    if(mid==0)break;
                    h=mid-1;
                }
                else if(fruits[mid][0]<(x)) l=mid+1;                                    
                else {st=mid;break;}
            }
            l=0,h=n-1;
            while(l<=h){//end
                mid=(l+h)/2;
                if(mid>=n or mid<0)break;
                if(fruits[mid][0]>y)h=mid-1;                
                else if(fruits[mid][0]<y){
                    end=mid;
                    if(mid==n-1)break; 
                    l=mid+1;                                    
                }
                else {end=mid;break;}
            }
            // cout<<st<<" "<<end<<endl;
            if(st==-1 or end==-1)return 0;
        return prefixFruits[end]-prefixFruits[st]+fruits[st][1];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        if(k==0){
            for(auto i:fruits){
                if(i[0]==startPos)return i[1];
            }
            return 0;
        }
        int n=fruits.size();
        vector<int>prefix(n);
        prefix[0]=fruits[0][0];
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+fruits[i][1];
        int res=0;
        //every time travel i distance in 1 direction then k-i opposite direction which will give max 
        for(int i=0;i<=(k/2);i++){
            // cout<<i<<" ";
            int remSteps=k-(2*i);
            
            // i distance travelled then remaining
            //startpos+i   to remSteps(k-2i)
            //going left = stpos-remSteps  to  stpos+i
           res=max(lowerPlusUpperBoundResult(fruits, startPos-remSteps, startPos+i, prefix ),res);
            //going right =stpos-i to stpos+remSteps
           res=max(lowerPlusUpperBoundResult(fruits, startPos-i, startPos+remSteps, prefix ),res);
        }
        return res;
    }
};