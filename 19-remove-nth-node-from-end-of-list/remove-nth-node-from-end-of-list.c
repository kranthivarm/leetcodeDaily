/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node;
node* removeNthFromEnd(node* head, int n){
if(head==NULL)return head;
node *temp=head,*x=NULL;
int l=0,cnt;
while(temp)
{
    ++l;   
    temp=temp->next;   
}
cnt=0;temp=head;
if(l==n){
    head=head->next;
    return head;
}
while(temp){  
    ++cnt;
    if(cnt==l-n){
        if(l-n==0){
            if(temp->next==NULL)temp=NULL;
            else temp=temp->next;break;
        }
        else{         
            if(temp->next==NULL)temp->next=NULL;
            else temp->next=temp->next->next;
        break;}
    }
    temp=temp->next;  
}return head;
}