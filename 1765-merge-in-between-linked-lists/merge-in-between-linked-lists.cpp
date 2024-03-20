class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // if(a==1 and b==1){
        //     ListNode * temp=list2;
        //     while(temp){
        //         if(!temp->next){
        //             temp->next=list1;
        //             return list2;
        //         }
        //         temp=temp->next;
        //     }
        // }        
        ListNode * temp=list1,*ne=NULL,*bNode=NULL,*aNext=NULL,*aPre=NULL;
        if(a==1){
            aNext=list1->next;
            aPre=list1;
        }
        else{
            int cnt=0;
            while(temp){
                if(cnt==a-1){
                    aNext=temp->next;
                    aPre=temp;
                    break;
                }
                temp=temp->next;
                cnt++;
            }
        }
        if(b==1){
            bNode=list1->next->next;
        }
        else{
            int cnt=a;
            while(aNext){
                if(cnt==b){
                    bNode=aNext->next;
                    break;
                }
                aNext=aNext->next;
                
                cnt++;
            } 
        }  
        temp=list2;
        while(temp){
            if(!temp->next){
                temp->next=bNode;
                aPre->next=list2;
                break;
            }
            temp=temp->next;
        }                 
        return list1;
    }
};