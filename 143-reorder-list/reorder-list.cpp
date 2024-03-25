
class Solution {
public:
// ListNode * temp=NULL,*half=NULL;
// int x=0;
//     void recurse(ListNode *head,int len){
//     if(head){
//         ++x;
//         if(len%2){//odd length;
//             if(x==len/2)return ;
//         }
//         else {
//             if(x==len/2){
//                 temp=head->next;
//                 head->next=half;
//                 if(head->next)head->next->next=temp;
//                 else head->next=temp;
//                 half=half->next;
//                 return ;
//             }
//         }        
//         recurse(head->next,len);
//             temp=head->next;
//             head->next=half;
//             if(head->next)head->next->next=temp;
//             else head->next=temp;
//             half=half->next;
//     }
//     }
//     void reorderList(ListNode* head) {
//         if(head==NULL || head->next==NULL)return ;
//         temp=head;
//         int cnt=0,x=0;
//         while(temp){
//             ++cnt;
//             temp=temp->next;
//         }
//         cnt=0;
//         while(temp){
//             ++x;
//             if(x==cnt/2 && cnt%2){
//                 half=temp->next;
//                 break;
//             }
//             else {
//                 half=temp;
//                 break;
//             }
//             temp=temp->next;
//         }
//         if(cnt==2)return;
//         recurse(head,cnt);
//     }
    void reorderList(ListNode* head) {
        //length of list
        //reversing from middle(half of list reversing)
        if(head==NULL)return;
        if(head->next==NULL)return ;
        int len=0,cnt=0;
        ListNode *temp=head,*pre=NULL,*ne=NULL,*reverse=NULL;
        while(temp){
            len++;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            cnt++;
            if(cnt==(len/2)){
                reverse=temp->next;
                break;
            }
            temp=temp->next;
        }
        if(len%2){
            reverse=reverse->next;
            temp=temp->next;
        }
        temp->next=NULL;
        //reversing half from middle
        while(reverse){
            ne=reverse->next;
            reverse->next=pre;
            pre=reverse;
            reverse=ne;
        }
        //pre is reversed half list
        temp=head;
        while(temp){
            ne=temp->next;
            temp->next=pre;
            if(pre)pre=pre->next;
            if(temp->next)temp->next->next=ne;
            temp=ne;
        }
        // return head;
    }
};