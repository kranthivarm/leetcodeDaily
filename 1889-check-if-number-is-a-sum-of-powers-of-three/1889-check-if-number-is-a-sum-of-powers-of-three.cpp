class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p=pow(3,15);     
        for(int i=0;i<=15 && n;i++){
            if(n>=p){
                n-=p;
                if(p==1)break;
                // cout<<n<<" ";
            }
            p/=3;
        }

        cout<<n<<" ";

        return !((bool)n);

    }
};