class Solution {
public:
    int numberOfSubstrings(string s) {
        //one is k and k-1 approach
        // answer is all (subarrays count )-(substring with distnict characters less than 3(1,2,0))
        int i=0,res=0,a=0,b=0,c=0,n=s.size();
        for(int j=0;j<n;j++){
            if(s[j]=='a')a++;
            else if(s[j]=='b')b++;
            else c++;
            
            while(a && b && c){
                res+=1+(n-j-1);
                if(s[i]=='a')a--;
                else if(s[i]=='b')b--;
                else c--;
                i++;
                // if(a && b && c)res+=1+(n-i-1);
            }                    
                          
        }
        return res;
    }
};