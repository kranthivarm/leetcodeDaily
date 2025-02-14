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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL)return head;
        ListNode* temp=head,*pre=NULL;
        head=NULL;
        while(temp){
            ListNode* t=temp->next;
            bool ptr=false;
            while(t){
                if(t->val == temp->val){
                    ptr=true;
                    t=t->next;
                }
                else break;
            }
            if(ptr){  
                if(pre!=NULL){
                    pre->next=t;
                }                
                temp=t;
            }            
            else {
                pre=temp;
                if(head==NULL)head=pre;
                temp=temp->next;
            }
        }
        return head;

    }
};