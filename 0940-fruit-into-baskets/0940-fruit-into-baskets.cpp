class Solution {
public:
    bool typeCheck(vector<int>&type,int a){
        if(type[0]==-1)type[0]=a;
        else if(type[0]!=a && type[1]==-1)type[1]=a;
        
        if(a==type[0] or a==type[1])return true;
        return false;
    }
    int totalFruit(vector<int>& fruits) {
        int res=0,curCnt=0;
        vector<int>type(2,-1);
        for(int i=0;i<fruits.size();i++){
            // cout<<"type1"<<type[0]<<" type2"<<type[1]<<endl;
            if(typeCheck(type,fruits[i])){
                curCnt++;                
                res=max(res,curCnt);
                continue;
            }
            type[0]=fruits[i-1];
            type[1]=fruits[i];
            int x=i-1;
            cout<<fruits[i]<<" ";
            while(fruits[x]==type[0]){
                // cout<<x<<" ";
                x--;
            }
            // cout<<endl;
            x++;
            curCnt=i-x+1;
            res=max(res,curCnt);
        }
        return max(res,curCnt);
    }
};