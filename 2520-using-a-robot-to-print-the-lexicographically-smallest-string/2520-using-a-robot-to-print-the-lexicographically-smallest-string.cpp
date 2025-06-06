class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        string res="";
        vector<char>suffix(n,'z');
        suffix[n-1]=s[n-1];
        for(int i=n-2;i>-1;i--)suffix[i]=min(suffix[i+1],s[i]); 
        stack<int>st;
        for(int i=0;i<n;i++){            
            if(st.empty()){st.push(s[i]);continue;}
            while(!st.empty()){
                if(st.top()<=suffix[i]){
                    res+=st.top();                    
                    st.pop();                    
                }
                else break;
            }      
            st.push(s[i]);
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
        // int n=s.size();
        // string res="";
        // map<char,int>mp;
        // for(auto i:s)mp[i]++;
        // stack<int>st;
        // for(int i=0;i<n;i++){            
        //     st.push(s[i]);
        //     while(!st.empty()){
        //         char ch=mp.begin()->first;
        //         if(st.top()==ch){
        //             res+=ch;
        //             if(mp[ch]==1)mp.erase(ch);
        //             else mp[ch]--;
        //             st.pop();
        //         }
        //         else break;
        //     }
        // }
        // while(!st.empty()){
        //     res+=st.top();
        //     st.pop();
        // }
        // return res;
    }
};