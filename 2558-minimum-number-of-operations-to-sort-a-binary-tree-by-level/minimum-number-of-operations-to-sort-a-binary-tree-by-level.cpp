class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=0;
        while(!(q.empty())){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                temp.push_back(q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            vector<int>con=temp;
            sort(con.begin(),con.end());
            // float noteq=0;
            // for(int i=0;i<n;i++){
            //     if(con[i]!=temp[i])noteq++;
            // }
            // res+=ceil(noteq/2);
            for(int i=0;i<n;i++){
                if(con[i]==temp[i])continue;
                int noteq=0;
                for(int j=i+1;j<n;j++){
                    if(con[i]==temp[j]){
                        int t=temp[j];
                        temp[j]=temp[i];
                        temp[i]=t;
                        res++;
                        continue;
                    }
                    // else noteq++;
                }
                // if(!noteq)break;
            }
            cout<<res<<" ";
        }
        return res;
    }
};