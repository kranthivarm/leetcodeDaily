class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        unordered_map<char,int>ump;
        for(auto i:w2){
            unordered_map<char,int>t;
            for(char j:i)t[j]++;
            for(auto j:t)ump[j.first]=max(ump[j.first],j.second);
        }
        vector<string>res;
        for(auto i:w1){
            unordered_map<char,int>t;
            for(char j:i)t[j]++;
            bool ptr=false;
            for(auto j:ump){
                if(t[j.first]<j.second){
                    ptr=true;
                    break;
                }
            }
            if(!ptr)res.push_back(i);
        }
        return res;
    }
};