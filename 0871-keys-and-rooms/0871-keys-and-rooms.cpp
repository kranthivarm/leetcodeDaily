class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>isVisit(n);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(isVisit[x])continue;
            isVisit[x]=true;
            for(auto i:rooms[x]){
                if(!isVisit[i])q.push(i);
            }
        }
        for(auto i:isVisit)if(!i)return false;
        return true;
    }
};