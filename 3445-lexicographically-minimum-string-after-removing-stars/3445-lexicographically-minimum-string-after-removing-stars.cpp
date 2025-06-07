class Solution {
public:
    struct comp{
        // bool operator()(pair<char,int>&a,pair<char,int>&b){
        //     // max heap
        //     // if(a.first < b.first)return true;
        //     // if(b.first < a.first)return false;
        //     // if(a.first > b.first)return true;
        //     // return false;
        //     if(a.first < b.first)return true;
        //     if(b.first < a.first)return false;
        //     if(a.first > b.first)return true;
        //     return false;
        // }
        bool operator()(pair<char,int>& a, pair<char,int>& b){
            if(a.first != b.first)
                return a.first > b.first;  
            return a.second < b.second;    
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
                continue;
            }
            if(pq.empty())continue;
            s[pq.top().second]='*';
            pq.pop();
        }
        string res="";
        for(auto i:s)if(i!='*')res+=i;
        return res;
    }
};