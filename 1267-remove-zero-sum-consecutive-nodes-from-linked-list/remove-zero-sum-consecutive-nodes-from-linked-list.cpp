/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // return NULL;
        ListNode *temp=head,*pre=NULL;
        int sum=0;
        //removing all zeroes;
        while(temp){
            if(temp->val==0){//removing all zeroes
                if(pre==NULL){
                    temp=temp->next;
                    head=temp;                    
                }
                else{
                    pre->next=temp->next;
                    temp=temp->next;
                }
                continue;
            }
            pre=temp;
            temp=temp->next;
        }
        if(!head)return NULL;
        vector<ListNode*>con;
        temp=head;
        int neg=0;
        while(temp){
            int sum=temp->val;
            if((temp->val)<0)neg++;
            if(neg>0){
                int x=0;
                for(int i=con.size()-1;i>-1;i--){
                    sum+=con[i]->val;
                    // cout<<(con[i]->val)<<" ";
                    if(sum==0){
                        // cout<<(temp->val)<<" ";
                        if(i-1>-1){
                            con[i-1]->next=temp->next;
                        }
                        else {
                            head=temp->next;
                        }
                        temp=head;
                        neg=0;
                        vector<ListNode*>t;
                        con=t;
                        x=1;
                        continue;
                    }
                }
                // cout<<endl;
                // if(!head)return NULL;
                if(x)continue;
            }
            con.push_back(temp);
            temp=temp->next;
        }
        return head;
    }
};