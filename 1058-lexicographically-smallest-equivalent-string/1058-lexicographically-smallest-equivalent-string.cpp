class Solution {
public:    
    vector<char>smallEquParent;
    char parentFind(char ch){
        int a=ch-'a';
        if(smallEquParent[a]==ch)return ch;
        // if(smallEquParent[a]==96)return smallEquParent[a]=ch;
        return smallEquParent[a]=parentFind(smallEquParent[a]);
    }
    void unionFind(char a,char b){
        char p1=parentFind(a);
        char p2=parentFind(b);
        if(p1<p2) smallEquParent[p2-'a']=p1;        
        else smallEquParent[(p1-'a')]=p2;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {        
        smallEquParent.resize(26,'a');
        for(int i=0;i<26;i++)smallEquParent[i]=('a'+i);
        for(int i=0;i<s1.size();i++){
            // unionFind(s1[i],s2[i]);
            smallEquParent[(s1[i]-'a')]=min(smallEquParent[(s1[i]-'a')],s2[i]);
            smallEquParent[(s2[i]-'a')]=min(smallEquParent[(s2[i]-'a')],s1[i]);
        }
        for(int i=0;i<s1.size();i++){
            unionFind(s1[i],s2[i]);
        }
        for(int i=0;i<26;i++)unionFind(('a'+i),smallEquParent[i]);
        for(int i=0;i<baseStr.size();i++)baseStr[i]=smallEquParent[(baseStr[i]-'a')];
        return baseStr;
    }
};