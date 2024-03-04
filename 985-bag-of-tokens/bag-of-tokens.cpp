class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ma=0,score=0,l=0,h=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        // for(int i:tokens) cout<<i<<" ";
        while(l<=h){
            if(tokens[l]<=power){
                power-=tokens[l++];
                score++;
            }
            else if(score){
                if(l==h)break;
                power+=tokens[h--];
                score--;
            }
            else break;
            //cout<<power<<" ";
        }
        return score;
    }
};