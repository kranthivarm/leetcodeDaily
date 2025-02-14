/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
node* partition(node* head, int x){
    if (head==NULL || head->next==NULL)return head;
    node *temp=head,*small=NULL,*big=NULL,*small_head=NULL,*big_head=NULL;
    while(temp)    
    {
        // printf("%d ",(temp->val));
        if(temp->val < x)
        {
            if(small==NULL)
            {
                small=temp;
                small_head=temp;               
            }
            else {
                small->next=temp;                        
                small=small->next;
            }
                temp=temp->next;  
                small->next=NULL;          
        }
        else{
            if(big==NULL)
            {
                big=temp;
                big_head=big;                
            }
            else {
                big->next=temp;                
                big=big->next;
            }
            temp=temp->next;
            big->next=NULL;        
        }
    }
    if(small_head==NULL && big_head==NULL)return NULL;
    if(big_head==NULL)return small_head;
    if(small_head==NULL)return big_head;
    small->next=big_head;
    return small_head;
    

}

//  typedef struct ListNode node;
// node* partition(node* head, int x){
// node* temp=head,*res,*pre,*x_x,*post,*temparary,*pre1;
// while(temp->val!=x)temp=temp->next;
// res=temp;
// pre=res;
// temp=temp->next;
// while(temp!=NULL)
// {
//     if(temp->val<x)
//     {   temparary=head;
//     //removing node whose value lesser than x
//         post=temp->next;        
//         pre->next=post;
//         temp->next=NULL;
//         x_x=temp;
//         temp=post;
//     //appending node before x;
//         while(temparary!=res){
//             if(temparary->val>x_x->val){
//                 if(temparary==head){
//                     x_x->next=temparary;
//                     head=x_x;
//                     break;
//                 }
//                 else{
//                     x_x->next=temparary;
//                     pre1->next=x_x;
//                     break;
//                 }
//             }
//             temparary=temparary->next;
//             pre1=temparary;
//         }
//     }
//     else temp=temp->next;
//     pre=temp;
// }
// return head;
// }