class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>mention(n,0);
        vector<int>t(n,0);
        for(int i=0;i<n;i++)t[i]=i;
        //sorting of events directly
        auto comp=[&](vector<string>i,vector<string>j){
            if(stoi(j[1])==stoi(i[1]) ){
                if(i[0][0]=='M')return false;
                return true;
            }
            return (stoi(i[1])<stoi(j[1]));
            // else return true;
        };
        sort(events.begin(),events.end(),comp);
        for(auto i:events){
            for(auto j:i)cout<<j<<" ";
            cout<<endl;
        }

        // //sorting events with by sorting vector with indices 
        // auto comp=[&](int i,int j){
        //     if(i<j){
        //         if(stoi(events[i][1])==stoi(events[j][1]))
        //         return true;                
        //     }
            
        //     if(stoi(events[i][1])<stoi(events[j][1])){
        //         auto t=events[i];
        //         events[i]=events[j];
        //         events[j]=t;
        //         return false;
        //     }
        //     // if(stoi(j[1])==stoi(i[1]) && j[0][0]=='M' && i[0][0]=='O')return false;
        //     else return true;
        // };
        // sort(t.begin(),t.end());
        int cnt=0;
        for(int i:t)cout<<i;
        unordered_map<int,int>ump;
        unordered_map<int,bool>zero;
        for(auto i:events){            
            int t=stoi(i[1]);
            // cout<<"-  ";
            if(i[0][0]=='M'){
                string s="";
                if(i[2][0]=='H'){
                    for(int id=0;id<n;id++){
                        // if(ump.find(id)==ump.end()){
                        if(ump[id]==0 && zero[id]==false){
                            mention[id]++;
                            continue;
                        }
                        if(ump[id]+60<=t)mention[id]++;
                    }
                    continue;
                }
                if(i[2][0]=='A'){
                    cnt++;
                    continue;
                }
                for(auto j:i[2]){
                    // if(j!=' ' && j<'0' && j>'9')continue;
                    if(j=='i' or j=='d'){
                        s="";
                        continue;
                    }
                    if(j==' '){
                        int id=stoi(s);
                        //// if(ump.find(id)==ump.end()){
                        // if(ump[id]==0 && zero[id]==false){
                        //     mention[id]++;
                        //     continue;
                        // }
                        // if(ump[id]+60<=t)mention[id]++;
                        mention[id]++;
                        s="";
                    }
                    else s+=j;
                }
                if(s=="")continue;
                int id=stoi(s);
                // // if(ump.find(id)==ump.end()){
                // if(ump[id]==0 && zero[id]==false){
                //     mention[id]++;
                //     continue;
                // }
                // if(ump[id]+60<=t)mention[id]++;
                mention[id]++;
            }
            else {
                if(t==0)zero[stoi(i[2])]=true;
                ump[stoi(i[2])]=t;                
            }
        }
        for(int i=0;i<n;i++)mention[i]+=cnt;
        return mention;
    }
};