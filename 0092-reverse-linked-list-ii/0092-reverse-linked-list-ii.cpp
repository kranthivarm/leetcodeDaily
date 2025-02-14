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
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     if(head==NULL)return NULL;
    //     ListNode* temp=head,*lefthead=NULL,*pre=NULL,*ne=NULL,*nn=NULL;
    //     int i,cnt=0;
    //     while(temp){
    //         ++cnt;
    //         if(cnt==left)break;
    //         pre=temp;
    //         temp=temp->next;
    //     }

    //     while(temp){
    //         if(cnt==right+1){
    //             break;
    //         }
    //         nn=temp;
    //         temp=temp->next;
    //         nn->next=pre->next;
    //         pre->next=nn;
    //         cnt++;
    //     }
    //     return head;
    // }
    ListNode* reverseBetween(ListNode* h, int l, int r) {
        if (h == nullptr) return h;
        
        ListNode* temp = new ListNode(0);
        temp->next = h;
        
        ListNode* pre = temp;
        for (int i = 0; i < l-1; i++) {
            pre = pre->next;
        }
        ListNode* curr = pre->next;
        
        for (int i = 0; i < r-l; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        
        return temp->next;
    }


};